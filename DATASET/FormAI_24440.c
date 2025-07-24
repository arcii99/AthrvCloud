//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

int map[WIDTH][HEIGHT];

void create_map() {
    int x, y;
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            if(rand() % 5 == 0) {
                map[x][y] = '#';
            } else {
                map[x][y] = '.';
            }
        }
    }
}

void print_map() {
    int x, y;
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    create_map();
    print_map();
    return 0;
}