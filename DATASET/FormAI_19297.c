//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define Constant
#define MAX_SPEED 100

// Struct for the Vehicle
typedef struct Vehicle {
    char name[50];
    int speed;
    int x_pos;
    int y_pos;
    int direction;
} Vehicle;

// Function to create a new Vehicle
Vehicle createVehicle(char* name, int speed) {
    Vehicle newVehicle;
    
    // Set the values
    strcpy(newVehicle.name, name);
    newVehicle.speed = speed;
    newVehicle.x_pos = 0;
    newVehicle.y_pos = 0;
    newVehicle.direction = 0;
    
    return newVehicle;
}

// Function to move the Vehicle in a particular direction
void moveVehicle(Vehicle* vehicle, int distance, int direction) {
    // Calculate the new x and y positions
    switch (direction) {
        case 0:
            vehicle->y_pos += distance;
            break;
        case 1:
            vehicle->x_pos += distance;
            vehicle->y_pos += distance;
            break;
        case 2:
            vehicle->x_pos += distance;
            break;
        case 3:
            vehicle->x_pos += distance;
            vehicle->y_pos -= distance;
            break;
        case 4:
            vehicle->y_pos -= distance;
            break;
        case 5:
            vehicle->x_pos -= distance;
            vehicle->y_pos -= distance;
            break;
        case 6:
            vehicle->x_pos -= distance;
            break;
        case 7:
            vehicle->x_pos -= distance;
            vehicle->y_pos += distance;
            break;
    }
}

// Function to turn the Vehicle
void turnVehicle(Vehicle* vehicle, int angle) {
    vehicle->direction += angle;
    if(vehicle->direction > 7) {
        vehicle->direction = 0;
    }
    else if(vehicle->direction < 0) {
        vehicle->direction = 7;
    }
}

// Function to print the current status of the Vehicle
void printStatus(Vehicle* vehicle) {
    printf("Name: %s\n", vehicle->name);
    printf("Speed: %d\n", vehicle->speed);
    printf("Position: (%d, %d)\n", vehicle->x_pos, vehicle->y_pos);
    printf("Direction: %d\n", vehicle->direction);
}

// Main function
int main() {
    // Create a new Vehicle
    Vehicle myVehicle = createVehicle("My Car", 50);
    
    // Print the initial status
    printStatus(&myVehicle);
    
    // Move the Vehicle
    moveVehicle(&myVehicle, 20, 0);
    printStatus(&myVehicle);
    
    // Turn the Vehicle
    turnVehicle(&myVehicle, 2);
    printStatus(&myVehicle);
    
    // Move the Vehicle again
    moveVehicle(&myVehicle, 30, 2);
    printStatus(&myVehicle);
    
    return 0;
}