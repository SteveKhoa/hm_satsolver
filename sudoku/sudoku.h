#pragma once

// Sudoku core
// Contains raw values of sudoku table.

#include <string>

class sudoku
{
    char ****map;

public:
    sudoku(const std::string&);
    ~sudoku();

    void print() const;
    void init();
    void load(const std::string&);

    int get(int y_sq, int x_sq, int x, int y) const;
    void set(int entry, int y_sq, int x_sq, int x, int y);
};