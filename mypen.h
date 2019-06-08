#ifndef MYPEN_H
#define MYPEN_H

#include "color.h"
#include "QPen"

class myPen : public color
{
public:
    myPen();
    QPen getPen();
    void setPStyle(int style);
    void setThick(int width);
    int getStyle();
    int getThick();

    enum Styles
    {
        SolidLine = 0,
        DashLine = 1,
        DotLine =2,
        DashDotLine = 3,
        DashDotDotLine = 4
    };

private:
    QPen pen;
    int CurrWidth;
    int CurrStyle;
};

#endif // MYPEN_H
