//FormAI DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Declare variables to represent the state of various devices.
    bool isMotionDetected = false;
    bool isLightOn = false;
    bool isDoorLocked = true;
    bool isAlarmActivated = false;
    
    // Loop to simulate continuous operation of the smart home automation system.
    while (true) {
        // Check if motion is detected.
        if (isMotionDetected) {
            // If motion is detected, turn on the lights.
            isLightOn = true;
            printf("Motion Detected. Turning on Lights.\n");
            
            // Check if the door is locked.
            if (isDoorLocked) {
                // If the door is locked, unlock it.
                isDoorLocked = false;
                printf("Door is Locked. Unlocking the door.\n");
                
                // Activate the alarm.
                isAlarmActivated = true;
                printf("Activating the Alarm.\n");
            }
        } else {
            // If no motion is detected, turn off the lights.
            isLightOn = false;
            printf("No Motion Detected. Turning off Lights.\n");
            
            // Check if the door is unlocked.
            if (!isDoorLocked) {
                // If the door is unlocked, lock it.
                isDoorLocked = true;
                printf("Door is Unlocked. Locking the door.\n");
                
                // Deactivate the alarm.
                isAlarmActivated = false;
                printf("Deactivating the Alarm.\n");
            }
        }
        
        // Wait for some time before checking for motion again.
        printf("Waiting for 5 seconds...\n");
        sleep(5);
        
        // Simulate motion detected randomly.
        isMotionDetected = rand() % 2;
    }
    
    return 0;
}