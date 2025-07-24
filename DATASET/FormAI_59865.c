//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>

// Define the number of rooms in the house and number of devices per room
#define NUM_ROOMS 3
#define NUM_DEVICES_PER_ROOM 4

// Define data structure for each device
typedef struct {
    char* device_name;
    int is_on;
} Device;

// Define data structure for each room
typedef struct {
    char* room_name;
    Device devices[NUM_DEVICES_PER_ROOM];
} Room;

// Define function to turn on a device
void turn_on(Device* device) {
    device->is_on = 1;
    printf("%s is now on\n", device->device_name);
}

// Define function to turn off a device
void turn_off(Device* device) {
    device->is_on = 0;
    printf("%s is now off\n", device->device_name);
}

int main() {
    // Initialize rooms and devices
    Room rooms[NUM_ROOMS] = {
        {"Living Room", 
         {{"TV", 0}, {"Sofa Light", 0}, {"Table Light", 0}, {"Air Conditioner", 0}}
        },
        {"Bedroom", 
         {{"Bed Light", 0}, {"Lamp", 0}, {"Air Humidifier", 0}, {"Fan", 0}}
        },
        {"Kitchen", 
         {{"Fridge", 0}, {"Microwave", 0}, {"Oven", 0}, {"Toaster", 0}}
        }
    };
    
    // Loop through each room and device to perform actions
    int i, j;
    for (i = 0; i < NUM_ROOMS; i++) {
        // Check if room name is not empty
        if (rooms[i].room_name != NULL) {
            printf("---------%s---------\n", rooms[i].room_name);
            
            // Loop through each device in the room
            for (j = 0; j < NUM_DEVICES_PER_ROOM; j++) {
                // Check if device name is not empty
                if (rooms[i].devices[j].device_name != NULL) {
                    
                    // Turn on the device if it's off
                    if (rooms[i].devices[j].is_on == 0) {
                        turn_on(&rooms[i].devices[j]);
                    }
                    
                    // Turn off the device if it's on
                    else {
                        turn_off(&rooms[i].devices[j]);
                    }
                }
            }
        }
    }
    
    return 0;
}