#include "color.h" //КЛАСС ЦВЕТА

color::color()
{
}

QColor color;

void color::setColor(QColor clr) //УСТАНОВКА ЦВЕТА
{
    CurrColor=clr;
}

QColor color::getColor()
{
    return(CurrColor);
}

