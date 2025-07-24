//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, num, speed = 0, direction = 0;

    // Prompt user for the number of steps the vehicle takes
    printf("Enter the number of steps your remote control vehicle will take: ");
    scanf("%d", &num);

    printf("\nStarting simulation...\n");

    // Loop through each step and simulate the remote control vehicle's movement
    for(i = 1; i <= num; i++){

        // Prompt user for the speed of the vehicle
        printf("\nEnter the speed (from 0 to 10) for step %d: ", i);
        scanf("%d", &speed);

        // Validate speed input
        if(speed < 0 || speed > 10){
            printf("\nInvalid speed, please enter a speed from 0 to 10.\n");
            i -= 1;
            continue;
        }

        // Prompt user for the direction of the vehicle
        printf("Enter the direction (0 for forward, 1 for reverse) for step %d: ", i);
        scanf("%d", &direction);

        // Validate direction input
        if(direction != 0 && direction != 1){
            printf("\nInvalid direction, please enter 0 (for forward) or 1 (for reverse).\n");
            i -= 1;
            continue;
        }

        // Output the simulated movement of the vehicle
        printf("\nStep %d: Speed %d, Direction %s\n", i, speed, (direction == 0) ? "Forward" : "Reverse");
    }

    printf("\nSimulation complete.\n");

    return 0;
}