//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>

/* Define constants for limits of drone movement */
#define MAX_HEIGHT 100
#define MIN_HEIGHT 0
#define MAX_ANGLE 90
#define MIN_ANGLE -90

/* Function to move the drone */
void move_drone(int height, int angle) {
    /* Check if the height and angle are within limits */
    if (height > MAX_HEIGHT || height < MIN_HEIGHT) {
       printf("Error: Invalid height value!\n");
       return;
    }
    if (angle > MAX_ANGLE || angle < MIN_ANGLE) {
       printf("Error: Invalid angle value!\n");
       return;
    }
    /* If within limits, move the drone */
    printf("Drone moved to height: %d and angle: %d\n", height, angle);
}

int main() {
    int height, angle;

    printf("Enter the height (0-100): ");
    scanf("%d", &height);
    printf("Enter the angle (-90 to 90): ");
    scanf("%d", &angle);

    /* Move the drone based on user input */
    move_drone(height, angle);

    return 0;
}