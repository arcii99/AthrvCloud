//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_FLIPS 20

void printGrid(int grid[ROWS][COLS], int hiddenGrid[ROWS][COLS]);
int checkGameOver(int grid[ROWS][COLS], int hiddenGrid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {
                        {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {1, 2, 3, 4},
                        {5, 6, 7, 8}
                    };
    int hiddenGrid[ROWS][COLS] = {0};
    int flips = 0;
    int maxFlips = MAX_FLIPS;
    int gameOver = 0;

    srand(time(NULL));

    // Shuffle grid
    for(int i = 0; i < ROWS * COLS; i++) {
        int x1 = rand() % ROWS;
        int y1 = rand() % COLS;

        int x2 = rand() % ROWS;
        int y2 = rand() % COLS;

        int temp = grid[x1][y1];
        grid[x1][y1] = grid[x2][y2];
        grid[x2][y2] = temp;
    }

    printf("Welcome to the Memory Game!\n");
    printf("You have %d flips to match all the images!\n", maxFlips);
    printf("Press enter to start the game.\n");
    getchar();

    while(flips < maxFlips && !gameOver) {
        system("clear");
        printGrid(grid, hiddenGrid);

        int x1, y1, x2, y2;
        printf("\nEnter the position of the first image (row column): ");
        scanf("%d %d", &x1, &y1);

        if(hiddenGrid[x1][y1] == 1) {
            continue;
        }

        hiddenGrid[x1][y1] = 1;

        system("clear");
        printGrid(grid, hiddenGrid);

        printf("\nEnter the position of the second image (row column): ");
        scanf("%d %d", &x2, &y2);

        if(hiddenGrid[x2][y2] == 1 || (x1 == x2 && y1 == y2)) {
            hiddenGrid[x1][y1] = 0;
            continue;
        }

        hiddenGrid[x2][y2] = 1;
        flips++;

        // Check if the images match
        if(grid[x1][y1] != grid[x2][y2]) {
            printf("\nNo match. You have %d flips left.\n", maxFlips - flips);
            hiddenGrid[x1][y1] = 0;
            hiddenGrid[x2][y2] = 0;
        }

        gameOver = checkGameOver(grid, hiddenGrid);
    }

    if(gameOver) {
        printf("\nCongratulations! You win!\n");
    } else {
        printf("\nGame over. You lose!\n");
    }

    return 0;
}

// Function to print grid
void printGrid(int grid[ROWS][COLS], int hiddenGrid[ROWS][COLS]) {
    printf("    0 1 2 3\n");
    printf("   --------\n");

    for(int i = 0; i < ROWS; i++) {
        printf("%d | ", i);

        for(int j = 0; j < COLS; j++) {
            if(hiddenGrid[i][j] == 1) {
                printf("%d ", grid[i][j]);
            } else {
                printf("* ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Function to check if all images are revealed
int checkGameOver(int grid[ROWS][COLS], int hiddenGrid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(hiddenGrid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}