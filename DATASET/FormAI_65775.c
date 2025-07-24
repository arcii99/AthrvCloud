//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25

char map[MAP_HEIGHT][MAP_WIDTH];
int playerX, playerY;

void generateMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int randNum = rand() % 100;
            if (randNum < 45) {
                map[i][j] = '.';
            } else if (randNum < 90) {
                map[i][j] = '#';
            } else {
                map[i][j] = '+';
            }
        }
    }
}

void printMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == playerY && j == playerX) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    switch (direction) {
        case 'n':
            playerY--;
            break;
        case 's':
            playerY++;
            break;
        case 'e':
            playerX++;
            break;
        case 'w':
            playerX--;
            break;
    }
}

int main() {
    srand(time(NULL));
    generateMap();
    playerX = MAP_WIDTH / 2;
    playerY = MAP_HEIGHT / 2;
    while (1) {
        system("clear");
        printMap();
        printf("Enter a direction (n/s/e/w): ");
        char input;
        scanf(" %c", &input);
        movePlayer(input);
    }
    return 0;
}