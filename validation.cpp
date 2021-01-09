//
//  Validation.cpp
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
int verify_that_puzzle_tiles_and_rows_are_valid (int puzzle_numbers[])
//  Function to call the puzzle tile validity and puzzle row validity functions.
{
//
    int puzzle_tile_valid[9] = {0};
    int puzzle_row_valid[9] = {0};
    int valid_or_invalid = 0;
    int puzzle_tile_validity = 0;
    int puzzle_row_validity = 0;
    int c=0;
//
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 0, 2, 9, 11, 18, 20, 1);
    puzzle_tile_valid[0] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 3, 5, 12, 14, 21, 23, 2);
    puzzle_tile_valid[1] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 6, 8, 15, 17, 24, 26, 3);
    puzzle_tile_valid[2] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 27, 29, 36, 38, 45, 47, 4);
    puzzle_tile_valid[3] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 30, 32, 39, 41, 48, 50, 5);
    puzzle_tile_valid[4] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 33, 35, 42, 44, 51, 53, 6);
    puzzle_tile_valid[5] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 54, 56, 63, 65, 72, 74, 7);
    puzzle_tile_valid[6] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 57, 59, 66, 68, 75, 77, 8);
    puzzle_tile_valid[7] = puzzle_tile_validity;
    puzzle_tile_validity = verify_that_puzzle_tile_is_valid (puzzle_numbers, 60, 62, 69, 71, 78, 80, 9);
    puzzle_tile_valid[8] = puzzle_tile_validity;
//
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 0, 8); //   Row 1
    puzzle_row_valid[0] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 9, 17); //  Row 2
    puzzle_row_valid[1] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 18, 26); // Row 3
    puzzle_row_valid[2] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 27, 35); // Row 4
    puzzle_row_valid[3] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 36, 44); // Row 5
    puzzle_row_valid[4] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 45, 53); // Row 6
    puzzle_row_valid[5] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 54, 62); // Row 7
    puzzle_row_valid[6] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 63, 71); // Row 8
    puzzle_row_valid[7] = puzzle_row_validity;
    puzzle_row_validity = verify_that_puzzle_row_is_valid (puzzle_numbers, 72, 80); // Row 9
    puzzle_row_valid[8] = puzzle_row_validity;
//
    for (c=0; c<=8; ++c)
        {
        if ((puzzle_tile_valid[c] == 1) || (puzzle_row_valid[c] == 1))
            {
            valid_or_invalid = 1;
            }
        }
//
    return valid_or_invalid;
//
}
//
int check_puzzle_validity (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to check that every number has been solved, and to check that the solution is valid.
{
//
    int puzzle_validity = 0;
    int puzzle_square[9][9] = {{0}};
//
    check_puzzle_square_complete (puzzle_square, puzzle_numbers);
//
    puzzle_validity = verify_that_puzzle_tiles_and_rows_are_valid (puzzle_numbers);
//
    if (puzzle_validity == 1)
        {
        printf("  This puzzle solution is In-Valid !!!\n\n");
        }
    else
        {
        printf("  This puzzle solution is Valid !!!\n\n");
        }
//
    return puzzle_validity;
//
}
//
void check_puzzle_square_complete (int puzzle_square[][9], int puzzle_numbers[])
//  Function to verify that there is a number in each cell in the puzzle.
{
    int row=0;
    int col=0;
    int zero_count = 0;
//
    fill_puzzle_square (puzzle_square, puzzle_numbers);
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (puzzle_square[row][col] == 0)
                {
                ++zero_count;
                }
            }
        }
//
    if (zero_count > 0)
        {
        printf("\n\n  Puzzle NOT Solved!!\n\n");
        printf("  Sorry ... but there are un-soloved puzzle squares!!\n\n");
        }
    if (zero_count == 0)
        {
        printf("\n\n  Puzzle Solved!!!\n\n");
        printf("  All puzzle squares have a valid number !!\n\n");
        }
//
}
//
int verify_that_puzzle_tile_is_valid (int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6, int n)
//  Function to verify that the numbers in a tile are unique 1-9.
{
    int a=0;
    int i=0;
    int j=0;
    int col=0;
    int puzzle_validity = 0;
    int temp_tile [9] = {0};
    int mask [9] = {1,2,3,4,5,6,7,8,9};
//
//
    a=0;
    for (col=c1; col<=c2; ++col)
        {
        temp_tile[a] = puzzle_numbers[col];
        ++a;
        }
//
    a=3;
    for (col=c3; col<=c4; ++col)
        {
        temp_tile[a] = puzzle_numbers[col];
        ++a;
        }
//
    a=6;
    for (col=c5; col<=c6; ++col)
        {
        temp_tile[a] = puzzle_numbers[col];
        ++a;
        }
//
    for (i = 0; i<=8; ++i)
        {
        for (j = i + 1; j<=8; ++j)
            {
            if (temp_tile[i] > temp_tile[j])
                {
                a =  temp_tile[i];
                temp_tile[i] = temp_tile[j];
                temp_tile[j] = a;
                }
            }
        }
//
    for (i=0; i<=8; ++i)
        {
        if (temp_tile[i] == mask[i])
            {
//          printf("TRUE Number is %d \n", temp_tile[i]);
            }
        else
            {
            puzzle_validity = 1;
            }
        }
//
    return puzzle_validity;
//
}
//
int verify_that_puzzle_row_is_valid (int puzzle_numbers[], int col_lower, int col_upper)
//  Function to verify that the numbers in a row are unique 1-9.
{
    int a=0;
    int i=0;
    int j=0;
    int col=0;
    int puzzle_row_validity = 0;
    int temp_tile [9] = {0};
    int mask [9] = {1,2,3,4,5,6,7,8,9};
//
//
    a=0;
    for (col=col_lower; col<=col_upper; ++col)
        {
        temp_tile[a] = puzzle_numbers[col];
        ++a;
        }
//
    for (i = 0; i<=8; ++i)
        {
        for (j = i + 1; j<=8; ++j)
            {
            if (temp_tile[i] > temp_tile[j])
                {
                a =  temp_tile[i];
                temp_tile[i] = temp_tile[j];
                temp_tile[j] = a;
                }
            }
        }
//
    for (i=0; i<=8; ++i)
        {
            if (temp_tile[i] == mask[i])
                {
                //printf("TRUE Number is %d \n", temp_tile[i]);
                }
            else
                {
                puzzle_row_validity = 1;
                }
        }
//
    return puzzle_row_validity;
//
}
//
//
