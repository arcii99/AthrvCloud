//FormAI DATASET v1.0 Category: Robot movement control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 0;
    int y = 0;
    srand(time(NULL));
    printf("Welcome to the Immersive C Robot Movement Control Program!\n\n");
    printf("Starting position: x = %d, y = %d\n\n", x, y);
    printf("Please input the number of steps you would like the robot to take: ");
    int steps;
    scanf("%d", &steps);
    printf("\n");

    for (int i = 0; i < steps; i++) {
        int direction = rand() % 4 + 1;
        switch (direction) {
            case 1: // move up
                y++;
                printf("Move #%d: Moved up! New position: x = %d, y = %d\n", i+1, x, y);
                break;
            case 2: // move down
                y--;
                printf("Move #%d: Moved down! New position: x = %d, y = %d\n", i+1, x, y);
                break;
            case 3: // move right
                x++;
                printf("Move #%d: Moved right! New position: x = %d, y = %d\n", i+1, x, y);
                break;
            case 4: // move left
                x--;
                printf("Move #%d: Moved left! New position: x = %d, y = %d\n", i+1, x, y);
                break;
        }
    }

    printf("\nRobot has completed its movements!\n");
    printf("Final position: x = %d, y = %d\n", x, y);

    return 0;
}