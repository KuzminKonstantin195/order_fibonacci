#ifndef PYRAMIDWINDOW_H
#define PYRAMIDWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <vector>

using namespace std;

namespace Ui {
class PyramidWindow;
}

class PyramidWindow : public QWidget
{
    Q_OBJECT

    vector<unsigned long long> row;                                                 // ряд фибоначчи

    /* Структура пирамиды в векторе:
     *
     * 1
     * 1 1
     * 1 2 1
     * 1 3 3 1
     * 1 4 6 4 1
     *
     * и т.д. */
    vector<vector<unsigned long long>> pyramidStruct;

public:
    explicit PyramidWindow(QWidget *parent = nullptr);
    ~PyramidWindow();


    void setArr(vector<unsigned long long> newRow);                                 // передача имеющегося ряда Фибоначчи в построение пирамиды

    void createPyramidStuct ();                                                     // создание pyramidStruct
    void paintEvent(QPaintEvent *);                                                 // отрисовка пирамиды

private:
    Ui::PyramidWindow *ui;
};

#endif // PYRAMIDWINDOW_H
