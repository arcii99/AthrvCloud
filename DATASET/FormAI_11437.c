//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, z;
} vector;

typedef struct {
    int id;
    vector location;
    int battery_level;
} drone;

typedef struct {
    int id;
    vector location;
} controller;

void connect_drone(drone* d, controller* c) {
    printf("Connection established between drone %d and controller %d\n", d->id, c->id);
}

void update_location(drone* d, vector new_loc) {
    printf("Drone %d moved from (%d,%d,%d) to (%d,%d,%d)\n", d->id, d->location.x, d->location.y, d->location.z, new_loc.x, new_loc.y, new_loc.z);
    d->location = new_loc;
}

void check_battery_level(drone* d) {
    printf("Drone %d battery level is %d%%\n", d->id, d->battery_level);
}

void land_drone(drone* d) {
    printf("Drone %d has landed\n", d->id);
}

int main() {
    drone d1 = {1, {0,0,0}, 100};
    controller c1 = {1, {0,0,0}};
    
    connect_drone(&d1, &c1);
    check_battery_level(&d1);
    update_location(&d1, (vector){1,1,1});
    check_battery_level(&d1);
    land_drone(&d1);
    
    return 0;
}