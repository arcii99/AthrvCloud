//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    srand(time(NULL)); // seed random number generator
    for (int row=0; row<MAP_HEIGHT; row++) {
        for (int col=0; col<MAP_WIDTH; col++) {
            int rand_num = rand() % 100; // generate random number between 0 and 99

            if (rand_num < 10) {
                map[row][col] = '#'; // 10% chance of generating a wall
            } else {
                map[row][col] = '.'; // 90% chance of generating floor
            }
        }
    }
}

void display_map() {
    for (int row=0; row<MAP_HEIGHT; row++) {
        for (int col=0; col<MAP_WIDTH; col++) {
            printf("%c", map[row][col]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    display_map();
    return 0;
}