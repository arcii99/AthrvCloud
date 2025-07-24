//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef enum {
    UNKNOWN,
    EMPTY,
    SHIP,
    HIT,
    MISS
} GridElement;

typedef struct {
    int id;
    int size;
    int hits;
    int x;
    int y;
    int horizontal;
} Ship;

void initializeGrid(GridElement grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = UNKNOWN;
        }
    }
}

void printGrid(GridElement grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    printf("  ");
    for (i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < GRID_SIZE; j++) {
            switch (grid[i][j]) {
                case UNKNOWN:
                    printf("  ");
                    break;
                case EMPTY:
                    printf(". ");
                    break;
                case SHIP:
                    printf("S ");
                    break;
                case HIT:
                    printf("X ");
                    break;
                case MISS:
                    printf("O ");
                    break;
                default:
                    printf("? ");
                    break;
            }
        }
        printf("\n");
    }
}

void placeShip(GridElement grid[GRID_SIZE][GRID_SIZE], Ship *ship) {
    int i, j;
    if (ship->horizontal) {
        for (i = 0; i < ship->size; i++) {
            grid[ship->y][ship->x + i] = SHIP;
        }
    } else {
        for (i = 0; i < ship->size; i++) {
            grid[ship->y + i][ship->x] = SHIP;
        }
    }
}

int checkCollision(GridElement grid[GRID_SIZE][GRID_SIZE], Ship *ship) {
    int i, j;
    if (ship->horizontal) {
        for (i = 0; i < ship->size; i++) {
            if (grid[ship->y][ship->x + i] == SHIP) {
                return 1;
            }
        }
    } else {
        for (i = 0; i < ship->size; i++) {
            if (grid[ship->y + i][ship->x] == SHIP) {
                return 1;
            }
        }
    }
    return 0;
}

void placeRandomShips(GridElement grid[GRID_SIZE][GRID_SIZE], int numShips) {
    int i, j;
    for (i = 0; i < numShips; i++) {
        Ship ship;
        ship.id = i;
        ship.size = rand() % 3 + 2;
        ship.hits = 0;
        ship.horizontal = rand() % 2;
        do {
            if (ship.horizontal) {
                ship.x = rand() % (GRID_SIZE - ship.size + 1);
                ship.y = rand() % GRID_SIZE;
            } else {
                ship.x = rand() % GRID_SIZE;
                ship.y = rand() % (GRID_SIZE - ship.size + 1);
            }
        } while (checkCollision(grid, &ship));
        placeShip(grid, &ship);
    }
}

int countShips(GridElement grid[GRID_SIZE][GRID_SIZE]) {
    int i, j, count = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == SHIP) {
                count++;
            }
        }
    }
    return count;
}

void playGame(GridElement grid[GRID_SIZE][GRID_SIZE]) {
    int x, y;
    int numShips = countShips(grid);
    int numHits = 0;
    printf("There are %d ships.\n", numShips);
    while (numHits < numShips) {
        printf("Enter a coordinate (x y): ");
        scanf("%d %d", &x, &y);
        if (grid[y][x] == UNKNOWN) {
            printf("Miss!\n");
            grid[y][x] = MISS;
        } else if (grid[y][x] == SHIP) {
            printf("Hit!\n");
            grid[y][x] = HIT;
            numHits++;
        } else {
            printf("Invalid coordinate!\n");
        }
        printGrid(grid);
    }
    printf("You win!\n");
}

int main() {
    srand(time(NULL));
    GridElement grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);
    placeRandomShips(grid, 5);
    printGrid(grid);
    playGame(grid);
    return 0;
}