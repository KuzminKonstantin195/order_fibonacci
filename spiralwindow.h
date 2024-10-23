#ifndef SPIRALWINDOW_H
#define SPIRALWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QRect>
#include <vector>

using namespace std;

namespace Ui {
class SpiralWindow;
}

class SpiralWindow : public QWidget
{
    Q_OBJECT

    vector<unsigned long long> row;                                             // переданный/принятый ряд

public:
    explicit SpiralWindow(QWidget *parent = nullptr);
    ~SpiralWindow();

    void setArr(vector<unsigned long long> newRow);                             // принятие row

    void paintEvent(QPaintEvent *);                                             //отрисовка спирали


private:
    Ui::SpiralWindow *ui;
};

#endif // SPIRALWINDOW_H
