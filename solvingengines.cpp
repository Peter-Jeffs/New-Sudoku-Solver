//
//  solvingengines.cpp
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
void simple_puzzle_solving_techniques (int puzzle_note_pad[][81],int puzzle_numbers[])
//  Function that applies the simple problem solving techniques.
{
//  A generic counter for use in loops ...
    int counter = 0;
//
    for (counter=0; counter<=0; ++counter)
        {
        find_vertical_candidate_lines_in_tiles (puzzle_note_pad, puzzle_numbers);
        }
    for (counter=0; counter<=0; ++counter)
        {
        find_horiz_candidate_lines_in_puzzle_v2 (puzzle_note_pad, puzzle_numbers);
        }
//
    find_naked_pairs_in_rows (puzzle_note_pad, puzzle_numbers);
    find_naked_pairs_in_cols (puzzle_note_pad, puzzle_numbers);
    find_naked_pairs_in_tiles (puzzle_note_pad, puzzle_numbers);
    find_hidden_pairs_in_rows (puzzle_note_pad, puzzle_numbers);
    find_hidden_pairs_in_cols (puzzle_note_pad, puzzle_numbers);
    find_hidden_pairs_in_tiles (puzzle_note_pad, puzzle_numbers);
//
}
//
void puzzle_solving_engine (int puzzle_note_pad[][81],int puzzle_numbers[], int initial_puzzle_number_count)
//  Function to apply simple and intermediate problem solving techniques to the puzzle.
{
//
    int counter = 0;
    int puzzle_number_counter = 0;
//
    puzzle_number_counter = 0;
    puzzle_number_counter = puzzle_number_count (puzzle_numbers);
    if (puzzle_number_counter != 81)
        {
        for (counter=0; counter<=0; ++counter)
            {
            simple_puzzle_solving_techniques (puzzle_note_pad, puzzle_numbers);
            }
        }
//
//
    if (puzzle_number_counter != 81)
        {
        for (counter=0; counter<=0; ++counter)
            {
            puzzle_number_counter = 0;
            puzzle_number_counter = puzzle_number_count (puzzle_numbers);
            if (puzzle_number_counter != 81)
                {
                find_xwing_in_puzzle_rows (puzzle_note_pad);
                fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
                find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
                }
//
            puzzle_number_counter = 0;
            puzzle_number_counter = puzzle_number_count (puzzle_numbers);
            if (puzzle_number_counter != 81)
                {
                for (counter=0; counter<=4; ++counter)
                    {
                    simple_puzzle_solving_techniques (puzzle_note_pad, puzzle_numbers);
                    }
                }
//
            puzzle_number_counter = 0;
            puzzle_number_counter = puzzle_number_count (puzzle_numbers);
            if (puzzle_number_counter != 81)
                {
                find_xwing_in_puzzle_cols (puzzle_note_pad);
                fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
                find_obvious_numbers_in_puzzle (puzzle_note_pad, puzzle_numbers);
                }
            }
        }
//
    puzzle_number_counter = 0;
    puzzle_number_counter = puzzle_number_count (puzzle_numbers);
    if (puzzle_number_counter != 81)
        {
        for (counter=0; counter<=0; ++counter)
            {
            simple_puzzle_solving_techniques (puzzle_note_pad, puzzle_numbers);
            }
        }
//
    puzzle_number_counter = puzzle_number_count (puzzle_numbers);
    cout << "number of puzzle numbers found =  " << puzzle_number_counter - initial_puzzle_number_count <<  "\n";
//
}
//
