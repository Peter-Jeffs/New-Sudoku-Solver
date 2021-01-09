//
//  hiddenpairs.cpp
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
void find_hidden_pairs_in_row (int puzzle_note_pad[][81],int puzzle_numbers[], int col_lower, int col_upper)
//  Function to find_hidden_pairs_in_row. 2 arguments are passed to the function that represent the start
//  and end of the ROW (e.g. 0-8, 9-17).
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
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int stored_numbers[9] = {0};
    int stored_numbers_count1 = 0;
    int stored_numbers_count2 = 0;
    int set_pair_flag = 0;
//
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_row[x] = 0;
        }
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
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (numbers_in_a_row[row] == 2)
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
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
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
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
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (work2_grid[row][col] != 0)
                    {
                    stored_numbers[row] = work2_grid[row][col];
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
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2)
            {
            set_pair_flag = 1;
            }
        }
//
    if ((stored_numbers_count1 == 2) && (stored_numbers_count2 == 2) &&  (set_pair_flag == 1))
        {
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (numbers_in_a_col[col] == 2)
                    {
                    temp_grid[row][col] = work2_grid[row][col];
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
void find_hidden_pairs_in_rows (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to find_hidden_pairs_in_rows in each ROW of the WHOLE puzzle.
//  Arguments are passed to the general find_hidden_pairs_in_row for ROWS 1-9.
//  This function could probably be re-factored, or at least amended so that analysis
//  is focused rather than bluntly across the whole puzzle.
{
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 0, 8); //   Row
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 9, 17); //  Row 2
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 18, 26); // Row 3
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 27, 35); // Row 4
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 36, 44); // Row 5
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 45, 53); // Row 6
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 54, 62); // Row 7
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 63, 71); // Row 8
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_row (puzzle_note_pad, puzzle_numbers, 72, 80); // Row 9
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
void find_hidden_pairs_in_col (int puzzle_note_pad[][81],int puzzle_numbers[], int col_lower, int col_upper)
//  Function to find_hidden_pairs_in_cols. 2 arguments are passed to the function that represent the start
//  and end of the COL (e.g. 0-72, 1-73).
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
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int final_numbers_in_a_col[9] = {0};
//
//  **************************************************************************
//  //  Row 1 for candidate pairs in Tile 1 ...
//  **************************************************************************
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
//
//    printf("Temp Grid\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] !=0)
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
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//
//    printf("work_grid\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", work_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
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
            if (numbers_in_a_col[col] >= 2)
                {
                work1_grid[row][col] = work_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_row[x] = 0;
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
            if (numbers_in_a_row[row] == 2)
                {
                work2_grid[row][col] = work1_grid[row][col];
                }
            }
        }
//
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work2_grid[row][col] !=0)
                {
                ++final_numbers_in_a_col[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (final_numbers_in_a_col[col] == 2)
                {
                temp_grid[row][col] = work2_grid[row][col];
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
void find_hidden_pairs_in_cols (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to find_hidden_pairs_in_cols in each COL of the WHOLE puzzle.
//  Arguments are passed to the general find_hidden_pairs_in_col for COLS 1-9.
//  This function could probably be re-factored, or at least amended so that analysis
//  is focused rather than bluntly across the whole puzzle.
{
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 0, 72);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 1, 73);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 2, 74);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 3, 75);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 4, 76);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 5, 77);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 6, 78);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 7, 79);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_col (puzzle_note_pad, puzzle_numbers, 8, 80);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_hidden_pairs_in_tile (int puzzle_note_pad[][81],int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6)
//  Pass 6 arguments to the function that represent the tile that is being analysed.
//  The arguments passed represent each row of the tile (e.g. 0-2, 3-5, 6-8).
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
    int work4_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_col[9] = {0};
    int stored_numbers[9] = {0};
    int stored_numbers_count1 = 0;
    int stored_numbers_count2 = 0;
    int set_pair_flag = 0;
//
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_col[x] = 0;
        }
//
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_row[x] = 0;
        }
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
            if (temp_grid[row][col] !=0)
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
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        numbers_in_a_row[x] = 0;
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
            if (numbers_in_a_col[col] > 1)
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
            if (numbers_in_a_row[row] == 2)
                {
                work2_grid[row][col] = work1_grid[row][col];
                }
            }
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
            if (numbers_in_a_col[col] == 2)
                {
                work4_grid[row][col] = work3_grid[row][col];
                }
            }
        }
//
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (work4_grid[row][col] != 0)
                    {
                    stored_numbers[row] = work4_grid[row][col];
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
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2)
            {
            set_pair_flag = 1;
            }
        }
//
    if ((stored_numbers_count1 == 2) && (stored_numbers_count2 == 2) &&  (set_pair_flag == 1))
        {
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                if (numbers_in_a_col[col] == 2)
                    {
                    temp_grid[row][col] = work4_grid[row][col];
                    }
                }
            }
        }
//
    c=c1;
//
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
//
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
//
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
void find_hidden_pairs_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
//  Function to apply the hidden pairs solving techniques in TILES to the WHOLE puzzle.
//  Arguments are passed to the find_hidden_pairs_in_tiles function to reflect each tile.
//  The resolve_obvious_number_in_puzzle and then the find_obvious_numbers_in_puzzle functions
//  are then called to resolve the obvious numbers.
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  0, 2, 9, 11, 18, 20);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  3, 5, 12, 14, 21, 23);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  6, 8, 15, 17, 24, 26);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  27, 29, 36, 38, 45, 47);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  30, 32, 39, 41, 48, 50);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  33, 35, 42, 44, 51, 53);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  54, 56, 63, 65, 72, 74);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  57, 59, 66, 68, 75, 77);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);;
//
    find_hidden_pairs_in_tile (puzzle_note_pad, puzzle_numbers,  60, 62, 69, 71, 78, 80);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//

//
