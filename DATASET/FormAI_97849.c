//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100   // Maximum speed
#define MIN_SPEED 0     // Minimum speed
#define MAX_ANGLE 90    // Maximum steering angle
#define MIN_ANGLE -90   // Minimum steering angle

int main(){
    int speed = 0;
    int angle = 0;

    while(1){
        printf("\nRemote Control Vehicle Simulation\n");
        printf("Current speed: %d\n", speed);
        printf("Current steering angle: %d\n", angle);

        // Get user input for speed and angle
        printf("\nEnter speed (0-100): ");
        scanf("%d", &speed);
        if(speed < MIN_SPEED || speed > MAX_SPEED){
            printf("Invalid speed!\n");
            continue;
        }

        printf("Enter steering angle (-90 to 90): ");
        scanf("%d", &angle);
        if(angle < MIN_ANGLE || angle > MAX_ANGLE){
            printf("Invalid steering angle!\n");
            continue;
        }

        // Perform simulation based on user input
        printf("\nSimulating Remote Control Vehicle...\n");
        printf("Acceleration: %d m/s^2\n", speed/10);
        printf("Turning Radius: %.2f m\n", 2 * (float)speed / (float)(angle + 90));

        // Check for speed and angle combinations that may cause the vehicle to flip
        if(speed > 50 && abs(angle) > 60){
            printf("\nWARNING! Possible flip at this speed and angle combination.\n");
        }
    }

    return 0;
}