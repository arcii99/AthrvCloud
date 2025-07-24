//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdbool.h>

// Define constants
#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20

// Define a struct to represent a device
typedef struct {
    char name[MAX_NAME_LENGTH];
    bool on;
} Device;

// Define a struct to represent a home with devices
typedef struct {
    Device devices[MAX_DEVICES];
    int numDevices;
} Home;

// Function to add a device to the home
void addDevice(Home *home, char name[MAX_NAME_LENGTH], bool on) {
    // Check if the home has reached the maximum number of devices
    if(home->numDevices >= MAX_DEVICES) {
        printf("Cannot add device. Maximum number of devices reached.\n");
        return;
    }

    // Add the device to the home
    Device device;
    strcpy(device.name, name);
    device.on = on;
    home->devices[home->numDevices] = device;
    home->numDevices++;
}

// Function to turn a device on or off
void toggleDevice(Device *device) {
    device->on = !device->on;
}

// Function to print the status of all devices in a home
void printDevices(Home *home) {
    printf("Current devices in home:\n");
    for(int i = 0; i < home->numDevices; i++) {
        printf("%s: %s\n", home->devices[i].name, home->devices[i].on ? "ON" : "OFF");
    }
}

int main() {
    // Create a home
    Home home = { .devices = {}, .numDevices = 0 };

    // Add devices to the home
    addDevice(&home, "Living Room Lights", false);
    addDevice(&home, "Kitchen Lights", true);
    addDevice(&home, "Bedroom Lights", false);

    // Print the initial status of all devices
    printDevices(&home);

    // Turn on the living room lights
    toggleDevice(&home.devices[0]);

    // Print the new status of all devices
    printDevices(&home);

    return 0;
}