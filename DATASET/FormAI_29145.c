//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up variables
    int x = 0, y = 0;
    char direction = 'N';

    // Generate a random seed using time
    srand(time(NULL));

    // Loop 20 times to simulate moving the RC vehicle
    for (int i = 0; i < 20; i++) {
        // Generate a random number between 1 and 4 for direction
        int randNum = rand() % 4 + 1;

        // Update direction and coordinates based on random number
        switch (randNum) {
            case 1:
                direction = 'N';
                y++;
                break;
            case 2:
                direction = 'S';
                y--;
                break;
            case 3:
                direction = 'E';
                x++;
                break;
            case 4:
                direction = 'W';
                x--;
                break;
        }

        // Print current direction and coordinates
        printf("Move %d: %c (%d,%d)\n", i+1, direction, x, y);
    }
    
    // End program
    return 0;
}