//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define STAIRCASE 5

char map[SIZE][SIZE];

int playerX, playerY;
int enemyX, enemyY;
int staircaseX, staircaseY;
int level = 1;

void generateMap() {
    int i, j;
    srand(time(NULL));

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            // randomly generate wall or floor
            if(rand() % 100 < 40) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = '.';
            }
        }
    }

    // place player randomly
    playerX = rand() % SIZE;
    playerY = rand() % SIZE;
    map[playerX][playerY] = '@';

    // place enemy randomly
    do {
        enemyX = rand() % SIZE;
        enemyY = rand() % SIZE;
    } while(map[enemyX][enemyY] != '.');
    map[enemyX][enemyY] = 'E';

    // place staircase randomly
    do {
        staircaseX = rand() % SIZE;
        staircaseY = rand() % SIZE;
    } while(map[staircaseX][staircaseY] != '.' || (staircaseX == playerX && staircaseY == playerY) || (staircaseX == enemyX && staircaseY == enemyY));
    map[staircaseX][staircaseY] = '>';
}

void printMap() {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;

    while(1) {
        printf("Level %d\n\n", level);
        generateMap();
        printMap();

        while(1) {
            char move;
            printf("Move (W/A/S/D): ");
            scanf(" %c", &move);

            int newPlayerX = playerX, newPlayerY = playerY;

            if(move == 'W') {
                newPlayerX--;
            }
            else if(move == 'A') {
                newPlayerY--;
            }
            else if(move == 'S') {
                newPlayerX++;
            }
            else if(move == 'D') {
                newPlayerY++;
            }

            if(map[newPlayerX][newPlayerY] == '#') {
                printf("You cannot move there!\n");
            }
            else if(map[newPlayerX][newPlayerY] == 'E') {
                printf("You have been killed!\n");
                exit(0);
            }
            else if(newPlayerX == staircaseX && newPlayerY == staircaseY) {
                level++;
                break;
            }
            else {
                map[playerX][playerY] = '.';
                playerX = newPlayerX;
                playerY = newPlayerY;
                map[playerX][playerY] = '@';
            }
        }
    }

    return 0;
}