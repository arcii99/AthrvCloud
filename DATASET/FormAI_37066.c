//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define DIRECTION_SIZE 4

// function prototypes
void generateMap(int map[][MAP_SIZE]);
void printMap(int map[][MAP_SIZE]);
void movePlayer(int *x, int *y, int direction);
void searchForResources(int map[][MAP_SIZE], int x, int y);

int main() {
    int map[MAP_SIZE][MAP_SIZE];
    int playerX = MAP_SIZE / 2;
    int playerY = MAP_SIZE / 2;
    int playerHealth = 100;

    generateMap(map);
    printMap(map);

    // main game loop
    while(playerHealth > 0) {
        printf("Health: %d\n", playerHealth);

        int direction;
        printf("Enter direction (0:up, 1:right, 2:down, 3:left): ");
        scanf("%d", &direction);

        if(direction < 0 || direction > DIRECTION_SIZE-1) {
            printf("Invalid direction!\n");
            continue;
        }

        movePlayer(&playerX, &playerY, direction);
        printMap(map);

        searchForResources(map, playerX, playerY);

        playerHealth -= rand() % 10 + 1;
    }

    printf("Game Over!\n");
    return 0;
}

/**
 * Function to generate the game map
 */
void generateMap(int map[][MAP_SIZE]) {
    srand(time(NULL));  // seed random number generator

    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            if(rand() % 100 < 10) {  // 10% chance of resource
                map[i][j] = rand() % 4 + 1;  // randomly assign resource value 1-4
            } else {
                map[i][j] = 0;
            }
        }
    }
}

/**
 * Function to print the game map to the console
 */
void printMap(int map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Function to move the player on the game map
 */
void movePlayer(int *x, int *y, int direction) {
    switch(direction) {
        case 0:  // up
            if(*y > 0) {
                (*y)--;
            }
            break;
        case 1:  // right
            if(*x < MAP_SIZE-1) {
                (*x)++;
            }
            break;
        case 2:  // down
            if(*y < MAP_SIZE-1) {
                (*y)++;
            }
            break;
        case 3:  // left
            if(*x > 0) {
                (*x)--;
            }
            break;
        default:
            break;
    }
}

/**
 * Function to search for resources on the game map
 */
void searchForResources(int map[][MAP_SIZE], int x, int y) {
    int resourceValue = map[y][x];

    if(resourceValue > 0) {
        printf("Found resource worth %d\n", resourceValue);
        map[y][x] = 0;
    }
}