#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <QMainWindow>
#include <QWidget>
#include <vector>

using namespace std;

class fibonachi
{
    Q_OBJECT

public:
    fibonachi();
    // сам ряд чисел
    vector<int> row;

    // создание ряда по кол-ву элементов
    void createRow (int count);
    // получить последнее число из ряда
    int getLastNumber ();
    // построить пирамиду
    void buildPiramid();
    // построить спираль
    void buildSpiral();
};

#endif // FIBONACHI_H
