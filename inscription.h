#ifndef INSCRIPTION_H
#define INSCRIPTION_H


#include "QPainter"
#include "point.h"
#include "mypen.h"
#include "mybrush.h"


class inscription : public point, public myPen, public myBrush
{
public:
    inscription();
    void draw(QImage *image, QPen pen, QBrush brush);
    void setText(QString str);
    QString getText();
private:
    QString text;
};

#endif // INSCRIPTION_H
