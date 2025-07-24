//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 10
#define SHIP_COUNT 3
#define MIN_SHIP_SIZE 2
#define MAX_SHIP_SIZE 5

// Structures
struct Ship {
    int size;
    int x[5];
    int y[5];
};
typedef struct Ship Ship;

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeShips(char grid[GRID_SIZE][GRID_SIZE], Ship ships[SHIP_COUNT]);
int getRandomNumber(int min, int max);
void setShipCoordinates(Ship *ship, int x, int y, int size, int direction);
void setShip(char grid[GRID_SIZE][GRID_SIZE], Ship *ship);
void playGame(char grid[GRID_SIZE][GRID_SIZE], Ship ships[SHIP_COUNT]);

int main() {
    srand(time(NULL)); // Seed random number generator
    char grid[GRID_SIZE][GRID_SIZE];
    Ship ships[SHIP_COUNT];
    initializeGrid(grid);
    placeShips(grid, ships);
    playGame(grid, ships);
    printf("\nCongratulations! You won the game!\n");
    return 0;
}

// Function definitions
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n   ");
    for(int i=0; i<GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<GRID_SIZE; i++) {
        printf("%d  ", i);
        for(int j=0; j<GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void placeShips(char grid[GRID_SIZE][GRID_SIZE], Ship ships[SHIP_COUNT]) {
    for(int i=0; i<SHIP_COUNT; i++) {
        int size = getRandomNumber(MIN_SHIP_SIZE, MAX_SHIP_SIZE);
        ships[i].size = size;
        int x = getRandomNumber(0, GRID_SIZE-size);
        int y = getRandomNumber(0, GRID_SIZE-size);
        int direction = getRandomNumber(0, 1);
        setShipCoordinates(&ships[i], x, y, size, direction);
        setShip(grid, &ships[i]);
    }
    printf("\n\nThe game is ready! Find and destroy %d ships!\n", SHIP_COUNT);
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void setShipCoordinates(Ship *ship, int x, int y, int size, int direction) {
    for(int i=0; i<size; i++) {
        if(direction == 0) { // horizontal
            ship->x[i] = x + i;
            ship->y[i] = y;
        }
        else { // vertical
            ship->x[i] = x;
            ship->y[i] = y + i;
        }
    }
}

void setShip(char grid[GRID_SIZE][GRID_SIZE], Ship *ship) {
    for(int i=0; i<ship->size; i++) {
        int x = ship->x[i];
        int y = ship->y[i];
        grid[x][y] = 'S';
    }
}

void playGame(char grid[GRID_SIZE][GRID_SIZE], Ship ships[SHIP_COUNT]) {
    int shipsDestroyed = 0;
    int shotsFired = 0;
    while(shipsDestroyed < SHIP_COUNT) {
        printGrid(grid);
        printf("\nEnter the coordinates to fire at:\n");
        int x, y;
        scanf("%d %d", &x, &y);
        if(grid[x][y] == '-') {
            printf("\nMiss!\n");
            grid[x][y] = 'O';
        }
        else if(grid[x][y] == 'S') {
            printf("\nHit!\n");
            grid[x][y] = 'X';
            for(int i=0; i<SHIP_COUNT; i++) {
                Ship *ship = &ships[i];
                for(int j=0; j<ship->size; j++) {
                    if(ship->x[j] == x && ship->y[j] == y) {
                        ship->x[j] = -1;
                        ship->y[j] = -1;
                        break;
                    }
                }
                int destroyed = 1;
                for(int j=0; j<ship->size; j++) {
                    if(ship->x[j] != -1 || ship->y[j] != -1) {
                        destroyed = 0;
                        break;
                    }
                }
                if(destroyed == 1) {
                    shipsDestroyed++;
                    printf("\nShip of size %d destroyed!\n", ship->size);
                    break;
                }
            }
        }
        else {
            printf("\nYou have already fired at this position!\n");
        }
        shotsFired++;
    }
    printf("\nYou destroyed all the ships in %d shots!\n", shotsFired);
}