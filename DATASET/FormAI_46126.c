//FormAI DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_ROOMS 5

typedef struct {
    char name[20];
    int id;
    float consumption;
    int status;
} Device;

typedef struct {
    char name[20];
    Device devices[MAX_DEVICES];
    int num_devices;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} SmartHome;

void turn_on_device(Device *device) {
    device->status = 1;
    printf("Device %s turned ON\n", device->name);
}

void turn_off_device(Device *device) {
    device->status = 0;
    printf("Device %s turned OFF\n", device->name);
}

void add_device(Room *room, Device device) {
    if (room->num_devices == MAX_DEVICES) {
        printf("Room is full\n");
        return;
    }
    room->devices[room->num_devices] = device;
    room->num_devices++;
    printf("Device %s added to room %s\n", device.name, room->name);
}

void add_room(SmartHome *smart_home, Room room) {
    if (smart_home->num_rooms == MAX_ROOMS) {
        printf("Smart Home is full\n");
        return;
    }
    smart_home->rooms[smart_home->num_rooms] = room;
    smart_home->num_rooms++;
    printf("Room %s added to Smart Home\n", room.name);
}

int main() {
    SmartHome my_smart_home;
    my_smart_home.num_rooms = 0;

    // Add rooms to my smart home
    Room living_room;
    strcpy(living_room.name, "Living Room");
    living_room.num_devices = 0;
    add_room(&my_smart_home, living_room);

    Room kitchen;
    strcpy(kitchen.name, "Kitchen");
    kitchen.num_devices = 0;
    add_room(&my_smart_home, kitchen);

    // Add devices to my rooms
    Device tv;
    strcpy(tv.name, "TV");
    tv.id = 1;
    tv.consumption = 100.0;
    tv.status = 0;
    add_device(&living_room, tv);

    Device fridge;
    strcpy(fridge.name, "Fridge");
    fridge.id = 2;
    fridge.consumption = 150.0;
    fridge.status = 0;
    add_device(&kitchen, fridge);

    // Turn on devices in my rooms
    turn_on_device(&my_smart_home.rooms[0].devices[0]);
    turn_on_device(&my_smart_home.rooms[1].devices[0]);

    return 0;
}