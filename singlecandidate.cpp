//
//  singlecandidate.cpp
//  Sudoku
//
//  Created by Peter Jeffs on 24/12/2020.
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"
using namespace std;
//
void find_single_candidates_in_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper)
//  Function to find_obvious_number_in_puzzle_row for whole puzzle.
{
//
int col=0;
int row=0;
int copied_puzzle_numbers [9] = {0};
int original_puzzle_numbers [9] = {0};
int new_puzzle_numbers [9] = {0};
int c = 0;
int x = 0;
//
    for (row=col_lower; row<=col_upper; ++row)
        {
        original_puzzle_numbers[x] = puzzle_numbers[row];
        cout << "original puzzle_numbers = " << original_puzzle_numbers[x] << endl;
        ++x;
        }
//
        for (row=0; row<=8; ++row)
            {
            copied_puzzle_numbers[row] = original_puzzle_numbers[row];
            cout << "copied puzzle_numbers = " << copied_puzzle_numbers[row] << endl;
            }
//
    print_puzzle_note_pad_row (puzzle_note_pad, 3, 18, 26);
//
    int temp_grid [9][9] = {{0}};
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
printf("Print of temp_grid of note_pad\n");
//
for (row=0; row<=8; ++row)
    {
    for (col=0; col<=8; ++col)
        {
        printf("%d ", temp_grid[row][col]);
        }
        printf("\n");
//
        printf("\n");
    }
//
    int row_counter [8] = {0};
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (temp_grid[col][row] != 0)
                {
                ++row_counter[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        cout << "temp_grid row count = " << row_counter[row] << endl;
        }
//
    for (row=0; row<=8; ++row)
        {
        if (row_counter[row] == 1)
            {
            new_puzzle_numbers [row] = row + 1;
            cout << "new puzzle number is = " << new_puzzle_numbers [row] << endl;
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        cout << "(final) new_puzzle_number list = " << new_puzzle_numbers [row] << endl;
        }
//
        for (row=0; row<=8; ++row)
            {
            copied_puzzle_numbers[row] = original_puzzle_numbers[row];
            cout << "(last) copied puzzle_numbers = " << copied_puzzle_numbers[row] << endl;
            }
}
//
    
