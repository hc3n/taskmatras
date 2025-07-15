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

        QByteArray byteArray = filebin.readAll();


    filebin.close();

        qDebug() << "Прочитано байт:" << byteArray.size();

        for (char byte : byteArray) {
            for(int i = 7; i >= 0 ; --i) {
                bool bit = (byte >> i) & 1;
                bitVector.append(bit);
            }
        }




};

QImage BitWidget::risovalka(const QVector<bool> &bitVector,int period)
{

    return QImage();
};
