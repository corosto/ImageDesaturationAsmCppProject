#include "ImageDesaturation.h"

ImageDesaturation::ImageDesaturation(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this); //setup okna
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint); //blokowanie zmiany rozmiaru okna
    this->setFixedSize(QSize(1072, 583)); //ustawianie stalego rozmiaru okna
}

ImageDesaturation::~ImageDesaturation()
{}

void ImageDesaturation::threadsSlider() {
    ui.threadsDisplay->setText(QString::number(ui.threadsSlider->value())); //wyswietlanie slidera ilosci threadow w oknie
}

void ImageDesaturation::loadImage() {///////////////////////////////////////////////////////////
    QString file = QFileDialog::getOpenFileName(this, tr("Choose"), "C:/Users/", tr("Images(*.png * .jpg * .jpeg * .bmp)"));
    QString fileName = file.mid(file.lastIndexOf("/") + 1);//wyluskiwanie nazwy pliku do wyswietlenia w oknie

    if (QString::compare(file, QString()) != 0) {
        imageAfter = blankImage; //czyszczenie zmiennych oraz obrazow
        imageBefore = blankImage; //czyszczenie zmiennych oraz obrazow
        ui.imageBefore->setPixmap(QPixmap::fromImage(blankImage)); //czyszczenie zmiennych oraz obrazow
        ui.imageAfter->setPixmap(QPixmap::fromImage(blankImage)); //czyszczenie zmiennych oraz obrazow

        validImage = imageBefore.load(file); //ladowanie zdjecia oraz zapisywanie czy sie zaladowalo

        if (validImage) {//jezeli tak to program sprawdza czy uzytkownik chce miec zdjecie przeskalowane do odpowiedniej wielkosci
            if (ui.scaleImagesButton->isChecked()) { //i laduje zdjecie w odpowiednim miejscu w oknie
                QImage scaledImageBefore = imageBefore.scaled(ui.imageBefore->width(), ui.imageBefore->height());
                ui.imageBefore->setPixmap(QPixmap::fromImage(scaledImageBefore));
            }
            else {
                ui.imageBefore->setPixmap(QPixmap::fromImage(imageBefore));
            }
            ui.scaleImagesButton->setEnabled(false);//wylaczenie mozliwosci skalowania zdjecia
            ui.convertImageButton->setEnabled(true); //wlaczenie mozliwosci desaturacji zdjecia
            ui.timeLabel->setText(""); //wyczyszczenie labela z czasem konwersji
            ui.messageForUser->setAlignment(Qt::AlignCenter);
            ui.messageForUser->setText("Waiting for action..."); //wiadomosc dla uzytkownika
            ui.nameLabel->setText("Image name: " + fileName); //nazwa pliku
            ui.dimensionsLabel->setText("Image dimensions: " + QString::number(imageBefore.width()) + " x " + QString::number(imageBefore.height()));//wymiary pliku
        }
        else {//jezeli nie udalo sie zaladowac zdjecia to uzytkownik moze sprobowac znow wczytac zdjecie
            ui.convertImageButton->setEnabled(false);
        }
    }
}

void ImageDesaturation::convertImage() {
    
    if (validImage) {

        myThreads.clear(); //czyszczenie wszytskich zmiennych
        elapsed;
        imageAfter  = blankImage;
        imageAfter = imageBefore;
        ui.imageAfter->setPixmap(QPixmap::fromImage(blankImage));

        threadCount = ui.threadsSlider->value(); //ilosc watkow ktora wybral uzytkownik
        rowsPerThread = std::ceil(imageAfter.height() / threadCount); //ilosc wierszy przypadajacych na 1 watek

        clock_t start = clock(); //poczatek mierzenia czasu
        dllHandle = (ui.useCPPdll->isChecked()) ? LoadLibrary(TEXT("CppLibrary.dll")) : LoadLibrary(TEXT("AsmLibrary.dll")); //ladowanie biblioteki do handlera

        if (dllHandle != NULL) { //pomyslnie zaladowano
            ConversionFunction = (DesaturationFunction)GetProcAddress(dllHandle, "DesaturationFunction"); //ladowanie adresu biblioteki

            if (NULL != ConversionFunction) {//jezeli to tez sie powiodlo to 

                for (int threadNumber = 0; threadNumber < threadCount; threadNumber++) {
                    int startRow = threadNumber * rowsPerThread;//miejsce od ktorego watek zaczyna
                    int endRow = ((threadNumber + 1) * rowsPerThread) - 1;//miejsce w ktorym watek konczy

                    if (threadNumber + 1 == threadCount) {//ostatni loop, dostaje wiersze od swojego poczatku do konca zdjecia
                        myThreads.push_back(std::thread(&ImageDesaturation::ThreadConversion, this, startRow, imageAfter.height() - 1));
                    }
                    else {//kazdy inny loop, kazdy thread dostaje odpowiednie zakresy
                        myThreads.push_back(std::thread(&ImageDesaturation::ThreadConversion, this, startRow, endRow));
                    }
                }

                for (auto& t : myThreads) {
                    t.join(); //joinowanie wszytskich threadow
                }
            
                clock_t end = clock(); //koniec mierzenia czasu
                elapsed = double(end - start) / CLOCKS_PER_SEC;  //obliczanie czasu trwania programu

                if (ui.scaleImagesButton->isChecked()) {//ladowanie zdjecia(przeskalowanego lub nie) do miejsca wynikowego
                    QImage scaledImageAfter = imageAfter.scaled(ui.imageAfter->width(), ui.imageAfter->height());
                    ui.imageAfter->setPixmap(QPixmap::fromImage(scaledImageAfter));
                }
                else {
                    ui.imageAfter->setPixmap(QPixmap::fromImage(imageAfter));
                }
        
                ui.timeLabel->setText("Execution time: " + QString::number(elapsed) + " seconds");//wypisanie czasu dzialania konwersji
                ui.scaleImagesButton->setEnabled(true);//wlaczenie przycisku do skalowania
            }
        }
        else {
            exit(134);//blad wczytywania dll, wywala blad
        }
    }
}

void ImageDesaturation::ThreadConversion(int startingRow, int endingRow) {
    for (int row = startingRow; row <= endingRow; row++) {
        for (int col = 0; col < this->imageAfter.width(); col++) {
            QColor currentRGB = this->imageAfter.pixel(col, row);//wyluskanie RGB z pixela
            float greyValue = ConversionFunction((float)currentRGB.red(), (float)currentRGB.green(), (float)currentRGB.blue());//wyliczenie odcienia szarosci w dll
            QMutexLocker locker(&mut);// mutex zeby nie bylo artefaktow ale dziala 6|7 razy wolniej
            this->imageAfter.setPixel(col, row, qRgb(greyValue, greyValue, greyValue));//ustawienie wyliczonej wartosci na odpowiednim pixelu
        }
    }
}