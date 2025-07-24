//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    int batteryLevel = 100;
    char direction[10] = "";
    char input[10] = "";
    int distance = 0;
    
    printf("Welcome to the remote control vehicle simulation program!\n");
    printf("Your vehicle is fully charged at 100%%.\n");
    
    while (1) {
        printf("Please enter a direction (forward, backward, left, right) and distance (in meters) separated by a space, or type 'exit' to quit: ");
        fgets(input, 10, stdin);
        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting program...\n");
            break;
        }
        sscanf(input, "%s %d", direction, &distance);
        if (strncmp(direction, "forward", 7) == 0) {
            printf("Moving forward %d meters...\n", distance);
            batteryLevel -= distance*2;
        } else if (strncmp(direction, "backward", 8) == 0) {
            printf("Moving backward %d meters...\n", distance);
            batteryLevel -= distance*2;
        } else if (strncmp(direction, "left", 4) == 0) {
            printf("Turning left...\n");
            batteryLevel -= 10;
        } else if (strncmp(direction, "right", 5) == 0) {
            printf("Turning right...\n");
            batteryLevel -= 10;
        } else {
            printf("Invalid input, please try again.\n");
            continue;
        }
        if (batteryLevel <= 0) {
            printf("Battery drained, vehicle cannot move.\n");
            break;
        }
        printf("Battery level: %d%%\n", batteryLevel);
    }

    return 0;
}