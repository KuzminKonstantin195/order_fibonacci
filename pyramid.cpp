#include "pyramid.h"
#include "ui_pyramid.h"

Pyramid::Pyramid(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pyramid)
{
    ui->setupUi(this);
}

Pyramid::~Pyramid()
{
    delete ui;
}
