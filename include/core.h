/**
 * @file core.h
 * @author Gnik Droy
 * @brief File containing function declarations for the core game.
 *
 */
#pragma once
#include <stdio.h>

#define SIZE 4
#define BASE 2

typedef char bool;

/**
 * @brief Write the game matrix to the stream.
 *
 * The matrix is written as a comma seperated list of indices.
 * Each row is seperated by a '\n' character.
 * Each empty cell is represented by '-' character.
 * 
 * The indices can be used to calculate the actual integers.
 * 
 * You can use the constant stdout from <stdio.h> for printing to 
 * standard output
 * 
 * @param matrix The game matrix that is to be printed.
 * @param stream The file stream to use.
 */
void print_matrix(unsigned char matrix[][SIZE],FILE* stream);


/**
 * @brief Checks if there are possible moves left on the game board.
 *
 * Checks for both movement and combinations of tiles.
 * 
 * @param matrix The game matrix.
 * @return Either 0 or 1
 */
bool is_game_over(unsigned char matrix[][SIZE]);

/**
 * @brief This clears out the game matrix
 *
 * This zeros out the entire game matrix.
 * 
 * @param matrix The game matrix.
 */
void clear_matrix(unsigned char matrix[][SIZE]);

/**
 * @brief Adds a value of 1 to random place to the matrix.
 *
 * The function adds 1 to a random place in the matrix.
 * The 1 is placed in empty tiles. i.e tiles containing 0.
 * 1 is kept since you can use raise it with BASE to get required value.
 * Also it keeps the size of matrix to a low value.
 * 
 * NOTE: It has no checks if there are any empty places for keeping 
 * the random value.
 * If no empty place is found a floating point exception will occur.
 */
void add_random(unsigned char matrix[][SIZE]);

/**
 * @brief Calculates the score of a game matrix
 *
 * It score the matrix in a simple way.
 * Each element in the matrix is used as exponents of the BASE. And the 
 * sum of all BASE^element is returned.
 * 
 * @return An integer that represents the current score
 */
int calculate_score(unsigned char matrix[][SIZE]);





/**
 * @brief Shifts the game matrix in X direction.
 *
 * It shifts all the elements of the game matrix in the X direction.
 * If the direction is given as 0, it shifts the game matrix in the left
 * direction. Any other non zero value shifts it to the right direction.
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the shift.
 * 
 * @return If the shift was successful
 */
bool shift_x(unsigned char matrix[][SIZE], bool opp);


/**
 * @brief Merges the elements in X direction.
 *
 * It merges consecutive successive elements of the game matrix in the X direction.
 * If the direction is given as 0, it merges the game matrix to the left
 * direction. Any other non zero value merges it to the right direction.
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the shift.
 * 
 * @return If the merge was successful
 */
bool merge_x(unsigned char matrix[][SIZE],bool opp);


/**
 * @brief Moves the elements in X direction.
 *
 * It simply performs shift_x() and merge_x().
 * If either of them were successful, it also calls add_random()
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the move.
 * 
 */
void move_x(unsigned char matrix[][SIZE], bool opp);



/**
 * @brief Shifts the game matrix in Y direction.
 *
 * It shifts all the elements of the game matrix in the Y direction.
 * If the direction is given as 0, it shifts the game matrix in the top
 * direction. Any other non-zero value shifts it to the bottom.
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the shift.
 * 
 * @return If the shift was successful
 */
bool shift_y(unsigned char matrix[][SIZE], bool opp);


/**
 * @brief Merges the elements in Y direction.
 *
 * It merges consecutive successive elements of the game matrix in the Y direction.
 * If the direction is given as 0, it merges the game matrix to the top
 * direction. Any other non zero value merges it to the bottom.
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the shift.
 * 
 * @return If the merge was successful
 */
bool merge_y(unsigned char matrix[][SIZE],bool opp);


/**
 * @brief Moves the elements in Y direction.
 *
 * It simply performs shift_y() and merge_y().
 * If either of them were successful, it also calls add_random()
 * 
 * @param matrix The game matrix.
 * @param opp The direction of the move.
 * 
 */
void move_y(unsigned char matrix[][SIZE],bool opp);

