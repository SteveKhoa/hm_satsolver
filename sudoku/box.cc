#include "sudoku.h"
#include "box.h"

box::box(sudoku *h)
{
    host = h;
    hashmap_NumChecked = new bool[9];
    for (int i = 0; i < 9; ++i)
    {
        hashmap_NumChecked[i] = 0;
    }
}

box::~box()
{
    delete hashmap_NumChecked;
}