//FormAI DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEVICES 10

// Define a structure for each device in the smart home
typedef struct {
    char name[20];
    bool state;
} Device;

// Define a structure for the smart home
typedef struct {
    Device devices[MAX_DEVICES];
    int num_devices;
} SmartHome;

// Function to add a device to the smart home
void add_device(SmartHome *home, char *name) {
    if (home->num_devices == MAX_DEVICES) {
        printf("Error: Maximum number of devices reached.\n");
        return;
    }
    Device new_device;
    strcpy(new_device.name, name);
    new_device.state = false;
    home->devices[home->num_devices++] = new_device;
    printf("Device \"%s\" added.\n", name);
}

// Function to remove a device from the smart home
void remove_device(SmartHome *home, char *name) {
    for (int i = 0; i < home->num_devices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            Device removed = home->devices[i];
            for (int j = i; j < home->num_devices - 1; j++) {
                home->devices[j] = home->devices[j+1];
            }
            home->num_devices--;
            printf("Device \"%s\" removed.\n", removed.name);
            return;
        }
    }
    printf("Error: Device \"%s\" not found.\n", name);
}

// Function to toggle the state of a device
void toggle_device(SmartHome *home, char *name) {
    for (int i = 0; i < home->num_devices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = !home->devices[i].state;
            if (home->devices[i].state) {
                printf("Device \"%s\" turned on.\n", name);
            } else {
                printf("Device \"%s\" turned off.\n", name);
            }
            return;
        }
    }
    printf("Error: Device \"%s\" not found.\n", name);
}

int main() {
    SmartHome my_home;
    my_home.num_devices = 0;
    add_device(&my_home, "Light 1");
    add_device(&my_home, "Light 2");
    add_device(&my_home, "TV");
    toggle_device(&my_home, "Light 1");
    toggle_device(&my_home, "Light 3");
    remove_device(&my_home, "Light 1");
    return 0;
}