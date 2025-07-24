//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIGHT 1
#define FAN 2
#define AC 3

typedef struct {
    int id;
    bool status;
} Device;

void toggle(Device device);
void status(Device device);

int main() {
    Device living_room_light = {1, false};
    Device living_room_fan = {2, false};
    Device living_room_ac = {3, false};
    Device bedroom_light = {4, false};
    Device bedroom_fan = {5, false};
    Device bedroom_ac = {6, false};
    
    srand(time(NULL));  // initialize random seed
    
    // Randomly set devices' status for demonstration purposes
    living_room_light.status = rand() % 2;
    living_room_fan.status = rand() % 2;
    living_room_ac.status = rand() % 2;
    bedroom_light.status = rand() % 2;
    bedroom_fan.status = rand() % 2;
    bedroom_ac.status = rand() % 2;
    
    // Demonstration of device toggling and status checking
    toggle(living_room_light);
    toggle(bedroom_fan);
    toggle(living_room_ac);
    status(living_room_light);
    status(bedroom_fan);
    status(living_room_ac);
    
    return 0;
}

void toggle(Device device) {
    if (device.status) {
        printf("Turning off Device %d\n", device.id);
        device.status = false;
    } else {
        printf("Turning on Device %d\n", device.id);
        device.status = true;
    }
}

void status(Device device) {
    if (device.status) {
        printf("Device %d is on\n", device.id);
    } else {
        printf("Device %d is off\n", device.id);
    }
}