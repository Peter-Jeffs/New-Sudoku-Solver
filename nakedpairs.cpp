//
//  nakedpairs.cpp
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
void find_naked_pairs_in_row (int puzzle_note_pad[][81], int col_lower, int col_upper)
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int temp_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int work1_grid [9][9] = {{0}};
    int work2_grid [9][9] = {{0}};
    int work3_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int stored_numbers[9] = {0};
    int stored_numbers_count1 = 0;
    int stored_numbers_count2 = 0;
//
    for (row=0; row<=8; ++row)
        {
        for (col=col_lower; col<=col_upper; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
 
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
 
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work1_grid[row][col] = work_grid[row][col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work1_grid[row][col] !=0)
                {
                ++numbers_in_a_row[row];
                }
            }
        }
 
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_row[row] > 1)
                {
                work2_grid[row][col] = work1_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work2_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work3_grid[row][col] = work2_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work3_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (work3_grid[row][col] != 0)
                    {
                    stored_numbers[row] = work3_grid[row][col];
                    }
                }
            }
//
    for (x=0; x<=8; ++x)
        {
        if (stored_numbers[x] !=0)
            {
            ++stored_numbers_count1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] !=0)
            {
            ++stored_numbers_count2;
            }
        }
//
    if ((stored_numbers_count1 == 2) && (stored_numbers_count2 == 2))
        {
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (stored_numbers[row] != 0)
                    {
                    temp_grid[row][col] = work3_grid[row][col];
                    }
                }
            }
        }
//
    c=col_lower;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_grid[row][col];
            ++c;
            }
        c=col_lower;
        }
//
}
//
void find_naked_pairs_in_rows (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    find_naked_pairs_in_row (puzzle_note_pad, 0, 8); //   Row 1
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 9, 17); //  Row 2
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 18, 26); // Row 3
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 27, 35); // Row 4
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 36, 44); // Row 5
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 45, 53); // Row 6
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 54, 62); // Row 7
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 63, 71); // Row 8
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_row (puzzle_note_pad, 72, 80); // Row 9
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_naked_pairs_in_col (int puzzle_note_pad[][81], int col_lower, int col_upper)
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int temp_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int work1_grid [9][9] = {{0}};
    int work2_grid [9][9] = {{0}};
    int work3_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int stored_numbers[9] = {0};
    int stored_numbers_count1 = 0;
    int stored_numbers_count2 = 0;
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
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work1_grid[row][col] = work_grid[row][col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work1_grid[row][col] !=0)
                {
                ++numbers_in_a_row[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_row[row] > 1)
                {
                work2_grid[row][col] = work1_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work2_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work3_grid[row][col] = work2_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work3_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (work3_grid[row][col] != 0)
                    {
                    stored_numbers[row] = work3_grid[row][col];
                    }
                }
            }
//
    for (x=0; x<=8; ++x)
        {
        if (stored_numbers[x] !=0)
            {
            ++stored_numbers_count1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] !=0)
            {
            ++stored_numbers_count2;
            }
        }
//
    if ((stored_numbers_count1 == 2) && (stored_numbers_count2 == 2))
        {
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (stored_numbers[row] != 0)
                    {
                    temp_grid[row][col] = work3_grid[row][col];
                    }
                }
            }
        }
//
    c=col_lower;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_grid[row][col];
            c+=9;
            }
        c=col_lower;
        }
//
}
//
void find_naked_pairs_in_cols (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    find_naked_pairs_in_col (puzzle_note_pad, 0, 72);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 1, 73);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 2, 74);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 3, 75);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 4, 76);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 5, 77);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 6, 78);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 7, 79);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_naked_pairs_in_col (puzzle_note_pad, 8, 80);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
 
void find_naked_pairs_in_tile (int puzzle_note_pad[][81],int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6)
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int temp_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int work1_grid [9][9] = {{0}};
    int work2_grid [9][9] = {{0}};
    int work3_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int stored_numbers_rows[9] = {0};
    int stored_numbers_count_row[9] = {0};
    int stored_numbers_count_col[9] = {0};
    int stored_numbers_count = 0;
//
//  **************************************************************************
//  //  create a temp grid from the original grid ...
//  **************************************************************************
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
// Look for 2 numbers in the cols - not sure if they are pairs yet!!
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] !=0)
                {
                ++numbers_in_a_row[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_row[row] == 2)
                {
                work1_grid[row][col] = work_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
// Look for 2 numbers in the cols - not sure if they are pairs yet!!
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work1_grid[row][col] !=0)
                {
                ++numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_col[col] == 2)
                {
                work2_grid[row][col] = work1_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_row[x] = 0;
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work2_grid[row][col] !=0)
                {
                ++numbers_in_a_row[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_row[row] == 2)
                {
                work3_grid[row][col] = work2_grid[row][col];
                }
            }
        }
//
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (work3_grid[row][col] != 0)
                    {
                    stored_numbers_rows[row] = work_grid[row][col];
                    ++stored_numbers_count_row[row];
                    ++stored_numbers_count_col[col];
                    }
                }
            }
//
    for (x=0; x<=8; ++x)
        {
        if (stored_numbers_rows[x] != 0)
            {
            ++stored_numbers_count;
            }
        }
//
    if (stored_numbers_count >= 2)
        {
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (temp_grid[row][col] == stored_numbers_rows[row])
                    {
                    temp_grid[row][col] = work3_grid[row][col];
                    }
                }
            }
        }
//
//  put number back into note_pad.
//
    c=c1;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=2; ++col)
            {
            puzzle_note_pad[row][c] = temp_grid[row][col];
            ++c;
            }
        c=c1;
        }
//
    c=c3;
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=5; ++col)
            {
            puzzle_note_pad[row][c] = temp_grid[row][col];
            ++c;
            }
        c=c3;
        }
//
    c=c5;
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_grid[row][col];
            ++c;
            }
        c=c5;
        }
//
}
//
void find_naked_pairs_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  0, 2, 9, 11, 18, 20);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  3, 5, 12, 14, 21, 23);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  6, 8, 15, 17, 24, 26);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  27, 29, 36, 38, 45, 47);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  30, 32, 39, 41, 48, 50);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  33, 35, 42, 44, 51, 53);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  54, 56, 63, 65, 72, 74);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  57, 59, 66, 68, 75, 77);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
 
    find_naked_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  60, 62, 69, 71, 78, 80);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//

//
