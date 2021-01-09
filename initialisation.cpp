//
//  initialisation.cpp
//  Sudoku
//
//  Created by Peter Jeffs on 21/12/2020.
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"
using namespace std;
//
int puzzle_number_count (int puzzle_numbers[])
//  Function to count numbers in the whole puzzle.
{
//
    int index=0;
    int puzzle_number_count=0;
//
    for (index=0; index<=80; ++index)
        {
        if (puzzle_numbers[index] != 0)
            {
            ++puzzle_number_count;
            }
        }
//
    return puzzle_number_count;
//
}
//
void fill_puzzle_square (int puzzle_square[][9], int puzzle_numbers[])
//  Take the sudoku puzzle square and fill it with known puzzle numbers (any stage).
{
    int row = 0;
    int col = 0;
    int puzzle_number_position = 0;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=8; ++col)
            {
            puzzle_square[row][col] = puzzle_numbers[puzzle_number_position];
            ++puzzle_number_position;
            }
        }
}
//
void puzzle_note_pad_initialised_with_1_to_9 (int puzzle_note_pad[][81])
//  Initialise the puzzle note pad with numbers 1-9, i.e. all the possible combinations for a square.
{
    int row=0;
    int col=0;
    int the_initialised_number = 1;
    for (row=0; row<=8; ++row)
        {
        for (col=0; col<=80; ++col)
            {
            puzzle_note_pad[row][col] = the_initialised_number;
            }
        ++the_initialised_number;
        }
}
//
void initialise_number_in_note_pad_col (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Put the Sudoku puzzle number into the puzzle_note_pad column.
{
    int puzzle_number_position=0;
    int row=0;
    for (puzzle_number_position=0; puzzle_number_position<=80; ++puzzle_number_position)
        {
        //  cout << "Number =  " << puzzle_number_position << endl;
        if (puzzle_numbers[puzzle_number_position] != 0)
            {
            for (row=0; row<=8; ++row)
                {
                puzzle_note_pad[row][puzzle_number_position] = 0;
                }
            }
        //puzzle_note_pad[puzzle_numbers[puzzle_number_position]-1][puzzle_number_position] = puzzle_numbers[puzzle_number_position];
        // cout << "number is = " << puzzle_number_position << endl;
        // cout << "number is = " << puzzle_numbers[puzzle_number_position] << endl;
        }
    for (puzzle_number_position=0; puzzle_number_position<=80; ++puzzle_number_position)
        {
        if (puzzle_numbers[puzzle_number_position] != 0)
            {
            puzzle_note_pad[puzzle_numbers[puzzle_number_position]-1][puzzle_number_position] = puzzle_numbers[puzzle_number_position];
            // cout << "puzzle number = " << puzzle_numbers[puzzle_number_position] << endl;
            }
        }
    //  cout << "we did get here? ..." << endl;
}
//
void initialise_note_pad_by_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int range_start, int range_stop)
//  Put the Sudoku puzzle number into the puzzle_note_pad by puzzle row.
{
    int index=0;
    int col=0;
//
    for (index=range_start; index<=range_stop; ++index)
        {
            if (puzzle_numbers[index] != 0)
            {
                for (col=range_start; col<=range_stop; ++col)
                {
                    puzzle_note_pad[puzzle_numbers[index]-1][col] = 0;
                }
            }
        }
    for (index=range_start; index<=range_stop; ++index)
        {
            if (puzzle_numbers[index] != 0)
                {
                puzzle_note_pad[puzzle_numbers[index]-1][index] = puzzle_numbers[index];
                }

        }
}
//
void initialise_note_pad_by_puzzle_col (int puzzle_note_pad[][81], int puzzle_numbers[], int range_start, int range_stop)
//  Put the Sudoku puzzle number into the puzzle_note_pad by puzzle col.
{
    int index=0;
    int col=0;
    for (index=range_start; index<=range_stop; index+=9)
        {
            if (puzzle_numbers[index] != 0)
                {
                for (col=range_start; col<=range_stop; col+=9)
                    {
                    puzzle_note_pad[puzzle_numbers[index]-1][col] = 0;
                    }
                }
        }
//
    for (index=range_start; index<=range_stop; index+=9)
        {
            if (puzzle_numbers[index] != 0)
                {
                puzzle_note_pad[puzzle_numbers[index]-1][index] = puzzle_numbers[index];
                }
        }
//
}
//
void initialise_note_pad_row_by_puzzle_tiles (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Put the Sudoku puzzle number into the puzzle_note_pad tile.
{
    int col=0;
    int spno_c=0;
    for (spno_c=0; spno_c <=80; ++spno_c)
        {
        if (puzzle_numbers[spno_c] != 0)
            {
//          If it's is Tile 1
            if (spno_c == 0 || spno_c == 1 || spno_c == 2 ||
                spno_c == 9 || spno_c == 10 || spno_c == 11 ||
                spno_c == 18 || spno_c == 19 || spno_c == 20)
                {
                for (col=0; col<=2; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=9; col<=11; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=18; col<=20; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 2
            if (spno_c == 3 || spno_c == 4 || spno_c == 5 ||
                spno_c == 12 || spno_c == 13 || spno_c == 14 ||
                spno_c == 21 || spno_c == 22 || spno_c == 23)
                {
                for (col=3; col<=5; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=12; col<=14; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=21; col<=23; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 3
            if (spno_c == 6 || spno_c == 7 || spno_c == 8 ||
                spno_c == 15 || spno_c == 16 || spno_c == 17 ||
                spno_c == 24 || spno_c == 25 || spno_c == 26)
                {
                for (col=6; col<=8; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=15; col<=17; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=24; col<=26; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
               puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 4
            if (spno_c == 27 || spno_c == 28 || spno_c == 29 ||
                spno_c == 36 || spno_c == 37 || spno_c == 38 ||
                spno_c == 45 || spno_c == 46 || spno_c == 47)
                {
                for (col=27; col<=29; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=36; col<=38; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=45; col<=47; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 5
            if (spno_c == 30 || spno_c == 31 || spno_c == 32 ||
                spno_c == 39 || spno_c == 40 || spno_c == 41 ||
                spno_c == 48 || spno_c == 49 || spno_c == 50)
                {
                for (col=30; col<=32; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=39; col<=41; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=48; col<=50; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 6
            if (spno_c == 33 || spno_c == 34 || spno_c == 35 ||
                spno_c == 42 || spno_c == 43 || spno_c == 44 ||
                spno_c == 51 || spno_c == 52 || spno_c == 53)
                {
                for (col=33; col<=35; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=42; col<=44; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=51; col<=53; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 7
            if (spno_c == 54 || spno_c == 55 || spno_c == 56 ||
                spno_c == 63 || spno_c == 64 || spno_c == 65 ||
                spno_c == 72 || spno_c == 73 || spno_c == 74)
                {
                for (col=54; col<=56; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=63; col<=65; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=72; col<=74; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 8
            if (spno_c == 57 || spno_c == 58 || spno_c == 59 ||
                spno_c == 66 || spno_c == 67 || spno_c == 68 ||
                spno_c == 75 || spno_c == 76 || spno_c == 77)
                {
                for (col=57; col<=59; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=66; col<=68; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=75; col<=77; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
//          If it's is Tile 9
            if (spno_c == 60 || spno_c == 61 || spno_c == 62 ||
                spno_c == 69 || spno_c == 70 || spno_c == 71 ||
                spno_c == 78 || spno_c == 79 || spno_c == 80)
                {
                for (col=60; col<=62; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=69; col<=71; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                    }
                for (col=78; col<=80; ++col)
                    {
                    puzzle_note_pad[puzzle_numbers[spno_c]-1][col] = 0;
                   }
                puzzle_note_pad[puzzle_numbers[spno_c]-1][spno_c] = puzzle_numbers[spno_c];
                }
            }
        }
}
//
void initialise_puzzle (int puzzle_note_pad[][81], int puzzle_numbers[])
//  Routine to place the initial numbers into the Sudoku puzzle - ready for the computer to solve.
{
//  Now take the initial puzzle number and place it in the column of the puzzle note pad.
    initialise_number_in_note_pad_col (puzzle_note_pad, puzzle_numbers);
//
//  Put the Sudoku puzzle number into the puzzle_note_pad by puzzle row.
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 0, 8);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 9, 17);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 18, 26);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 27, 35);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 36, 44);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 45, 53);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 54, 62);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 63, 71);
    initialise_note_pad_by_puzzle_row (puzzle_note_pad, puzzle_numbers, 72, 80);
//
//  Put the Sudoku puzzle number into the puzzle_note_pad by puzzle col.
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 0, 72);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 1, 73);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 2, 74);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 3, 75);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 4, 76);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 5, 77);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 6, 78);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 7, 79);
    initialise_note_pad_by_puzzle_col (puzzle_note_pad, puzzle_numbers, 8, 80);
//
//  Put the Sudoku puzzle number into the puzzle_note_pad by puzzle tile.
    initialise_note_pad_row_by_puzzle_tiles (puzzle_note_pad, puzzle_numbers);
//
}
//
void find_singles_in_note_pad (int puzzle_note_pad[][81])
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
            cout << " col_counter[c] = " << col_counter[c] << endl;
            cout << " [c] = " << c << endl;
            ++col_counter_count;
            }
        }
//
    cout << " col_counter_count = " << col_counter_count << endl;
//
}
//
