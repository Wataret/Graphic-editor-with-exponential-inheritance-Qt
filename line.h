#ifndef LINE_H
#define LINE_H

#include "QPainter"
#include "point.h"
#include "mypen.h"
#include "mybrush.h"

class line : public point, public myPen, public myBrush
{
public:
    line();
    void draw(QImage *image, QPen pen);
    void setX_2(int X);
    void setY_2(int Y);
    int X_2(void);
    int Y_2(void);
private:
    int x_2,y_2;
};

#endif // LINE_H
