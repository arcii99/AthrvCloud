//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configurable constants
#define MAX_DEVICES 10
#define MAX_NAME_LEN 20

// Device structure
typedef struct {
    char name[MAX_NAME_LEN];
    int state;
} Device;

// Smart Home system structure
typedef struct {
    char name[MAX_NAME_LEN];
    Device devices[MAX_DEVICES];
    int num_devices;
} SmartHomeSystem;

// Function prototypes
void init(SmartHomeSystem *system);
void add_device(SmartHomeSystem *system, char *name, int state);
void remove_device(SmartHomeSystem *system, char *name);
void toggle_device_state(Device *device);

int main() {
    // Initialize the Smart Home system
    SmartHomeSystem myHome;
    init(&myHome);

    // Add some devices
    add_device(&myHome, "Living Room Light", 0);
    add_device(&myHome, "Kitchen Light", 0);
    add_device(&myHome, "Bedroom Light", 0);

    // Turn on the lights in the living room and kitchen
    toggle_device_state(&myHome.devices[0]);
    toggle_device_state(&myHome.devices[1]);

    // Remove the bedroom light
    remove_device(&myHome, "Bedroom Light");

    // Print the state of each device
    printf("Devices in %s:\n", myHome.name);
    for (int i = 0; i < myHome.num_devices; i++) {
        printf("%s: %s\n", myHome.devices[i].name, myHome.devices[i].state ? "ON" : "OFF");
    }

    return 0;
}

// Initialize the Smart Home system
void init(SmartHomeSystem *system) {
    strcpy(system->name, "My Home");
    system->num_devices = 0;
}

// Add a new device to the Smart Home system
void add_device(SmartHomeSystem *system, char *name, int state) {
    if (system->num_devices < MAX_DEVICES) {
        Device new_device;
        strcpy(new_device.name, name);
        new_device.state = state;
        system->devices[system->num_devices] = new_device;
        system->num_devices++;
    }
}

// Remove a device with the given name from the Smart Home system
void remove_device(SmartHomeSystem *system, char *name) {
    int i;
    for (i = 0; i < system->num_devices; i++) {
        if (strcmp(system->devices[i].name, name) == 0) {
            break;
        }
    }
    if (i < system->num_devices) {
        for (int j = i; j < system->num_devices - 1; j++) {
            system->devices[j] = system->devices[j+1];
        }
        system->num_devices--;
    }
}

// Toggle the state of a device (ON to OFF or vice versa)
void toggle_device_state(Device *device) {
    device->state = !device->state;
}