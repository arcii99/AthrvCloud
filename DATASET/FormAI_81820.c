//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int x = 0;
    int y = 0;

    // Initialize the robot position to (0,0)
    printf("Robot position: (%d,%d)\n", x, y);

    // Generate random movements
    for (int i = 0; i < 10; i++) {
        int choice = rand() % 4 + 1; // Randomly choose a direction

        switch (choice) {
            case 1: // Move up
                y++;
                break;
            case 2: // Move down
                y--;
                break;
            case 3: // Move left
                x--;
                break;
            case 4: // Move right
                x++;
                break;
        }

        printf("Robot position: (%d,%d)\n", x, y);
    }

    return 0;
}