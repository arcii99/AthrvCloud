//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>

void droneController(int distance, int altitude, int speed) {
    if (altitude >= 100) {
        printf("Drone reached maximum altitude of 100m. Descending...\n");
        droneController(distance, altitude - 20, speed);
    } else if (distance >= 500) {
        printf("Drone reached maximum distance of 500m. Returning...\n");
        droneController(0, altitude, speed);
    } else {
        printf("Distance: %d m\n", distance);
        printf("Altitude: %d m\n", altitude);
        printf("Speed: %d m/s\n", speed);
        
        char command;
        printf("Enter command (f = forward, b = backward, u = up, d = down, s = stop): ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'f':
                droneController(distance + 50, altitude, speed);
                break;
            case 'b':
                droneController(distance - 50, altitude, speed);
                break;
            case 'u':
                droneController(distance, altitude + 10, speed);
                break;
            case 'd':
                droneController(distance, altitude - 10, speed);
                break;
            case 's':
                printf("Drone stopped.\n");
                break;
            default:
                printf("Invalid command.\n");
                droneController(distance, altitude, speed);
                break;
        }
    }
}

int main() {
    printf("C Drone Remote Control\n");
    droneController(0, 0, 10);
    return 0;
}