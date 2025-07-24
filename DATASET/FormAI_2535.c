//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the devices in the smart home
typedef enum {
    LIGHT,
    THERMOSTAT,
    LOCK,
    CAMERA
} Device;

// Define the states for each device
typedef enum {
    OFF,
    ON
} State;

// Define the rooms in the smart home
typedef enum {
    LIVING_ROOM,
    BEDROOM,
    KITCHEN,
    BATHROOM
} Room;

// Define the smart home object
typedef struct {
    State lightState[4];
    State thermostatState[4];
    State lockState[4];
    State cameraState[4];
} SmartHome;

// Initialize the smart home object
SmartHome initSmartHome() {
    SmartHome smartHome;

    for (int i = 0; i < 4; i++) {
        smartHome.lightState[i] = OFF;
        smartHome.thermostatState[i] = OFF;
        smartHome.lockState[i] = OFF;
        smartHome.cameraState[i] = OFF;
    }

    return smartHome;
}

// Turn on a device in a specific room
void turnOn(SmartHome *smartHome, Device device, Room room) {
    switch (device) {
        case LIGHT:
            smartHome->lightState[room] = ON;
            printf("Turned on light in room %d\n", room);
            break;
        case THERMOSTAT:
            smartHome->thermostatState[room] = ON;
            printf("Turned on thermostat in room %d\n", room);
            break;
        case LOCK:
            smartHome->lockState[room] = ON;
            printf("Locked room %d\n", room);
            break;
        case CAMERA:
            smartHome->cameraState[room] = ON;
            printf("Turned on camera in room %d\n", room);
            break;
    }
}

// Turn off a device in a specific room
void turnOff(SmartHome *smartHome, Device device, Room room) {
    switch (device) {
        case LIGHT:
            smartHome->lightState[room] = OFF;
            printf("Turned off light in room %d\n", room);
            break;
        case THERMOSTAT:
            smartHome->thermostatState[room] = OFF;
            printf("Turned off thermostat in room %d\n", room);
            break;
        case LOCK:
            smartHome->lockState[room] = OFF;
            printf("Unlocked room %d\n", room);
            break;
        case CAMERA:
            smartHome->cameraState[room] = OFF;
            printf("Turned off camera in room %d\n", room);
            break;
    }
}

// Check the status of a device in a specific room
void checkStatus(SmartHome smartHome, Device device, Room room) {
    switch (device) {
        case LIGHT:
            if (smartHome.lightState[room] == ON) {
                printf("Light in room %d is on\n", room);
            } else {
                printf("Light in room %d is off\n", room);
            }
            break;
        case THERMOSTAT:
            if (smartHome.thermostatState[room] == ON) {
                printf("Thermostat in room %d is on\n", room);
            } else {
                printf("Thermostat in room %d is off\n", room);
            }
            break;
        case LOCK:
            if (smartHome.lockState[room] == ON) {
                printf("Room %d is locked\n", room);
            } else {
                printf("Room %d is unlocked\n", room);
            }
            break;
        case CAMERA:
            if (smartHome.cameraState[room] == ON) {
                printf("Camera in room %d is on\n", room);
            } else {
                printf("Camera in room %d is off\n", room);
            }
            break;
    }
}

int main() {
    SmartHome smartHome = initSmartHome();

    // Turn on the lights in the living room
    turnOn(&smartHome, LIGHT, LIVING_ROOM);

    // Check the status of the lights in the living room
    checkStatus(smartHome, LIGHT, LIVING_ROOM);

    // Turn off the lights in the living room
    turnOff(&smartHome, LIGHT, LIVING_ROOM);

    // Check the status of the lights in the living room
    checkStatus(smartHome, LIGHT, LIVING_ROOM);

    return 0;
}