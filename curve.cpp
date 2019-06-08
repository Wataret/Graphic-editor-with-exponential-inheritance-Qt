#include "curve.h" //КЛАСС ДУГИ

curve::curve()
{
}

int StartAngle,EndAngle;

void curve::draw(QImage *image, QPen pen) //РИСОВАНИЕ ДУГИ
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.drawArc(X(),Y(),getWidth(),getHeight(),getStartAngle()*16,getEndAngle()*16);
}


void curve::setStartAngle(int angle)
{
    StartAngle=angle;
}


void curve::setEndAngle(int angle)
{
    EndAngle=angle;
}


int curve::getStartAngle(void)
{
    return(StartAngle);
}


int curve::getEndAngle(void)
{
    return(EndAngle);
}
