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
    int height = bitVector.size() / period;
    int width = period;

    /* format_indexed8 8 бит = 1 байт */
    QImage image(width,height,QImage::Format_Indexed8);
    uchar *data = image.bits(); // data - указатель на первый пиксель в памяти
    // используем два цвета через индексированную палитру
    image.setColor(0,qRgb(0,0,0)); // black
    image.setColor(1,qRgb(0,255,0)); // green

    for(int i=0; i<bitVector.size();++i)
    {
        data[i] = bitVector[i] ? 1 : 0;
    }

    return image;
};
