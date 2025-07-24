//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int speed = 0;
    int direction = 0;
    while(1) {
        printf("Enter speed (1-10): ");
        scanf("%d", &speed);
        printf("Enter direction (0-360): ");
        scanf("%d", &direction);
        printf("Vehicle moving at speed %d in direction %d\n", speed, direction);
        // Insert code for sending speed and direction commands to the remote controlled vehicle here
    }
    return 0;
}