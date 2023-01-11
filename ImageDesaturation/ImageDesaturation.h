#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QColor>
#include <QMutexLocker>
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "windows.h"
#include "histogram.h"
#include "ui_ImageDesaturation.h"

class ImageDesaturation : public QMainWindow
{
    Q_OBJECT

public:
    ImageDesaturation(QWidget *parent = nullptr); //postawowy konstruktor
    ~ImageDesaturation(); //postawowy destruktor

private:
    void ThreadConversion(int, int); //funkcje przyjmujace poczatkowy i koncowy wiersz dla danego watku, 
                                     //wywoluja petle i przekazuja parametry pojedynczego pixela do dll
    Ui::MainWindow ui; //obiekt okna
    QImage imageBefore; //zmienna przechowujaca zdjecie po konwersji
    QImage imageAfter; //zmienna przechowujaca zdjecie przed konwersja
    QImage blankImage; //pusta zmienna uzywana do czyszczenia imageAfter oraz imageBefore
    bool validImage = false; //zmienna uzywana do sprawdzenia czy zdjecie zostalo wczytane
    std::mutex mut; //obiekt mutexa
    HINSTANCE dllHandle = NULL; //handler do dll'ki
    typedef float(_stdcall* DesaturationFunction)(float, float, float); //definicja funkcji bedacej w dll zwracajaca odpowiedni kolor pixela
    DesaturationFunction ConversionFunction; //funkcja desaturacji w dll z assemblera i c++
    std::vector<std::thread> myThreads; //wektor watkow
    double elapsed = 0; //czas wykonania konwersji
    int threadCount = 0; //ilosc watkow
    double rowsPerThread = 0; //ilosc wierszy na watek
    histogram* histogramBefore;
    histogram* histogramAfter;

private slots:
    void threadsSlider(); //metoda wyboru ilosci watkow
    void loadImage(); //metoda ladujaca zdjecie 
    void convertImage(); //metoda rozpoczynajaca konwersje zdjecia
    void CreateColorChart();
    void CreateGreyChart();
};