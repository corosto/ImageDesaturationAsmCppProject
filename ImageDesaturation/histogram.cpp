#include "histogram.h"

histogram::histogram(QImage image, QWidget* parent)
{
    ui.setupUi(this);

    QLineSeries* red = new QLineSeries();
    QLineSeries* green = new QLineSeries();
    QLineSeries* blue = new QLineSeries();
    QChart* chart = new QChart();
    QChartView* chartView = new QChartView(chart);

    for (int row = 0; row <= image.height(); row++) {
        for (int col = 0; col < image.width(); col++) {
            QColor currentRGB = image.pixel(col, row);
            redBefore[currentRGB.red()]++;
            greenBefore[currentRGB.green()]++;
            blueBefore[currentRGB.blue()]++;
        }
    }

    red->setColor("red");
    green->setColor("green");
    blue->setColor("blue");
    
    for (int i = 0; i < 256; i++) {
        red->append(i, redBefore[i]);
        green->append(i, greenBefore[i]);
        blue->append(i, blueBefore[i]);
    }

    chart->addSeries(red);
    chart->addSeries(green);
    chart->addSeries(blue);


    chart->createDefaultAxes();
    chart->setTitle("Histogram of color");
    chart->legend()->hide();

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui.horizontalFrame);
}

histogram::~histogram()
{
}