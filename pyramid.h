#ifndef PYRAMID_H
#define PYRAMID_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Pyramid;
}

class Pyramid : public QWidget
{
    Q_OBJECT

public:
    explicit Pyramid(QWidget *parent = nullptr);
    ~Pyramid();

    void paintEvent(QPaintEvent* event);

private:
    Ui::Pyramid *ui;
};

#endif // PYRAMID_H
