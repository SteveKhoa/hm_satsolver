#pragma once
#include "sudoku.h"

// Note: Box = Square in sudoku's definition
class box
{
    sudoku* host;
    bool* hashmap_NumChecked;

    int r_idx;
    int c_idx;
public:
    box(sudoku *h, int idx);
    ~box();

public:
    bool canAccept(int entry);

private:
    void set(int entry, int r, int c);
};