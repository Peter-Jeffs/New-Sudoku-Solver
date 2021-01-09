//
//  outputtofile.cpp
//  Sudoku
//
//  Created by Peter Jeffs on 24/12/2020.
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//
//
void print_puzzle_note_pad_to_file (int puzzle_note_pad[][81], int row_start, int row_stop)
//  Print the puzzle note pad to file.
{
    ofstream file {"puzzlenotepad.txt", ios::out|ios::app};
    int col=0;
    int row=0;
//  Iterate through the array ...
    for (row=0; row<=8; ++row)
        {
//  Because this is is one Row from the whole 3x3 tile grid, we have to choose the columns
//  carefully, e.g. 0, 1, 2; 9, 10, 11; 18, 19, 20 - make Tile #1 i.e. add +9 for new column.
        for (col=row_start; col<=row_stop; ++col)
            {
            file << " " << puzzle_note_pad[row][col];
            }
            file << "\n";
        }
}
//
//
