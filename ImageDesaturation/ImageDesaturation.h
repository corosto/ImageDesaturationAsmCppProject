#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QColor>
#include <QDebug>
#include <time.h>
#include <future>
#include "ui_ImageDesaturation.h"

class ImageDesaturation : public QMainWindow
{
    Q_OBJECT

public:
    ImageDesaturation(QWidget *parent = nullptr);
    ~ImageDesaturation();
    void cppThreadConversion(int, int);
    void asmThreadConversion(int, int);

private:
    Ui::MainWindow ui;
    QImage imageBefore;
    QImage imageAfter;
    QImage blankImage;
    bool validImage;
    std::mutex mut;
    typedef float(_stdcall* AsmConversion)(float, float, float);
    HINSTANCE dllHandle = NULL;
    AsmConversion AssemblerFunction;

private slots:
    void threadsSlider();
    void loadImage();
    void convertImage();
};
