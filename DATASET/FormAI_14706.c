//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

// Function to turn on/off the living room lights
void toggleLivingRoomLights(bool lightStatus) {
    if (lightStatus) {
        printf("Living room lights turned on.\n");
    } else {
        printf("Living room lights turned off.\n");
    }
}

// Function to set the temperature of the AC in the living room
void setLivingRoomTemperature(int temperature) {
    printf("Temperature in living room set to %d degrees.\n", temperature);
}

// Function to lock/unlock the front door
void toggleFrontDoor(bool doorLockStatus) {
    if (doorLockStatus) {
        printf("Front door locked.\n");
    } else {
        printf("Front door unlocked.\n");
    }
}

// Main function
int main() {
    bool livingRoomLights = false;
    int livingRoomTemperature = 23;
    bool frontDoorLocked = true;

    // Printing initial status of the devices
    toggleLivingRoomLights(livingRoomLights);
    setLivingRoomTemperature(livingRoomTemperature);
    toggleFrontDoor(frontDoorLocked);
    printf("\n");

    // Changing the status of the devices
    livingRoomLights = true;
    livingRoomTemperature = 25;
    frontDoorLocked = false;

    // Printing updated status of the devices
    toggleLivingRoomLights(livingRoomLights);
    setLivingRoomTemperature(livingRoomTemperature);
    toggleFrontDoor(frontDoorLocked);

    return 0;
}