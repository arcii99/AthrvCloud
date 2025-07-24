//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Drone struct to hold the current state of the drone.
typedef struct {
    float x; // x position
    float y; // y position
    float z; // z position
    bool armed; // Whether or not the drone is armed
} Drone;

// Define global variables for the drone and remote control
Drone drone = {.x = 0, .y = 0, .z = 0, .armed = false};
bool remoteConnected = false;

// Arm the drone
void armDrone() {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    drone.armed = true;
    printf("Drone armed.\n");
}

// Disarm the drone
void disarmDrone() {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    drone.armed = false;
    printf("Drone disarmed.\n");
}

// Takeoff the drone
void takeoff() {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.z = 1.0f;
    printf("Drone took off.\n");
}

// Land the drone
void land() {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.z = 0.0f;
    printf("Drone landed.\n");
}

// Move drone along x axis
void moveX(float deltaX) {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.x += deltaX;
    printf("Drone moved along x axis by %f units.\n", deltaX);
}

// Move drone along y axis
void moveY(float deltaY) {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.y += deltaY;
    printf("Drone moved along y axis by %f units.\n", deltaY);
}

// Move drone along z axis
void moveZ(float deltaZ) {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.z += deltaZ;
    printf("Drone moved along z axis by %f units.\n", deltaZ);
}

// Set the drone's position
void setPosition(float x, float y, float z) {
    if (!remoteConnected) {
        printf("[ERROR] Remote control not connected.\n");
        return;
    }
    if (!drone.armed) {
        printf("[ERROR] Drone not armed.\n");
        return;
    }
    drone.x = x;
    drone.y = y;
    drone.z = z;
    printf("Drone set position to (%f,%f,%f).\n", x, y, z);
}

// Connect to the remote control
void connectRemote() {
    remoteConnected = true;
    printf("Remote control connected.\n");
}

// Disconnect from the remote control
void disconnectRemote() {
    remoteConnected = false;
    printf("Remote control disconnected.\n");
}

// Run the drone program
int main() {
    // Connect to the remote control
    connectRemote();

    // Arm the drone
    armDrone();

    // Takeoff
    takeoff();

    // Move the drone
    moveX(1.0f);
    moveY(2.0f);
    moveZ(-0.5f);

    // Set the drone's position
    setPosition(5.0f, 3.0f, 2.0f);

    // Land the drone
    land();

    // Disarm the drone
    disarmDrone();

    // Disconnect from the remote control
    disconnectRemote();

    return 0;
}