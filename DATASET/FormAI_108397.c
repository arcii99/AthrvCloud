//FormAI DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define LIGHT 1
#define FAN 2
#define AC 3

typedef struct Device {
    int type;
    int id;
    char* name;
    int status; // 0 off, 1 on
} Device;

typedef struct Room {
    int id;
    char* name;
    int num_devices;
    Device* devices;
} Room;

typedef struct SmartHome {
    int num_rooms;
    Room* rooms;
} SmartHome;

void check_device_status(Device* device) {
    if (device->status == 0) {
        printf("%s is currently turned off.\n", device->name);
        device->status = 1;
        printf("Turning %s on...\n", device->name);
    } else {
        printf("%s is currently turned on.\n", device->name);
        device->status = 0;
        printf("Turning %s off...\n", device->name);
    }
}

void control_device_in_room(Room* room, int device_id) {
    for (int i = 0; i < room->num_devices; i++) {
        if (room->devices[i].id == device_id) {
            check_device_status(&room->devices[i]);
            return;
        }
    }
    printf("Device with id %d not found in room %s.\n", device_id, room->name);
}

void control_device_in_smart_home(SmartHome* smart_home, int device_id) {
    for (int i = 0; i < smart_home->num_rooms; i++) {
        control_device_in_room(&smart_home->rooms[i], device_id);
    }
}

int main() {
    Device light1 = { LIGHT, 1, "Living Room Light", 0 };
    Device light2 = { LIGHT, 2, "Bedroom Light", 0 };
    Device fan1 = { FAN, 3, "Living Room Fan", 0 };
    Device ac1 = { AC, 4, "Living Room AC", 0 };

    Device living_room_devices[3] = { light1, fan1, ac1 };
    Device bedroom_devices[1] = { light2 };

    Room living_room = { 1, "Living Room", 3, living_room_devices };
    Room bedroom = { 2, "Bedroom", 1, bedroom_devices };

    Room all_rooms[2] = { living_room, bedroom };

    SmartHome smart_home = { 2, all_rooms };

    control_device_in_smart_home(&smart_home, 1);
    control_device_in_smart_home(&smart_home, 1);
    control_device_in_room(&living_room, 3);

    return 0;
}