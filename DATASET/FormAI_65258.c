//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>

int main() {
    // Declare variables for light and motion sensors
    int light_sensor = 0;
    int motion_sensor = 0;
    
    // Set default values for light and motion sensors
    printf("Initializing smart home light control system...\n");
    printf("Light sensor: %d\n", light_sensor);
    printf("Motion sensor: %d\n\n", motion_sensor);
    
    // Loop to simulate constant monitoring of sensors
    while(1) {
        // Get updated values from sensors (in a real system, this would be done through hardware input)
        printf("Checking sensors...\n");
        light_sensor = rand() % 2; // randomly generate a 0 or 1 to simulate light levels
        motion_sensor = rand() % 2; // randomly generate a 0 or 1 to simulate motion detection
        
        // Based on sensor values, determine whether to turn lights on or off
        if(light_sensor == 0 && motion_sensor == 1) {
            printf("Motion detected! Turning on lights...\n\n");
            // Code here to turn lights on (in a real system, this would be done through hardware output)
        }
        else if(light_sensor == 1 && motion_sensor == 0) {
            printf("No motion detected. Checking light levels...\n");
            // Code here to check light level (in a real system, this would be done through hardware input)
            if(light_sensor < 50) { // if light level is too low, turn on lights
                printf("Light level low. Turning on lights...\n\n");
                // Code here to turn lights on (in a real system, this would be done through hardware output)
            }
            else {
                printf("Light level sufficient. Keeping lights off.\n\n");
                // Code here to keep lights off (in a real system, this would be done through hardware output)
            }
        }
        else {
            printf("No motion detected. Keeping lights off.\n\n");
            // Code here to keep lights off (in a real system, this would be done through hardware output)
        }
        
        // Pause program for 5 seconds to simulate constant monitoring
        sleep(5);
    }
    
    return 0;
}