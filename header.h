//
//  Header.h
//  Sudoku
//
//  Created by Peter Jeffs on 21/12/2020.
//
#ifndef Header_h
#define Header_h
// print functions
void print_puzzle_note_pad_col (int puzzle_note_pad[][81], int col_number, int col_start, int col_stop);
void print_puzzle_note_pad_cols (int puzzle_note_pad[][81]);
void print_puzzle_note_pad_row (int puzzle_note_pad[][81], int row_number, int row_start, int row_stop);
void print_puzzle_note_pad_rows (int puzzle_note_pad[][81]);
void print_puzzle_note_pad_tile (int puzzle_note_pad[][81], int tile_number, int c1, int c2, int c3, int c4, int c5, int c6);
void print_all_puzzle_note_pad_tiles (int puzzle_note_pad[][81], int puzzle_numbers[]);
void print_puzzle_square (int puzzle_square[][9]);
void print_puzzle_note_pad (int puzzle_note_pad[][81], int row_start, int row_stop);
void print_puzzle_note_pad_to_file (int puzzle_note_pad[][81], int row_start, int row_stop);
//
// initialisation functions
void puzzle_note_pad_initialised_with_1_to_9 (int puzzle_note_pad[][81]);
void initialise_number_in_note_pad_col (int puzzle_note_pad[][81], int puzzle_numbers[]);
void initialise_note_pad_by_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int range_start, int range_stop);
void initialise_note_pad_by_puzzle_col (int puzzle_note_pad[][81], int puzzle_numbers[], int range_start, int range_stop);
void initialise_note_pad_row_by_puzzle_tile (int puzzle_note_pad[][81], int puzzle_numbers[]);
void initialise_note_pad_row_by_puzzle_tiles (int puzzle_note_pad[][81], int puzzle_numbers[]);
void initialise_puzzle (int puzzle_note_pad[][81], int puzzle_numbers[]);
//
//  Various Functions for finding Obvious Numbers
void find_singles_in_note_pad (int puzzle_note_pad[][81]);
void fon_in_puzzle_note_pad (int puzzle_note_pad[][81], int puzzle_numbers[]);
void find_obvious_number_in_puzzle_col (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper);
void find_obvious_number_in_puzzle_cols (int puzzle_note_pad[][81], int puzzle_numbers[]);
void find_obvious_number_in_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper);
void find_obvious_number_in_puzzle_rows (int puzzle_note_pad[][81], int puzzle_numbers[]);
void find_obvious_number_in_puzzle_tile (int puzzle_note_pad[][81], int puzzle_numbers[],  int c1, int c2, int c3, int c4, int c5, int c6);
void find_obvious_number_in_puzzle_tiles (int puzzle_note_pad[][81], int puzzle_numbers[]);
void find_obvious_numbers_in_puzzle (int puzzle_note_pad[][81], int puzzle_numbers[]);
//
//  The various generic Processing Functions
void fill_puzzle_square (int puzzle_square[][9], int puzzle_numbers[]);
int puzzle_number_count (int puzzle_numbers[]);
void puzzle_solving_engine (int puzzle_note_pad[][81],int puzzle_numbers[], int initial_puzzle_number_count);
//
//  Validating Functions ...
int verify_that_puzzle_tiles_and_rows_are_valid (int puzzle_numbers[]);
int check_puzzle_validity (int puzzle_note_pad[][81], int puzzle_numbers[]);
void check_puzzle_square_complete (int puzzle_square[][9], int puzzle_numbers[]);
int verify_that_puzzle_tile_is_valid (int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6, int n);
int verify_that_puzzle_row_is_valid (int puzzle_numbers[], int col_lower, int col_upper);
//
//  Functions to find naked pairs.
void find_naked_pairs_in_col (int puzzle_note_pad[][81], int col_lower, int col_upper);
void find_naked_pairs_in_cols (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_naked_pairs_in_row (int puzzle_note_pad[][81], int col_lower, int col_upper);
void find_naked_pairs_in_rows (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_naked_pairs_in_tile (int puzzle_note_pad[][81],int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6);
void find_naked_pairs_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[]);
//
//  Functions to find hidden pairs.
void find_hidden_pairs_in_col (int puzzle_note_pad[][81],int puzzle_numbers[], int col_lower, int col_upper);
void find_hidden_pairs_in_cols (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_hidden_pairs_in_row (int puzzle_note_pad[][81],int puzzle_numbers[], int col_lower, int col_upper);
void find_hidden_pairs_in_rows (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_hidden_pairs_in_tile (int puzzle_note_pad[][81],int puzzle_numbers[], int c1, int c2, int c3, int c4, int c5, int c6);
void find_hidden_pairs_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[]);
//
//  Functions to find solutions to x-wings.
void find_xwing_in_puzzle_rows (int puzzle_note_pad[][81]);
void find_xwing_in_puzzle_cols (int puzzle_note_pad[][81]);
//
//  Re-factored functions using arguments instead of literals for finding horizontal candidate pairs.
void find_horiz_candidate_lines_t1_t3_t4_t6_t7_t9 (int puzzle_note_pad[][81], int puzzle_numbers[],
    int ll_r1, int ul_r1, int ll_r2, int ul_r2, int ll_r3, int ul_r3,
    int ll_tile_r1, int ul_tile_r1, int ll_tile_r2, int ul_tile_r2, int ll_tile_r3, int ul_tile_r3,
    int ll_rcl_r1, int ul_rcl_r1, int ll_rcl_r2, int ul_rcl_r2, int ll_rcl_r3, int ul_rcl_r3,
    int ll_tcl_r1, int ul_tcl_r1, int ll_tcl_r2, int ul_tcl_r2, int ll_tcl_r3, int ul_tcl_r3,
    int refill_row1, int refill_row2, int refill_row3);
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
    int refill_row1, int refill_row2, int refill_row3);
void find_horiz_candidate_lines_in_puzzle_v2 (int puzzle_note_pad[][81], int puzzle_numbers[]);
//
//  Functions to eliminate entries due to candidate lines.
void find_vertical_candidate_lines_in_tile1 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile2 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile3 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile4 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile5 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile6 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile7 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile8 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tile9 (int puzzle_note_pad[][81],int puzzle_numbers[]);
void find_vertical_candidate_lines_in_tiles (int puzzle_note_pad[][81],int puzzle_numbers[]);
//
//  Solving Engines.
void simple_puzzle_solving_techniques (int puzzle_note_pad[][81], int puzzle_numbers[]);
void puzzle_solving_engine (int puzzle_note_pad[][81],int puzzle_numbers[], int initial_puzzle_number_count);
//
//  Find single Candidates
void find_single_candidates_in_puzzle_row (int puzzle_note_pad[][81], int puzzle_numbers[], int col_lower, int col_upper);
//
#endif /* Header_h */
