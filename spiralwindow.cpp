#include "spiralwindow.h"
#include "ui_spiralwindow.h"
#include <cmath>

SpiralWindow::SpiralWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpiralWindow)
{
    ui->setupUi(this);
}

SpiralWindow::~SpiralWindow()
{
    delete ui;
}

QColor color1 (217, 247, 151);                                                  // бледно-желтый
QColor color2 (212, 151, 148);                                                  // бледно-красный
QColor color3 (81, 117, 79);                                                    // зеленый
QColor color4 (124, 138, 196);                                                  // голубой


QColor colors[] {color1,color2, color3, color4};                                // массив цветов (будут чередоваться в спирали)

void SpiralWindow::setArr(vector<unsigned long long> newRow)
{
  row = newRow;
}

//функция рисует сетку в области построения
void drawWeb(int x, int y, int width, int lineCount, QPainter &painter, QPen &pen, int colorNum)
{
    int indent=width/lineCount;

    // между линиями должен быть минимум 1 пиксель
    if (indent < 2)
    {
        indent = 2;
    }
    // если с минимальным отступом сетка не вмещается в прямоугольник - переопределяем кол-во линий и отступы
    if (indent * lineCount > width)
    {
        lineCount = width/indent;
    }

    painter.fillRect(x,y,width,width, QBrush(colors[colorNum]));                // заливаем область прямоугольника

    int sX, sY, eX, eY;                                                         // координаты начала и конца рисуемой линии

    // устанавливаем вид линий сетки
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    // рисуем сетку
    // вертикальные линии
    for(int num = 0; num < lineCount; num++)
    {
        sX = x + indent*(num+1);
        eX = sX;
        sY = y;
        eY = y + width;

        painter.drawLine(sX, sY, eX, eY);
    }
    // горизонтальные линии
    for(int num = 0; num < lineCount; num++)
    {
        sX = x;
        eX = x + width;
        sY = y + indent*(num+1);
        eY = sY;

        painter.drawLine(sX, sY, eX, eY);
    }
}

void SpiralWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QPen pen;

    float dx = 50, dy = 50;                                                     // динамичная координата начала отрисовки блока

    int rectWidth = 3, arcWidth = 3;                                            // толщины для рисования
    int count = 0;                                                              // счетчик порядкового номера прямоугольника (для выбора цвета и ориентации дуги)

    unsigned long long prevWight = 0;                                           // хранит значение ширины предыдущего при построении прямоугольника (для задания координат)

    float zoom;                                                                 // коэффициент масштаба

    painter.begin(this);                                                        // начало отрисовки
                                                                                // ставим защиту "от дурака"
    if (!row.empty()){

        zoom = (640 / *(row.end()-1)*1.5);
        zoom =round(zoom*10000)/10000;

        /*
         * контролируем коэффициент масштаба при слишком маленьких значениях
        */
        if (zoom < 1)
        {
            if (*(row.end()-1) > 100000)
            {
                zoom = 0.001;

            }   else if (*(row.end()-1) > 10000)
            {
                zoom = 0.01;
            } else if (*(row.end()-1) > 4000)
            {
                zoom = 0.08;
            }
            else if (*(row.end()-1) > 1000)
            {
                zoom = 0.5;
            } else if (*(row.end()-1) > 500)
            {
                zoom = 0.8;
            }

        }

    for (auto num = (row.end()-1); num != row.begin(); num--)
    {
        // в свиче определяем начало построения блока дуги и её ориентацию
        switch (count)
        {
        case 0:
            if(prevWight!=0) {
                dy-=(*num)*zoom;
            }
            //рисуем со стандартной ориентацией + заливаем и рисуем сетку
            pen.setColor(Qt::black);

            drawWeb(dx,dy, ((*num)*zoom), *num,painter,pen,count);
            pen.setWidth(rectWidth);
            painter.setPen(pen);
            painter.drawRect(dx,dy, (*num)*zoom, (*num)*zoom);


            //рисуем дугу
            pen.setColor(Qt::red);
            pen.setWidth(arcWidth);
            painter.setPen(pen);

            painter.drawArc(dx,dy,(*num)*zoom*2, (*num)*zoom*2, 16*180,-16*90);

            break;
        case 1:
            // поворот на 90
            dx+=prevWight;

            pen.setColor(Qt::black);
            drawWeb(dx,dy, ((*num)*zoom), *num,painter,pen,count);

            pen.setWidth(rectWidth);
            painter.setPen(pen);

            painter.drawRect(dx,dy, (*num) *zoom, (*num) * zoom);

            pen.setColor(Qt::red);
            pen.setWidth(arcWidth);
            painter.setPen(pen);
            painter.drawArc(dx - (*num)*zoom, dy, (*num)*zoom*2, (*num)*zoom*2, 16*90,-16*90);
            break;
        case 2:
            // поворот на 180
            dx += prevWight-(*num)*zoom;
            dy += prevWight;

            pen.setColor(Qt::black);
            drawWeb(dx,dy, (*num)*zoom, *num,painter,pen,count);
            pen.setWidth(rectWidth);
            painter.setPen(pen);

            //
            painter.drawRect(dx,dy, (*num) *zoom, (*num) * zoom);

            //рисуем дугу
            pen.setColor(Qt::red);
            pen.setWidth(arcWidth);
            painter.setPen(pen);
            painter.drawArc(dx-(*num)*zoom, dy-(*num)*zoom, (*num)*zoom*2, (*num)*zoom*2, 0,-16*90);
            break;
        case 3:
            // поворот на 270
            dx -= (*num)*zoom;
            dy += prevWight-(*num)*zoom;

            pen.setColor(Qt::black);
            drawWeb(dx,dy, (*num)*zoom, *num,painter,pen,count);
            pen.setWidth(rectWidth);
            painter.setPen(pen);

            painter.drawRect(dx,dy, (*num) *zoom, (*num) * zoom);

            //рисуем дугу
            pen.setColor(Qt::red);
            pen.setWidth(arcWidth);
            painter.setPen(pen);
            painter.drawArc(dx, dy-(*num)*zoom, (*num)*zoom*2, (*num)*zoom*2, -16*90,-16*90);

            break;
        default:
            break;
        }

        // пишем текст
        if ((*num)*zoom > 50){
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawText(dx+20,dy+30,QString::number(*num) + "x" + QString::number(*num));
        }

        prevWight = (*num) * zoom;

        count < 3 ? count++ : count = 0;                                                        // меняем счетчик по кругу

    }}
    painter.end();
}


