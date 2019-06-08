#include "broken.h" //КЛАСС ЛОМАНОЙ

broken::broken()
{
}

int pointCount;

void broken::draw(QImage *image, QPen pen) //РИСОВАНИЕ ЛОМАНОЙ
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.drawLine(X(),Y(),X_2(),Y_2());
}
