//FormAI DATASET v1.0 Category: Smart home automation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_ROOMS 5

typedef struct {
    int id;
    bool status;
    char name[20];
    char type[20];
} Device;

typedef struct {
    int id;
    Device devices[MAX_DEVICES];
} Room;

typedef struct {
    int id;
    Room rooms[MAX_ROOMS];
} Home;

void turn_on_device(Device* device) {
    printf("Turning on %s %s with id %d...\n", device->name, device->type, device->id);
    device->status = true;
}

void turn_off_device(Device* device) {
    printf("Turning off %s %s with id %d...\n", device->name, device->type, device->id);
    device->status = false;
}

void add_device_to_room(Room* room, Device device) {
    for(int i = 0; i < MAX_DEVICES; i++) {
        if(room->devices[i].id == 0) {
            room->devices[i] = device;
            printf("%s %s with id %d added to room %d\n", device.name, device.type, device.id, room->id);
            break;
        }
    }
}

void add_room_to_home(Home* home, Room room) {
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(home->rooms[i].id == 0) {
            home->rooms[i] = room;
            printf("Room with id %d added to home\n", room.id);
            break;
        }
    }
}

void print_device_status(Device device) {
    printf("%s %s with id %d is %s\n", device.name, device.type, device.id, device.status ? "on" : "off");
}

void print_room_status(Room room) {
    printf("Room %d:\n", room.id);
    for(int i = 0; i < MAX_DEVICES; i++) {
        if(room.devices[i].id != 0) {
            print_device_status(room.devices[i]);
        }
    }
}

void print_home_status(Home home) {
    printf("Home status:\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(home.rooms[i].id != 0) {
            print_room_status(home.rooms[i]);
        }
    }
}

int main() {
    Home my_home = {1, {0}};

    Room living_room = {1, {0}};
    add_room_to_home(&my_home, living_room);

    Device tv = {1, false, "TV", "Entertainment"};
    add_device_to_room(&living_room, tv);

    Device air_conditioner = {2, false, "Air-Conditioner", "AC"};
    add_device_to_room(&living_room, air_conditioner);

    print_home_status(my_home);

    turn_on_device(&tv);
    turn_on_device(&air_conditioner);

    print_home_status(my_home);

    turn_off_device(&tv);
    turn_off_device(&air_conditioner);

    print_home_status(my_home);

    return 0;
}