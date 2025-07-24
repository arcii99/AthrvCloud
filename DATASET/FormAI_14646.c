//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>

// Define the structure of the remote control vehicle with its properties
struct rc_vehicle {
    int x; // Current x position
    int y; // Current y position
    int speed; // Current speed
    int direction; // Current direction
};

// Define the function to move the vehicle
void move(struct rc_vehicle *vehicle, int distance) {
    printf("Moving vehicle by %d units\n", distance);
    if(vehicle->direction == 0) {
        // Move North
        vehicle->y += distance;
    } else if(vehicle->direction == 1) {
        // Move East
        vehicle->x += distance;
    } else if(vehicle->direction == 2) {
        // Move South
        vehicle->y -= distance;
    } else {
        // Move West
        vehicle->x -= distance;
    }
}

// Define the function to change the direction of the vehicle
void change_direction(struct rc_vehicle *vehicle, int new_direction) {
    printf("Changing vehicle direction to %d\n", new_direction);
    vehicle->direction = new_direction;
}

// Define the function to change the speed of the vehicle
void change_speed(struct rc_vehicle *vehicle, int new_speed) {
    printf("Changing vehicle speed to %d\n", new_speed);
    vehicle->speed = new_speed;
}

// Define the main function to simulate the remote control vehicle
int main() {
    // Create a new instance of the remote control vehicle
    struct rc_vehicle vehicle;
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.speed = 0;
    vehicle.direction = 0;
    
    // Perform a series of actions on the vehicle
    change_speed(&vehicle, 5);
    change_direction(&vehicle, 1);
    move(&vehicle, 10);
    move(&vehicle, -5);
    change_direction(&vehicle, 2);
    move(&vehicle, 7);
    move(&vehicle, -3);
    change_direction(&vehicle, 3);
    move(&vehicle, 8);
    move(&vehicle, -4);
    
    // Print the final position of the vehicle
    printf("Final position: (%d, %d)\n", vehicle.x, vehicle.y);
    
    return 0;
}