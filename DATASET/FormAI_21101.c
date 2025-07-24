//FormAI DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // size of the grid
#define MAX_MOVES SIZE * SIZE / 2 // maximum number of moves allowed

void initGrid(int grid[][SIZE]);
void printGrid(int grid[][SIZE], int uncovered[][SIZE]);
void shuffle(int grid[][SIZE]);
void uncover(int grid[][SIZE], int uncovered[][SIZE], int row, int col);
int isComplete(int uncovered[][SIZE]);

int main() {
    // Seed the random number generator
    srand((unsigned) time(NULL));

    // Initialize the grid and uncovered arrays
    int grid[SIZE][SIZE];
    int uncovered[SIZE][SIZE];
    initGrid(grid);
    initGrid(uncovered);

    // Shuffle the grid
    shuffle(grid);

    // Start the game
    int moves = 0;
    while (!isComplete(uncovered) && moves < MAX_MOVES) {
        printf("Moves: %d/%d\n", moves, MAX_MOVES);
        printGrid(grid, uncovered);

        // Get the user's move
        int row1, col1, row2, col2;
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);

        // Uncover the selected cards
        uncover(grid, uncovered, row1, col1);
        uncover(grid, uncovered, row2, col2);

        // Increment the move counter
        moves++;
    }

    // Print the final grid and the number of moves taken
    printf("Moves: %d/%d\n", moves, MAX_MOVES);
    printGrid(grid, uncovered);
    printf("Congratulations, you won in %d moves!\n", moves);

    return 0;
}

/**
 * Initialize the given grid with pairs of numbers from 1 to SIZE * SIZE / 2.
 */
void initGrid(int grid[][SIZE]) {
    int nums[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the numbers
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        int j = rand() % (SIZE * SIZE / 2);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Place the shuffled numbers in the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = nums[i * SIZE / 2 + j / 2];
        }
    }
}

/**
 * Print the given grid, with only the cells in the uncovered array showing their values.
 */
void printGrid(int grid[][SIZE], int uncovered[][SIZE]) {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (uncovered[i][j]) {
                printf("%d ", grid[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

/**
 * Shuffle the given grid by swapping pairs of cells randomly.
 */
void shuffle(int grid[][SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int row1 = rand() % SIZE;
        int col1 = rand() % SIZE;
        int row2 = rand() % SIZE;
        int col2 = rand() % SIZE;

        int temp = grid[row1][col1];
        grid[row1][col1] = grid[row2][col2];
        grid[row2][col2] = temp;
    }
}

/**
 * Set the given cell in the uncovered array to 1, revealing the value of the corresponding cell in the grid.
 */
void uncover(int grid[][SIZE], int uncovered[][SIZE], int row, int col) {
    uncovered[row][col] = 1;
}

/**
 * Check if all cells in the uncovered array are set to 1.
 */
int isComplete(int uncovered[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!uncovered[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}