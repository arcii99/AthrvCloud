//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>

int main() {
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int throttle = 0;

    printf("Welcome to the Drone Remote Control Program!\n");

    while (1) {
        printf("\nEnter pitch value (-100 to 100): ");
        scanf("%d", &pitch);

        printf("Enter roll value (-100 to 100): ");
        scanf("%d", &roll);

        printf("Enter yaw value (-100 to 100): ");
        scanf("%d", &yaw);

        printf("Enter throttle value (0 to 100): ");
        scanf("%d", &throttle);

        // Here, we can send these values to the drone
        // to control its movement

        printf("\nSending pitch = %d, roll = %d, yaw = %d, throttle = %d to the drone.\n", pitch, roll, yaw, throttle);
    }

    return 0;
}