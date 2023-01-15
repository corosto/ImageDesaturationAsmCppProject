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

    int redArray[256]{};
    int greenArray[256]{};
    int blueArray[256]{};

private:
    Ui::histogramClass ui;
};