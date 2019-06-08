#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QList"
#include "QMessageBox"
#include "QColorDialog"

#include "drawwindow.h" //ПОДКЛЮЧЕНИЕ КЛАССОВ
#include "pixel.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"
#include "curve.h"
#include "broken.h"
#include "polygon.h"


int Work=-1; //УСТАНОВКА НАЧАЛЬНОГО ПАРАМЕТРА ДЛЯ ОТОБРАЖЕНИЯ ГЕОМЕТРИЧЕСКИХ ОБЪЕКТОВ
int n;
QColor penColor,brushColor,lastPenColor,lastBrushColor;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_size->hide();
    ui->label_size->hide();
    ui->comboBox_brushStyle->setVisible(false);
    ui->pushButton_brushColor->setVisible(false);
    ui->comboBox_brushStyle->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked() //НАЧАЛО РИСОВАНИЕ ОБЪЕКТА
{
    bool fl_int;
    myPen pen;
    pen.setThick(ui->spinBox_penWidth->value());
    pen.setPStyle(ui->comboBox_penStyle->currentIndex());
    pen.setColor(penColor);
    myBrush brush;
    brush.setBStyle(ui->comboBox_brushStyle->currentIndex());
    brush.setColor(brushColor);
    switch (Work)
    {
    case 0:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ТОЧКИ И НАЖАТИИ НАРИСОВАТЬ
    {
        pixel px;
        px.setX((ui->tableWidget->item(0,0)->text()).toInt(&fl_int,10));
        px.setY((ui->tableWidget->item(0,1)->text()).toInt(&fl_int,10));
        px.draw(ui->DrawSpace->getImage(), pen.getPen());
        break;
    }

    case 1:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ЛИНИИ И НАЖАТИИ НАРИСОВАТЬ
    {
        line ln;
        ln.setX((ui->tableWidget->item(0,0)->text()).toInt(&fl_int,10));
        ln.setY((ui->tableWidget->item(0,1)->text()).toInt(&fl_int,10));
        ln.setX_2((ui->tableWidget->item(0,2)->text()).toInt(&fl_int,10));
        ln.setY_2((ui->tableWidget->item(0,3)->text()).toInt(&fl_int,10));
        ln.draw(ui->DrawSpace->getImage(), pen.getPen());
        break;
    }

    case 2:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ПРЯМОУГОЛЬНИКА И НАЖАТИИ НАРИСОВАТЬ
    {
        rectangle rect;
        rect.setX((ui->tableWidget->item(0,0)->text()).toInt(&fl_int,10));
        rect.setY((ui->tableWidget->item(0,1)->text()).toInt(&fl_int,10));
        rect.setWidth((ui->tableWidget->item(0,2)->text()).toInt(&fl_int,10));
        rect.setHeight((ui->tableWidget->item(0,3)->text()).toInt(&fl_int,10));
        rect.draw(ui->DrawSpace->getImage(), pen.getPen(), brush.getBrush());

        break;
    }

    case 3:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ЭЛИПСА И НАЖАТИИ НАРИСОВАТЬ
    {
        ellipse elli;
        elli.setX((ui->tableWidget->item(0,0)->text()).toInt(&fl_int,10));
        elli.setY((ui->tableWidget->item(0,1)->text()).toInt(&fl_int,10));
        elli.setRad1((ui->tableWidget->item(0,2)->text()).toInt(&fl_int,10));
        elli.setRad2((ui->tableWidget->item(0,3)->text()).toInt(&fl_int,10));
        elli.draw(ui->DrawSpace->getImage(), pen.getPen(), brush.getBrush());
        break;
    }
    case 4:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ДУГИ И НАЖАТИИ НАРИСОВАТЬ
    {
        curve arc;
        arc.setX((ui->tableWidget->item(0,0)->text()).toInt(&fl_int,10));
        arc.setY((ui->tableWidget->item(0,1)->text()).toInt(&fl_int,10));
        arc.setWidth((ui->tableWidget->item(0,2)->text()).toInt(&fl_int,10));
        arc.setHeight((ui->tableWidget->item(0,3)->text()).toInt(&fl_int,10));
        arc.setStartAngle((ui->tableWidget->item(0,4)->text()).toInt(&fl_int,10));
        arc.setEndAngle((ui->tableWidget->item(0,5)->text()).toInt(&fl_int,10));
        arc.draw(ui->DrawSpace->getImage(), pen.getPen());
        break;
    }
    case 5:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ ЛОМАННОЙ И НАЖАТИИ НАРИСОВАТЬ
    {
        broken bline;
        for (int i=0; i<(ui->spinBox_size->value())-1; i++)
        {
            bline.setX((ui->tableWidget->item(0,i)->text()).toInt(&fl_int,10));
            bline.setY((ui->tableWidget->item(1,i)->text()).toInt(&fl_int,10));
            bline.setX_2((ui->tableWidget->item(0,i+1)->text()).toInt(&fl_int,10));
            bline.setY_2((ui->tableWidget->item(1,i+1)->text()).toInt(&fl_int,10));
            bline.draw(ui->DrawSpace->getImage(), pen.getPen());
        }
    }
    case 6:     //ДЕЙСТВИЯ ПРИ ВЫБОРЕ МНОГОУГОЛЬНИКА И НАЖАТИИ НАРИСОВАТЬ
    {
        polygon poly;
        int x,y;
        poly.setPointCount((ui->spinBox_size->value()));
        for (int i=0; i<(ui->spinBox_size->value()); i++)
        {
            x=(ui->tableWidget->item(0,i)->text().toInt(&fl_int,10));
            y=(ui->tableWidget->item(1,i)->text().toInt(&fl_int,10));
            poly.setPoint(i,x,y);
        }
        poly.draw(ui->DrawSpace->getImage(), pen.getPen(), brush.getBrush());
        poly.deletePntArray();
    }
    }

    if (!ui->DrawSpace->isVisible())
    {
        ui->DrawSpace->setVision(!ui->DrawSpace->isVisible());
    }
    repaint();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch(index)
        {
        case 0:
        {
            Work=0;
            ui->checkBox_brush->setVisible(false);
            ui->pushButton_brushColor->setVisible(false);
            ui->tableWidget->verticalHeader()->setVisible(false);
            ui->comboBox_brushStyle->setVisible(false);
            ui->spinBox_size->hide();
            ui->label_size->hide();
            QStringList header;
            ui->tableWidget->setColumnCount(2);
            ui->tableWidget->setGeometry(340,30,222,60);
            header << " X " << " Y ";
            ui->tableWidget->setHorizontalHeaderLabels(header);
            break;

        }
        case 1:
        {
            Work=1;
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->checkBox_brush->setVisible(false);
            ui->pushButton_brushColor->setVisible(false);
            ui->comboBox_brushStyle->setVisible(false);
            ui->tableWidget->verticalHeader()->setVisible(false);
            ui->spinBox_size->hide();
            ui->label_size->hide();
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setGeometry(340,30,442,60);
            for(int i=0; i<4;i++)
            {
                item = new QTableWidgetItem(QString::number(0));
                ui->tableWidget->setItem(0,i,item);
                item=NULL;
            }
            QStringList header;
            header << "Х начала" << "Y начала" << "Х конца" << "Y конца";
            ui->tableWidget->setHorizontalHeaderLabels(header);
            break;
        }
        case 2:
        {
            Work=2;
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->checkBox_brush->setVisible(true);
            if (ui->checkBox_brush->isChecked())
            {
                ui->comboBox_brushStyle->setVisible(true);
                ui->pushButton_brushColor->setVisible(true);
            }
            ui->tableWidget->verticalHeader()->setVisible(false);
            ui->spinBox_size->hide();
            ui->label_size->hide();
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setGeometry(340,30,442,60);
            for(int i=0; i<4;i++)
            {
                item = new QTableWidgetItem(QString::number(0));
                ui->tableWidget->setItem(0,i,item);
                item=NULL;
            }
            QStringList header;
            header << "Х " << " Y " << "Ширина" << "Высота";
            ui->tableWidget->setHorizontalHeaderLabels(header);
            break;
        }
        case 3:
        {
            Work=3;
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->checkBox_brush->setVisible(true);
            if (ui->checkBox_brush->isChecked())
            {
                ui->comboBox_brushStyle->setVisible(true);
                ui->pushButton_brushColor->setVisible(true);
            }
            ui->tableWidget->verticalHeader()->setVisible(false);
            ui->spinBox_size->hide();
            ui->label_size->hide();
            ui->tableWidget->setColumnCount(4);
            for(int i=0; i<4;i++)
            {
                item = new QTableWidgetItem(QString::number(0));
                ui->tableWidget->setItem(0,i,item);
                item=NULL;
            }
            ui->tableWidget->setGeometry(340,30,442,60);
            QStringList header;
            header << "Х " << " Y " << "Радиус N1" << "Радиус N2";
            ui->tableWidget->setHorizontalHeaderLabels(header);
            break;
        }
        case 4:
        {
            Work=4;
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->checkBox_brush->setVisible(false);
            ui->pushButton_brushColor->setVisible(false);
            ui->comboBox_brushStyle->setVisible(false);
            ui->tableWidget->verticalHeader()->setVisible(false);
            ui->spinBox_size->hide();
            ui->label_size->hide();
            ui->tableWidget->setColumnCount(6);
            for(int i=0; i<6;i++)
            {
                item = new QTableWidgetItem(QString::number(0));
                ui->tableWidget->setItem(0,i,item);
                item=NULL;
            }
            ui->tableWidget->setGeometry(340,30,662,60);
            QStringList header;
            header << "Х " << " Y " << "Ширина" << "Высота" << "Начальный угол" << "Градусная мера";
            ui->tableWidget->setHorizontalHeaderLabels(header);
            break;
        }
        case 5:
        {
            Work=5;
            ui->tableWidget->verticalHeader()->setVisible(true);
            ui->checkBox_brush->setVisible(false);
            ui->pushButton_brushColor->setVisible(false);
            ui->comboBox_brushStyle->setVisible(false);
            ui->spinBox_size->show();
            ui->label_size->show();
            ui->spinBox_size->setMinimum(2);
            ui->tableWidget->setColumnCount(ui->spinBox_size->value());
            ui->tableWidget->setRowCount(2);
            QTableWidgetItem *item = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            item->setText("X");
            item2->setText("Y");
            ui->tableWidget->setVerticalHeaderItem(0,item);
            ui->tableWidget->setVerticalHeaderItem(1,item2);
            item=NULL;
            item2=NULL;
            for(int i=0; i<(ui->spinBox_size->value());i++)
            {
                item = new QTableWidgetItem(QString::number(i+1));
                ui->tableWidget->setHorizontalHeaderItem(i,item);
                item=NULL;
                for (int j=0; j<2; j++)
                {
                    item = new QTableWidgetItem(QString::number(0));
                    ui->tableWidget->setItem(j,i,item);
                    item=NULL;
                }
                if ((ui->spinBox_size->value())<=5)
                {
                    ui->tableWidget->setGeometry(510,10,18+110*(ui->spinBox_size->value()),78);
                }
                else
                {
                    ui->tableWidget->setGeometry(510,13,10+550,78);
                }
            }
            break;
        }
        case 6:
        {
            Work=6;
            ui->checkBox_brush->setVisible(true);
            if (ui->checkBox_brush->isChecked())
            {
                ui->comboBox_brushStyle->setVisible(true);
                ui->pushButton_brushColor->setVisible(true);
            }
            ui->tableWidget->verticalHeader()->setVisible(true);
            ui->spinBox_size->setMinimum(3);
            ui->spinBox_size->show();
            ui->label_size->show();
            ui->tableWidget->setColumnCount(ui->spinBox_size->value());
            ui->tableWidget->setRowCount(2);
            QTableWidgetItem *item = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            item->setText("X Вершины");
            item2->setText("Y Вершины");
            ui->tableWidget->setVerticalHeaderItem(0,item);
            ui->tableWidget->setVerticalHeaderItem(1,item2);
            item=NULL;
            item2=NULL;
            for(int i=0; i<(ui->spinBox_size->value());i++)
            {
                item = new QTableWidgetItem(QString::number(i+1));
                ui->tableWidget->setHorizontalHeaderItem(i,item);
                item=NULL;
                for (int j=0; j<2; j++)
                {
                    item = new QTableWidgetItem(QString::number(0));
                    ui->tableWidget->setItem(j,i,item);
                    item=NULL;
                }
                if ((ui->spinBox_size->value())<=5)
                {
                    ui->tableWidget->setGeometry(510,10,78+110*(ui->spinBox_size->value()),78);
                }
                else
                {
                    ui->tableWidget->setGeometry(510,10,73+550,78);
                }
            }
            break;
        }
        }
}

void MainWindow::on_spinBox_size_valueChanged(int arg1) //ВОЗМОЖНОСТЬ ВВЕСТИ  В СПИНБОКСЕ КОЛ-ВО ВЫБРАННЫХ ТОЧЕК
{
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}



void MainWindow::on_pushButton_clear_clicked() //ДЕЙСТВИЯ ПРИ НАЖАТИИ КНОПКИ  ОЧИСТИТЬ
{
    ui->DrawSpace->clearImage();
}


void MainWindow::on_pushButton_color_clicked() //ВЫБОР ЦВЕТА ПЕРА
{
    QColorDialog colorDialog;
    penColor=colorDialog.getColor(lastPenColor,this);
    lastPenColor=penColor;
}

void MainWindow::on_pushButton_brushColor_clicked() //ВЫБОР ЦВЕТА ЗАЛИВКИ
{
    QColorDialog colorDialog;
    brushColor=colorDialog.getColor(lastBrushColor,this);
    lastBrushColor=brushColor;
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)     //ДЕЙСТВИЯ ПРИ ИЗМЕНЕНИИ ЭЛЕМЕНТА ТАБЛИЦЫ
{
    int col,row,num;
    QString str;
    bool flag,fault=false;
    col=(item->column());
    row=(item->row());
    str=(item->text());
    num=str.toInt(&flag);
    if (flag)
    {
        switch (Work)
        {
        case 0:
        case 1:
        {
            if (((col+1)%2!=0)&&((num<0)||(num>840)))
                fault=true;
            if (((col+1)%2==0)&&((num<0)||(num>610)))
                fault=true;
            if (fault)
            {
                item->setText("0");
                QMessageBox::information(0,"Ошибка","Координаты за пределами окна! (размер окна 840х590)",QMessageBox::Ok);
            }
            else
                *item = QTableWidgetItem(str);
            break;
        }
        case 2:
        {
            if ((col==0)&&((num<0)||(num>840)))
                fault=true;
            if ((col==1)&&((num<0)||(num>590)))
                fault=true;
            if (fault)
            {
                item->setText("0");
                QMessageBox::information(0,"Ошибка","Координаты за пределами окна! (размер окна 840х590)",QMessageBox::Ok);
            }
            else
                *item = QTableWidgetItem(str);
            break;
        }
        case 3:
        {
            if ((col==0)&&((num<0)||(num>840)))
                fault=true;
            if ((col==1)&&((num<0)||(num>590)))
                fault=true;
            if (fault)
            {
                item->setText("0");
                QMessageBox::information(0,"Ошибка","Координаты за пределами окна! (размер окна 840х590)",QMessageBox::Ok);
            }
            else
                *item = QTableWidgetItem(str);
            break;
        }
        case 4:
        {
            if ((col==0)&&((num<0)||(num>840)))
                fault=true;
            if ((col==1)&&((num<0)||(num>590)))
                fault=true;
            if (fault)
            {
                item->setText("0");
                QMessageBox::information(0,"Ошибка","Координаты за пределами окна! (размер окна 840х590)",QMessageBox::Ok);
            }
            else
            {
                if ((col==4)&&((num>360)||(num<(-360))))
                {
                    if (num>360)
                    {
                        num=360;
                    }
                    else
                    {
                        num=-360;
                    }
                }
                if ((col==5)&&((num>360)||(num<(-360))))
                {
                    if (num>360)
                    {
                        num=360;;
                    }
                    else
                    {
                        num=-360;;
                    }
                }
                *item = QTableWidgetItem(QString::number(num));
            }
            break;
        }
        case 5:
        case 6:
        {
            if ((row==0)&&((num<0)||(num>840)))
                fault=true;
            if ((row==1)&&((num<0)||(num>590)))
                fault=true;
            if (fault)
            {
                item->setText("0");
                QMessageBox::information(0,"Ошибка","Координаты за пределами окна! (размер окна 840х590)",QMessageBox::Ok);
            }
            break;
        }
        }
    }
    else
    {
        item->setText("0");
        QMessageBox::information(0,"Ошибка","Введены некорректные данные!",QMessageBox::Ok);
    }
}






void MainWindow::on_checkBox_brush_clicked() //ДЕЙСТВИЯ ПРИ НАЖАТИИ КНОПКИ ЗАЛИВКИ
{
    ui->comboBox_brushStyle->setVisible(!ui->comboBox_brushStyle->isVisible());
    if (!ui->comboBox_brushStyle->isVisible())
    {
        ui->comboBox_brushStyle->setCurrentIndex(-1);
        ui->pushButton_brushColor->setVisible(false);
        ui->comboBox_brushStyle->setVisible(false);
    }
    else
    {
        ui->comboBox_brushStyle->setCurrentIndex(0);
        ui->pushButton_brushColor->setVisible(true);
        ui->comboBox_brushStyle->setVisible(true);
    }
}






