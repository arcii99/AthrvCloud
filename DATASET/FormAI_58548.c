//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

// Sensors
bool motionSensor = false;
bool doorSensor = false;
bool windowSensor = false;

// Switches
bool lightSwitch = false;
bool doorLockSwitch = false;
bool windowLockSwitch = false;

// Actuators
bool lightBulb = false;
bool doorLock = false;
bool windowLock = false;

// Function to turn the lightbulb on or off
void toggleLightBulb(bool value) {
    lightBulb = value;
    if (value == true) {
        printf("Lightbulb turned ON\n");
    } else {
        printf("Lightbulb turned OFF\n");
    }
}

// Function to lock or unlock the door 
void toggleDoorLock(bool value) {
    doorLock = value;
    if (value == true) {
        printf("Door locked\n");
    } else {
        printf("Door unlocked\n");
    }
}

// Function to lock or unlock the window
void toggleWindowLock(bool value) {
    windowLock = value;
    if (value == true) {
        printf("Window locked\n");
    } else {
        printf("Window unlocked\n");
    }
}

int main() {
    // Check the state of the sensors and act accordingly
    while (true) {
        if (motionSensor == true && lightSwitch == true) {
            toggleLightBulb(true);
        } else {
            toggleLightBulb(false);
        }
        
        if (doorSensor == true && doorLockSwitch == true) {
            toggleDoorLock(true);
        } else {
            toggleDoorLock(false);
        }
        
        if (windowSensor == true && windowLockSwitch == true) {
            toggleWindowLock(true);
        } else {
            toggleWindowLock(false);
        }
    }
    return 0;
}