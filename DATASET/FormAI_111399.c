//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

char map[MAP_WIDTH][MAP_HEIGHT];
int playerPosX, playerPosY;

void initMap() {
    int i, j;

    /* Initialize the map */
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[j][i] = '#';
        }
    }

    /* Place the player randomly */
    srand(time(NULL));
    playerPosX = rand() % MAP_WIDTH;
    playerPosY = rand() % MAP_HEIGHT;
    map[playerPosX][playerPosY] = '@';
}

void printMap() {
    int i, j;

    /* Print the map */
    printf("\033[2J"); /* Clear screen */
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[j][i]);
        }
        printf("\n");
    }
}

void updateMap(int dx, int dy) {
    /* Update the player position */
    if ((playerPosX + dx) >= 0 && (playerPosX + dx) < MAP_WIDTH) {
        playerPosX += dx;
    }
    if ((playerPosY + dy) >= 0 && (playerPosY + dy) < MAP_HEIGHT) {
        playerPosY += dy;
    }

    /* Update the map */
    initMap();
    map[playerPosX][playerPosY] = '@';
}

int main() {
    char input;
    int dx, dy;

    initMap();
    printMap();

    /* Game loop */
    do {
        /* Get user input */
        input = getchar();

        /* Update the map based on user input */
        switch (input) {
            case 'w':
                dx = 0;
                dy = -1;
                break;
            case 'a':
                dx = -1;
                dy = 0;
                break;
            case 's':
                dx = 0;
                dy = 1;
                break;
            case 'd':
                dx = 1;
                dy = 0;
                break;
            default:
                dx = 0;
                dy = 0;
        }
        updateMap(dx, dy);
        printMap();
    } while (input != 'q');

    return 0;
}