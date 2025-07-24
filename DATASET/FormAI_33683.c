//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30

char map[MAP_HEIGHT][MAP_WIDTH];

void generateMap() {
    // Initialize the "map" array with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Place some floors randomly
    srand(time(NULL));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j] == '#' && rand() % 5 == 0) {
                map[i][j] = '.';
            }
        }
    }
}

int main() {
    generateMap();

    // Display the generated map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}