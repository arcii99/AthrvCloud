//FormAI DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

void mainMenu();
void loadRandomLayout(int grid[HEIGHT][WIDTH]);
void loadLayoutFromFile(char* fileName, int grid[HEIGHT][WIDTH]);
int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y);
void applyRules(int grid[HEIGHT][WIDTH]);
void displayGrid(int grid[HEIGHT][WIDTH]);

int main() {
    srand(time(NULL));
    int grid[HEIGHT][WIDTH];
    int choice;

    do {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                loadRandomLayout(grid);
                break;
            case 2:
                char fileName[50];
                printf("\nEnter file name: ");
                scanf("%s", fileName);
                loadLayoutFromFile(fileName, grid);
                break;
            case 3:
                applyRules(grid);
                displayGrid(grid);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void mainMenu() {
    printf("\nWELCOME TO GAME OF LIFE\n");
    printf("1. Random layout\n");
    printf("2. Load layout from file\n");
    printf("3. Apply rules & display\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void loadRandomLayout(int grid[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    displayGrid(grid);
}

void loadLayoutFromFile(char* fileName, int grid[HEIGHT][WIDTH]) {
    FILE* fp;
    int i, j, num;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &num);
            grid[i][j] = num;
        }
    }

    fclose(fp);

    displayGrid(grid);
}

int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && x+i >= 0 && x+i < HEIGHT && y+j >= 0 && y+j < WIDTH) {
                if (grid[x+i][y+j] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

void applyRules(int grid[HEIGHT][WIDTH]) {
    int i, j;
    int neighbors;

    int newGrid[HEIGHT][WIDTH];

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            neighbors = countNeighbors(grid, i, j);

            // Rule 1: Any live cell with fewer than two live neighbors dies, as if by underpopulation.
            // Rule 2: Any live cell with two or three live neighbors lives on to the next generation.
            // Rule 3: Any live cell with more than three live neighbors dies, as if by overpopulation.
            // Rule 4: Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    // Copy new grid to old grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void displayGrid(int grid[HEIGHT][WIDTH]) {
    int i, j;

    printf("\n");

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    printf("\n");
}