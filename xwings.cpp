//
//  xwings.cpp
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
void find_xwing_in_puzzle_cols (int puzzle_note_pad[][81])
//  Function to ...
{
//
//  Function to apply the x-wing solving techniques in COLS for the whole puzzle.
//  This probably could do with re-factoring over time. It could be broken down into
//  smaller functions.
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
//
    int xwing_found = 0;
//
    int temp_col1 [9][9] = {{0}};
    int temp_col2 [9][9] = {{0}};
    int temp_col3 [9][9] = {{0}};
    int temp_col4 [9][9] = {{0}};
    int temp_col5 [9][9] = {{0}};
    int temp_col6 [9][9] = {{0}};
    int temp_col7 [9][9] = {{0}};
    int temp_col8 [9][9] = {{0}};
    int temp_col9 [9][9] = {{0}};
//
    int col1_count[9] = {0};
    int col2_count[9] = {0};
    int col3_count[9] = {0};
    int col4_count[9] = {0};
    int col5_count[9] = {0};
    int col6_count[9] = {0};
    int col7_count[9] = {0};
    int col8_count[9] = {0};
    int col9_count[9] = {0};
//
    int set_col1_xwing_flag = 0;
    int set_col2_xwing_flag = 0;
    int set_col3_xwing_flag = 0;
    int set_col4_xwing_flag = 0;
    int set_col5_xwing_flag = 0;
    int set_col6_xwing_flag = 0;
//
    int xwing_in_col1_and_col4 = 0;
    int xwing_in_col1_and_col5 = 0;
    int xwing_in_col1_and_col6 = 0;
    int xwing_in_col1_and_col7 = 0;
    int xwing_in_col1_and_col8 = 0;
    int xwing_in_col1_and_col9 = 0;
    int xwing_col1_4_store[9] = {0};
    int xwing_col1_5_store[9] = {0};
    int xwing_col1_6_store[9] = {0};
    int xwing_col1_7_store[9] = {0};
    int xwing_col1_8_store[9] = {0};
    int xwing_col1_9_store[9] = {0};
    int final_xwing_num_1_4 = 0;
    int final_xwing_num_1_5 = 0;
    int final_xwing_num_1_6 = 0;
    int final_xwing_num_1_7 = 0;
    int final_xwing_num_1_8 = 0;
    int final_xwing_num_1_9 = 0;
//
    int xwing_in_col2_and_col4 = 0;
    int xwing_in_col2_and_col5 = 0;
    int xwing_in_col2_and_col6 = 0;
    int xwing_in_col2_and_col7 = 0;
    int xwing_in_col2_and_col8 = 0;
    int xwing_in_col2_and_col9 = 0;
    int xwing_col2_4_store[9] = {0};
    int xwing_col2_5_store[9] = {0};
    int xwing_col2_6_store[9] = {0};
    int xwing_col2_7_store[9] = {0};
    int xwing_col2_8_store[9] = {0};
    int xwing_col2_9_store[9] = {0};
    int final_xwing_num_2_4 = 0;
    int final_xwing_num_2_5 = 0;
    int final_xwing_num_2_6 = 0;
    int final_xwing_num_2_7 = 0;
    int final_xwing_num_2_8 = 0;
    int final_xwing_num_2_9 = 0;
//
    int xwing_in_col3_and_col4 = 0;
    int xwing_in_col3_and_col5 = 0;
    int xwing_in_col3_and_col6 = 0;
    int xwing_in_col3_and_col7 = 0;
    int xwing_in_col3_and_col8 = 0;
    int xwing_in_col3_and_col9 = 0;
    int xwing_col3_4_store[9] = {0};
    int xwing_col3_5_store[9] = {0};
    int xwing_col3_6_store[9] = {0};
    int xwing_col3_7_store[9] = {0};
    int xwing_col3_8_store[9] = {0};
    int xwing_col3_9_store[9] = {0};
    int final_xwing_num_3_4 = 0;
    int final_xwing_num_3_5 = 0;
    int final_xwing_num_3_6 = 0;
    int final_xwing_num_3_7 = 0;
    int final_xwing_num_3_8 = 0;
    int final_xwing_num_3_9 = 0;
//
    int xwing_in_col4_and_col7 = 0;
    int xwing_in_col4_and_col8 = 0;
    int xwing_in_col4_and_col9 = 0;
    int xwing_col4_7_store[9] = {0};
    int xwing_col4_8_store[9] = {0};
    int xwing_col4_9_store[9] = {0};
   int final_xwing_num_4_7 = 0;
    int final_xwing_num_4_8 = 0;
    int final_xwing_num_4_9 = 0;
//
    int xwing_in_col5_and_col7 = 0;
    int xwing_in_col5_and_col8 = 0;
    int xwing_in_col5_and_col9 = 0;
    int xwing_col5_7_store[9] = {0};
    int xwing_col5_8_store[9] = {0};
    int xwing_col5_9_store[9] = {0};
    int final_xwing_num_5_7 = 0;
    int final_xwing_num_5_8 = 0;
    int final_xwing_num_5_9 = 0;
//
    int xwing_in_col6_and_col7 = 0;
    int xwing_in_col6_and_col8 = 0;
    int xwing_in_col6_and_col9 = 0;
    int xwing_col6_7_store[9] = {0};
    int xwing_col6_8_store[9] = {0};
    int xwing_col6_9_store[9] = {0};
    int final_xwing_num_6_7 = 0;
    int final_xwing_num_6_8 = 0;
    int final_xwing_num_6_9 = 0;
//
//  For column 1...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=72; col+=9)
            {
            temp_col1[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 2...
    for (row=0; row<=8; ++row)
        {
        for (col=1; col<=73; col+=9)
            {
            temp_col2[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 3...
    for (row=0; row<=8; ++row)
        {
        for (col=2; col<=74; col+=9)
            {
            temp_col3[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 4...
    for (row=0; row<=8; ++row)
        {
        for (col=3; col<=75; col+=9)
            {
            temp_col4[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 5...
    for (row=0; row<=8; ++row)
        {
        for (col=4; col<=76; col+=9)
            {
            temp_col5[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 6...
    for (row=0; row<=8; ++row)
        {
        for (col=5; col<=77; col+=9)
            {
            temp_col6[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 7...
    for (row=0; row<=8; ++row)
        {
        for (col=6; col<=78; col+=9)
            {
            temp_col7[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 8...
    for (row=0; row<=8; ++row)
        {
        for (col=7; col<=79; col+=9)
            {
            temp_col8[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  For column 9...
    for (row=0; row<=8; ++row)
        {
        for (col=8; col<=80; col+=9)
            {
            temp_col9[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  find out if there are only 2 of one number in a column of the puzzle...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col1[row][col] != 0)
                {
                ++col1_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col2[row][col] != 0)
                {
                ++col2_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col3[row][col] != 0)
                {
                ++col3_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col4[row][col] != 0)
                {
                ++col4_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col5[row][col] != 0)
                {
                ++col5_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col6[row][col] != 0)
                {
                ++col6_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col7[row][col] != 0)
                {
                ++col7_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col8[row][col] != 0)
                {
                ++col8_count[row];
                }
            }
        }
//
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_col9[row][col] != 0)
                {
                ++col9_count[row];
                }
            }
        }
//
//  find out which columns there are only 2 of one number in the puzzle...
    for (x=0; x<=8; ++x)
        {
        if (col1_count[x] == 2)
            {
            set_col1_xwing_flag = 1;
            //printf("set_col1_xwing_flag = %d\n", set_col1_xwing_flag);
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (col2_count[x] == 2)
            {
            set_col2_xwing_flag = 1;
            //printf("set_col2_xwing_flag = %d\n", set_col2_xwing_flag);
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (col3_count[x] == 2)
            {
            set_col3_xwing_flag = 1;
            //printf("set_col3_xwing_flag = %d\n", set_col3_xwing_flag);
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (col4_count[x] == 2)
            {
            set_col4_xwing_flag = 1;
            //printf("set_col4_xwing_flag = %d\n", set_col4_xwing_flag);
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (col5_count[x] == 2)
            {
            set_col5_xwing_flag = 1;
            //printf("set_col5_xwing_flag = %d\n", set_col5_xwing_flag);
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (col6_count[x] == 2)
            {
            set_col6_xwing_flag = 1;
            //printf("set_col6_xwing_flag = %d\n", set_col6_xwing_flag);
            }
        }
//
//  find x-wing routine col 1...
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col4[row][col] != 0 && temp_col1[row][col] == temp_col4[row][col]
                    && col1_count[row] == 2 && col4_count[row] == 2)
                    {
                    ++xwing_col1_4_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_4_store[x] == 2)
                {
                final_xwing_num_1_4 = x;
                xwing_in_col1_and_col4 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col4[row][col] != 0 && temp_col1[row][col] == temp_col4[row][col]
                    && col1_count[row] == 2 && col4_count[row] == 2 && final_xwing_num_1_4 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col5[row][col] != 0 && temp_col1[row][col] == temp_col5[row][col]
                    && col1_count[row] == 2 && col5_count[row] == 2)
                    {
                    ++xwing_col1_5_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_5_store[x] == 2)
                {
                final_xwing_num_1_5 = x;
                xwing_in_col1_and_col5 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col5[row][col] != 0 && temp_col1[row][col] == temp_col5[row][col]
                    && col1_count[row] == 2 && col5_count[row] == 2 && final_xwing_num_1_5 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col6[row][col] != 0 && temp_col1[row][col] == temp_col6[row][col]
                    && col1_count[row] == 2 && col6_count[row] == 2)
                    {
                    ++xwing_col1_6_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_6_store[x] == 2)
                {
                final_xwing_num_1_6 = x;
                xwing_in_col1_and_col6 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col6[row][col] != 0 && temp_col1[row][col] == temp_col6[row][col]
                    && col1_count[row] == 2 && col6_count[row] == 2 && final_xwing_num_1_6 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col7[row][col] != 0 && temp_col1[row][col] == temp_col7[row][col]
                    && col1_count[row] == 2 && col7_count[row] == 2)
                    {
                    ++xwing_col1_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_7_store[x] == 2)
                {
                final_xwing_num_1_7 = x;
                xwing_in_col1_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col7[row][col] != 0 && temp_col1[row][col] == temp_col7[row][col]
                    && col1_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_1_7 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col8[row][col] != 0 && temp_col1[row][col] == temp_col8[row][col]
                    && col1_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col1_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_8_store[x] == 2)
                {
                final_xwing_num_1_8 = x;
                xwing_in_col1_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col8[row][col] != 0 && temp_col1[row][col] == temp_col8[row][col]
                    && col1_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_1_8 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col9[row][col] != 0 && temp_col1[row][col] == temp_col9[row][col]
                    && col1_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col1_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col1_9_store[x] == 2)
                {
                final_xwing_num_1_9 = x;
                xwing_in_col1_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col1_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col1[row][col] != 0 && temp_col9[row][col] != 0 && temp_col1[row][col] == temp_col9[row][col]
                    && col1_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_1_9 == row)
                    {
                    if (temp_col2[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 2...
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col4[row][col] != 0 && temp_col2[row][col] == temp_col4[row][col]
                    && col2_count[row] == 2 && col4_count[row] == 2)
                    {
                    ++xwing_col2_4_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_4_store[x] == 2)
                {
                final_xwing_num_2_4 = x;
                xwing_in_col2_and_col4 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col4[row][col] != 0 && temp_col2[row][col] == temp_col4[row][col]
                    && col2_count[row] == 2 && col4_count[row] == 2 && final_xwing_num_2_4 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col5[row][col] != 0 && temp_col2[row][col] == temp_col5[row][col]
                    && col2_count[row] == 2 && col5_count[row] == 2)
                    {
                    ++xwing_col2_5_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_5_store[x] == 2)
                {
                final_xwing_num_2_5 = x;
                xwing_in_col2_and_col5 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col5[row][col] != 0 && temp_col2[row][col] == temp_col5[row][col]
                    && col2_count[row] == 2 && col5_count[row] == 2 && final_xwing_num_2_5 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col6[row][col] != 0 && temp_col2[row][col] == temp_col6[row][col]
                    && col2_count[row] == 2 && col6_count[row] == 2)
                    {
                    ++xwing_col2_6_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_6_store[x] == 2)
                {
                final_xwing_num_2_6 = x;
                xwing_in_col2_and_col6 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col6[row][col] != 0 && temp_col2[row][col] == temp_col6[row][col]
                    && col2_count[row] == 2 && col6_count[row] == 2 && final_xwing_num_2_6 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col7[row][col] != 0 && temp_col2[row][col] == temp_col7[row][col]
                    && col2_count[row] == 2 && col7_count[row] == 2)
                    {
                    ++xwing_col2_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_7_store[x] == 2)
                {
                final_xwing_num_2_7 = x;
                xwing_in_col2_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col7[row][col] != 0 && temp_col2[row][col] == temp_col7[row][col]
                    && col2_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_2_7 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col8[row][col] != 0 && temp_col2[row][col] == temp_col8[row][col]
                    && col2_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col2_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_8_store[x] == 2)
                {
                final_xwing_num_2_8 = x;
                xwing_in_col2_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col8[row][col] != 0 && temp_col2[row][col] == temp_col8[row][col]
                    && col2_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_2_8 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col1[row][col] = 0;
                        //printf("temp_col1[%d][%d] = %d\n", row, col, temp_col1[row][col]);
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col3[row][col] = 0;
                        //printf("temp_col3[%d][%d] = %d\n", row, col, temp_col3[row][col]);
                        }
                    if (temp_col4[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col4[row][col] = 0;
                        //printf("temp_col4[%d][%d] = %d\n", row, col, temp_col4[row][col]);
                        }
                    if (temp_col5[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col5[row][col] = 0;
                        //printf("temp_col5[%d][%d] = %d\n", row, col, temp_col5[row][col]);
                        }
                    if (temp_col6[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col6[row][col] = 0;
                        //printf("temp_col6[%d][%d] = %d\n", row, col, temp_col6[row][col]);
                        }
                    if (temp_col7[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col7[row][col] = 0;
                        //printf("temp_col7[%d][%d] = %d\n", row, col, temp_col7[row][col]);
                        }
                    if (temp_col9[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_col9[row][col] = 0;
                        //printf("temp_col9[%d][%d] = %d\n", row, col, temp_col9[row][col]);
                        }
                    }
                }
            }
        }
//
//
    if (set_col2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col9[row][col] != 0 && temp_col2[row][col] == temp_col9[row][col]
                    && col2_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col2_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col2_9_store[x] == 2)
                {
                final_xwing_num_2_9 = x;
                xwing_in_col2_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col2_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col2[row][col] != 0 && temp_col9[row][col] != 0 && temp_col2[row][col] == temp_col9[row][col]
                    && col2_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_2_9 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 3...
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col4[row][col] != 0 && temp_col3[row][col] == temp_col4[row][col]
                    && col3_count[row] == 2 && col4_count[row] == 2)
                    {
                    ++xwing_col3_4_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_4_store[x] == 2)
                {
                final_xwing_num_3_4 = x;
                xwing_in_col3_and_col4 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col4[row][col] != 0 && temp_col3[row][col] == temp_col4[row][col]
                    && col3_count[row] == 2 && col4_count[row] == 2 && final_xwing_num_3_4 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 3...
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col5[row][col] != 0 && temp_col3[row][col] == temp_col5[row][col]
                    && col3_count[row] == 2 && col5_count[row] == 2)
                    {
                    ++xwing_col3_5_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_5_store[x] == 2)
                {
                final_xwing_num_3_5 = x;
                xwing_in_col3_and_col5 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col5[row][col] != 0 && temp_col3[row][col] == temp_col5[row][col]
                    && col3_count[row] == 2 && col5_count[row] == 2 && final_xwing_num_3_5 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col6[row][col] != 0 && temp_col3[row][col] == temp_col6[row][col]
                    && col3_count[row] == 2 && col6_count[row] == 2)
                    {
                    ++xwing_col3_6_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_6_store[x] == 2)
                {
                final_xwing_num_3_6 = x;
                xwing_in_col3_and_col6 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col6[row][col] != 0 && temp_col3[row][col] == temp_col6[row][col]
                    && col3_count[row] == 2 && col6_count[row] == 2 && final_xwing_num_3_6 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col7[row][col] != 0 && temp_col3[row][col] == temp_col7[row][col]
                    && col3_count[row] == 2 && col7_count[row] == 2)
                    {
                    ++xwing_col3_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_7_store[x] == 2)
                {
                final_xwing_num_3_7 = x;
                xwing_in_col3_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col7[row][col] != 0 && temp_col3[row][col] == temp_col7[row][col]
                    && col3_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_3_7 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col8[row][col] != 0 && temp_col3[row][col] == temp_col8[row][col]
                    && col3_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col3_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_8_store[x] == 2)
                {
                final_xwing_num_3_8 = x;
                xwing_in_col3_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col8[row][col] != 0 && temp_col3[row][col] == temp_col8[row][col]
                    && col3_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_3_8 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col9[row][col] != 0 && temp_col3[row][col] == temp_col9[row][col]
                    && col3_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col3_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col3_9_store[x] == 2)
                {
                final_xwing_num_3_9 = x;
                xwing_in_col3_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col3_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col3[row][col] != 0 && temp_col9[row][col] != 0 && temp_col3[row][col] == temp_col9[row][col]
                    && col3_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_3_9 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 4...
    if (set_col4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col7[row][col] != 0 && temp_col4[row][col] == temp_col7[row][col]
                    && col4_count[row] == 2 && col7_count[row] == 2)
                    {
                    ++xwing_col4_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col4_7_store[x] == 2)
                {
                final_xwing_num_4_7 = x;
                xwing_in_col4_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col4_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col7[row][col] != 0 && temp_col4[row][col] == temp_col7[row][col]
                    && col4_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_4_7 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_col4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col8[row][col] != 0 && temp_col4[row][col] == temp_col8[row][col]
                    && col4_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col4_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col4_8_store[x] == 2)
                {
                final_xwing_num_4_8 = x;
                xwing_in_col4_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col4_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col8[row][col] != 0 && temp_col4[row][col] == temp_col8[row][col]
                    && col4_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_4_8 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_col4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col9[row][col] != 0 && temp_col4[row][col] == temp_col9[row][col]
                    && col4_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col4_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col4_9_store[x] == 2)
                {
                final_xwing_num_4_9 = x;
                xwing_in_col4_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col4_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col4[row][col] != 0 && temp_col9[row][col] != 0 && temp_col4[row][col] == temp_col9[row][col]
                    && col4_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_4_9 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 5...
    if (set_col5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col7[row][col] != 0 && temp_col5[row][col] == temp_col7[row][col]
                    && col5_count[row] == 2 && col7_count[row] == 2)
                    {
                    ++xwing_col5_7_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_col5_7_store[x] == 2)
                {
                final_xwing_num_5_7 = x;
                xwing_in_col5_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col5_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col7[row][col] != 0 && temp_col5[row][col] == temp_col7[row][col]
                    && col5_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_5_7 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col1[row][col] = 0;
                        //printf("temp_col1[%d][%d] = %d\n", row, col, temp_col1[row][col]);
                        }
                    if (temp_col2[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col2[row][col] = 0;
                        //printf("temp_col2[%d][%d] = %d\n", row, col, temp_col2[row][col]);
                        }
                    if (temp_col3[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col3[row][col] = 0;
                        //printf("temp_col3[%d][%d] = %d\n", row, col, temp_col3[row][col]);
                        }
                    if (temp_col4[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col4[row][col] = 0;
                        //printf("temp_col4[%d][%d] = %d\n", row, col, temp_col4[row][col]);
                        }
                    if (temp_col6[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col6[row][col] = 0;
                        //printf("temp_col6[%d][%d] = %d\n", row, col, temp_col6[row][col]);
                        }
                    if (temp_col8[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col8[row][col] = 0;
                        //printf("temp_col8[%d][%d] = %d\n", row, col, temp_col8[row][col]);
                        }
                    if (temp_col9[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_col9[row][col] = 0;
                        //printf("temp_col9[%d][%d] = %d\n", row, col, temp_col9[row][col]);
                        }
                    }
                }
            }
        }
//
//
    if (set_col5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col8[row][col] != 0 && temp_col5[row][col] == temp_col8[row][col]
                    && col5_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col5_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col5_8_store[x] == 2)
                {
                final_xwing_num_5_8 = x;
                xwing_in_col5_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col5_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col8[row][col] != 0 && temp_col5[row][col] == temp_col8[row][col]
                    && col5_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_5_8 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col6[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col6[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col9[row][col] != 0 && temp_col5[row][col] == temp_col9[row][col]
                    && col5_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col5_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col5_9_store[x] == 2)
                {
                final_xwing_num_5_9 = x;
                xwing_in_col5_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col5_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col5[row][col] != 0 && temp_col9[row][col] != 0 && temp_col5[row][col] == temp_col9[row][col]
                    && col5_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_5_9 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col1[row][col] = 0;
                        //printf("temp_col1[%d][%d] = %d\n", row, col, temp_col1[row][col]);
                        }
                    if (temp_col2[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col2[row][col] = 0;
                        //printf("temp_col2[%d][%d] = %d\n", row, col, temp_col2[row][col]);
                        }
                    if (temp_col3[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col3[row][col] = 0;
                        //printf("temp_col3[%d][%d] = %d\n", row, col, temp_col3[row][col]);
                        }
                    if (temp_col4[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col4[row][col] = 0;
                        //printf("temp_col4[%d][%d] = %d\n", row, col, temp_col4[row][col]);
                        }
                    if (temp_col6[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col6[row][col] = 0;
                        //printf("temp_col6[%d][%d] = %d\n", row, col, temp_col6[row][col]);
                        }
                    if (temp_col7[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col7[row][col] = 0;
                        //printf("temp_col7[%d][%d] = %d\n", row, col, temp_col7[row][col]);
                        }
                    if (temp_col8[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_col8[row][col] = 0;
                        //printf("temp_col8[%d][%d] = %d\n", row, col, temp_col8[row][col]);
                        }
                    }
                }
            }
        }
//
//  **************************************************************************
//  //  find x-wing routine col 6...
//  **************************************************************************
//
    if (set_col6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col7[row][col] != 0 && temp_col6[row][col] == temp_col7[row][col]
                    && col6_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col6_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col6_7_store[x] == 2)
                {
                final_xwing_num_6_7 = x;
                xwing_in_col6_and_col7 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col6_and_col7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col7[row][col] != 0 && temp_col6[row][col] == temp_col7[row][col]
                    && col6_count[row] == 2 && col7_count[row] == 2 && final_xwing_num_6_7 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  **************************************************************************
//  //  find x-wing routine col 6...
//  **************************************************************************
//
    if (set_col6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col8[row][col] != 0 && temp_col6[row][col] == temp_col8[row][col]
                    && col6_count[row] == 2 && col8_count[row] == 2)
                    {
                    ++xwing_col6_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col6_8_store[x] == 2)
                {
                final_xwing_num_6_8 = x;
                xwing_in_col6_and_col8 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col6_and_col8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col8[row][col] != 0 && temp_col6[row][col] == temp_col8[row][col]
                    && col6_count[row] == 2 && col8_count[row] == 2 && final_xwing_num_6_8 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col9[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_col9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//
    if (set_col6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col9[row][col] != 0 && temp_col6[row][col] == temp_col9[row][col]
                    && col6_count[row] == 2 && col9_count[row] == 2)
                    {
                    ++xwing_col6_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_col6_9_store[x] == 2)
                {
                final_xwing_num_6_9 = x;
                xwing_in_col6_and_col9 = 1;
                xwing_found = 1;
                }
            }
        }
//
    if (xwing_in_col6_and_col9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_col6[row][col] != 0 && temp_col9[row][col] != 0 && temp_col6[row][col] == temp_col9[row][col]
                    && col6_count[row] == 2 && col9_count[row] == 2 && final_xwing_num_6_9 == row)
                    {
                    if (temp_col1[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col1[row][col] = 0;
                        }
                    if (temp_col2[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col2[row][col] = 0;
                        }
                    if (temp_col3[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col3[row][col] = 0;
                        }
                    if (temp_col4[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col4[row][col] = 0;
                        }
                    if (temp_col5[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col5[row][col] = 0;
                        }
                    if (temp_col7[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col7[row][col] = 0;
                        }
                    if (temp_col8[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_col8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  put temp column 6 back to real column...
    if (xwing_found == 1)
        {
        c=0;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col1[row][col];
                c+=9;
                }
            c=0;
            }
        }
 
//
        c=1;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col2[row][col];
                c+=9;
                }
            c=1;
            }
//
        c=2;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col3[row][col];
                c+=9;
                }
            c=2;
            }
//
        c=3;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col4[row][col];
                c+=9;
                }
            c=3;
            }
//
        c=4;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col5[row][col];
                c+=9;
                }
            c=4;
            }
//
        c=5;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col6[row][col];
                c+=9;
                }
            c=5;
            }
//
        c=6;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col7[row][col];
                c+=9;
                }
            c=6;
            }
//
        c=7;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col8[row][col];
                c+=9;
                }
            c=7;
            }
//
        c=8;
        for (row=0; row<=8; ++row)
            {
            for (col=0; col<=8; ++col)
                {
                puzzle_note_pad[row][c] = temp_col9[row][col];
                c+=9;
                }
            c=8;
            }
//
}
void find_xwing_in_puzzle_rows (int puzzle_note_pad[][81])
//  Function to ...
{
//
//  Function to apply the x-wing solving techniques in ROWS for the whole puzzle.
//  This probably could do with re-factoring over time. It could be broken down into
//  smaller functions.
//
    int row=0;
    int col=0;
    int c=0;
    int x=0;
//
    int temp_row1 [9][9] = {{0}};
    int temp_row2 [9][9] = {{0}};
    int temp_row3 [9][9] = {{0}};
    int temp_row4 [9][9] = {{0}};
    int temp_row5 [9][9] = {{0}};
    int temp_row6 [9][9] = {{0}};
    int temp_row7 [9][9] = {{0}};
    int temp_row8 [9][9] = {{0}};
    int temp_row9 [9][9] = {{0}};
//
    int row1_count[9] = {0};
    int row2_count[9] = {0};
    int row3_count[9] = {0};
    int row4_count[9] = {0};
    int row5_count[9] = {0};
    int row6_count[9] = {0};
    int row7_count[9] = {0};
    int row8_count[9] = {0};
    int row9_count[9] = {0};
//
    int set_row1_xwing_flag = 0;
    int set_row2_xwing_flag = 0;
    int set_row3_xwing_flag = 0;
    int set_row4_xwing_flag = 0;
    int set_row5_xwing_flag = 0;
    int set_row6_xwing_flag = 0;
//
    int xwing_in_row1_and_row4 = 0;
    int xwing_in_row1_and_row5 = 0;
    int xwing_in_row1_and_row6 = 0;
    int xwing_in_row1_and_row7 = 0;
    int xwing_in_row1_and_row8 = 0;
    int xwing_in_row1_and_row9 = 0;
    int xwing_row1_4_store[9] = {0};
    int xwing_row1_5_store[9] = {0};
    int xwing_row1_6_store[9] = {0};
    int xwing_row1_7_store[9] = {0};
    int xwing_row1_8_store[9] = {0};
    int xwing_row1_9_store[9] = {0};
    int final_xwing_num_1_4 = 0;
    int final_xwing_num_1_5 = 0;
    int final_xwing_num_1_6 = 0;
    int final_xwing_num_1_7 = 0;
    int final_xwing_num_1_8 = 0;
    int final_xwing_num_1_9 = 0;
//
    int xwing_in_row2_and_row4 = 0;
    int xwing_in_row2_and_row5 = 0;
    int xwing_in_row2_and_row6 = 0;
    int xwing_in_row2_and_row7 = 0;
    int xwing_in_row2_and_row8 = 0;
    int xwing_in_row2_and_row9 = 0;
    int xwing_row2_4_store[9] = {0};
    int xwing_row2_5_store[9] = {0};
    int xwing_row2_6_store[9] = {0};
    int xwing_row2_7_store[9] = {0};
    int xwing_row2_8_store[9] = {0};
    int xwing_row2_9_store[9] = {0};
    int final_xwing_num_2_4 = 0;
    int final_xwing_num_2_5 = 0;
    int final_xwing_num_2_6 = 0;
    int final_xwing_num_2_7 = 0;
    int final_xwing_num_2_8 = 0;
    int final_xwing_num_2_9 = 0;
//
    int xwing_in_row3_and_row4 = 0;
    int xwing_in_row3_and_row5 = 0;
    int xwing_in_row3_and_row6 = 0;
    int xwing_in_row3_and_row7 = 0;
    int xwing_in_row3_and_row8 = 0;
    int xwing_in_row3_and_row9 = 0;
    int xwing_row3_4_store[9] = {0};
    int xwing_row3_5_store[9] = {0};
    int xwing_row3_6_store[9] = {0};
    int xwing_row3_7_store[9] = {0};
    int xwing_row3_8_store[9] = {0};
    int xwing_row3_9_store[9] = {0};
    int final_xwing_num_3_4 = 0;
    int final_xwing_num_3_5 = 0;
    int final_xwing_num_3_6 = 0;
    int final_xwing_num_3_7 = 0;
    int final_xwing_num_3_8 = 0;
    int final_xwing_num_3_9 = 0;
//
    int xwing_in_row4_and_row7 = 0;
    int xwing_in_row4_and_row8 = 0;
    int xwing_in_row4_and_row9 = 0;
    int xwing_row4_7_store[9] = {0};
    int xwing_row4_8_store[9] = {0};
    int xwing_row4_9_store[9] = {0};
    int final_xwing_num_4_7 = 0;
    int final_xwing_num_4_8 = 0;
    int final_xwing_num_4_9 = 0;
//
    int xwing_in_row5_and_row7 = 0;
    int xwing_in_row5_and_row8 = 0;
    int xwing_in_row5_and_row9 = 0;
    int xwing_row5_7_store[9] = {0};
    int xwing_row5_8_store[9] = {0};
    int xwing_row5_9_store[9] = {0};
    int final_xwing_num_5_7 = 0;
    int final_xwing_num_5_8 = 0;
    int final_xwing_num_5_9 = 0;
//
    int xwing_in_row6_and_row7 = 0;
    int xwing_in_row6_and_row8 = 0;
    int xwing_in_row6_and_row9 = 0;
    int xwing_row6_7_store[9] = {0};
    int xwing_row6_8_store[9] = {0};
    int xwing_row6_9_store[9] = {0};
    int final_xwing_num_6_7 = 0;
    int final_xwing_num_6_8 = 0;
    int final_xwing_num_6_9 = 0;
//
//  Temp Row 1  ...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            temp_row1[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 2 ...
    for (row=0; row<=8; ++row)
        {
        for (col=9; col<=17; ++col)
            {
            temp_row2[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 3 ...
    for (row=0; row<=8; ++row)
        {
        for (col=18; col<=26; ++col)
            {
            temp_row3[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 4 ...
    for (row=0; row<=8; ++row)
        {
        for (col=27; col<=35; ++col)
            {
            temp_row4[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 5 ...
    for (row=0; row<=8; ++row)
        {
        for (col=36; col<=44; ++col)
            {
            temp_row5[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 6 ...
    for (row=0; row<=8; ++row)
        {
        for (col=45; col<=53; ++col)
            {
            temp_row6[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 7 ...
    for (row=0; row<=8; ++row)
        {
        for (col=54; col<=62; ++col)
            {
            temp_row7[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 8 ...
    for (row=0; row<=8; ++row)
        {
        for (col=63; col<=71; ++col)
            {
            temp_row8[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  Temp Row 9 ...
    for (row=0; row<=8; ++row)
        {
        for (col=72; col<=80; ++col)
            {
            temp_row9[row][c] = puzzle_note_pad[row][col];
            ++c;
            }
        c=0;
        }
//
//  find out if there are only 2 of one number in a column of the puzzle...
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row1[row][col] != 0)
                {
                ++row1_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row2[row][col] != 0)
                {
                ++row2_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row3[row][col] != 0)
                {
                ++row3_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row4[row][col] != 0)
                {
                ++row4_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row5[row][col] != 0)
                {
                ++row5_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row6[row][col] != 0)
                {
                ++row6_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row7[row][col] != 0)
                {
                ++row7_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row8[row][col] != 0)
                {
                ++row8_count[row];
                }
            }
        }
//
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            if (temp_row9[row][col] != 0)
                {
                ++row9_count[row];
                }
            }
        }
//
//  find out which columns there are only 2 of one number in the puzzle...
    for (x=0; x<=8; ++x)
        {
        if (row1_count[x] == 2)
            {
            set_row1_xwing_flag = 1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (row2_count[x] == 2)
            {
            set_row2_xwing_flag = 1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (row3_count[x] == 2)
            {
            set_row3_xwing_flag = 1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (row4_count[x] == 2)
            {
            set_row4_xwing_flag = 1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (row5_count[x] == 2)
            {
            set_row5_xwing_flag = 1;
            }
        }
//
    for (x=0; x<=8; ++x)
        {
        if (row6_count[x] == 2)
            {
            set_row6_xwing_flag = 1;
            }
        }
//
//  find x-wing routine col 1...
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row4[row][col] != 0 && temp_row1[row][col] == temp_row4[row][col]
                    && row1_count[row] == 2 && row4_count[row] == 2)
                    {
                    ++xwing_row1_4_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_4_store[x] == 2)
                {
                final_xwing_num_1_4 = x;
                xwing_in_row1_and_row4 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row4[row][col] != 0 && temp_row1[row][col] == temp_row4[row][col]
                    && row1_count[row] == 2 && row4_count[row] == 2 && final_xwing_num_1_4 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_1_4+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row5[row][col] != 0 && temp_row1[row][col] == temp_row5[row][col]
                    && row1_count[row] == 2 && row5_count[row] == 2)
                    {
                    ++xwing_row1_5_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_5_store[x] == 2)
                {
                final_xwing_num_1_5 = x;
                xwing_in_row1_and_row5 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row5[row][col] != 0 && temp_row1[row][col] == temp_row5[row][col]
                    && row1_count[row] == 2 && row5_count[row] == 2 && final_xwing_num_1_5 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_1_5+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row6[row][col] != 0 && temp_row1[row][col] == temp_row6[row][col]
                    && row1_count[row] == 2 && row6_count[row] == 2)
                    {
                    ++xwing_row1_6_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_6_store[x] == 2)
                {
                final_xwing_num_1_6 = x;
                xwing_in_row1_and_row6 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row6[row][col] != 0 && temp_row1[row][col] == temp_row6[row][col]
                    && row1_count[row] == 2 && row6_count[row] == 2 && final_xwing_num_1_6 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_1_6+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row7[row][col] != 0 && temp_row1[row][col] == temp_row7[row][col]
                    && row1_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row1_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_7_store[x] == 2)
                {
                final_xwing_num_1_7 = x;
                xwing_in_row1_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row7[row][col] != 0 && temp_row1[row][col] == temp_row7[row][col]
                    && row1_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_1_7 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_1_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row8[row][col] != 0 && temp_row1[row][col] == temp_row8[row][col]
                    && row1_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row1_8_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_8_store[x] == 2)
                {
                final_xwing_num_1_8 = x;
                xwing_in_row1_and_row8 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row8[row][col] != 0 && temp_row1[row][col] == temp_row8[row][col]
                    && row1_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_1_8 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_1_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row1_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row9[row][col] != 0 && temp_row1[row][col] == temp_row9[row][col]
                    && row1_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row1_9_store[row];
                    }
               }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row1_9_store[x] == 2)
                {
                final_xwing_num_1_9 = x;
                xwing_in_row1_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row1_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row1[row][col] != 0 && temp_row9[row][col] != 0 && temp_row1[row][col] == temp_row9[row][col]
                    && row1_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_1_9 == row)
                    {
                    if (temp_row2[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_1_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 2...
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row4[row][col] != 0 && temp_row2[row][col] == temp_row4[row][col]
                    && row2_count[row] == 2 && row4_count[row] == 2)
                    {
                    ++xwing_row2_4_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_4_store[x] == 2)
                {
                final_xwing_num_2_4 = x;
                xwing_in_row2_and_row4 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row4[row][col] != 0 && temp_row2[row][col] == temp_row4[row][col]
                    && row2_count[row] == 2 && row4_count[row] == 2 && final_xwing_num_2_4 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_2_4+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row5[row][col] != 0 && temp_row2[row][col] == temp_row5[row][col]
                    && row2_count[row] == 2 && row5_count[row] == 2)
                    {
                    ++xwing_row2_5_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_5_store[x] == 2)
                {
                final_xwing_num_2_5 = x;
                xwing_in_row2_and_row5 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row5[row][col] != 0 && temp_row2[row][col] == temp_row5[row][col]
                    && row2_count[row] == 2 && row5_count[row] == 2 && final_xwing_num_2_5 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_2_5+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row6[row][col] != 0 && temp_row2[row][col] == temp_row6[row][col]
                    && row2_count[row] == 2 && row6_count[row] == 2)
                    {
                    ++xwing_row2_6_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_6_store[x] == 2)
                {
                final_xwing_num_2_6 = x;
                xwing_in_row2_and_row6 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row6[row][col] != 0 && temp_row2[row][col] == temp_row6[row][col]
                    && row2_count[row] == 2 && row6_count[row] == 2 && final_xwing_num_2_6 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_2_6+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row7[row][col] != 0 && temp_row2[row][col] == temp_row7[row][col]
                    && row2_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row2_7_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_7_store[x] == 2)
                {
                final_xwing_num_2_7 = x;
                xwing_in_row2_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row7[row][col] != 0 && temp_row2[row][col] == temp_row7[row][col]
                    && row2_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_2_7 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_2_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row8[row][col] != 0 && temp_row2[row][col] == temp_row8[row][col]
                    && row2_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row2_8_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_8_store[x] == 2)
                {
                final_xwing_num_2_8 = x;
                xwing_in_row2_and_row8 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row8[row][col] != 0 && temp_row2[row][col] == temp_row8[row][col]
                    && row2_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_2_8 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_2_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row2_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row9[row][col] != 0 && temp_row2[row][col] == temp_row9[row][col]
                    && row2_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row2_9_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row2_9_store[x] == 2)
                {
                final_xwing_num_2_9 = x;
                xwing_in_row2_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row2_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row2[row][col] != 0 && temp_row9[row][col] != 0 && temp_row2[row][col] == temp_row9[row][col]
                    && row2_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_2_9 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_2_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine row 3...
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row4[row][col] != 0 && temp_row3[row][col] == temp_row4[row][col]
                    && row3_count[row] == 2 && row4_count[row] == 2)
                    {
                    ++xwing_row3_4_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_4_store[x] == 2)
                {
                final_xwing_num_3_4 = x;
                xwing_in_row3_and_row5 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row4 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row4[row][col] != 0 && temp_row3[row][col] == temp_row4[row][col]
                    && row3_count[row] == 2 && row4_count[row] == 2 && final_xwing_num_3_4 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_3_4+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine row 3...
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row5[row][col] != 0 && temp_row3[row][col] == temp_row5[row][col]
                    && row3_count[row] == 2 && row5_count[row] == 2)
                    {
                    ++xwing_row3_5_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_5_store[x] == 2)
                {
                final_xwing_num_3_5 = x;
                xwing_in_row3_and_row5 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row5 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row5[row][col] != 0 && temp_row3[row][col] == temp_row5[row][col]
                    && row3_count[row] == 2 && row5_count[row] == 2 && final_xwing_num_3_5 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_3_5+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row6[row][col] != 0 && temp_row3[row][col] == temp_row6[row][col]
                    && row3_count[row] == 2 && row6_count[row] == 2)
                    {
                    ++xwing_row3_6_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_6_store[x] == 2)
                {
                final_xwing_num_3_6 = x;
                xwing_in_row3_and_row6 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row6 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row6[row][col] != 0 && temp_row3[row][col] == temp_row6[row][col]
                    && row3_count[row] == 2 && row6_count[row] == 2 && final_xwing_num_3_6 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_3_6+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row7[row][col] != 0 && temp_row3[row][col] == temp_row7[row][col]
                    && row3_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row3_7_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_7_store[x] == 2)
                {
                final_xwing_num_3_7 = x;
                xwing_in_row3_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row7[row][col] != 0 && temp_row3[row][col] == temp_row7[row][col]
                    && row3_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_3_7 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_3_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row8[row][col] != 0 && temp_row3[row][col] == temp_row8[row][col]
                    && row3_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row3_8_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_8_store[x] == 2)
                {
                final_xwing_num_3_8 = x;
                xwing_in_row3_and_row8 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row8[row][col] != 0 && temp_row3[row][col] == temp_row8[row][col]
                    && row3_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_3_8 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_3_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row3_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row9[row][col] != 0 && temp_row3[row][col] == temp_row9[row][col]
                    && row3_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row3_9_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row3_9_store[x] == 2)
                {
                final_xwing_num_3_9 = x;
                xwing_in_row3_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row3_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row3[row][col] != 0 && temp_row9[row][col] != 0 && temp_row3[row][col] == temp_row9[row][col]
                    && row3_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_3_9 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_3_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 4...
    if (set_row4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row7[row][col] != 0 && temp_row4[row][col] == temp_row7[row][col]
                    && row4_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row4_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row4_7_store[x] == 2)
                {
                final_xwing_num_4_7 = x;
                xwing_in_row4_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row4_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row7[row][col] != 0 && temp_row4[row][col] == temp_row7[row][col]
                    && row4_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_4_7 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_4_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row8[row][col] != 0 && temp_row4[row][col] == temp_row8[row][col]
                    && row4_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row4_8_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row4_8_store[x] == 2)
                {
                final_xwing_num_4_8 = x;
                xwing_in_row4_and_row8 = 1;
                //printf("xwing_in_row4_and_row8 = %d\n", xwing_in_row4_and_row8);
                }
            }
        }
//
    if (xwing_in_row4_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row8[row][col] != 0 && temp_row4[row][col] == temp_row8[row][col]
                    && row4_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_4_8 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_4_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row4_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row9[row][col] != 0 && temp_row4[row][col] == temp_row9[row][col]
                    && row4_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row4_9_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row4_9_store[x] == 2)
                {
                final_xwing_num_4_9 = x;
                xwing_in_row4_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row4_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row4[row][col] != 0 && temp_row9[row][col] != 0 && temp_row4[row][col] == temp_row9[row][col]
                    && row4_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_4_9 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_4_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine col 5...
    if (set_row5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row7[row][col] != 0 && temp_row5[row][col] == temp_row7[row][col]
                    && row5_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row5_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row5_7_store[x] == 2)
                {
                final_xwing_num_5_7 = x;
                xwing_in_row5_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row5_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row7[row][col] != 0 && temp_row5[row][col] == temp_row7[row][col]
                    && row5_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_5_7 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_5_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row8[row][col] != 0 && temp_row5[row][col] == temp_row8[row][col]
                    && row5_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row5_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row5_8_store[x] == 2)
                {
                final_xwing_num_5_8 = x;
                xwing_in_row5_and_row8 = 1;
                }
            }
        }
//
    if (xwing_in_row5_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row8[row][col] != 0 && temp_row5[row][col] == temp_row8[row][col]
                    && row5_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_5_8 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_5_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row5_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row9[row][col] != 0 && temp_row5[row][col] == temp_row9[row][col]
                    && row5_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row5_9_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row5_9_store[x] == 2)
                {
                final_xwing_num_5_9 = x;
                xwing_in_row5_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row5_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row5[row][col] != 0 && temp_row9[row][col] != 0 && temp_row5[row][col] == temp_row9[row][col]
                    && row5_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_5_9 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row6[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row6[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_5_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//***********************************************************************
//  find x-wing routine col 6...
    if (set_row6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row7[row][col] != 0 && temp_row6[row][col] == temp_row7[row][col]
                    && row6_count[row] == 2 && row7_count[row] == 2)
                    {
                    ++xwing_row6_7_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row6_7_store[x] == 2)
                {
                final_xwing_num_6_7 = x;
                xwing_in_row6_and_row7 = 1;
                }
            }
        }
//
    if (xwing_in_row6_and_row7 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row7[row][col] != 0 && temp_row6[row][col] == temp_row7[row][col]
                    && row6_count[row] == 2 && row7_count[row] == 2 && final_xwing_num_6_7 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_6_7+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
//  find x-wing routine row 6...
    if (set_row6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row8[row][col] != 0 && temp_row6[row][col] == temp_row8[row][col]
                    && row6_count[row] == 2 && row8_count[row] == 2)
                    {
                    ++xwing_row6_8_store[row];
                    }
                }
            }
        for (x=0; x<=8; ++x)
            {
            if (xwing_row6_8_store[x] == 2)
                {
                final_xwing_num_6_8 = x;
                xwing_in_row6_and_row8 = 1;
                }
            }
        }
//
    if (xwing_in_row6_and_row8 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row8[row][col] != 0 && temp_row6[row][col] == temp_row8[row][col]
                    && row6_count[row] == 2 && row8_count[row] == 2 && final_xwing_num_6_8 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row9[row][col] == final_xwing_num_6_8+1)
                        {
                        temp_row9[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    if (set_row6_xwing_flag == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row9[row][col] != 0 && temp_row6[row][col] == temp_row9[row][col]
                    && row6_count[row] == 2 && row9_count[row] == 2)
                    {
                    ++xwing_row6_9_store[row];
                    }
                }
            }
//
        for (x=0; x<=8; ++x)
            {
            if (xwing_row6_9_store[x] == 2)
                {
                final_xwing_num_6_9 = x;
                xwing_in_row6_and_row9 = 1;
                }
            }
        }
//
    if (xwing_in_row6_and_row9 == 1)
        {
        for (row=0; row<=8; ++row)
            {
           for (col=0; col<=8; ++col)
                {
                if (temp_row6[row][col] != 0 && temp_row9[row][col] != 0 && temp_row6[row][col] == temp_row9[row][col]
                    && row6_count[row] == 2 && row9_count[row] == 2 && final_xwing_num_6_9 == row)
                    {
                    if (temp_row1[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row1[row][col] = 0;
                        }
                    if (temp_row2[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row2[row][col] = 0;
                        }
                    if (temp_row3[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row3[row][col] = 0;
                        }
                    if (temp_row4[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row4[row][col] = 0;
                        }
                    if (temp_row5[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row5[row][col] = 0;
                        }
                    if (temp_row7[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row7[row][col] = 0;
                        }
                    if (temp_row8[row][col] == final_xwing_num_6_9+1)
                        {
                        temp_row8[row][col] = 0;
                        }
                    }
                }
            }
        }
//
    c=0;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row1[row][col];
            ++c;
            }
        c=0;
        }
//
    c=9;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row2[row][col];
            ++c;
            }
        c=9;
        }
//
//
    c=18;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row3[row][col];
            ++c;
            }
        c=18;
        }
//
    c=27;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row4[row][col];
            ++c;
            }
        c=27;
        }
//
    c=36;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row5[row][col];
            ++c;
            }
        c=36;
        }
//
    c=45;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row6[row][col];
            ++c;
            }
        c=45;
        }
//
    c=54;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row7[row][col];
            ++c;
            }
        c=54;
        }
//
    c=63;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row8[row][col];
            ++c;
            }
        c=63;
        }
//
    c=72;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_note_pad[row][c] = temp_row9[row][col];
            ++c;
            }
        c=72;
        }
//
}
//
//
