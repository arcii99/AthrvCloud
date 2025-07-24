//FormAI DATASET v1.0 Category: Robot movement control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random movements
int generateMovement() {
    int movement = rand() % 4;
    return movement;
}

int main() {
    int x = 0, y = 0;
    char direction;

    // Generate random seed
    srand(time(NULL));

    // Print starting position
    printf("Starting Position: (%d, %d)\n", x, y);

    // Loop for 25 movements
    for (int i = 0; i < 25; i++) {
        // Generate random movement
        int movement = generateMovement();

        // Move the robot
        switch (movement) {
            case 0:
                x++;
                direction = 'E';
                break;

            case 1:
                y++;
                direction = 'N';
                break;

            case 2:
                x--;
                direction = 'W';
                break;

            case 3:
                y--;
                direction = 'S';
                break;
        }

        // Output the movement
        printf("Movement %d: Moved %c, (%d, %d)\n", i+1, direction, x, y);
    }

    // Output final position
    printf("Final Position: (%d, %d)\n", x, y);

    return 0;
}