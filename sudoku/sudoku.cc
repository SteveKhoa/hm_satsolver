#include "sudoku.h"

sudoku::sudoku()
{
    map = new int***[3];
    for (int i = 0 ; i < 3 ; ++i)
    {
        map[i] = new int**[3];
        for (int j = 0 ; j < 3 ; ++j)
        {
            map[i][j] = new int*[3];
            for (int k = 0 ; k < 3 ; ++k)
            {
                map[i][j][k] = new int[3];
            }
        }
    }
}

sudoku::~sudoku()
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        for (int j = 0 ; j < 3 ; ++j)
        {
            for (int k = 0 ; k < 3 ; ++k)
            {
                delete[] map[i][j][k];
            }
            delete[] map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}

void sudoku::print() const
{

}