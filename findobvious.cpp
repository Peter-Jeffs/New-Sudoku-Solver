//
//  FindObvious.cpp
//  Sudoku
//
//  Created by Peter Jeffs on 23/12/2020.
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"
using namespace std;
//
void fon_in_puzzle_note_pad (int puzzle_note_pad[][81], int puzzle_numbers[])
//  This function finds obvious numbers in the puzzle_note_pad.
{
    //
        int row = 0;
        int col = 0;
        int c = 0;
        int col_counter [81] = {0};
        int col_counter_count = 0;
    //
        for (col=0; col<=80; ++col)
            {
            for (row=0; row<=8; ++row)
                {
                if (puzzle_note_pad[row][col] == 0)
                    {
                    ++col_counter[col];
                    }
                }
            }
    //
        for (c=0; c<=80; ++c)
            {
            if (col_counter[c] == 8)
                {
                ++col_counter_count;
                }
            }
    //
            int the_obvious_number_is [81] = {0};
    //
            for (c=0; c<=80; ++c)
                {
                if (col_counter[c] == 8)
                    {
                    for (row=0; row<=8; ++row)
                        {
                        if (puzzle_note_pad[row][c] != 0)
                            {
                            the_obvious_number_is[c] = puzzle_note_pad[row][c];
                            }
                        }
                    }
                }
        //
        for (c=0; c<=80; ++c)
            {
            if (the_obvious_number_is[c] != 0)
                {
                puzzle_numbers[c] = the_obvious_number_is[c];
                }
            }
    //
}
//
void find_obvious_number_in_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper)
//  Function to find_obvious_number_in_puzzle_row for whole puzzle.
{
//
    int row=0;
    int col=0;
    int single_number_count[9]={0};
    int puzzle_number_count=0;
//
    for (row=0; row<=8; ++row)
        {
        for (col=col_lower; col<=col_upper; ++col)
            {
            if (puzzle_note_pad[row][col] != 0)
                {
                ++single_number_count[row];
                }
            }
        }
//
    for (puzzle_number_count=col_lower; puzzle_number_count<=col_upper; ++puzzle_number_count)
        {
        if (puzzle_numbers[puzzle_number_count] == 0)
            {
            for (row=0; row<=8; ++row)
                {
                if (puzzle_note_pad[row][puzzle_number_count] != 0 && single_number_count[row] == 1)
                    {
                    puzzle_numbers[puzzle_number_count] = row + 1;
                    }
                }
            }
         }
//
}
//
void find_obvious_number_in_puzzle_rows (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to call the find_obvious_number_in_puzzle_row function for whole puzzle.
{
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 0, 8);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 9, 17);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 18, 26);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 27, 35);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 36, 44);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 45, 53);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 54, 62);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 63, 71);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 72, 80);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_obvious_number_in_puzzle_col (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper)
//  Function to find_obvious_number_in_puzzle_col using column limits (supplied).
{
//
    int single_number_row_count[9]={0};
    int temp_spno[9] = {0};
    int row=0;
    int col=0;
    int b=0;
    int c=0;
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
//
    for (row=0; row<=8; ++row)
        {
        for (col=col_lower; col<=col_upper; col+=9)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] != 0)
                {
                ++single_number_row_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (single_number_row_count[row] == 1)
                {
                temp1_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp1_grid[row][col] != 0)
                {
                temp_spno[col] = temp_grid[row][col];
                }
            }
        }
//
    b=col_lower;
//
    for (col=0; col<=8; ++col)
        {
        puzzle_numbers[b] = temp_spno[col];
        b+=9;
        }
//
}
//
void find_obvious_number_in_puzzle_cols (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to call the find_obvious_number_in_puzzle_col function for whole puzzle.
{
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 0, 72); // Col 1
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 1, 73); // Col 2
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 2, 74); // Col 3
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 3, 75); // Col 4
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 4, 76); // Col 5
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 5, 77); // Col 6
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 6, 78); // Col 7
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 7, 79); // Col 8
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_col (puzzle_note_pad, puzzle_numbers, 8, 80); // Col 9
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_obvious_number_in_puzzle_tile (int puzzle_note_pad[][81], int puzzle_numbers[],  int c1, int c2, int c3, int c4, int c5, int c6)
//  Function to call the find_obvious_number_in_puzzle_tile function for whole puzzle.
{
//
    int row=0;
    int col=0;
    int single_number_count[9]={0};
    int temp_grid [9][9] = {{0}};
    int c=0;
//
    c=0;
//
    for (row=0; row<=8; ++row)
        {
        for (col=c1; col<=c2; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
           ++c;
            }
        c=0;
        }
//
    c=3;
//
    for (row=0; row<=8; ++row)
        {
        for (col=c3; col<=c4; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=3;
        }
//
    c=6;
//
    for (row=0; row<=8; ++row)
        {
        for (col=c5; col<=c6; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] != 0)
                {
                ++single_number_count[row];
                }
            }
        }
//
    for (c=c1; c<=c2; ++c)
        {
        for (row=0; row<=8; ++row)
            {
            if (puzzle_note_pad[row][c] != 0 && single_number_count[row] == 1)
                {
                if (puzzle_numbers[c] == 0)
                    {
                    puzzle_numbers[c] = puzzle_note_pad[row][c];
                    }
                }
            }
        }
//
    for (c=c3; c<=c4; ++c)
        {
        for (row=0; row<=8; ++row)
            {
            if (puzzle_note_pad[row][c] != 0 && single_number_count[row] == 1)
                {
                if (puzzle_numbers[c] == 0)
                    {
                    puzzle_numbers[c] = puzzle_note_pad[row][c];
                    }
                }
            }
        }
//
    for (c=c5; c<=c6; ++c)
        {
        for (row=0; row<=8; ++row)
            {
            if (puzzle_note_pad[row][c] != 0 && single_number_count[row] == 1)
                {
                if (puzzle_numbers[c] == 0)
                    {
                    puzzle_numbers[c] = puzzle_note_pad[row][c];
                    }
                }
            }
        }
//
}
//
void find_obvious_number_in_puzzle_tiles (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to call the find_obvious_number_in_puzzle_tile function for whole puzzle.
{
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  0, 2, 9, 11, 18, 20);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  3, 5, 12, 14, 21, 23);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  6, 8, 15, 17, 24, 26);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  27, 29, 36, 38, 45, 47);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  30, 32, 39, 41, 48, 50);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  33, 35, 42, 44, 51, 53);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  54, 56, 63, 65, 72, 74);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  57, 59, 66, 68, 75, 77);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_tile (puzzle_note_pad, puzzle_numbers,  60, 62, 69, 71, 78, 80);
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_obvious_numbers_in_puzzle (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to find the obvious numbers across ROW, COLUMN and TILE in the whole puzzle.
{
//
    find_obvious_number_in_puzzle_tiles (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_cols (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
    find_obvious_number_in_puzzle_rows (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
}
//
