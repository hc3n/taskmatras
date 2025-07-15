/*
Зеленый = 1 QColor(0,255,0)
Черный = 0 QColor(0,0,0)

*/
#include <QApplication>
#include "mainwindow.h"
#include "bitwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;

    BitWidget bitWidget;
    QVector<bool> bitVector;
    bitWidget.obrabotkaBin("/Users/timofey/QtLib/STCproject/test_short_1504.bin",bitVector);
    window.setWindowTitle("Битовый отрисовщик");
    window.resize(400, 150);
    window.show();

    return app.exec();
}
