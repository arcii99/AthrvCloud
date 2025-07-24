//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5
#define RANGE 15

void printGrid(int grid[SIZE][SIZE]);
bool checkWin(int grid[SIZE][SIZE]);

int main() {
    srand(time(NULL));

    int grid[SIZE][SIZE], pickedNums[RANGE] = {0};
    bool win = false;

    // Initialize the grid with 0s
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            grid[row][col] = 0;
        }
    }

    // Loop until someone wins
    while(!win) {
        // Generate a random number
        int num = rand() % RANGE + 1;

        // Check if the number has already been picked, if not mark it as picked
        if(pickedNums[num-1] == 0) {
            pickedNums[num-1] = 1;
            printf("Number %d\n", num);

            // Check if the number is in the grid, if so mark it as found
            for(int row = 0; row < SIZE; row++) {
                for(int col = 0; col < SIZE; col++) {
                    if(grid[row][col] == num) {
                        grid[row][col] = -1;
                    }
                }
            }

            // Print the updated grid
            printf("Current Grid:\n");
            printGrid(grid);
            printf("\n");

            // Check if there is a winner
            if(checkWin(grid)) {
                printf("Bingo! You won.\n");
                win = true;
            }
        }
    }

    return 0;
}

void printGrid(int grid[SIZE][SIZE]) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(grid[row][col] == -1) {
                // Mark found numbers with 'X'
                printf("X ");
            } else {
                printf("%d ", grid[row][col]);
            }
        }
        printf("\n");
    }
}

bool checkWin(int grid[SIZE][SIZE]) {
    bool win = false;

    // Check rows and columns for a win
    for(int i = 0; i < SIZE; i++) {
        bool rowWin = true, colWin = true;
        for(int j = 0; j < SIZE; j++) {
            if(grid[i][j] != -1) {
                rowWin = false;
            }
            if(grid[j][i] != -1) {
                colWin = false;
            }
        }
        if(rowWin || colWin) {
            win = true;
            break;
        }
    }

    // Check diagonals for a win
    if(!win && grid[0][0] == -1 && grid[1][1] == -1 && grid[2][2] == -1 && grid[3][3] == -1 && grid[4][4] == -1) {
        win = true;
    }
    if(!win && grid[0][4] == -1 && grid[1][3] == -1 && grid[2][2] == -1 && grid[3][1] == -1 && grid[4][0] == -1) {
        win = true;
    }

    return win;
}