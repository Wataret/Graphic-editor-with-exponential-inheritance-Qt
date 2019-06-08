#include "mybrush.h" //КЛАСС ЗАЛИВКИ

myBrush::myBrush()
{
}


QBrush myBrush::getBrush() //ВЫБОР СТИЛЯ ЗАЛИВКИ
{
    switch (CurrStyle)
    {
    case NoBrush:
    {
        brush.setStyle(Qt::NoBrush);
        break;
    }
    case SolidPattern:
    {
        brush.setStyle(Qt::SolidPattern);
        break;
    }
    case HorPattern:
    {
        brush.setStyle(Qt::HorPattern);
        break;
    }
    case VerPattern:
    {
        brush.setStyle(Qt::VerPattern);
        break;
    }
    case CrossPattern:
    {
        brush.setStyle(Qt::CrossPattern);
        break;
    }
    case RadialGradientPattern:
    {
        brush.setStyle(Qt::RadialGradientPattern);
        break;
    }
    }
    brush.setColor(getColor());
    return(brush);
}


void myBrush::setBStyle(int style)
{
    CurrStyle=style;
}


int myBrush::getStyle()
{
    return(CurrStyle);
}

