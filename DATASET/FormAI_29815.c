//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char map[WIDTH][HEIGHT];

void generate_map() {
    srand(time(NULL));
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (rand() % 10 < 7) { // 70% chance of generating a space
                map[x][y] = '.';
            } else { // 30% chance of generating a wall
                map[x][y] = '#';
            }
        }
    }
}

void print_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}