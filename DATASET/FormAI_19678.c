//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Initialize sensors and devices
    bool motionSensor = false;
    bool lightSwitch = false;
    bool doorLock = false;
    
    // Execute smart home automation process
    while (true) {
        printf("Checking sensors...\n");
        
        // Check motion sensor
        if (!motionSensor) {
            printf("Motion detected! Turning on lights...\n");
            lightSwitch = true;
        } else {
            printf("No motion detected.\n");
            lightSwitch = false;
        }
        
        // Check door lock
        if (!doorLock) {
            printf("Door unlocked. Locking door...\n");
            doorLock = true;
        } else {
            printf("Door locked.\n");
        }
        
        // Check light switch
        if (lightSwitch) {
            printf("Lights on.\n");
        } else {
            printf("Lights off.\n");
        }
        
        printf("Process completed. Sleeping...\n\n");
        
        // Simulate waiting for sensor updates
        for (int i = 0; i < 5; i++) {
            printf("%d seconds until next update...\n", 5 - i);
        }
        
        // Simulate sensor updates
        printf("Updating sensor data...\n");
        motionSensor = !motionSensor;
        printf("Sensor data updated.\n\n");
    }
    
    return 0;
}