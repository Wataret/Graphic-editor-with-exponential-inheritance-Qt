#ifndef CURVE_H
#define CURVE_H

#include "rectangle.h"
#include "QPainter"

class curve : public rectangle
{
public:
    curve();
    void draw(QImage *image, QPen pen);
    void setStartAngle(int angle);
    void setEndAngle(int angle);
     int getStartAngle(void);
     int getEndAngle(void);
private:
    int StartAngle,EndAngle;
};

#endif // CURVE_H
