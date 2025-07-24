//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to simulate remote control vehicle
void remoteControlVehicle(int s, int d) {
    // Check for safe distances
    if (d <= 10) {
        printf("\nObstacle Detected! Move further back...\n");
    } else if (d >= 50) {
        printf("\nDistance too far! Move closer...\n");
    } else {
        // Move the vehicle
        if (s < 0) {
            printf("\nMoving backwards %d meters...\n", -s);
        } else {
            printf("\nMoving forwards %d meters...\n", s);
        }
    }
}

int main() {
    int speed, distance;
    // Loop to simulate remote control vehicle movements
    while(1) {
        // Prompt user for input
        printf("\nEnter movement speed (-5 to 5): ");
        scanf("%d", &speed);
        printf("Enter distance to move (10 to 50): ");
        scanf("%d", &distance);

        // Call function to move the vehicle
        remoteControlVehicle(speed, distance);
    }
    return 0;
}