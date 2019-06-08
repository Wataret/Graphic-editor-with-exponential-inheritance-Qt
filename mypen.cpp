#include "mypen.h" //КЛАСС ПЕРА

myPen::myPen()
{
}

QPen myPen::getPen() //ВЫБОР СТИЛЯ ЛИНИИ
{
    switch (CurrStyle)
    {
    case SolidLine:
    {
        pen.setStyle(Qt::SolidLine);
        break;
    }
    case DashLine:
    {
        pen.setStyle(Qt::DashLine);
        break;
    }
    case DotLine:
    {
        pen.setStyle(Qt::DotLine);
        break;
    }
    case DashDotLine:
    {
        pen.setStyle(Qt::DashDotLine);
        break;
    }
    case DashDotDotLine:
    {
        pen.setStyle(Qt::DashDotDotLine);
        break;
    }
    }
    pen.setWidth(CurrWidth);
    pen.setColor(getColor());
    return(pen);
}


void myPen::setPStyle(int style)
{
    CurrStyle=style;
}


void myPen::setThick(int width)
{
    CurrWidth=width;
}


int myPen::getStyle()
{
    return(CurrStyle);
}


int myPen::getThick()
{
     return(CurrWidth);
}
