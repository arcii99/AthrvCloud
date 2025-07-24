//FormAI DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main() {

    int i, j, k;
    int old_board[ROWS][COLS], new_board[ROWS][COLS]; // declaring 2D arrays to store current and updated generation

    srand(time(NULL)); // generating seed for random numbers

    // initializing the initial board randomly
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(rand() % 2 == 0) {
                old_board[i][j] = 1;
            } else {
                old_board[i][j] = 0;
            }
        }
    }

    // print the initial board
    printf("INITIAL BOARD:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", old_board[i][j]);
        }
        printf("\n");
    }

    // the main game loop
    for(k = 0; k < 10; k++) {

        // updating each cell based on the rules of the game
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                int num_neighbors = 0;
                
                // count neighbor cells that are alive
                if(i > 0 && old_board[i-1][j] == 1) { // top neighbor
                    num_neighbors++;
                }
                if(i < ROWS-1 && old_board[i+1][j] == 1) { // bottom neighbor
                    num_neighbors++;
                }
                if(j > 0 && old_board[i][j-1] == 1) { // left neighbor
                    num_neighbors++;
                }
                if(j < COLS-1 && old_board[i][j+1] == 1) { // right neighbor
                    num_neighbors++;
                }
                if(i > 0 && j > 0 && old_board[i-1][j-1] == 1) { // top-left neighbor
                    num_neighbors++;
                }
                if(i > 0 && j < COLS-1 && old_board[i-1][j+1] == 1) { // top-right neighbor
                    num_neighbors++;
                }
                if(i < ROWS-1 && j > 0 && old_board[i+1][j-1] == 1) { // bottom-left neighbor
                    num_neighbors++;
                }
                if(i < ROWS-1 && j < COLS-1 && old_board[i+1][j+1] == 1) { // bottom-right neighbor
                    num_neighbors++;
                }

                // applying game rules to each cell
                if(old_board[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3)) {
                    new_board[i][j] = 0; // cell dies from under/overpopulation
                } else if(old_board[i][j] == 0 && num_neighbors == 3) {
                    new_board[i][j] = 1; // cell comes to life from reproduction
                } else {
                    new_board[i][j] = old_board[i][j]; // cell stays the same
                }
            }
        }

        // copying the updated board to the old board for next iteration
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                old_board[i][j] = new_board[i][j];
            }
        }

        // print the current board
        printf("\nGENERATION %d:\n", k+1);
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                printf("%d ", old_board[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}