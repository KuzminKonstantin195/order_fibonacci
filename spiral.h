#ifndef SPIRAL_H
#define SPIRAL_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Spiral;
}

class Spiral : public QWidget
{
    Q_OBJECT

public:
    explicit Spiral(QWidget *parent = nullptr);
    ~Spiral();

    void paintEvent(QPaintEvent* event);

private:
    Ui::Spiral *ui;
};

#endif // SPIRAL_H
