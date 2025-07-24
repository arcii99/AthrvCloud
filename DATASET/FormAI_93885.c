//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DRONES 10

// Drone structure
typedef struct Drone {
    int id;
    bool isFlying;
    float x;
    float y;
    float z;
} Drone;

// Remote Control structure
typedef struct RemoteControl {
    Drone drones[MAX_DRONES];
    int numDrones;
} RemoteControl;

/**
 * Creates a new drone with the given ID
 */
Drone createDrone(int id) {
    Drone drone;
    drone.id = id;
    drone.isFlying = false;
    drone.x = 0.0;
    drone.y = 0.0;
    drone.z = 0.0;
    return drone;
}

/**
 * Creates a new remote control object
 */
RemoteControl createRemoteControl() {
    RemoteControl remoteControl;
    remoteControl.numDrones = 0;
    return remoteControl;
}

/**
 * Adds a drone to the remote control
 */
void addDrone(RemoteControl *remoteControl, Drone drone) {
    if (remoteControl->numDrones >= MAX_DRONES) {
        printf("Error: Max number of drones reached!");
        return;
    }
    remoteControl->drones[remoteControl->numDrones++] = drone;
}

/**
 * Sets the drone's position
 */
void setPosition(Drone *drone, float x, float y, float z) {
    if (!drone->isFlying) {
        printf("Error: Drone is not flying!");
        return;
    }
    drone->x = x;
    drone->y = y;
    drone->z = z;
}

/**
 * Flies the drone to the given position
 */
void flyTo(RemoteControl *remoteControl, int droneId, float x, float y, float z) {
    // Find the drone with the given ID
    Drone *drone = NULL;
    for (int i = 0; i < remoteControl->numDrones; i++) {
        if (remoteControl->drones[i].id == droneId) {
            drone = &remoteControl->drones[i];
            break;
        }
    }
    if (!drone) {
        printf("Error: Drone with ID %d not found!", droneId);
        return;
    }
    if (drone->isFlying) {
        printf("Error: Drone is already flying!");
        return;
    }
    printf("Flight started!\n");
    drone->isFlying = true;
    setPosition(drone, x, y, z);
    printf("Drone %d flying to (%.2f, %.2f, %.2f)\n", droneId, x, y, z);
}

/**
 * Lands the drone
 */
void land(RemoteControl *remoteControl, int droneId) {
    // Find the drone with the given ID
    Drone *drone = NULL;
    for (int i = 0; i < remoteControl->numDrones; i++) {
        if (remoteControl->drones[i].id == droneId) {
            drone = &remoteControl->drones[i];
            break;
        }
    }
    if (!drone) {
        printf("Error: Drone with ID %d not found!", droneId);
        return;
    }
    if (!drone->isFlying) {
        printf("Error: Drone is not flying!");
        return;
    }
    printf("Landing drone %d...\n", droneId);
    drone->isFlying = false;
    setPosition(drone, 0.0, 0.0, 0.0);
    printf("Drone %d landed successfully!\n", droneId);
}

int main() {
    RemoteControl remoteControl = createRemoteControl();

    // Create some drones
    Drone drone1 = createDrone(1);
    Drone drone2 = createDrone(2);
    Drone drone3 = createDrone(3);

    // Add drones to the remote control
    addDrone(&remoteControl, drone1);
    addDrone(&remoteControl, drone2);
    addDrone(&remoteControl, drone3);

    // Fly drone 1 to a position
    flyTo(&remoteControl, 1, 10.0, 20.0, 5.0);

    // Land drone 1
    land(&remoteControl, 1);

    return 0;
}