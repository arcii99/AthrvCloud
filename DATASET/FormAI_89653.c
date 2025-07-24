//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 50

char map[MAX_ROWS][MAX_COLS];

int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void generate_map() {
    // Fill map with empty spaces
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            map[i][j] = ' ';
        }
    }

    // Place walls randomly
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (random_int(1, 100) < 20) {
                map[i][j] = '#';
            }
        }
    }

    // Place player
    int player_x = random_int(0, MAX_COLS - 1);
    int player_y = random_int(0, MAX_ROWS - 1);
    map[player_y][player_x] = '@';
}

void print_map() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}