//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

// Function that generates a random number between min and max
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char map[HEIGHT][WIDTH]; // Allocate the map

    // Generate the map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int rand_int = random_int(0, 99); // Generate a random number between 0 and 99
            if (rand_int < 50) { // 50% chance of a wall
                map[y][x] = '#';
            } else { // 50% chance of an empty space
                map[y][x] = '.';
            }
        }
    }

    // Print the map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}