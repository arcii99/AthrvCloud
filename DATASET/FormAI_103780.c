//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the haunted house simulation
#define ROWS 15
#define COLS 15
#define MAX_GHOSTS 5
#define MAX_STEPS 15
#define GHOST 'G'
#define PLAYER 'P'
#define WALL '#'
#define EMPTY ' '

// function to print the game board
void print_board(char board[ROWS][COLS], int player_row, int player_col)
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == player_row && j == player_col) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// function to check if a given row and column is within bounds of the game board
int within_bounds(int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if a given row and column is a wall cell
int is_wall(char board[ROWS][COLS], int row, int col)
{
    if(board[row][col] == WALL) {
        return 1;
    } else {
        return 0;
    }
}

// function to randomly place ghosts onto the game board
void place_ghosts(char board[ROWS][COLS], int num_ghosts)
{
    int ghosts_placed = 0;
    while(ghosts_placed < num_ghosts) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(board[row][col] == EMPTY) {
            board[row][col] = GHOST;
            ghosts_placed++;
        }
    }
}

int main()
{
    // seed the random number generator
    srand(time(NULL));
    
    // initialize the game board
    char board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                board[i][j] = WALL;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    
    // randomly place ghosts onto the game board
    place_ghosts(board, MAX_GHOSTS);
    
    // initialize the player's starting position
    int player_row = ROWS / 2;
    int player_col = COLS / 2;
    
    // main game loop
    for(int i = 0; i < MAX_STEPS; i++) {
        
        // print the current game board
        print_board(board, player_row, player_col);
        
        // get the player's next move
        char move;
        printf("Enter your next move (up, down, left, right): ");
        scanf(" %c", &move);
        
        // move the player one cell in the chosen direction, if possible
        switch(move) {
            case 'up':
                if(within_bounds(player_row - 1, player_col) && !is_wall(board, player_row - 1, player_col)) {
                    player_row--;
                }
                break;
            case 'down':
                if(within_bounds(player_row + 1, player_col) && !is_wall(board, player_row + 1, player_col)) {
                    player_row++;
                }
                break;
            case 'left':
                if(within_bounds(player_row, player_col - 1) && !is_wall(board, player_row, player_col - 1)) {
                    player_col--;
                }
                break;
            case 'right':
                if(within_bounds(player_row, player_col + 1) && !is_wall(board, player_row, player_col + 1)) {
                    player_col++;
                }
                break;
            default:
                printf("Invalid move!\n");
        }
        
        // check if the player has encountered a ghost and end the game if so
        if(board[player_row][player_col] == GHOST) {
            printf("You encountered a ghost and lost the game!\n");
            printf("Better luck next time!\n");
            return 0;
        }
    }
    
    // if the player has made it to the end of the game without encountering a ghost, they win
    printf("Congratulations, you made it through the haunted house and won the game!\n");
    
    return 0;
}