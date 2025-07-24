//FormAI DATASET v1.0 Category: Robot movement control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for each movement
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Set starting position
    int x = 0;
    int y = 0;

    // Display starting position
    printf("Starting position: (%d, %d)\n", x, y);

    // Loop 50 times to perform 50 movements
    for (int i = 0; i < 50; i++) {

        // Choose a random movement
        int movement = rand() % 4 + 1;

        // Perform the movement and update position
        switch (movement) {
            case RIGHT:
                x++;
                printf("Mov to RIGHT: (%d, %d)\n", x, y);
                break;
            case LEFT:
                x--;
                printf("Mov to LEFT: (%d, %d)\n", x, y);
                break;
            case UP:
                y++;
                printf("Mov to UP: (%d, %d)\n", x, y);
                break;
            case DOWN:
                y--;
                printf("Mov to DOWN: (%d, %d)\n", x, y);
                break;
        }

        // Add a delay to simulate time passing
        usleep(500000);
    }

    // Display final position
    printf("Final position: (%d, %d)\n", x, y);

    return 0;
}