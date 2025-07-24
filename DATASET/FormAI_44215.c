//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

char map[MAP_SIZE][MAP_SIZE];
int playerX, playerY;

void generateMap();
void printMap();
void movePlayer(int x, int y);

int main()
{
    srand(time(NULL));
    generateMap();
    playerX = MAP_SIZE/2;
    playerY = MAP_SIZE/2;
    map[playerX][playerY] = '@';
    printMap();
    char input;
    while (1) {
        input = getchar();
        switch (input) {
            case 'w':
                movePlayer(-1, 0);
                break;
            case 's':
                movePlayer(1, 0);
                break;
            case 'a':
                movePlayer(0, -1);
                break;
            case 'd':
                movePlayer(0, 1);
                break;
            default:
                break;
        }
        system("clear");
        printMap();
    }
}

void generateMap()
{
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (rand()%10 == 0) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void printMap()
{
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        printf("|");
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c|", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int x, int y)
{
    if (playerX + x >= 0 && playerX + x < MAP_SIZE) {
        if (map[playerX+x][playerY+y] != '#') {
            map[playerX][playerY] = '.';
            playerX += x;
            playerY += y;
            map[playerX][playerY] = '@';
        }
    }
}