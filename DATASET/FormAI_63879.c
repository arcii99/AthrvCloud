//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define MAX_ROOMS 6

char dungeon[ROWS][COLS];

int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate a room in a given area
void generate_room(int min_row, int max_row, int min_col, int max_col) {
    int rows = rand_range(3, 6);
    int cols = rand_range(5, 10);
    int row = rand_range(min_row, max_row - rows);
    int col = rand_range(min_col, max_col - cols);

    for (int i = row; i < row + rows; i++) {
        for (int j = col; j < col + cols; j++) {
            dungeon[i][j] = '.';
        }
    }
}

// Generate a dungeon with random rooms
void generate_dungeon() {
    // Initialize dungeon
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dungeon[i][j] = '#';
        }
    }

    // Generate rooms
    int num_rooms = rand_range(1, MAX_ROOMS);
    for (int i = 0; i < num_rooms; i++) {
        generate_room(1, ROWS - 1, 1, COLS - 1);
    }
}

// Print the dungeon
void print_dungeon() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_dungeon();
    print_dungeon();
    return 0;
}