#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QWidget>
#include "QPainter"
#include "QDebug"

class DrawWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWindow(QWidget *parent = 0);
    void show(void);
    void hide(void);
    bool isVisible(void);
    void setVision(bool fl);
    QImage *getImage();
    void clearImage();
signals:

public slots:

private:
    void paintEvent(QPaintEvent *event);
    bool fl_dr;
    QImage *drawImage;
};

#endif // DRAWWINDOW_H
