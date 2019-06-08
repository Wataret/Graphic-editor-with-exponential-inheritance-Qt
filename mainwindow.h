#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "QDebug"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_brushColor_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_spinBox_size_valueChanged(int arg1);

    void on_checkBox_brush_clicked();

    void on_comboBox_currentIndexChanged(int index);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
