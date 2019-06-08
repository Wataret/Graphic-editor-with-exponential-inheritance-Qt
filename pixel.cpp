#include "pixel.h" //КЛАСС ПИКСЕЛЯ

pixel::pixel()
{
}


void pixel::draw(QImage *image, QPen pen) //МЕТОД ОТОБРАЖЕНИЯ ПИКСЕЛЯ
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.drawPoint(X(),Y());
}
