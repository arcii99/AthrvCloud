//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int x = 0, y = 0, maxX = 10, maxY = 10, i = 0;
    srand(time(NULL)); // Seed the random number generator

    while (i < 5) { // Robot should move 5 times
        int moveX = generateRandNum(-1, 1);
        int moveY = generateRandNum(-1, 1);

        // Check if robot stays within bounds of maxX and maxY
        if ((x + moveX < 0) || (x + moveX > maxX)) {
            moveX *= -1; // Change X direction
        }
        if ((y + moveY < 0) || (y + moveY > maxY)) {
            moveY *= -1; // Change Y direction
        }

        // Update robot position
        x += moveX;
        y += moveY;

        printf("Moved %d steps on X, %d steps on Y. New position: (%d, %d)\n", moveX, moveY, x, y);
        i++;
    }

    printf("Final Position: (%d, %d)\n", x, y); // Print final position of the robot

    return 0;
}