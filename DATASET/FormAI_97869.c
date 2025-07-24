//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_RANGE 1000

typedef struct {
    int x;
    int y;
} Location;

typedef struct {
    Location location;
    int range;
    int battery;
} Drone;

typedef struct {
    Drone drones[MAX_DRONES];
    int numDrones;
} RemoteControl;

void addDrone(RemoteControl *rc, int x, int y, int range, int battery) {
    if (rc->numDrones < MAX_DRONES) {
        Drone newDrone = { {x, y}, range, battery };
        rc->drones[rc->numDrones] = newDrone;
        rc->numDrones++;
    } else {
        printf("Error: Maximum number of drones already added\n");
    }
}

Drone *getDrone(RemoteControl *rc, int index) {
    if (index >= 0 && index < rc->numDrones) {
        return &(rc->drones[index]);
    } else {
        printf("Error: Invalid drone index\n");
        return NULL;
    }
}

void flyDrone(Drone *drone, int x, int y) {
    int distance = abs(drone->location.x - x) + abs(drone->location.y - y);
    if (distance <= drone->range && distance <= drone->battery) {
        drone->location.x = x;
        drone->location.y = y;
        drone->battery -= distance;
        printf("Drone(%d,%d) has been flown to (%d,%d). Battery remaining: %d\n",
            drone->location.x, drone->location.y, x, y, drone->battery);
    } else {
        printf("Error: Drone cannot be flown to (%d,%d)\n", x, y);
    }
}

int main() {
    RemoteControl rc = { {}, 0 };
    addDrone(&rc, 0, 0, MAX_RANGE/2, MAX_RANGE/2);
    addDrone(&rc, MAX_RANGE, MAX_RANGE, MAX_RANGE/2, MAX_RANGE/2);
    Drone *drone1 = getDrone(&rc, 0);
    Drone *drone2 = getDrone(&rc, 1);
    flyDrone(drone1, MAX_RANGE/4, MAX_RANGE/4);
    flyDrone(drone2, MAX_RANGE/2, MAX_RANGE/2 + 100);
    flyDrone(drone1, MAX_RANGE * 2, MAX_RANGE * 2); // Invalid location
    flyDrone(drone2, MAX_RANGE/2, MAX_RANGE/2 + 600); // Out of range
    return 0;
}