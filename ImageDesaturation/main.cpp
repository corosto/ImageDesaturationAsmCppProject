#include "ImageDesaturation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageDesaturation w;
    w.show();
    return a.exec();
}
