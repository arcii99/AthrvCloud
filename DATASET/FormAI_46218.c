//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

char grid[GRID_SIZE][GRID_SIZE];

void initGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%c ", i + 65);
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 1; i <= GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void placeShips(int numShips) {
    int shipsPlaced = 0;
    while (shipsPlaced < numShips) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == '-') {
            grid[row][col] = 'S';
            shipsPlaced++;
        }
    }
}

int getRow(char* shot) {
    return (int)toupper(shot[0]) - 65;
}

int getCol(char* shot) {
    return atoi(&shot[1]) - 1;
}

int main() {
    srand(time(NULL));
    initGrid();
    int numShips = 5;
    placeShips(numShips);
    printGrid();
    int hitCount = 0;
    int shotCount = 0;
    while (hitCount < numShips) {
        char shot[3];
        printf("Enter a shot (ex. A1): ");
        scanf("%s", shot);
        int row = getRow(shot);
        int col = getCol(shot);
        shotCount++;
        if (grid[row][col] == 'S') {
            printf("Hit!\n");
            grid[row][col] = 'H';
            hitCount++;
        } else {
            printf("Miss!\n");
            grid[row][col] = 'M';
        }
        printGrid();
    }
    printf("You sunk all %d ships in %d shots!\n", numShips, shotCount);
    return 0;
}