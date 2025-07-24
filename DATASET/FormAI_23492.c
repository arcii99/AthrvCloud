//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Smart Home Devices
typedef struct {
    char* name;
    bool state;
} Device;

// Define Smart Home Rooms
typedef struct {
    char* name;
    int num_devices;
    Device *devices;
} Room;

// Define Smart Home
typedef struct {
    int num_rooms;
    Room *rooms;
} SmartHome;

// Function to turn on/off a device
void toggle_device(Device *device) {
    device->state = !device->state;
}

// Function to control a room
void control_room(Room *room) {
    int choice;
    do {
        // Display room devices and their states
        printf("\nRoom: %s\n", room->name);
        for (int i = 0; i < room->num_devices; i++) {
            printf("%d. %s - %s\n", i+1, room->devices[i].name, room->devices[i].state ? "On" : "Off");
        }
        printf("0. Exit\n");

        // Get user choice
        printf("Enter Choice: ");
        scanf("%d", &choice);

        // Toggle device state or exit
        if (choice > 0 && choice <= room->num_devices) {
            toggle_device(&room->devices[choice-1]);
        }
    } while (choice != 0);
}

// Function to control the smart home
void control_home(SmartHome *home) {
    int choice;
    do {
        // Display room names
        printf("\nSmart Home:\n");
        for (int i = 0; i < home->num_rooms; i++) {
            printf("%d. %s\n", i+1, home->rooms[i].name);
        }
        printf("0. Exit\n");

        // Get user choice
        printf("Enter Choice: ");
        scanf("%d", &choice);

        // Control room or exit
        if (choice > 0 && choice <= home->num_rooms) {
            control_room(&home->rooms[choice-1]);
        }
    } while (choice != 0);
}

// Main function
int main() {
    // Create Smart Home
    SmartHome home = {
        .num_rooms = 2,
        .rooms = (Room[]) {
            {
                .name = "Living Room",
                .num_devices = 2,
                .devices = (Device[]) {
                    {"TV", false},
                    {"Lights", false}
                }
            },
            {
                .name = "Bedroom",
                .num_devices = 3,
                .devices = (Device[]) {
                    {"Fan", false},
                    {"Lights", false},
                    {"Air Conditioner", false}
                }
            }
        }
    };

    // Control Smart Home
    control_home(&home);

    return 0;
}