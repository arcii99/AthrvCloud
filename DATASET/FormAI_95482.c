//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n\n");

    int speed = 0; // initial speed set to 0
    int direction = 0; // initial direction set to 0

    printf("Please select a speed from 1 - 10:\n");
    scanf("%d", &speed);

    if(speed < 1 || speed > 10) {
        printf("Invalid speed selected. Please select a speed from 1 - 10.\n");
        return 0;
    }

    printf("Please select a direction from 1 - 4:\n");
    printf("1: Forward\n");
    printf("2: Right\n");
    printf("3: Backward\n");
    printf("4: Left\n");
    scanf("%d", &direction);

    if(direction < 1 || direction > 4) {
        printf("Invalid direction selected. Please select a direction from 1 - 4.\n");
        return 0;
    }

    // simulate vehicle movement
    switch(direction) {
        case 1:
            printf("Vehicle is moving forward at speed %d.\n", speed);
            break;
        case 2:
            printf("Vehicle is turning right at speed %d.\n", speed);
            break;
        case 3:
            printf("Vehicle is moving backward at speed %d.\n", speed);
            break;
        case 4:
            printf("Vehicle is turning left at speed %d.\n", speed);
            break;
    }

    printf("\nThank you for using the Remote Control Vehicle Simulation Program!\n");

    return 0;
}