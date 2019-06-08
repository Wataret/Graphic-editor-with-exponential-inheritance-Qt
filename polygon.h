#ifndef polygon_H
#define polygon_H

#include "broken.h"
#include "QPainter"

class polygon : public broken
{
public:
    polygon();
    void draw(QImage *image, QPen pen, QBrush brush);
    void setPointCount(int count=3);
    void deletePntArray();
    int getPointCount();
    void setPoint(int n, int x, int y);
    int getPointX(int n);
    int getPointY(int n);
private:
    QPoint *pnt;
    int pointCnt;
};

#endif // polygon_H
