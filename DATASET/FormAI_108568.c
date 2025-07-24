//FormAI DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices that can be controlled
#define MAX_DEVICES 10

// Define a structure for representing a smart device
typedef struct {
    char name[30];
    char type[20];
    int state;  // 0=off, 1=on
} SmartDevice;

// Define a structure for representing a smart home
typedef struct {
    char name[30];
    int numDevices;
    SmartDevice devices[MAX_DEVICES];
} SmartHome;

// Define a function for adding a new device to a smart home
void addDevice(SmartHome *home, char *name, char *type) {
    if (home->numDevices < MAX_DEVICES) {
        SmartDevice device;
        strcpy(device.name, name);
        strcpy(device.type, type);
        device.state = 0;  // default state is off
        home->devices[home->numDevices] = device;
        home->numDevices++;
        printf("Device %s added to %s\n", name, home->name);
    } else {
        printf("Cannot add device, max limit reached\n");
    }
}

// Define a function for turning a device on or off
void toggleDevice(SmartHome *home, char *name) {
    int i;
    for (i = 0; i < home->numDevices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            if (home->devices[i].state == 0) {
                home->devices[i].state = 1;
                printf("%s turned ON\n", home->devices[i].name);
            } else {
                home->devices[i].state = 0;
                printf("%s turned OFF\n", home->devices[i].name);
            }
            return;
        }
    }
    printf("Device not found\n");
}

// Define a function for printing the status of all devices in a smart home
void printStatus(SmartHome *home) {
    printf("%s:\n", home->name);
    int i;
    for (i = 0; i < home->numDevices; i++) {
        printf("%s %s status: %s\n", home->devices[i].type, home->devices[i].name, home->devices[i].state ? "ON" : "OFF");
    }
}

int main() {
    // Create a new smart home and add some devices
    SmartHome home;
    strcpy(home.name, "My Home");
    home.numDevices = 0;
    addDevice(&home, "Living Room Lights", "Light");
    addDevice(&home, "Bedroom AC", "AC");
    addDevice(&home, "Kitchen Fan", "Fan");
    
    // Print the status of all devices in the home
    printStatus(&home);
    
    // Turn a device on or off
    toggleDevice(&home, "Living Room Lights");
    toggleDevice(&home, "Bedroom AC");
    
    // Print the status of all devices in the home again
    printStatus(&home);
    
    return 0;
}