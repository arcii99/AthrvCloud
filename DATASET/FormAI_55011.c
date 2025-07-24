//FormAI DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
// Donald Knuth's Smart Home Automation Program

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DEVICES 10   // Maximum number of devices a home can have

typedef struct {
    bool state;
    char* name;
} device;

device home_devices[MAX_DEVICES];  // The array to store home devices

// Function to initialize the devices
void init_devices() {
    for(int i=0; i<MAX_DEVICES; i++) {
        home_devices[i].state = false;
        home_devices[i].name = "";
    }
}

// Function to add a new device to the home
void add_device(char* device_name) {
    for(int i=0; i<MAX_DEVICES; i++) {
        if(home_devices[i].name == "") {
            home_devices[i].state = false;
            home_devices[i].name = device_name;
            printf("%s device added to the home\n", device_name);
            return;
        }
    }
    printf("Cannot add device - Maximum limit reached\n");
}

// Function to remove a device from the home
void remove_device(char* device_name) {
    for(int i=0; i<MAX_DEVICES; i++) {
        if(home_devices[i].name == device_name) {
            home_devices[i].state = false;
            home_devices[i].name = "";
            printf("%s device removed from the home\n", device_name);
            return;
        }
    }
    printf("Cannot remove device - Device not found\n");
}

// Function to turn on a device
void turn_on_device(char* device_name) {
    for(int i=0; i<MAX_DEVICES; i++) {
        if(home_devices[i].name == device_name) {
            home_devices[i].state = true;
            printf("%s device turned ON\n", device_name);
            return;
        }
    }
    printf("Cannot turn ON device - Device not found\n");
}

// Function to turn off a device
void turn_off_device(char* device_name) {
    for(int i=0; i<MAX_DEVICES; i++) {
        if(home_devices[i].name == device_name) {
            home_devices[i].state = false;
            printf("%s device turned OFF\n", device_name);
            return;
        }
    }
    printf("Cannot turn OFF device - Device not found\n");
}

// The main function
int main() {
    init_devices();
    add_device("Lights");
    add_device("AC");
    add_device("Fan");
    turn_on_device("Lights");
    turn_on_device("AC");
    turn_off_device("Fan");
    remove_device("AC");
    return 0;
}