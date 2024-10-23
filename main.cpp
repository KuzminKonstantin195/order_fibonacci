#include "mainwindow.h"
#include "rowfibonacci.h"
#include "ui_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RowFibonacci rowFibonacci (nullptr);
    Ui::MainWindow window;

    window.setupUi(&rowFibonacci);

    rowFibonacci.lineEdit = window.lineEdit;
    rowFibonacci.lineEdit_2 = window.lineEdit_2;

    rowFibonacci.checkBox = window.checkBox;
    rowFibonacci.checkBox_2 = window.checkBox_2;

    rowFibonacci.show();

    return a.exec();
}
