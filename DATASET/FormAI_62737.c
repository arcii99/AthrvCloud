//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>

// Function declarations
void robotMove(int);

int main() {
    int distance;
    printf("How far should the robot move? ");
    scanf("%d", &distance);

    if (distance <= 0) {
        printf("Distance must be a positive integer.\n");
        return 1;
    }

    robotMove(distance);

    return 0;
}

// Recursive function to move the robot
void robotMove(int distance) {
    if (distance == 0) {
        return;
    }

    printf("Robot moves forward 1 unit.\n");
    robotMove(distance - 1);
    printf("Robot moves backward 1 unit.\n");
}