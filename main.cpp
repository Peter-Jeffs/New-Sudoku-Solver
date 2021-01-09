//
//************************************************************************************
//*                                                                                  *
//* Sudoku Puzzlw Solver ported into MACOS by Peter Jeffs in December 2020.          *
//*                                                                                  *
//* Sudoku Puzzle Solver written by Peter Jeffs in June 2015 using C++.              *
//*                                                                                  *
//* Re-factored from the Sudoku Puzzle Solver written by Peter Jeffs in C June 2014. *
//*                                                                                  *
//************************************************************************************
//
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"
using namespace std;
//
int main() {
//  A generic counter for use in loops ...
int solved_puzzle_numbers_count = 0;
int puzzle_square[9][9] = {{0}};
int puzzle_note_pad[9][81] = {{0}};
int initial_puzzle_number_count = 0;
int final_number_count = 0;
//
//    int puzzle_numbers [81] =  {4,0,0,0,0,0,0,7,3,
//                                0,8,7,0,0,2,1,0,4,
//                                1,0,3,0,0,0,0,0,0,
//                                0,0,6,2,0,4,0,0,0,
//                                0,4,0,0,6,0,0,2,0,
//                                0,0,0,9,0,5,6,0,0,
//                                0,0,0,0,0,0,2,0,9,
//                                8,0,9,1,0,0,4,3,0,
//                                7,1,0,0,0,0,0,0,6};
//
//int puzzle_numbers [81] =  {0,4,0,0,0,9,0,0,0,
//                            0,9,5,3,1,0,0,0,0,
//                            0,0,3,0,0,6,0,1,0,
//                            5,2,4,0,0,0,0,3,0,
//                            6,0,0,0,3,0,0,0,7,
//                            0,3,0,0,0,0,4,2,1,
//                            0,8,0,5,0,0,2,0,0,
//                            0,0,0,0,8,1,7,4,0,
//                            0,0,0,9,0,0,0,8,0};
//
//  The one you're working on ...
//    int puzzle_numbers [81] =  {9,0,1,0,0,0,0,4,0,
//                                0,0,0,7,2,0,0,9,0,
//                                0,5,0,4,3,0,0,0,8,
//                                0,1,0,0,0,4,3,0,0,
//                                0,0,8,0,0,0,1,0,0,
//                                0,0,9,8,0,0,0,2,0,
//                                1,0,0,0,4,7,0,3,0,
//                                0,7,0,0,8,2,0,0,0,
//                                0,4,0,0,0,0,9,0,2};
//
//  this puzzle needed additional numbers to work!!!
int puzzle_numbers [81] =  {5,2,9,0,1,0,0,7,8,
                            7,0,0,9,0,8,3,0,0,
                            0,0,0,2,0,7,9,0,0,
                            0,0,5,0,0,0,8,0,9,
                            2,3,0,0,8,9,5,6,4,
                            8,9,0,0,0,5,1,0,0,
                            0,0,4,8,0,2,0,0,0,
                            0,0,0,5,0,6,0,0,1,
                            6,5,2,0,9,0,0,8,3};
//
//    int puzzle_numbers [81] =  {0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0,
//                                0,0,0,0,0,0,0,0,0};
//
fill_puzzle_square (puzzle_square, puzzle_numbers);
print_puzzle_square (puzzle_square);
//
puzzle_note_pad_initialised_with_1_to_9 (puzzle_note_pad);
initialise_puzzle (puzzle_note_pad, puzzle_numbers);
fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
//
initial_puzzle_number_count = puzzle_number_count (puzzle_numbers);
cout << "1st solved_puzzle_numbers_count =  " << solved_puzzle_numbers_count <<  "\n";
//
//  Print Functionality ...
//  print_puzzle_note_pad(puzzle_note_pad, 0, 26);
//  print_puzzle_note_pad(puzzle_note_pad, 27, 53);
//  print_puzzle_note_pad(puzzle_note_pad, 54, 80);
//
//find_single_candidates_in_puzzle_row (puzzle_note_pad, puzzle_numbers, 18, 26);
//
//  print_puzzle_note_pad_to_file (puzzle_note_pad, 0, 26);
//  print_puzzle_note_pad_to_file (puzzle_note_pad, 27, 53);
//  print_puzzle_note_pad_to_file (puzzle_note_pad, 54, 80);
//
int count=0;
//
for (count=0; count<=10; ++count)
    {
    initialise_puzzle (puzzle_note_pad, puzzle_numbers);
    fon_in_puzzle_note_pad (puzzle_note_pad, puzzle_numbers);
    }
//
solved_puzzle_numbers_count = puzzle_number_count (puzzle_numbers);
cout << "2nd solved_puzzle_numbers_count =  " << solved_puzzle_numbers_count <<  "\n";
//
//  START MAIN PROGRAM FUNCTIONALITY ...
puzzle_solving_engine (puzzle_note_pad, puzzle_numbers, initial_puzzle_number_count);
//
final_number_count = puzzle_number_count (puzzle_numbers);
if (final_number_count != 81)
    {
    cout << "\n" << "... oh dear !! Your techniques have failed to solve the puzzle !!!" << "\n";
    cout << "... you'll have to code some more techniques !!! " << "\n";
    }
//
solved_puzzle_numbers_count = puzzle_number_count (puzzle_numbers);
cout << "Final solved_puzzle_numbers_count =  " << solved_puzzle_numbers_count <<  "\n";
//
//  Print Functionality ...
//  print_puzzle_note_pad(puzzle_note_pad, 0, 26);
//  print_puzzle_note_pad(puzzle_note_pad, 27, 53);
//  print_puzzle_note_pad(puzzle_note_pad, 54, 80);
//
//  Validation Functions ...
check_puzzle_validity(puzzle_note_pad, puzzle_numbers);
//
//  Put Numbers in Puzzle and Print ...
fill_puzzle_square (puzzle_square, puzzle_numbers);
print_puzzle_square (puzzle_square);
//
cout << "Program Finished \n\n" << endl;
return 0;
}
//

