//FormAI DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 20

// Define a structure to represent a device
typedef struct device {
    char name[20];
    bool state;
} Device;

// Define a structure to represent a room
typedef struct room {
    char name[20];
    Device devices[MAX_DEVICES];
    int num_devices;
} Room;

// Define a structure to represent the whole house
typedef struct smart_home {
    char name[20];
    Room rooms[10];
    int num_rooms;
} SmartHome;

// Function to turn a device on or off
void toggle_device(Device *dev) {
    dev->state = !dev->state;
    printf("%s is now %s\n", dev->name, dev->state ? "on" : "off");
}

// Function to add a new room to the house
void add_room(SmartHome *home, char *room_name) {
    Room new_room = {"", {}, 0};
    strcpy(new_room.name, room_name);
    home->rooms[home->num_rooms++] = new_room;
}

// Function to add a new device to a room
void add_device(Room *room, char *device_name) {
    Device new_device = {"", false};
    strcpy(new_device.name, device_name);
    room->devices[room->num_devices++] = new_device;
}

// Function to find a device in a room by name
Device *find_device(Room *room, char *device_name) {
    for (int i = 0; i < room->num_devices; i++) {
        if (strcmp(room->devices[i].name, device_name) == 0) {
            return &(room->devices[i]);
        }
    }
    return NULL;
}

int main() {
    // Create a new smart home
    SmartHome my_home = {"My House", {}, 0};

    // Add some rooms and devices
    add_room(&my_home, "Living Room");
    add_device(&(my_home.rooms[0]), "TV");
    add_device(&(my_home.rooms[0]), "Sound System");
    add_room(&my_home, "Kitchen");
    add_device(&(my_home.rooms[1]), "Oven");
    add_device(&(my_home.rooms[1]), "Refrigerator");
    add_room(&my_home, "Bedroom");
    add_device(&(my_home.rooms[2]), "Lamp");
    add_device(&(my_home.rooms[2]), "Alarm Clock");

    // Print out the list of devices in each room
    for (int i = 0; i < my_home.num_rooms; i++) {
        printf("%s:\n", my_home.rooms[i].name);
        for (int j = 0; j < my_home.rooms[i].num_devices; j++) {
            printf("- %s is %s\n", my_home.rooms[i].devices[j].name, my_home.rooms[i].devices[j].state ? "on" : "off");
        }
    }

    // Turn on the TV
    Device *tv = find_device(&(my_home.rooms[0]), "TV");
    if (tv != NULL) {
        toggle_device(tv);
    }

    // Turn off the refrigerator
    Device *fridge = find_device(&(my_home.rooms[1]), "Refrigerator");
    if (fridge != NULL) {
        toggle_device(fridge);
    }

    // Turn on the lamp in the bedroom
    Device *lamp = find_device(&(my_home.rooms[2]), "Lamp");
    if (lamp != NULL) {
        toggle_device(lamp);
    }

    return 0;
}