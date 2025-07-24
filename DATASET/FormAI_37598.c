//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
/* This program implements a scientific simulation of Conway's classic cellular automaton, the Game of Life.
 * The "game board" is represented as a grid of cells, each of which has two possible states: "alive" or "dead".
 * The program iterates through generations of the game, updating the state of each cell based on the state of its neighbors.
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20     // number of rows in the game board
#define COLS 20     // number of columns in the game board
#define GENERATIONS 50  // number of iterations of the game to run

/* Function prototypes */
void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);

int main(void) {
    int game_board[ROWS][COLS];   // initialize the game board
    
    /* Populate and print the initial game board */
    initialize_board(game_board);
    printf("Initial game board:\n");
    print_board(game_board);
    
    /* Run the game for a specified number of generations */
    for (int i = 0; i < GENERATIONS; i++) {
        update_board(game_board);
        printf("Game board after generation %d:\n", i+1);
        print_board(game_board);
    }
    
    return 0;
}

/* Function to populate the game board with randomly generated cell states */
void initialize_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;   // randomly assign the cell as alive or dead
        }
    }
}

/* Function to print the current state of the game board */
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '*' : '.');   // use * to represent "alive" cells and . to represent "dead" cells
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to update the game board to the next generation */
void update_board(int board[ROWS][COLS]) {
    int next_board[ROWS][COLS];   // create a new board to hold the updated cell states
    
    /* Iterate through each cell, determining its updated state based on the state of its neighbors */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;   // count the number of "alive" neighboring cells
            
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if (r == 0 && c == 0) {
                        continue;   // skip the current cell
                    }
                    int row = i + r;
                    int col = j + c;
                    
                    /* If the neighboring cell is off the game board, assume its state as "dead" */
                    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
                        continue;
                    }
                    neighbors += board[row][col];   // add to the neighbor count if the cell is "alive"
                }
            }
            
            /* Apply the game rules to determine the updated state of the cell */
            if (board[i][j] && (neighbors < 2 || neighbors > 3)) {
                next_board[i][j] = 0;   // if an "alive" cell has less than 2 or more than 3 "alive" neighbors, it dies
            } else if (!board[i][j] && neighbors == 3) {
                next_board[i][j] = 1;   // if a "dead" cell has exactly 3 "alive" neighbors, it becomes "alive"
            } else {
                next_board[i][j] = board[i][j];   // in all other cases, the cell's state remains the same
            }
        }
    }
    
    /* Copy the updated cell states to the original game board */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}