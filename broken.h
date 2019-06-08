#ifndef BROKEN_H
#define BROKEN_H

#include "line.h"
#include "mypen.h"
#include "mybrush.h"
#include "QPainter"

class broken  : public line
{
public:
    broken();
    void draw(QImage *image, QPen pen);

private:
};

#endif // BROKEN_H
