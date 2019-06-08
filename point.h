#ifndef POINT_H
#define POINT_H

#include "QPainter"

class point
{
public:
    point();
    void setX(int X);
    void setY(int Y);
    int X(void);
    int Y(void);
private:
    int x,y;
};

#endif // POINT_H
