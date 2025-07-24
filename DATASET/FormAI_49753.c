//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

char map[ROWS][COLS];

void generate_map() {
    srand(time(NULL));

    // Fill map with empty spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            map[i][j] = ' ';
        }
    }

    // Generate walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                map[i][j] = '#';
            } else if(rand() % 10 < 3) {
                map[i][j] = '#';
            }
        }
    }

    // Generate player location
    int player_x = rand() % (COLS-2) + 1;
    int player_y = rand() % (ROWS-2) + 1;
    map[player_y][player_x] = '@';
}

void print_map() {
    for(int i = 0; i < ROWS; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}