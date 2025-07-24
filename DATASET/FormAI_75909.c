//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int map[10][10]; // 10x10 map
int playerX; // player's x coordinate
int playerY; // player's y coordinate
int treasureX; // treasure's x coordinate
int treasureY; // treasure's y coordinate

void generateMap() {
    // initialize random seed
    srand(time(NULL));
    
    // generate map
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            // randomly generate ground or wall
            if(rand() % 2 == 0) {
                map[i][j] = 1; // ground
            } else {
                map[i][j] = 0; // wall
            }
        }
    }
    
    // randomly generate player and treasure coordinates
    playerX = rand() % 10;
    playerY = rand() % 10;
    treasureX = rand() % 10;
    treasureY = rand() % 10;
    
    // make sure player and treasure are not on walls
    while(map[playerY][playerX] == 0) {
        playerX = rand() % 10;
        playerY = rand() % 10;
    }
    while(map[treasureY][treasureX] == 0 || (treasureX == playerX && treasureY == playerY)) {
        treasureX = rand() % 10;
        treasureY = rand() % 10;
    }
}

void printMap() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            // print player or treasure or ground or wall
            if(i == playerY && j == playerX) {
                printf("P ");
            } else if(i == treasureY && j == treasureX) {
                printf("T ");
            } else if(map[i][j] == 1) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();
    
    return 0;
}