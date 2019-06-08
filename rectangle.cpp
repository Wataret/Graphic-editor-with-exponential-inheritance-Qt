#include "rectangle.h" //КЛАСС ПРЯМОУГОЛЬНИКА

rectangle::rectangle()
{
}


void rectangle::draw(QImage *image, QPen pen, QBrush brush) //РИСОВАНИЕ ПРЯМОУУГОЛЬНИКА
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(X(),Y(),getWidth(),getHeight());
}


void rectangle::setWidth(int w)
{
    width=w;
}


void rectangle::setHeight(int h)
{
    height=h;
}


int rectangle::getWidth(void)
{
    return(width);
}


int rectangle::getHeight(void)
{
    return(height);
}
