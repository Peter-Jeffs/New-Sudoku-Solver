//
//  print.cpp
//  Sudoku
//
//  Created by Peter Jeffs on 21/12/2020.
//
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"
using namespace std;
//
void print_puzzle_square (int puzzle_square[][9])
//  print the sudoku puzzle square.
{
    int row = 0;
    int col = 0;
//  Title of the display ...
    cout << "  9x9 Sudoku Puzzle Square\n\n";
//  Go through the 9x9 array and send to output stream ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            cout << "  " << puzzle_square[row][col];
            }
            cout << "\n";
        cout << "\n";
        }
}
//
void print_puzzle_note_pad_tile (int puzzle_note_pad[][81], int tile_number, int c1, int c2, int c3, int c4, int c5, int c6)
//  Prints a puzzle note pad tile.
{
    int col=0;
    int row=0;
//  Display title ...
    cout << "  Puzzle Note Pad .. Tile " << tile_number << "\n" << "\n";
//  Iterate through the array ...
    for (row=0; row<=8; ++row)
        {
//  Because this is one Tile from the whole 3x3 tile grid, we have to choose the columns
//  carefully, e.g. 0, 1, 2; 9, 10, 11; 18, 19, 20 - make Tile #1 i.e. add +9 for new column.
        for (col=c1; col<=c2; ++col)
            {
            cout << "  " << puzzle_note_pad[row][col];
            }
        for (col=c3; col<=c4; ++col)
            {
            cout << "  " << puzzle_note_pad[row][col];
            }
        for (col=c5; col<=c6; ++col)
            {
            cout << "  " << puzzle_note_pad[row][col];
            }
            cout << "\n";
        cout << "\n";
        }
}
//
void print_puzzle_note_pad_row (int puzzle_note_pad[][81], int row_number, int row_start, int row_stop)
//  Print the puzzle note pad row.
{
    int col=0;
    int row=0;
//  Display title ...
    cout << "  Puzzle Note Pad .. Row " << row_number << "\n" << "\n";
//  Iterate through the array ...
    for (row=0; row<=8; ++row)
        {
//  Because this is one Row from the whole 3x3 tile grid, we have to choose the columns
//  carefully, e.g. 0, 1, 2; 9, 10, 11; 18, 19, 20 - make Tile #1 i.e. add +9 for new column.
        for (col=row_start; col<=row_stop; ++col)
            {
            cout << "  " << puzzle_note_pad[row][col];
            }
            cout << "\n";
        cout << "\n";
        }
}
//
void print_puzzle_note_pad_col (int puzzle_note_pad[][81], int col_number, int col_start, int col_stop)
//  Print the puzzle note pad col.
{
    int col=0;
    int row=0;
//  Display title ...
    cout << "  Puzzle Note Pad .. Col " << col_number << "\n" << "\n";
//  Iterate through the array ...
    for (row=0; row<=8; ++row)
        {
//  Because this is one Row from the whole 3x3 tile grid, we have to choose the columns
//  carefully, e.g. 0, 1, 2; 9, 10, 11; 18, 19, 20 - make Tile #1 i.e. add +9 for new column.
        for (col=col_start; col<=col_stop; col+=9)
            {
            cout << "  " << puzzle_note_pad[row][col];
            }
            cout << "\n";
        cout << "\n";
        }
}
//
void print_all_puzzle_note_pad_tiles (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Prints print_all_puzzle_note_pad_tiles.
{
//  OK. This whole routine just calls the print_note_pad_tile function using the arguments
//  Tile Number and columns ranges 1-3,4-6,and 7-9, which represent the Tile numbers.
//  This is because each Tile number can have 9 possible numbers. I have represented each tile
//  as a 2 dimensional array of 9 elements (tile numbers) by 9 elements (tile number possibilities).
    print_puzzle_note_pad_tile (puzzle_note_pad, 1, 0, 2, 9, 11, 18, 20);
    print_puzzle_note_pad_tile (puzzle_note_pad, 2, 3, 5, 12, 14, 21, 23);
    print_puzzle_note_pad_tile (puzzle_note_pad, 3, 6, 8, 15, 17, 24, 26);
    print_puzzle_note_pad_tile (puzzle_note_pad, 4, 27, 29, 36, 38, 45, 47);
    print_puzzle_note_pad_tile (puzzle_note_pad, 5, 30, 32, 39, 41, 48, 50);
    print_puzzle_note_pad_tile (puzzle_note_pad, 6, 33, 35, 42, 44, 51, 53);
    print_puzzle_note_pad_tile (puzzle_note_pad, 7, 54, 56, 63, 65, 72, 74);
    print_puzzle_note_pad_tile (puzzle_note_pad, 8, 57, 59, 66, 68, 75, 77);
    print_puzzle_note_pad_tile (puzzle_note_pad, 9, 60, 62, 69, 71, 78, 80);
//
}
//
void print_puzzle_note_pad_rows (int puzzle_note_pad[][81])
//  Print the puzzle note pad rows.
{
//  OK. This whole routine just calls the print_note_pad_tile function using the arguments
//  Tile Number and columns ranges 1-3,4-6,and 7-9, which represent the Tile numbers.
//  This is because each Tile number can have 9 possible numbers. I have represented each tile
//  as a 2 dimensional array of 9 elements (tile numbers) by 9 elements (tile number possibilities).
    print_puzzle_note_pad_row (puzzle_note_pad, 1, 0, 8);
    print_puzzle_note_pad_row (puzzle_note_pad, 2, 9, 17);
    print_puzzle_note_pad_row (puzzle_note_pad, 3, 18, 26);
    print_puzzle_note_pad_row (puzzle_note_pad, 4, 27, 35);
    print_puzzle_note_pad_row (puzzle_note_pad, 5, 36, 44);
    print_puzzle_note_pad_row (puzzle_note_pad, 6, 45, 53);
    print_puzzle_note_pad_row (puzzle_note_pad, 7, 54, 62);
    print_puzzle_note_pad_row (puzzle_note_pad, 8, 63, 71);
    print_puzzle_note_pad_row (puzzle_note_pad, 9, 72, 80);
//
}
//
void print_puzzle_note_pad_cols (int puzzle_note_pad[][81])
//  Print the puzzle note pad cols.
{
    print_puzzle_note_pad_col (puzzle_note_pad, 1, 0, 72);
    print_puzzle_note_pad_col (puzzle_note_pad, 2, 1, 73);
    print_puzzle_note_pad_col (puzzle_note_pad, 3, 2, 74);
    print_puzzle_note_pad_col (puzzle_note_pad, 4, 3, 75);
    print_puzzle_note_pad_col (puzzle_note_pad, 5, 4, 76);
    print_puzzle_note_pad_col (puzzle_note_pad, 6, 5, 77);
    print_puzzle_note_pad_col (puzzle_note_pad, 7, 6, 78);
    print_puzzle_note_pad_col (puzzle_note_pad, 8, 7, 79);
    print_puzzle_note_pad_col (puzzle_note_pad, 9, 8, 80);
//
}
//
void print_puzzle_note_pad (int puzzle_note_pad[][81], int row_start, int row_stop)
//  Print the puzzle note pad.
{
    int col=0;
    int row=0;
//  Display title ...
    cout << "  Puzzle Note Pad ... " << "\n" << "\n";
//  Iterate through the array ...
    for (row=0; row<=8; ++row)
        {
//  Because this is is one Row from the whole 3x3 tile grid, we have to choose the columns
//  carefully, e.g. 0, 1, 2; 9, 10, 11; 18, 19, 20 - make Tile #1 i.e. add +9 for new column.
        for (col=row_start; col<=row_stop; ++col)
            {
            cout << " " << puzzle_note_pad[row][col];
            }
            cout << "\n";
        cout << "\n";
        }
}
//
