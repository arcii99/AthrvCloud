//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>

struct remoteControlVehicle {
    int speed;
    int direction;
    int batteryLevel;
};

int main() {
    struct remoteControlVehicle rcv = {0, 0, 100};
    
    printf("Remote Control Vehicle Simulation\n");
    printf("Speed: %d\nDirection: %d\nBattery Level: %d\n", rcv.speed, rcv.direction, rcv.batteryLevel);
    
    // user input for speed and direction
    printf("Enter speed (0-100): ");
    scanf("%d", &rcv.speed);
    
    printf("Enter direction (-180 to 180): ");
    scanf("%d", &rcv.direction);
    
    // simulation begins
    printf("\nSimulation Begins\n");
    
    // checks if battery level is above minimum
    while (rcv.batteryLevel > 20) {
        printf("\nSpeed: %d\nDirection: %d\n", rcv.speed, rcv.direction);
        printf("Battery Level: %d\n", rcv.batteryLevel);
        
        // decrease battery level over time
        rcv.batteryLevel -= 5;
        
        // user input for speed and direction
        printf("Enter speed (0-100): ");
        scanf("%d", &rcv.speed);
        
        printf("Enter direction (-180 to 180): ");
        scanf("%d", &rcv.direction);
    }
    
    // battery level is below minimum
    printf("\nBattery level below minimum. Simulation ended.\n");
    
    return 0;
}