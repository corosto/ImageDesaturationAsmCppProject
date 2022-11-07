#include "ImageDesaturation.h"
#include "windows.h"
#include "CppLibrary.h"
#include <QMutexLocker>

ImageDesaturation::ImageDesaturation(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(1072, 583));
}

ImageDesaturation::~ImageDesaturation()
{}

void ImageDesaturation::threadsSlider() {
    ui.threadsDisplay->setText(QString::number(ui.threadsSlider->value()));
}

void ImageDesaturation::loadImage() {
    QString file = QFileDialog::getOpenFileName(this, tr("Choose"), "C:/Users/filip/Downloads", tr("Images(*.png * .jpg * .jpeg * .bmp)"));
    QString fileName = file.mid(file.lastIndexOf("/") + 1);//SCIEZKA DO ZMIANY

    if (QString::compare(file, QString()) != 0) {
        imageAfter = blankImage;
        imageBefore = blankImage;
        ui.imageBefore->setPixmap(QPixmap::fromImage(blankImage));
        ui.imageAfter->setPixmap(QPixmap::fromImage(blankImage));

        validImage = imageBefore.load(file);

        if (validImage) {
            if (ui.scaleImagesButton->isChecked()) {
                QImage scaledImageBefore = imageBefore.scaled(ui.imageBefore->width(), ui.imageBefore->height());
                ui.imageBefore->setPixmap(QPixmap::fromImage(scaledImageBefore));
            }
            else {
                ui.imageBefore->setPixmap(QPixmap::fromImage(imageBefore));
            }
            ui.scaleImagesButton->setEnabled(false);
            ui.convertImageButton->setEnabled(true);
            ui.messageForUser->setAlignment(Qt::AlignCenter);
            ui.timeLabel->setText("");
            ui.messageForUser->setText("Waiting for action...");
            ui.nameLabel->setText("Image name: " + fileName);
            ui.dimensionsLabel->setText("Image dimensions: " + QString::number(imageBefore.width()) + " x " + QString::number(imageBefore.height()));
        }
        else {
            ui.convertImageButton->setEnabled(false);
        }
    }
}

void ImageDesaturation::convertImage() {
    
    if (validImage) {

        imageAfter  = blankImage;
        ui.imageAfter->setPixmap(QPixmap::fromImage(blankImage));
        imageAfter = imageBefore;

        int threadCount = ui.threadsSlider->value();
        double rowsPerThread = std::ceil(imageAfter.height() / threadCount);
        double elapsed = 0;

        std::vector<std::thread> myThreads;

        if (ui.useCPPdll->isChecked()) {

            clock_t start = clock();

            for (int threadNumber = 0; threadNumber < threadCount; threadNumber++) {
                int startRow = threadNumber * rowsPerThread;
                int endRow = ((threadNumber + 1) * rowsPerThread) - 1;

                if (threadNumber + 1 == threadCount) {//tzn ze to ostatni loop
                    myThreads.push_back(std::thread(&ImageDesaturation::cppThreadConversion, this, startRow, imageAfter.height()-1));
                }
                else {
                    myThreads.push_back(std::thread(&ImageDesaturation::cppThreadConversion, this, startRow, endRow));
                }
            }

            for (auto& t : myThreads) {
                t.join();
            }

            clock_t end = clock();
            elapsed = double(end - start) / CLOCKS_PER_SEC;
        }
        else if(ui.useASMdll->isChecked()) {
            clock_t start = clock();

            dllHandle = LoadLibrary(TEXT("AsmLibrary.dll"));
            AssemblerFunction = (AsmConversion)GetProcAddress(dllHandle, "AsmConversion");

            for (int threadNumber = 0; threadNumber < threadCount; threadNumber++) {
                int startRow = threadNumber * rowsPerThread;
                int endRow = ((threadNumber + 1) * rowsPerThread) - 1;

                if (threadNumber + 1 == threadCount) {//tzn ze to ostatni loop
                    myThreads.push_back(std::thread(&ImageDesaturation::asmThreadConversion, this, startRow, imageAfter.height() - 1));
                }
                else {
                    myThreads.push_back(std::thread(&ImageDesaturation::asmThreadConversion, this, startRow, endRow));
                }
            }

            for (auto& t : myThreads) {
                t.join();
            }

            clock_t end = clock();
            elapsed = double(end - start) / CLOCKS_PER_SEC;
        }

        if (ui.scaleImagesButton->isChecked()) {
            QImage scaledImageAfter = imageAfter.scaled(ui.imageAfter->width(), ui.imageAfter->height());
            ui.imageAfter->setPixmap(QPixmap::fromImage(scaledImageAfter));
        }
        else {
            ui.imageAfter->setPixmap(QPixmap::fromImage(imageAfter));
        }
        
        ui.timeLabel->setText("Execution time: " + QString::number(elapsed) + " seconds");
        ui.scaleImagesButton->setEnabled(true);
    }
}

void ImageDesaturation::cppThreadConversion(int startingRow, int endingRow) {
    for (int row = startingRow; row <= endingRow; row++) {
        for (int col = 0; col < this->imageAfter.width(); col++) {
            QColor currentRGB = this->imageAfter.pixel(col, row);
            float greyValue = CppConversion(currentRGB.red(), currentRGB.green(), currentRGB.blue());
            QMutexLocker locker(&mut);// 6|7 razy wolniej, ale bez tego sa artefakty
            this->imageAfter.setPixel(col, row, qRgb(greyValue, greyValue, greyValue));
        }
    }
}

void ImageDesaturation::asmThreadConversion(int startingRow, int endingRow) {
    for (int row = startingRow; row <= endingRow; row++) {
        for (int col = 0; col < this->imageAfter.width(); col++) {
            QColor currentRGB = this->imageAfter.pixel(col, row);
            float greyValue = AssemblerFunction((float)currentRGB.red(), (float)currentRGB.green(), (float)currentRGB.blue());
            QMutexLocker locker(&mut);// 6|7 razy wolniej, ale bez tego sa artefakty
            this->imageAfter.setPixel(col, row, qRgb(greyValue, greyValue, greyValue));
        }
    }
}