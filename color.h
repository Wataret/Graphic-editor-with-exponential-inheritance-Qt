#ifndef COLOR_H
#define COLOR_H

#include "QColor"

class color
{
public:
    color();
    void setColor(QColor clr);
    QColor getColor();
private:
    QColor CurrColor;
};

#endif // COLOR_H
