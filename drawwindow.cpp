#include "drawwindow.h" //КЛАСС ВИДЖЕТА КОТОРЫЙ РИСУЕТ
#include "pixel.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"

QImage *drawImage;

DrawWindow::DrawWindow(QWidget *parent) :
    QWidget(parent)
{
    fl_dr=false;
    drawImage = new QImage(840,590,QImage::Format_ARGB32_Premultiplied); //УСТАНОВКА ПАРАМЕТРОВ ОГРАНИЧЕНИЯ ВИДЖЕТА
}



void DrawWindow::paintEvent(QPaintEvent *event) //ОТРИСОВКА ВИДЖЕТА НА ЭКРАНЕ
{
    if (fl_dr)
    {
        QPainter im_draw(this);
        im_draw.drawImage(0,0,*drawImage);
    }
}


QImage *DrawWindow::getImage()
{
    return(drawImage);
}


void DrawWindow::clearImage() //ОЧИСТКА ВИДЖЕТА
{
    drawImage->fill(0);
    QPainter im_draw(drawImage);
    im_draw.drawImage(0,0,*drawImage);
    repaint();
}

void DrawWindow::show(void)
{
    fl_dr=true;
}


void DrawWindow::hide(void)
{
    fl_dr=false;
}


bool DrawWindow::isVisible(void)
{
    return(fl_dr);
}


void DrawWindow::setVision(bool fl)
{
    fl_dr=fl;
}
