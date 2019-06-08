#ifndef MYBRUSH_H
#define MYBRUSH_H

#include "color.h"
#include "QBrush"

class myBrush   : public color
{
public:
    myBrush();
    QBrush getBrush();
    void setBStyle(int style);
    int getStyle();

    enum Styles
    {
        NoBrush=-1,
        SolidPattern= 0,
        HorPattern = 1,
        VerPattern = 2,
        CrossPattern = 3,
        RadialGradientPattern = 4
    };
private:
    QBrush brush;
    int CurrStyle;
};

#endif // MYBRUSH_H
