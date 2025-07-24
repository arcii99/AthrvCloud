//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: energetic
#include <stdio.h>

int main() {
    int speed = 0, direction = 0;
    printf("Welcome to RC vehicle simulation!\n");
    printf("Enter a positive non-zero value for speed, and a direction (1 for forward, -1 for backward):\n");
    scanf("%d %d", &speed, &direction); // user input for speed and direction

    if(direction == 1) {
        printf("RC vehicle moving forward at speed %d\n", speed);
    } else if(direction == -1) {
        printf("RC vehicle moving backward at speed %d\n", speed);
    } else {
        printf("Invalid direction input! Please enter 1 for forward, or -1 for backward.\n");
        return 0;
    }

    printf("Enter a degree value for steering (between -45 and 45):\n");
    int steering = 0;
    scanf("%d", &steering); // user input for steering

    if(steering >= -45 && steering <= 45) {
        printf("RC vehicle turning by %d degrees\n", steering);
    } else {
        printf("Invalid steering input! Please enter a degree value between -45 and 45.\n");
        return 0;
    }

    printf("RC vehicle simulation complete. Thank you for using our program!\n");

    return 0;
}