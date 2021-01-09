//
//  candidatelines.cpp
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
//
void find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (int puzzle_note_pad[][81], int puzzle_numbers[],
    int ll_r1, int ul_r1, int ll_r2, int ul_r2, int ll_r3, int ul_r3,
    int ll_tile_r1, int ul_tile_r1, int ll_tile_r2, int ul_tile_r2, int ll_tile_r3, int ul_tile_r3,
    int ll_rcl_r1, int ul_rcl_r1, int ll_rcl_r2, int ul_rcl_r2, int ll_rcl_r3, int ul_rcl_r3,
    int ll_tcl_r1, int ul_tcl_r1, int ll_tcl_r2, int ul_tcl_r2, int ll_tcl_r3, int ul_tcl_r3,
    int refill_row1, int refill_row2, int refill_row3)
//  Function to find candidate lines in Tiles 1, 3, 4, 6, 7, and 9.
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int spno_c = 0;
    int set_flag_for_row1 = 0;
    int set_flag_for_row2 = 0;
    int set_flag_for_row3 = 0;
    int candidate_lines_in_row1 = 0;
    int candidate_lines_in_row2 = 0;
    int candidate_lines_in_row3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_row1[9] = {0};
    int numbers_in_a_row2[9] = {0};
    int numbers_in_a_row3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  Create a temporary grid to hold a puzzle row ...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r1; col<=ul_r1; ++col)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Row 8 for candidate pairs in Tile 9 ...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r2; col<=ul_r2; ++col)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Row 9 for candidate pairs in Tile 9 ...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r3; col<=ul_r3; ++col)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Zero out the temp grid ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//
//  The next set of routines copy Tile 9 into a temp grid.
    for (row=0; row<=8; ++row)
        {
        for (col=ll_tile_r1; col<=ul_tile_r1; ++col)
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
        for (col=ll_tile_r2; col<=ul_tile_r2; ++col)
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
        for (col=ll_tile_r3; col<=ul_tile_r3; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=2; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row1[row];
                ++numbers_in_a_row[row];
                }
            }
        for (col=3; col<=5; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row2[row];
                ++numbers_in_a_row[row];
                }
            }
        for (col=6; col<=8; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row3[row];
                ++numbers_in_a_row[row];
                }
            }
        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  Compare Row 1 (Temp1) with the Tile ...
    for (spno_c=ll_rcl_r1; spno_c<=ul_rcl_r1; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row1 = 1;
            }
        }
//
//  Compare Row 2 (Temp1) with the Tile ...
    for (spno_c=ll_rcl_r2; spno_c<=ul_rcl_r2; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row2 = 1;
            }
        }
//
//  Compare Row 3 (Temp1) with the Tile ...
    for (spno_c=ll_rcl_r2; spno_c<=ul_rcl_r3; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row3 = 1;
            }
        }
//
//  Row 7 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row1[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[0] != 0 || pesky_pairs_in_col_count[1] != 0 ||
                pesky_pairs_in_col_count[2] != 0) && (candidate_lines_in_row1 == 1))
                {
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_row1 = 1;
//
                for (col=ll_tcl_r1; col<=ul_tcl_r1; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                }
            }
//
//  Row 8 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row2[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[3] != 0 || pesky_pairs_in_col_count[4] != 0 ||
            pesky_pairs_in_col_count[5] != 0) && (candidate_lines_in_row2 == 1))
                {
                set_flag_for_row2 = 1;
//
                for (col=ll_tcl_r2; col<=ul_tcl_r2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
//  Row 9 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row3[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[6] != 0 || pesky_pairs_in_col_count[7] != 0 ||
                pesky_pairs_in_col_count[8] != 0) && (candidate_lines_in_row3 == 1))
                {
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_row3 = 1;
//
                for (col=ll_tcl_r3; col<=ul_tcl_r3; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
//    Copy the temp1 grid to the notepad grid
    if (set_flag_for_row1 == 1)
        {
        c=refill_row1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                ++c;
                }
            c=refill_row1;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_row2 == 1)
        {
        c=refill_row2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                ++c;
                }
            c=refill_row2;
            }
        }
//
//    Copy the temp3 grid to the notepad grid
    if (set_flag_for_row3 == 1)
        {
        c=refill_row3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                ++c;
                }
            c=refill_row3;
            }
        }
//
}
//
void find_horiz_candidate_lines_t2_t5_t8 (int puzzle_note_pad[][81], int puzzle_numbers[],
    int ll_r1, int ul_r1, int ll_r2, int ul_r2, int ll_r3, int ul_r3,
    int ll_tile_r1, int ul_tile_r1, int ll_tile_r2, int ul_tile_r2, int ll_tile_r3, int ul_tile_r3,
    int ll_rcll_r1, int ul_rcll_r1, int ll_rclr_r1, int ul_rclr_r1,
    int ll_rcll_r2, int ul_rcll_r2, int ll_rclr_r2, int ul_rclr_r2,
    int ll_rcll_r3, int ul_rcll_r3, int ll_rclr_r3, int ul_rclr_r3,
    int ll_tcll_r1, int ul_tcll_r1, int ll_tclr_r1, int ul_tclr_r1,
    int ll_tcll_r2, int ul_tcll_r2, int ll_tclr_r2, int ul_tclr_r2,
    int ll_tcll_r3, int ul_tcll_r3, int ll_tclr_r3, int ul_tclr_r3,
    int refill_row1, int refill_row2, int refill_row3)
//  Function to find candidate lines in Tiles 2, 5, and 8.
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int spno_c = 0;
    int set_flag_for_row1 = 0;
    int set_flag_for_row2 = 0;
    int set_flag_for_row3 = 0;
    int candidate_lines_in_row1 = 0;
    int candidate_lines_in_row2 = 0;
    int candidate_lines_in_row3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_row[9] = {0};
    int numbers_in_a_row1[9] = {0};
    int numbers_in_a_row2[9] = {0};
    int numbers_in_a_row3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  Temporary grid (1)...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r1; col<=ul_r1; ++col)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temporary grid (2)...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r2; col<=ul_r2; ++col)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temporary grid (3)...
    for (row=0; row<=8; ++row)
        {
        for (col=ll_r3; col<=ul_r3; ++col)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Zero out the temp grid ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//
//  The next set of routines copy Tile 8 into a temp grid.
    for (row=0; row<=8; ++row)
        {
        for (col=ll_tile_r1; col<=ul_tile_r1; ++col)
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
        for (col=ll_tile_r2; col<=ul_tile_r2; ++col)
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
        for (col=ll_tile_r3; col<=ul_tile_r3; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=2; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row1[row];
                ++numbers_in_a_row[row];
                }
            }
        for (col=3; col<=5; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row2[row];
                ++numbers_in_a_row[row];
                }
            }
        for (col=6; col<=8; ++col)
            {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_row3[row];
                ++numbers_in_a_row[row];
                }
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_row1[%i] = %i\n", x, numbers_in_a_row1[x]);
//        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_row2[%i] = %i\n", x, numbers_in_a_row2[x]);
//        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_row3[%i] = %i\n", x, numbers_in_a_row3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_row[%i] = %i\n", x, numbers_in_a_row[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_row[x] == 2 && numbers_in_a_row3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
               {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  Compare Row 7 (Temp1) with the Tile ...
    for (spno_c=ll_rcll_r1; spno_c<=ul_rcll_r1; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row1 = 1;
//            printf("candidate_lines_in_row7 = %i!!\n", candidate_lines_in_row7);
            }
        }
//
    for (spno_c=ll_rclr_r1; spno_c<=ul_rclr_r1; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row1 = 1;
//            printf("candidate_lines_in_row7 = %i!!\n", candidate_lines_in_row7);
            }
        }
//
//  Compare Row 8 (Temp1) with the Tile ...
    for (spno_c=ll_rcll_r2; spno_c<=ul_rcll_r2; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row2 = 1;
//            printf("candidate_lines_in_row8 = %i!!\n", candidate_lines_in_row8);
            }
        }
//
    for (spno_c=ll_rclr_r2; spno_c<=ul_rclr_r2; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row2 = 1;
//            printf("candidate_lines_in_row8 = %i!!\n", candidate_lines_in_row8);
            }
        }
//  Row 9  ...
    for (spno_c=ll_rcll_r3; spno_c<=ul_rcll_r3; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row3 = 1;
//            printf("candidate_lines_in_row9 = %i!!\n", candidate_lines_in_row9);
            }
        }
//
    for (spno_c=ll_rclr_r3; spno_c<=ul_rclr_r3; ++spno_c)
        {
        if (puzzle_numbers[spno_c] == 0)
            {
//          set flag to say there ARE candidate lines
            candidate_lines_in_row3 = 1;
//            printf("candidate_lines_in_row9 = %i!!\n", candidate_lines_in_row9);
            }
        }
//
//  Row 7 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row1[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[0] != 0 || pesky_pairs_in_col_count[1] != 0 ||
                pesky_pairs_in_col_count[2] != 0) && (candidate_lines_in_row1 == 1))
                {
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_row1 = 1;
//
                for (col=ll_tcll_r1; col<=ul_tcll_r1; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                for (col=ll_tclr_r1; col<=ul_tclr_r1; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  Row 8 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row2[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[3] != 0 || pesky_pairs_in_col_count[4] != 0 ||
            pesky_pairs_in_col_count[5] != 0) && (candidate_lines_in_row2 == 1))
                {
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_row2 = 1;
//
                for (col=ll_tcll_r2; col<=ul_tcll_r2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                for (col=ll_tclr_r2; col<=ul_tclr_r2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
//  Row 9 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_row3[row] == 2) && (two_pair_row_num[row] == 2) && (pesky_pairs_in_col_count[6] != 0 || pesky_pairs_in_col_count[7] != 0 ||
                pesky_pairs_in_col_count[8] != 0) && (candidate_lines_in_row3 == 1))
                {
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_row3 = 1;
//
                for (col=ll_tcll_r3; col<=ul_tcll_r3; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                for (col=ll_tclr_r3; col<=ul_tclr_r3; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
    if (set_flag_for_row1 == 1)
        {
        c=refill_row1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                ++c;
                }
            c=refill_row1;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_row2 == 1)
        {
        c=refill_row2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                ++c;
                }
            c=refill_row2;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_row3 == 1)
        {
        c=refill_row3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                ++c;
                }
            c=refill_row3;
            }
        }
//
}
//
void find_horiz_candidate_lines_in_puzzle_v2 (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Function to call the find_candidate_lines_in_puzzle function for whole puzzle.
{
//  tile 1
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    0, 8, 9, 17, 18, 26,
    0, 2, 9, 11, 18, 20,
    3, 8, 12, 17, 21, 26,
    3, 8, 3, 8, 3, 8,
    0, 9, 18);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 2
    find_horiz_candidate_lines_t2_t5_t8 (puzzle_note_pad, puzzle_numbers,
    0, 8, 9, 17, 18, 26,
    3, 5, 12, 14, 21, 23,
    0, 2, 6, 8,
    9, 11, 15, 17,
    18, 20, 24, 26,
    0, 2, 6, 8,
    0, 2, 6, 8,
    0, 2, 6, 8,
    0, 9, 18);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 3
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    0, 8, 9, 17, 18, 26,
    6, 8, 15, 17, 24, 26,
    0, 5, 9, 14, 18, 23,
    0, 5, 0, 5, 0, 5,
    0, 9, 18);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 4
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    27, 35, 36, 44, 45, 53,
    27, 29, 36, 38, 45, 47,
    30, 35, 39, 44, 48, 53,
    3, 8, 3, 8, 3, 8,
    27, 36, 45);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 5
    find_horiz_candidate_lines_t2_t5_t8 (puzzle_note_pad, puzzle_numbers,
    27, 35, 36, 44, 45, 53,
    30, 32, 39, 41, 48, 50,
    27, 29, 33, 35,
    36, 38, 42, 44,
    45, 47, 51, 53,
    0, 2, 6, 8,
    0, 2, 6, 8,
    0, 2, 6, 8,
    27, 36, 45);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 6
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    27, 35, 36, 44, 45, 53,
    33, 35, 42, 44, 51, 53,
    27, 32, 36, 41, 45, 50,
    0, 5, 0, 5, 0, 5,
    27, 36, 45);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 7
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    54, 62, 63, 71, 72, 80,
    54, 56, 63, 65, 72, 74,
    57, 62, 66, 71, 75, 80,
    3, 8, 3, 8, 3, 8,
    54, 63, 72);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 8
    find_horiz_candidate_lines_t2_t5_t8 (puzzle_note_pad, puzzle_numbers,
    54, 62, 63, 71, 72, 80,
    57, 59, 66, 68, 75, 77,
    54, 56, 60, 62,
    63, 65, 69, 71,
    72, 74, 78, 80,
    0, 2, 6, 8,
    0, 2, 6, 8,
    0, 2, 6, 8,
    54, 63, 72);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//  tile 9
    find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (puzzle_note_pad, puzzle_numbers,
    54, 62, 63, 71, 72, 80,
    60, 62, 69, 71, 78, 80,
    54, 59, 63, 68, 72, 77,
    0, 5, 0, 5, 0, 5,
    54, 63, 72);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_vertical_candidate_lines_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    find_vertical_candidate_lines_in_tile1 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile2 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile3 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile4 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile5 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile6 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile7 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile8 (puzzle_note_pad, puzzle_numbers);    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
    find_vertical_candidate_lines_in_tile9 (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_vertical_candidate_lines_in_tile1 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=72; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=1; col<=73; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=2; col<=74; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=2; ++col)
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
        for (col=9; col<=11; ++col)
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
        for (col=18; col<=20; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3)
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3)
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3)
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
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
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                set_flag_for_col1 = 1;
                for (col=3; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                }
            }
//
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                set_flag_for_col2 = 1;
                for (col=3; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                set_flag_for_col3 = 1;
                for (col=3; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
    if (set_flag_for_col1 == 1)
        {
        c=0;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=0;
            }
        }
//
    if (set_flag_for_col2 == 1)
        {
        c=1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=1;
            }
        }
//
    if (set_flag_for_col3 == 1)
        {
        c=2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=2;
            }
        }
//
}
//
void find_vertical_candidate_lines_in_tile2 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=75; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }puzzle_note_pad
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=4; col<=76; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=5; col<=77; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=5; ++col)
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
        for (col=12; col<=14; ++col)
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
        for (col=21; col<=23; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
           possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
           {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** two_pair_row_num[%i] = %i\n", x, two_pair_row_num[x]);
//        }
//
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
 
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=3;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=4;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=4;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=5;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=5;
            }
        }
//
//
}
//
void find_vertical_candidate_lines_in_tile3 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=78; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=7; col<=79; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=8; col<=80; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=8; ++col)
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
        for (col=15; col<=17; ++col)
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
        for (col=24; col<=26; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
           possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
           {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** two_pair_row_num[%i] = %i\n", x, two_pair_row_num[x]);
//        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=3; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
 
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=6;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=6;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=7;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=7;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=8;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=8;
            }
        }
//
//
}
//
void find_vertical_candidate_lines_in_tile4 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
   int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=72; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=1; col<=73; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=2; col<=74; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=27; col<=29; ++col)
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
        for (col=36; col<=38; ++col)
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
        for (col=45; col<=47; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
//                printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
//                printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
//                printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=0;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=0;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=1;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=2;
            }
        }
//
}
//
void find_vertical_candidate_lines_in_tile5 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=75; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=4; col<=76; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=5; col<=77; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=30; col<=32; ++col)
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
        for (col=39; col<=41; ++col)
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
        for (col=48; col<=50; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=3;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=4;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=4;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=5;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=5;
            }
        }
//
//
}
//
void find_vertical_candidate_lines_in_tile6 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=78; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=7; col<=79; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=8; col<=80; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=33; col<=35; ++col)
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
        for (col=42; col<=44; ++col)
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
        for (col=51; col<=53; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=2; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                for (col=6; col<=8; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=6;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=6;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=7;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=7;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=8;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=8;
            }
        }
//
}
//
void find_vertical_candidate_lines_in_tile7 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=72; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=1; col<=73; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=2; col<=74; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=54; col<=56; ++col)
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
        for (col=63; col<=65; ++col)
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
        for (col=72; col<=74; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
           possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
           {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
 
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=0;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=0;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=1;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=2;
            }
        }
//
}
//
void find_vertical_candidate_lines_in_tile8 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=75; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=4; col<=76; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=5; col<=77; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=57; col<=59; ++col)
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
        for (col=66; col<=68; ++col)
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
        for (col=75; col<=77; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
           possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
           {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
 
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=3;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=4;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=4;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=5;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=5;
            }
        }
//
}
//
void find_vertical_candidate_lines_in_tile9 (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function to ...
{
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
    int set_flag_for_col1 = 0;
    int set_flag_for_col2 = 0;
    int set_flag_for_col3 = 0;
    int pesky_pairs_in_col_count[9] = {0};
    int temp_grid [9][9] = {{0}};
    int temp1_grid [9][9] = {{0}};
    int temp2_grid [9][9] = {{0}};
    int temp3_grid [9][9] = {{0}};
    int work_grid [9][9] = {{0}};
    int numbers_in_a_col[9] = {0};
    int numbers_in_a_col1[9] = {0};
    int numbers_in_a_col2[9] = {0};
    int numbers_in_a_col3[9] = {0};
    int possible_pair_num[9] = {0};
    int two_pair_row_num[9] = {0};
//
//  **************************************************************************
//  //  Col 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=78; col+=9)
            {
            temp1_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//    printf("Temp Grid for Col 7 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp1_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  COl 7 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=7; col<=79; col+=9)
            {
            temp2_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 8 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp2_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Col 9 for candidate pairs in Tile 3 ...
//  **************************************************************************
    for (row=0; row<=8; ++row)
        {
        for (col=8; col<=80; col+=9)
            {
            temp3_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//
//    printf("Temp Grid for Col 9 --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//            {
//            printf("%d ", temp3_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  **************************************************************************
//  Zero out the temp grid ...
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_grid[row][col] = 0;
            }
        }
//  *************************************************************************
//  The next set of routines copy Tile 3 into a temp grid.
//
    for (row=0; row<=8; ++row)
        {
        for (col=60; col<=62; ++col)
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
        for (col=69; col<=71; ++col)
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
        for (col=78; col<=80; ++col)
            {
            temp_grid[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=6;
        }
//  *************************************************************************
//  Print the Temp grid ...
//    printf("Temp Grid for TILE 3 Rows --->\n");
//
//    for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=8; ++col)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 1 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=0; col<=6; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 2 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=1; col<=7; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
//  Print the Temp grid ...
//    printf("Temp Grid for col 3 of tile 3 --->\n");
//
//     for (row=0; row<=8; ++row)
//        {
//        for (col=2; col<=8; col+=3)
//           {
//            printf("%d ", temp_grid[row][col]);
//            }
//            printf("\n");
//
//        printf("\n");
//        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=0; col<=6; col+=3) // Look in col 1 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col1[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=1; col<=7; col+=3) // Look in col 2 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col2[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
     for (row=0; row<=8; ++row)
        {
        for (col=2; col<=8; col+=3) // Look in col 3 of the tile and determine if there is unique pair.
           {
            if (temp_grid[row][col] !=0)
                {
                ++numbers_in_a_col3[row];
                ++numbers_in_a_col[row];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col1[%i] = %i\n", x, numbers_in_a_col1[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col2[%i] = %i\n", x, numbers_in_a_col2[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> numbers_in_a_col3[%i] = %i\n", x, numbers_in_a_col3[x]);
//        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf(" ");
//        printf("---> numbers_in_a_COL TOTAL[%i] = %i\n", x, numbers_in_a_col[x]);
//        }
//
//  If the numbers is 2, that means that the digits could be the hidden pair!!
//  so store the number in a variable possible_pair_num[x].
    for (x=0; x<=8; ++x)
        {
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col1[x] == 2)
            {
           possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col2[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        if (numbers_in_a_col[x] == 2 && numbers_in_a_col3[x] == 2)
            {
            possible_pair_num[x] = x+1;
            }
        }
//
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("---> POSSIBLE_pair_num[%i] = %i\n", x, possible_pair_num[x]);
//        }
//  If the temporary grid number is the same as the possible pair number then
//  create a work grid with just those numbers ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_grid[row][col] == possible_pair_num[row])
                {
                work_grid[row][col] = temp_grid[row][col];
                }
            }
        }
//
//  ********************************************************************************
//    printf("WORK (1) Grid Tile 3 --->\n");
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
//  HERE we need to work out which cols the numbers are in to help
//  work out which row to call and remove numbers (because of candidate lines!!)
    for (col=0; col<=8; ++col)
        {
        for (row=0; row<=8; ++row)
            {
            if (work_grid[row][col] != 0)
                {
                ++pesky_pairs_in_col_count[col];
                }
            }
        }
//
//    for (x=0; x<=8; ++x)
//        {
//        printf("*** PESKY_pairs_in_COL_count[%i] = %i\n", x, pesky_pairs_in_col_count[x]);
//        }
//
//  ***********************************************************
//  Now keep the naked pairs ONLY in the cols !!! ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (work_grid[row][col] != 0)
                {
                ++two_pair_row_num[row];
                }
            }
        }
//
//  *************************************************************************
//  Row 1 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col1[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-1!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col1 = 1;
//                printf("NEW LOGIC*ROW 7*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp1_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 2 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col2[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-2!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col2 = 1;
//                printf("NEW LOGIC*ROW 8*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp2_grid[row][col] = 0;
                    }
 
                }
            }
//
//  *************************************************************************
//  Row 3 logic ...
        for (row=0; row<=8; ++row)
            {
            if ((numbers_in_a_col3[row] == 2) && (two_pair_row_num[row] == 2))
                {
                //printf("\n\nHERE for Col-3!!\n\n");
//              If there is a pair in a puzzle line and a pair in the grid row and a pair in the first 3 cols
//              then zero the ROW number in ROW 7.
                set_flag_for_col3 = 1;
//                printf("NEW LOGIC*ROW 9*numbers_in_a_row1[%i] == %i\n", row, numbers_in_a_row1[row]);
                for (col=0; col<=5; ++col)
                    {
                    temp3_grid[row][col] = 0;
                    }
 
                }
            }
//
//    Copy the temp2 grid to the notepad grid
//
    if (set_flag_for_col1 == 1)
        {
        c=6;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp1_grid[row][col];
                c+=9;
                }
            c=6;
            }
        }
 
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col2 == 1)
        {
        c=7;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp2_grid[row][col];
                c+=9;
                }
            c=7;
            }
        }
//
//    Copy the temp2 grid to the notepad grid
    if (set_flag_for_col3 == 1)
        {
        c=8;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp3_grid[row][col];
                c+=9;
                }
            c=8;
            }
        }
//
}
//

//
