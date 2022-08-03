#include "sudoku.h"
#include "box.h"

box::box(sudoku *h, int idx)
{
    host = h;

    hashmap_NumChecked = new bool[9];
    for (int i = 0; i < 9; ++i)
    {
        hashmap_NumChecked[i] = 0;
    }

    // Designate where this box is referencing to (on sudoku's map).
    switch(idx)
    {
        case 0:
        {
            r_idx = 0;
            c_idx = 0;
        }
        case 1:
        {
            r_idx = 0;
            c_idx = 1;
        }
        case 2:
        {
            r_idx = 0;
            c_idx = 2;
        }
        case 3:
        {
            r_idx = 1;
            c_idx = 0;
        }
        case 4:
        {
            r_idx = 1;
            c_idx = 1;
        }
        case 5:
        {
            r_idx = 1;
            c_idx = 2;
        }
        case 6:
        {
            r_idx = 2;
            c_idx = 0;
        }
        case 7:
        {
            r_idx = 2;
            c_idx = 1;
        }
        case 8:
        {
            r_idx = 2;
            c_idx = 2;
        }
        default:
            throw std::runtime_error("Undefined idx");
    }
}

box::~box()
{
    delete hashmap_NumChecked;
}

bool box::canAccept(int entry)
{
    // If the number have not existed in this box, then that number
    // is accepted.
    if (hashmap_NumChecked[entry] == 0)
        return true;
    return false;
}

void box::set(int entry, int r, int c)
{
    host->set(entry, r_idx, c_idx, r, c);
}