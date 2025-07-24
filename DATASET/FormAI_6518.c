//FormAI DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 50

void print_board(int board[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j])
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void calculate_next_iteration(int board[][COLUMNS]) {
    int new_board[ROWS][COLUMNS];

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {

            // Count the number of live neighbors each cell has
            int count = 0;

            if(i > 0 && j > 0 && board[i-1][j-1])
                count++;

            if(i > 0 && board[i-1][j])
                count++;

            if(i > 0 && j < COLUMNS-1 && board[i-1][j+1])
                count++;

            if(j > 0 && board[i][j-1])
                count++;

            if(j < COLUMNS-1 && board[i][j+1])
                count++;

            if(i < ROWS-1 && j > 0 && board[i+1][j-1])
                count++;

            if(i < ROWS-1 && board[i+1][j])
                count++;

            if(i < ROWS-1 && j < COLUMNS-1 && board[i+1][j+1])
                count++;

            // Apply rules of the game of life to determine the cell's new state:
            if(board[i][j]) {
                if(count < 2)
                    new_board[i][j] = 0;
                else if(count <= 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = 0;
            }
            else {
                if(count == 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = 0;
            }
        }
    }

    // Copy the new board back to the original board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int board[ROWS][COLUMNS];

    // Initialize the game board randomly
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    for(int i=0; i<100; i++) {
        system("clear"); // Clear the console
        print_board(board); // Print the current state of the game board
        calculate_next_iteration(board); // Calculate the next iteration of the game
        usleep(100000); // Wait 0.1 seconds before starting the next iteration
    }

    return 0;
}