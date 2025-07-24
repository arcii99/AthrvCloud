//FormAI DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the various devices in the smart home
typedef struct {
    bool status;
    int level;
} Light;

typedef struct {
    bool status;
    int temperature;
} Thermostat;

typedef struct {
    bool status;
} Lock;

// Defining the smart home structure
typedef struct {
    Light living_room_light;
    Light bedroom_light;
    Thermostat thermostat;
    Lock front_door_lock;
} SmartHome;

int main() {
    // Creating a new smart home instance
    SmartHome my_home;
    my_home.living_room_light.status = false;
    my_home.living_room_light.level = 0;
    my_home.bedroom_light.status = false;
    my_home.bedroom_light.level = 0;
    my_home.thermostat.status = false;
    my_home.thermostat.temperature = 70;
    my_home.front_door_lock.status = true;

    // Turning on the living room light
    printf("Turning on the living room light...\n");
    my_home.living_room_light.status = true;
    my_home.living_room_light.level = 100;

    // Turning on the bedroom light
    printf("Turning on the bedroom light...\n");
    my_home.bedroom_light.status = true;
    my_home.bedroom_light.level = 50;

    // Adjusting the thermostat
    printf("Adjusting the thermostat...\n");
    my_home.thermostat.status = true;
    my_home.thermostat.temperature = 72;

    // Locking the front door
    printf("Locking the front door...\n");
    my_home.front_door_lock.status = false;

    return 0;
}