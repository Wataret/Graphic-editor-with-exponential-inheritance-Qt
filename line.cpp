#include "line.h" //КЛАСС ЛИНИИ

line::line()
{
}


void line::draw(QImage *image, QPen pen) //РИСОВАНИЕ ЛИНИИ
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.drawLine(X(),Y(),X_2(),Y_2());
}

void line::setX_2(int X)
{
    x_2=X;
}


void line::setY_2(int Y)
{
    y_2=Y;
}


int line::X_2(void)
{
    return(x_2);
}


int line::Y_2(void)
{
    return(y_2);
}
