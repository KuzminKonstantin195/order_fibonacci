#include "fibonachi.h"

fibonachi::fibonachi() {}

void fibonachi::createRow(int count)
{
    if (count > 2)
    {
        createRow(count-1);
    }
    else if (count == 2)
    {
        row = {0,1};
    } else if (count == 1 || count==0)
    {
        row = {0};
    }

                                                            // добавляем новый элемент только если нужно
    if (row.size() >= 2 && count >= 2)
    {
                                                            // скдадываем последний и предпоследний элемент
        row.push_back(*(row.end()-1) + *(row.end()-2) );
    }
}

int fibonachi::getLastNumber ()
{
    return *(row.end()-1);
}


