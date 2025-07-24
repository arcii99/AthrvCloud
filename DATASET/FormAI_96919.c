//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>

// Struct for storing vehicle information
typedef struct Vehicle {
    int speed;
    int direction;
    int battery_level;
    int distance_traveled;
} Vehicle;

// Struct for storing remote control information
typedef struct Remote {
    int battery_level;
    char status[10];
} Remote;

// Function for controlling the vehicle's speed and direction
void control_vehicle(int speed, int direction, Vehicle *vehicle) {
    vehicle->speed = speed;
    vehicle->direction = direction;
    vehicle->distance_traveled += (speed * direction);
}

// Function for checking remote control battery level
int check_remote_battery(Remote *remote) {
    return remote->battery_level;
}

// Function for updating remote control status
void update_remote_status(Remote *remote, char *status) {
    snprintf(remote->status, sizeof(remote->status), "%s", status);
}

int main() {
    Vehicle car = {0, 1, 100, 0};
    Remote remote = {50, "connected"};

    printf("Welcome to the Remote Control Vehicle Simulation\n");
    printf("Vehicle Speed: %d\n", car.speed);
    printf("Vehicle Direction: %d\n", car.direction);
    printf("Vehicle Battery Level: %d\n", car.battery_level);
    printf("Vehicle Distance Traveled: %d\n", car.distance_traveled);
    printf("Remote Control Battery Level: %d\n", remote.battery_level);
    printf("Remote Control Status: %s\n\n", remote.status);

    // Simulate controlling the vehicle with the remote control
    control_vehicle(10, 1, &car);
    update_remote_status(&remote, "controlling");
    printf("Remote Control Status: %s\n", remote.status);
    printf("Vehicle Speed: %d\n", car.speed);
    printf("Vehicle Direction: %d\n", car.direction);
    printf("Vehicle Distance Traveled: %d\n\n", car.distance_traveled);

    // Simulate checking remote control battery level
    int battery_level = check_remote_battery(&remote);
    printf("Remote Control Battery Level: %d\n\n", battery_level);

    // Simulate stopping the vehicle
    control_vehicle(0, 0, &car);
    update_remote_status(&remote, "disconnected");
    printf("Remote Control Status: %s\n", remote.status);
    printf("Vehicle Speed: %d\n", car.speed);
    printf("Vehicle Direction: %d\n", car.direction);
    printf("Vehicle Distance Traveled: %d\n\n", car.distance_traveled);

    // Simulate recharging the remote control battery and checking again
    remote.battery_level = 100;
    battery_level = check_remote_battery(&remote);
    printf("Remote Control Battery Level: %d\n\n", battery_level);

    return 0;
}