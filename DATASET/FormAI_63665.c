//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_WIDTH][MAP_HEIGHT];
int player_x, player_y;

void generate_map() {
    int i, j;
    for(i = 0; i < MAP_WIDTH; i++) {
        for(j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = '.';
        }
    }

    srand(time(NULL));
    int num_obstacles = rand() % 20 + 10;
    int k;
    for(k = 0; k < num_obstacles; k++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;

        if(map[x][y] != '#') {
            map[x][y] = '#';
        }
    }

    player_x = rand() % MAP_WIDTH;
    player_y = rand() % MAP_HEIGHT;
    map[player_x][player_y] = '@';
}

void print_map() {
    int i, j;
    for(j = 0; j < MAP_HEIGHT; j++) {
        for(i = 0; i < MAP_WIDTH; i++) {
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