#include "bitwidget.h"

BitWidget::BitWidget(QWidget *parent)
    : QWidget(parent)
{

}
// path + filename
void BitWidget::obrabotkaBin(const QString &filename,QVector<bool> &bitVector)
{
    bitVector.clear();
    QFile filebin(filename);

    if(!filebin.open(QIODevice::ReadOnly)) {
        qDebug() << "Ошибка открытия файла" << filename;
        qDebug() << "Причина" << filebin.errorString();
    }

        QByteArray dataBin = filebin.readAll();


    filebin.close();

        qDebug() << "Прочитано байт:" << dataBin.size();


};

QImage BitWidget::risovalka(const QVector<bool> &bitVector,int period)
{

    return QImage();
};
