#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "QPainter"
#include "point.h"
#include "mypen.h"
#include "mybrush.h"

class rectangle : public point, public myPen, public myBrush
{
public:
    rectangle();
    void draw(QImage *image, QPen pen, QBrush brush);
    void setWidth(int w);
    void setHeight(int h);
    int getWidth(void);
    int getHeight(void);
private:
    int height,width;
};

#endif // RECTANGLE_H
