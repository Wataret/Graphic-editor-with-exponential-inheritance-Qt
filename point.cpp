#include "point.h" //КЛАСС ТОЧКИ
#include "mainwindow.h"

point::point()
{
}


void point::setX(int X) //УСТАНОВКА КООРДИНАТЫ X
{
    x=X;
}


void point::setY(int Y) //УСТАНОВКА КООРДИНАТЫ Y
{
    y=Y;
}


int point::X(void)  //ПОЛУЧЕНИЕ КООРДИНАТЫ X
{
    return(x);
}


int point::Y(void)  //ПОЛУЧЕНИЕ КООРДИНАТЫ Y
{
    return(y);
}
