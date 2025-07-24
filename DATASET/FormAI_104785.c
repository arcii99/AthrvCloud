//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

void generateMap(char map[][MAP_SIZE]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            // randomly generate a tile type
            int tile_type = rand() % 4;
            switch(tile_type) {
                case 0:
                    map[i][j] = '.';
                    break;
                case 1:
                case 2:
                    map[i][j] = '#';
                    break;
                case 3:
                    map[i][j] = '@';
                    break;
            }
        }
    }
}

void printMap(char map[][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];

    generateMap(map);
    printMap(map);

    return 0;
}