#include "spiral.h"
#include "ui_spiral.h"

Spiral::Spiral(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Spiral)
{
    ui->setupUi(this);
}

Spiral::~Spiral()
{
    delete ui;
}
