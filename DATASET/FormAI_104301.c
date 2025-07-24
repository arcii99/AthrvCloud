//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

typedef struct {
    int x;
    int y;
} Position;

int map[SIZE][SIZE];
Position playerPos;

void generateMap();
void placePlayer();
void printMap();

int main() {
    srand(time(NULL));
    generateMap();
    placePlayer();
    printMap();
    return 0;
}

void generateMap() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

void placePlayer() {
    int i, j;
    do {
        i = rand() % SIZE;
        j = rand() % SIZE;
    } while (map[i][j] != 0);
    playerPos.x = i;
    playerPos.y = j;
}

void printMap() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == playerPos.x && j == playerPos.y) {
                printf("@");
            } else {
                printf("%d", map[i][j]);
            }
        }
        printf("\n");
    }
}