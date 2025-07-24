//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point pos;
    char symbol;
} Entity;

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    // Fill map with nothing
    for (int row=0; row<MAP_HEIGHT; row++) {
        for (int col=0; col<MAP_WIDTH; col++) {
            map[row][col] = ' ';
        }
    }

    // Place obstacles
    for (int i=0; i<20; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x] = '#';
    }

    // Place player
    Point player_pos = {MAP_WIDTH/2, MAP_HEIGHT/2};
    Entity player = {player_pos, '@'};
    map[player_pos.y][player_pos.x] = '@';
}

void print_map() {
    for (int row=0; row<MAP_HEIGHT; row++) {
        for (int col=0; col<MAP_WIDTH; col++) {
            printf("%c", map[row][col]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random generator

    generate_map();
    print_map();

    return 0;
}