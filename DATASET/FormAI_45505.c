//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50
#define DELAY 100000 // Delay in microseconds

void display_cells(int cells[ROWS][COLS]) { // Function to print the current state of cells
    system("clear"); // Clearing the screen for better visualization

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cells[i][j] == 1)
                printf("◼︎ ");
            else
                printf("◻︎ ");
        }
        printf("\n");
    }
}

int count_neighbors(int cells[ROWS][COLS], int i, int j) { // Function to count the number of live neighbors
    int count = 0;

    for (int m = -1; m <= 1; m++) {
        for (int n = -1; n <= 1; n++) {
            int row = i + m;
            int col = j + n;

            if (row < 0)
                row = ROWS - 1;
            else if (row >= ROWS)
                row = 0;

            if (col < 0)
                col = COLS - 1;
            else if (col >= COLS)
                col = 0;

            count += cells[row][col];
        }
    }

    count -= cells[i][j]; // Subtracting the count of the current cell

    return count;
}

void update_cells(int cells[ROWS][COLS]) { // Function to update the next state of cells
    int next[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(cells, i, j);

            if (cells[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3)
                    next[i][j] = 0; // Cell dies due to underpopulation or overpopulation
                else
                    next[i][j] = 1; // Cell survives
            } else {
                if (neighbors == 3)
                    next[i][j] = 1; // Cell becomes alive due to reproduction
                else
                    next[i][j] = 0; // Cell remains dead
            }
        }
    }

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cells[i][j] = next[i][j]; // Updating the current state of cells with the next state
}

int main() {
    int cells[ROWS][COLS];

    // Initializing the cells randomly
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cells[i][j] = rand() % 2;

    // Running the Game of Life for a number of generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        display_cells(cells);
        update_cells(cells);
        usleep(DELAY);
    }

    return 0;
}