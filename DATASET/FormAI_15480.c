//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

char world[HEIGHT][WIDTH];
char buffer[HEIGHT][WIDTH];
char characters[] = {' ', '*', '#'};

int main(void) {
    srand(time(NULL));
    int i, j;

    // Set initial world state
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 6 == 0) {
                world[i][j] = characters[rand() % 3];
            } else {
                world[i][j] = characters[0];
            }
            buffer[i][j] = characters[0];
        }
    }

    // Run simulation
    while (1) {
        // Clear screen
        system("clear");

        // Display current world state
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                printf("%c", world[i][j]);
            }
            printf("\n");
        }

        // Apply rules to create new world state
        for (i = 1; i < HEIGHT - 1; i++) {
            for (j = 1; j < WIDTH - 1; j++) {
                int count = 0;
                if (world[i - 1][j - 1] != characters[0]) count++;
                if (world[i - 1][j] != characters[0]) count++;
                if (world[i - 1][j + 1] != characters[0]) count++;
                if (world[i][j - 1] != characters[0]) count++;
                if (world[i][j + 1] != characters[0]) count++;
                if (world[i + 1][j - 1] != characters[0]) count++;
                if (world[i + 1][j] != characters[0]) count++;
                if (world[i + 1][j + 1] != characters[0]) count++;

                if (world[i][j] == characters[0] && count == 3) {
                    buffer[i][j] = characters[rand() % 3];
                } else if (world[i][j] != characters[0] && (count < 2 || count > 3)) {
                    buffer[i][j] = characters[0];
                } else {
                    buffer[i][j] = world[i][j];
                }
            }
        }

        // Copy buffer to world for next iteration
        memcpy(world, buffer, sizeof(buffer));
    }

    return 0;
}