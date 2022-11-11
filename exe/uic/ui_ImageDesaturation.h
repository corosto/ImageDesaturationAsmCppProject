/********************************************************************************
** Form generated from reading UI file 'ImageDesaturation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDESATURATION_H
#define UI_IMAGEDESATURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *useASMdll;
    QRadioButton *useCPPdll;
    QLabel *imageBefore;
    QLabel *imageAfter;
    QLabel *labelBefore;
    QLabel *labelAfter;
    QPushButton *loadImageButton;
    QPushButton *convertImageButton;
    QLabel *title;
    QLabel *messageForUser;
    QPushButton *labelButton;
    QLabel *nameLabel;
    QLabel *dimensionsLabel;
    QCheckBox *scaleImagesButton;
    QLabel *timeLabel;
    QSlider *threadsSlider;
    QFrame *frame;
    QLabel *label;
    QLabel *threadsDisplay;
    QButtonGroup *dllGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1085, 610);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{background-color: rgb(127,220,165)}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        useASMdll = new QRadioButton(centralwidget);
        dllGroup = new QButtonGroup(MainWindow);
        dllGroup->setObjectName("dllGroup");
        dllGroup->addButton(useASMdll);
        useASMdll->setObjectName("useASMdll");
        useASMdll->setGeometry(QRect(350, 510, 191, 51));
        QFont font;
        font.setPointSize(10);
        useASMdll->setFont(font);
        useASMdll->setChecked(false);
        useCPPdll = new QRadioButton(centralwidget);
        dllGroup->addButton(useCPPdll);
        useCPPdll->setObjectName("useCPPdll");
        useCPPdll->setGeometry(QRect(350, 470, 191, 51));
        useCPPdll->setFont(font);
        useCPPdll->setAutoFillBackground(false);
        useCPPdll->setChecked(true);
        imageBefore = new QLabel(centralwidget);
        imageBefore->setObjectName("imageBefore");
        imageBefore->setGeometry(QRect(30, 110, 441, 291));
        imageBefore->setAcceptDrops(true);
        imageBefore->setStyleSheet(QString::fromUtf8(""));
        imageBefore->setFrameShape(QFrame::Panel);
        imageBefore->setFrameShadow(QFrame::Plain);
        imageBefore->setScaledContents(false);
        imageAfter = new QLabel(centralwidget);
        imageAfter->setObjectName("imageAfter");
        imageAfter->setGeometry(QRect(600, 110, 441, 291));
        imageAfter->setStyleSheet(QString::fromUtf8(""));
        imageAfter->setFrameShape(QFrame::Panel);
        imageAfter->setFrameShadow(QFrame::Plain);
        labelBefore = new QLabel(centralwidget);
        labelBefore->setObjectName("labelBefore");
        labelBefore->setGeometry(QRect(30, 80, 211, 21));
        labelAfter = new QLabel(centralwidget);
        labelAfter->setObjectName("labelAfter");
        labelAfter->setGeometry(QRect(600, 80, 221, 21));
        loadImageButton = new QPushButton(centralwidget);
        loadImageButton->setObjectName("loadImageButton");
        loadImageButton->setGeometry(QRect(490, 200, 91, 24));
        convertImageButton = new QPushButton(centralwidget);
        convertImageButton->setObjectName("convertImageButton");
        convertImageButton->setEnabled(false);
        convertImageButton->setGeometry(QRect(490, 240, 91, 24));
        convertImageButton->setAutoFillBackground(false);
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(10, 10, 441, 51));
        messageForUser = new QLabel(centralwidget);
        messageForUser->setObjectName("messageForUser");
        messageForUser->setGeometry(QRect(480, 270, 111, 141));
        messageForUser->setFont(font);
        messageForUser->setWordWrap(true);
        labelButton = new QPushButton(centralwidget);
        labelButton->setObjectName("labelButton");
        labelButton->setGeometry(QRect(30, 110, 441, 291));
        labelButton->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(30, 410, 251, 31));
        nameLabel->setAutoFillBackground(false);
        dimensionsLabel = new QLabel(centralwidget);
        dimensionsLabel->setObjectName("dimensionsLabel");
        dimensionsLabel->setGeometry(QRect(30, 440, 251, 31));
        scaleImagesButton = new QCheckBox(centralwidget);
        scaleImagesButton->setObjectName("scaleImagesButton");
        scaleImagesButton->setGeometry(QRect(460, 400, 181, 41));
        scaleImagesButton->setFont(font);
        scaleImagesButton->setChecked(true);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(30, 470, 251, 31));
        threadsSlider = new QSlider(centralwidget);
        threadsSlider->setObjectName("threadsSlider");
        threadsSlider->setGeometry(QRect(610, 511, 201, 31));
        threadsSlider->setMinimum(1);
        threadsSlider->setMaximum(64);
        threadsSlider->setPageStep(5);
        threadsSlider->setOrientation(Qt::Horizontal);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(540, 470, 341, 91));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 261, 31));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);
        threadsDisplay = new QLabel(frame);
        threadsDisplay->setObjectName("threadsDisplay");
        threadsDisplay->setGeometry(QRect(280, 0, 31, 51));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        threadsDisplay->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        imageBefore->raise();
        useASMdll->raise();
        useCPPdll->raise();
        imageAfter->raise();
        labelBefore->raise();
        labelAfter->raise();
        loadImageButton->raise();
        convertImageButton->raise();
        title->raise();
        messageForUser->raise();
        labelButton->raise();
        nameLabel->raise();
        dimensionsLabel->raise();
        scaleImagesButton->raise();
        timeLabel->raise();
        threadsSlider->raise();

        retranslateUi(MainWindow);
        QObject::connect(loadImageButton, SIGNAL(clicked()), MainWindow, SLOT(loadImage()));
        QObject::connect(convertImageButton, SIGNAL(clicked()), MainWindow, SLOT(convertImage()));
        QObject::connect(labelButton, SIGNAL(clicked()), MainWindow, SLOT(loadImage()));
        QObject::connect(threadsSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(threadsSlider()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        useASMdll->setText(QCoreApplication::translate("MainWindow", "Convert using ASM library", nullptr));
        useCPPdll->setText(QCoreApplication::translate("MainWindow", "Convert using C++ library", nullptr));
        imageBefore->setText(QString());
        imageAfter->setText(QString());
        labelBefore->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#5555ff;\">Image before conversion</span></p></body></html>", nullptr));
        labelAfter->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#5555ff;\">Image after conversion</span></p></body></html>", nullptr));
        loadImageButton->setText(QCoreApplication::translate("MainWindow", "Load image", nullptr));
        convertImageButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; color:#aa55ff;\">Project name: Converting image to greyscale</span></p></body></html>", nullptr));
        messageForUser->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Waiting for action...</p></body></html>", nullptr));
        labelButton->setText(QString());
        nameLabel->setText(QString());
        dimensionsLabel->setText(QString());
        scaleImagesButton->setText(QCoreApplication::translate("MainWindow", "Scale image to fit frame", nullptr));
        timeLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "How many threads to convert image:", nullptr));
        threadsDisplay->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDESATURATION_H
