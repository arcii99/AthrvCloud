//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 20
#define MAP_COLS 40

char map[MAP_ROWS][MAP_COLS];

void generate_map() {
    // Initialize the random number generator
    srand(time(NULL));

    // Fill the map with walls
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            map[i][j] = '#';
        }
    }

    // Add some random rooms
    for (int room = 0; room < 10; room++) {
        int row_start = rand() % (MAP_ROWS - 6) + 1;
        int col_start = rand() % (MAP_COLS - 12) + 1;
        int width = rand() % 10 + 5;
        int height = rand() % 6 + 3;

        for (int i = row_start; i < row_start + height; i++) {
            for (int j = col_start; j < col_start + width; j++) {
                map[i][j] = '.';
            }
        }
    }

    // Connect the rooms with corridors
    for (int i = 1; i < MAP_ROWS - 1; i++) {
        for (int j = 1; j < MAP_COLS - 1; j++) {
            if (map[i][j] == '.' && map[i][j-1] == '.' && map[i][j+1] == '.') {
                if (map[i-1][j] == '#' && map[i+1][j] == '#') {
                    map[i][j] = '#';
                }
            } else if (map[i][j] == '.' && map[i-1][j] == '.' && map[i+1][j] == '.') {
                if (map[i][j-1] == '#' && map[i][j+1] == '#') {
                    map[i][j] = '#';
                }
            }
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();

    return 0;
}