#pragma once
#include "sudoku.h"

class box
{
    sudoku* host;
    bool* hashmap_NumChecked;
public:
    box(sudoku *h);
    ~box();

public:
    
};