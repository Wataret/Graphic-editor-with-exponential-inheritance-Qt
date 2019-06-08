#include "ellipse.h" //КЛАСС ЭЛИПСА

ellipse::ellipse()
{
}

void ellipse::draw(QImage *image, QPen pen, QBrush brush) //РИСОВАНИЕ ЭЛИПСА
{  
    QPainter painter(image);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(X(),Y(),getR1(),getR2());
}

void ellipse::setRad1(int r1)
{
    rad1=r1;
}

void ellipse::setRad2(int r2)
{
    rad2=r2;
}

int ellipse::getR1(void)
{
    return(rad1);
}

int ellipse::getR2(void)
{
    return(rad2);
}
