//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25
#define MAX_MONSTERS 10

char map[MAP_HEIGHT][MAP_WIDTH];

struct monster {
    int x_pos;
    int y_pos;
    int health;
};

struct monster monsters[MAX_MONSTERS];

void print_map() {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void place_monsters() {
    srand(time(NULL));
    for(int i = 0; i < MAX_MONSTERS; i++) {
        monsters[i].x_pos = rand() % MAP_WIDTH;
        monsters[i].y_pos = rand() % MAP_HEIGHT;
        monsters[i].health = 100;
        map[monsters[i].y_pos][monsters[i].x_pos] = 'M';
    }
}

void generate_map() {
    srand(time(NULL));
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            if(rand() % 2 == 0) {
                map[i][j] = '.';
            } else {
                map[i][j] = '#';
            }
        }
    }
}

int main() {
    generate_map();
    place_monsters();
    print_map();
    return 0;
}