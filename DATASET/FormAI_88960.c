//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent RC vehicles
struct RCVehicle {
    int id;
    char name[50];
    int speed;
    double battery_life;
    int distance_traveled;
};

// Function to initialize the default values of a new RC vehicle
void initVehicle(struct RCVehicle *vehicle) {
    vehicle->id = -1;
    strcpy(vehicle->name, "");
    vehicle->speed = 0;
    vehicle->battery_life = 0.0;
    vehicle->distance_traveled = 0;
}

// Function to print the details of an RC vehicle
void printVehicleDetails(struct RCVehicle vehicle) {
    printf("ID: %d\n", vehicle.id);
    printf("Name: %s\n", vehicle.name);
    printf("Speed: %d km/h\n", vehicle.speed);
    printf("Battery Life: %.2f hours\n", vehicle.battery_life);
    printf("Distance Traveled: %d meters\n", vehicle.distance_traveled);
}

int main() {
    struct RCVehicle vehicle;
    initVehicle(&vehicle);

    // Lets give our vehicle an ID and a name
    vehicle.id = 1;
    strcpy(vehicle.name, "Racer");

    // Lets set its speed and battery life
    vehicle.speed = 50;
    vehicle.battery_life = 2.5;

    printf("Original Vehicle Details:\n");
    printVehicleDetails(vehicle);

    // Lets simulate moving the vehicle for some distance
    int distance = 100;
    vehicle.distance_traveled += distance;
    double hours_taken = (double) distance / vehicle.speed;
    vehicle.battery_life -= hours_taken;

    printf("\nVehicle Details after moving %d meters:\n", distance);
    printVehicleDetails(vehicle);

    // Let's simulate changing the speed of the vehicle
    int new_speed = 75;
    int old_speed = vehicle.speed;
    vehicle.speed = new_speed;
    double hours_taken_for_same_distance = (double) distance / old_speed;
    double hours_left_after_distance = vehicle.battery_life - hours_taken_for_same_distance;
    int new_distance = (int) (vehicle.speed * hours_left_after_distance);
    vehicle.distance_traveled += new_distance;
    vehicle.battery_life = hours_left_after_distance;

    printf("\nVehicle Details after setting new speed of %d km/h:\n", new_speed);
    printVehicleDetails(vehicle);

    return 0;
}