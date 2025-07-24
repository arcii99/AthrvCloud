//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

typedef struct {
    int row;
    int col;
} Position;

Position player_pos;
char map[ROWS][COLS];

void print_map() {
    system("clear");  // clear the console
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", map[i]);
    }
}

void init_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
}

void place_player() {
    int row, col;
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (map[row][col] != '#');
    player_pos.row = row;
    player_pos.col = col;
    map[row][col] = '@';
}

void place_enemies() {
    int num = rand() % 10 + 1;  // place 1 to 10 enemies
    for (int i = 0; i < num; i++) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (map[row][col] != '#');
        map[row][col] = 'E';
    }
}

void generate_map() {
    srand(time(NULL));
    init_map();
    place_player();
    place_enemies();
    print_map();
}

int main() {
    generate_map();
    return 0;
}