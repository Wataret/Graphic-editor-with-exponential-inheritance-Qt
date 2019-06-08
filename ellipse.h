#ifndef ELIPSE_H
#define ELIPSE_H

#include "QPainter"
#include "point.h"
#include "mypen.h"
#include "mybrush.h"


class ellipse : public point, public myPen, public myBrush
{
public:
    ellipse();
    void draw(QImage *image, QPen pen, QBrush brush);
    void setRad1(int r1);
    void setRad2(int r2);
     int getR1(void);
     int getR2(void);
private:
    int rad1,rad2;
};

#endif // ELIPSE_H
