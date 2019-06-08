#include "polygon.h" //КЛАСС МНОГОУГОЛЬНИКА
#include <QDebug>

polygon::polygon()
{
}

QPoint *pnt;
int pointCnt;

void polygon::draw(QImage *image, QPen pen, QBrush brush) //РИСОВАНИЕ МНОГОУГОЛЬНИКА
{
    QPainter painter(image);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolygon(pnt,pointCnt);
}


void polygon::setPointCount(int count) //СОЗДАНИЕ МАССИВА ТОЧЕК
{
    pointCnt=count;
    pnt = new QPoint [pointCnt];
}


int polygon::getPointCount()
{
    return(pointCnt);
}


void polygon::deletePntArray() //УДАЛЕНИЕ МАССИВА ТОЧЕК
{
    if (!pnt->isNull())
    {

        delete [] pnt;
        pnt=NULL;
    }
}


void polygon::setPoint(int n, int x, int y)
{
    pnt[n].setX(x);
    pnt[n].setY(y);
}


int polygon::getPointX(int n)
{
    return (pnt[n].x());
}


int polygon::getPointY(int n)
{
    return (pnt[n].y());
}
