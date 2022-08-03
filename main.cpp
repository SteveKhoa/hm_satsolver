#include <iostream>
#include "sudoku/sudoku.h"
#include "simpleB.h"

// Build sudoku solver with SAT
// MIT assignment
// Link: http://www.mit.edu/~6.005/sp12/psets/ps2/ps2.html

int main()
{
    {
        sudoku s("sudoku/sudoku.txt");
        s.set(9, 2, 1, 1, 0);
        s.print();
    }
    checkleak();

    return 0;
}