#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_histogram.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

class histogram : public QDialog
{
    Q_OBJECT

public:
    histogram(QImage, QWidget* parent = nullptr);
    ~histogram();

    int redBefore[256]{};
    int greenBefore[256]{};
    int blueBefore[256]{};
    int redAfter[256]{};
    int greenAfter[256]{};
    int blueAfter[256]{};

private:
    Ui::histogramClass ui;
};