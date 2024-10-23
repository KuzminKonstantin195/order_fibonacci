#include "rowfibonacci.h"

void RowFibonacci::createArrey (int count)
{
    arrey = {0};

    if (count > 1)
    {
        arrey.push_back(1);
    }

    if (count > 2)
    {
        for(int i = 2; i<count; i++)
        {
            arrey.push_back( *(arrey.end()-1) + *(arrey.end()-2));
        }
    }
}

unsigned long long RowFibonacci::getLastNumber()
{

    return *(arrey.end()-1);
}

void RowFibonacci::spiralShow()
{
    auto scrollArea = new QScrollArea;

    spiral.setArr(arrey);
    scrollArea->setWidget(&spiral);
    scrollArea->resize(1420,1024);
    scrollArea->show();
}

void RowFibonacci::pyramidShow()
{
    auto scrollArea = new QScrollArea;

    pyramid.setArr(arrey);
    pyramid.createPyramidStuct();

    scrollArea->setWidget(&pyramid);
    scrollArea->resize(1420,1024);
    scrollArea->show();
}

void RowFibonacci::calkArr()
{
    createArrey (lineEdit->text().toInt());
    lineEdit_2->setText(QString::number(getLastNumber()));

    if (checkBox->isChecked())
    {
        spiralShow();
    }
    if (checkBox_2->isChecked())
    {
        pyramidShow();
    }
}

void RowFibonacci::clearBar()
{
    lineEdit->clear();
    lineEdit_2->clear();
}

void RowFibonacci::buildSpiral()
{
    spiralShow();
}

void RowFibonacci::buildPyramid()
{
    pyramidShow();
}
