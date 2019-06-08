#ifndef PIXEL_H
#define PIXEL_H

#include "point.h"
#include "QPainter"
#include "mypen.h"
#include "mybrush.h"

class pixel : public point, public myPen, public myBrush
{
public:
    pixel();
    void draw(QImage *image, QPen pen);

};

#endif // PIXEL_H
