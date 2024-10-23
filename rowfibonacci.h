#ifndef ROWFIBONACCI_H
#define ROWFIBONACCI_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>

#include <vector>

#include "spiralwindow.h"
#include "pyramidwindow.h"

using namespace std;

class RowFibonacci : public QMainWindow
{
    Q_OBJECT

public:

    RowFibonacci(QWidget* parent=nullptr) : QMainWindow(parent) {arrey = {0,1};};

    //хранилище ряда
    vector<unsigned long long> arrey;
    // создание/калькуляция ряда Фибоначчи *count - номер позиции
    void createArrey (int count);

    // создание ряда до указанного числа *num - максимальное число в ряду (или ближайшее)
    void arreyToVal (unsigned long long num);

    // получить максимальное число в ряду
    unsigned long long getLastNumber();

    // конструктивы
    QLineEdit* lineEdit = nullptr;
    QLineEdit* lineEdit_2 = nullptr;

    // Рассчитать
    QPushButton* pushButton;
    //Очистить
    QPushButton* pushButton_2;
    // построить спираль
    QPushButton* pushButton_3;
    // построить пирамиду
    QPushButton* pushButton_4;
    // автопостроение спирали
    QCheckBox* checkBox = nullptr;
    // автопостроение пирамиды
    QCheckBox* checkBox_2 = nullptr;

    // виджет с прорисованной спиралью
    SpiralWindow spiral;
    PyramidWindow pyramid;

    void spiralShow();
    void pyramidShow();

public slots:
    void calkArr();

    void clearBar();

    void buildSpiral();

    void buildPyramid();
};

#endif // ROWFIBONACCI_H
