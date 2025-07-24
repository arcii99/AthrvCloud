//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 10

// Enumerated type for space objects
typedef enum {
    EMPTY,
    PLANET,
    ASTEROID,
    SHIP
} SpaceObject;

// Function prototypes
void initializeMap(SpaceObject map[MAP_SIZE][MAP_SIZE]);
void printMap(SpaceObject map[MAP_SIZE][MAP_SIZE]);
void moveShip(int direction, int *shipX, int *shipY);
bool checkValidMove(int direction, int shipX, int shipY);
void interactWithObject(SpaceObject object);

int main() {
    // Initialize the game map
    SpaceObject map[MAP_SIZE][MAP_SIZE];
    initializeMap(map);
    printf("Welcome to the Procedural Space Adventure!\n");

    // Set starting location of player's ship
    int shipX = MAP_SIZE / 2;
    int shipY = MAP_SIZE / 2;
    map[shipX][shipY] = SHIP;
    printf("You are starting at (%d,%d)\n", shipX, shipY);
    printMap(map);

    // Main game loop
    while (true) {
        printf("Enter a direction to move (1=up, 2=down, 3=left, 4=right): ");
        int direction;
        scanf("%d", &direction);
        if (checkValidMove(direction, shipX, shipY)) {
            moveShip(direction, &shipX, &shipY);
            SpaceObject currentObject = map[shipX][shipY];
            interactWithObject(currentObject);
            if (currentObject != SHIP) {
                map[shipX][shipY] = EMPTY;
            }
            map[shipX][shipY] = SHIP;
            printMap(map);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return 0;
}

// Function to initialize the game map
void initializeMap(SpaceObject map[MAP_SIZE][MAP_SIZE]) {
    // Randomly generate planets and asteroids
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            int objectType = rand() % 4;
            if (objectType == 0) {
                map[i][j] = PLANET;
            } else if (objectType == 1) {
                map[i][j] = ASTEROID;
            } else {
                map[i][j] = EMPTY;
            }
        }
    }
}

// Function to print the game map
void printMap(SpaceObject map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            switch (map[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case PLANET:
                    printf("P ");
                    break;
                case ASTEROID:
                    printf("A ");
                    break;
                case SHIP:
                    printf("S ");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to move the ship in a given direction
void moveShip(int direction, int *shipX, int *shipY) {
    switch (direction) {
        case 1:
            (*shipX)--;
            break;
        case 2:
            (*shipX)++;
            break;
        case 3:
            (*shipY)--;
            break;
        case 4:
            (*shipY)++;
            break;
    }
}

// Function to check if a given move is valid
bool checkValidMove(int direction, int shipX, int shipY) {
    switch (direction) {
        case 1:
            return shipX > 0;
        case 2:
            return shipX < MAP_SIZE - 1;
        case 3:
            return shipY > 0;
        case 4:
            return shipY < MAP_SIZE - 1;
        default:
            return false;
    }
}

// Function to interact with a space object
void interactWithObject(SpaceObject object) {
    switch (object) {
        case EMPTY:
            printf("You move forward into empty space.\n");
            break;
        case PLANET:
            printf("You land on a nearby planet and explore its surface.\n");
            break;
        case ASTEROID:
            printf("You dodge past a dangerous asteroid belt and continue on your way.\n");
            break;
        case SHIP:
            printf("You encounter another ship and engage in a friendly space battle.\n");
            break;
    }
}