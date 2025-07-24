//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 20

struct device {
    char* name;
    int status;
    int (*turn_on)();
    int (*turn_off)();
};

struct device devices[MAX_DEVICES];
int num_devices = 0;

int add_device(char* name, int status, int (*turn_on)(), int (*turn_off)()) {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: Too many devices.\n");
        return 0;
    }
    devices[num_devices].name = name;
    devices[num_devices].status = status;
    devices[num_devices].turn_on = turn_on;
    devices[num_devices].turn_off = turn_off;
    num_devices++;
    return 1;
}

int turn_on_device(char* name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            if (devices[i].status == 0) {
                int result = devices[i].turn_on();
                devices[i].status = result;
                return result;
            } else {
                printf("%s is already turned on.\n", name);
                return devices[i].status;
            }
        }
    }
    printf("Error: Device not found.\n");
    return 0;
}

int turn_off_device(char* name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            if (devices[i].status == 1) {
                int result = devices[i].turn_off();
                devices[i].status = result;
                return result;
            } else {
                printf("%s is already turned off.\n", name);
                return devices[i].status;
            }
        }
    }
    printf("Error: Device not found.\n");
    return 0;
}

// Example devices

int turn_on_lights() {
    printf("Lights turned on.\n");
    return 1;
}

int turn_off_lights() {
    printf("Lights turned off.\n");
    return 0;
}

int turn_on_fan() {
    printf("Fan turned on.\n");
    return 1;
}

int turn_off_fan() {
    printf("Fan turned off.\n");
    return 0;
}

int main() {
    // Add devices to the home automation system
    add_device("Living Room Lights", 0, turn_on_lights, turn_off_lights);
    add_device("Bedroom Lights", 0, turn_on_lights, turn_off_lights);
    add_device("Ceiling Fan", 0, turn_on_fan, turn_off_fan);

    // Turn on living room lights
    turn_on_device("Living Room Lights");

    // Turn off living room lights (already turned on)
    turn_off_device("Living Room Lights");

    // Turn on bedroom lights
    turn_on_device("Bedroom Lights");

    // Turn on ceiling fan
    turn_on_device("Ceiling Fan");

    // Turn off living room lights (already turned off)
    turn_off_device("Living Room Lights");

    return 0;
}