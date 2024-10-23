#include "pyramidwindow.h"
#include "ui_pyramidwindow.h"

#define FONT_SIZE 20            // размер шрифта задаем макросом


PyramidWindow::PyramidWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PyramidWindow)
{
    ui->setupUi(this);
}

PyramidWindow::~PyramidWindow()
{
    delete ui;
}

void PyramidWindow::setArr(vector<unsigned long long> newRow)
{
    row = newRow;
}

void PyramidWindow::paintEvent(QPaintEvent *)
{
    // создаем пирамиду
    createPyramidStuct ();

    QPainter painter (this);
    QPen pen;

    // коорднаты начала построения пирамиды (верхней единицы)
    int dx, dy = 80;

    painter.begin(this);
    pen.setColor(Qt::black);
    QFont font;
    font.setPixelSize(FONT_SIZE);
    painter.setFont(font);
    painter.setPen(pen);
    /*
     * создаем строку с каждым рядом пирамиды, считаем длину - задаем координаты и рисуем
    */
    for (auto lineNumber = 1; lineNumber < pyramidStruct.size(); lineNumber++)
    {
        QString str;

        for (auto num = 0; num < pyramidStruct[lineNumber].size(); num++)
        {
            str+=QString::number(pyramidStruct[lineNumber][num]);
            if (num != pyramidStruct[lineNumber].size()-1)
            {
                str+= " ";
            }
        }

        dx = this->width()/2 - (str.size()*FONT_SIZE)/4;
        painter.drawText(dx, dy, str);

        dy += FONT_SIZE + 5;
    }
    painter.end();
}

void PyramidWindow::createPyramidStuct ()
{
    pyramidStruct = {{0},{1}};
    int rowSize = row.size();
    int lineNumber;
    if (rowSize < 2)
    {
        pyramidStruct = {{0},{1}};
        lineNumber = 1;
    }
    else if (rowSize == 2)
    {
        pyramidStruct = {{0},{1}};
        lineNumber = 2;
    }
    else
    {
        pyramidStruct = {{0},{1},{1,1}};
        lineNumber = 3;
    }

        // начинаем c 3-ей строки (длина строки - номер+1)
    unsigned long long maxSum = 1;                                               // сумма по диагонали

    while (maxSum < *(row.end()-1) )
    {
        vector<unsigned long long> nextLine (lineNumber);

        for (auto num = 0; num < nextLine.size(); num++)
        {
            if (num == 0 || num == (nextLine.size()-1))
            {
                nextLine[num] = 1;
            } else
            {
                nextLine[num] = pyramidStruct[lineNumber-1][num] + pyramidStruct[lineNumber-1][num-1];;
            }
        }


        pyramidStruct.push_back(nextLine);

        maxSum = 0;
        int lineNumberForSum = lineNumber;
        int numPos = pyramidStruct[lineNumberForSum][0];                  // начинаем с последней позиции нижней строки

        while(true)
        {
            try {
                maxSum +=  pyramidStruct[lineNumberForSum].at(numPos);
            }
            catch (...)                                                         // если выполняется блок catch - значит, число не найдено (диагональ дошла до края и можно прекращать цикл)
            {
                break;
            }

            lineNumberForSum--;                                                 // меняем номер позиции числа
            numPos++;
        }
        lineNumber++;                                                           // переходим на следующую строку
    }
}
