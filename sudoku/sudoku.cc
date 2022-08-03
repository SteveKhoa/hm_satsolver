#include "sudoku.h"
#include <iostream>
#include <fstream>

// Define sudoku's map size
#include "manifest.h"
const int& map_size = shared_sudoku_mapsize;

sudoku::sudoku(const std::string& filename)
{
    map = new char ***[map_size];
    for (int i = 0; i < map_size; ++i)
    {
        map[i] = new char **[map_size];
        for (int j = 0; j < map_size; ++j)
        {
            map[i][j] = new char *[map_size];
            for (int k = 0; k < map_size; ++k)
            {
                map[i][j][k] = new char[map_size];
            }
        }
    }

    load(filename);
}

sudoku::~sudoku()
{
    for (int i = 0; i < map_size; ++i)
    {
        for (int j = 0; j < map_size; ++j)
        {
            for (int k = 0; k < map_size; ++k)
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
    std::cout << std::endl;
    for (int rowSq = 0; rowSq < map_size; ++rowSq)
    {
        if (rowSq > 0)
            std::cout << std::endl << std::endl;
        for (int sq_row = 0; sq_row < map_size; ++sq_row)
        {
            if (sq_row > 0)
                std::cout << std::endl;
            for (int colSq = 0; colSq < map_size; ++colSq)
            {
                if (colSq > 0)
                    std::cout << "  ";
                for (int sq_col = 0; sq_col < map_size; ++sq_col)
                {
                    if (sq_col > 0)
                        std::cout << " ";
                    std::cout << map[rowSq][colSq][sq_row][sq_col];
                }
            }
        }
    }
    std::cout << std::endl;
}

void sudoku::init()
{
    for (int rowSq = 0; rowSq < map_size; ++rowSq)
    {
        for (int sq_row = 0; sq_row < map_size; ++sq_row)
        {
            for (int colSq = 0; colSq < map_size; ++colSq)
            {
                for (int sq_col = 0; sq_col < map_size; ++sq_col)
                {
                    map[rowSq][colSq][sq_row][sq_col] = '~';
                }
            }
        }
    }
}

void sudoku::load(const std::string& file_dir)
{
    std::ifstream in;
    in.open(file_dir);

    if (!in.is_open())
    {
        throw std::runtime_error("Can not load the input file.");
    }

    for (int rowSq = 0; rowSq < map_size; ++rowSq)
    {
        for (int sq_row = 0; sq_row < map_size; ++sq_row)
        {
            for (int colSq = 0; colSq < map_size; ++colSq)
            {
                for (int sq_col = 0; sq_col < map_size; ++sq_col)
                {
                    in >> map[rowSq][colSq][sq_row][sq_col];
                }
            }
        }
    }
}

/**
 * @brief return -1 if the cell is empty, otherwise the value of the cell.
 */
int sudoku::get(int y_sq, int x_sq, int x, int y) const
{
    char &ref = map[y_sq][x_sq][x][y];

    if (ref == '~')
        return -1;
    return int(ref - '0');
}

/**
 * @brief if entry = -1, set the cell to emptiness, otherwise set the cell's value := entry.
 */
void sudoku::set(int entry, int y_sq, int x_sq, int x, int y)
{
    char &ref = map[y_sq][x_sq][x][y];

    if (entry == -1)
        ref = '~';
    ref = char(entry + '0');
}