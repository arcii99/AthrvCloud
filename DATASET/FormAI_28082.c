//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
// C Remote Control Vehicle Simulation Example Program
// by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_SPEED 100 // km/h
#define MIN_SPEED 0 // km/h
#define MAX_DIRECTION 360 // degrees
#define MIN_DIRECTION 0 // degrees
#define MAX_BATTERY_LIFE 100 // percent
#define MIN_BATTERY_LIFE 0 // percent
#define MAX_DISTANCE 10000 // meters
#define MIN_DISTANCE 0 // meters
#define BATTERY_CONSUMPTION_RATE 10 // percent per km

// Define vehicle structure
typedef struct {
    int speed; // km/h
    int direction; // degrees
    int battery_life; // percent
    int distance_traveled; // meters
} Vehicle;

// Function to generate a random integer between min and max
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the vehicle's movement
void move_vehicle(Vehicle *vehicle) {
    int distance = random_int(1, MAX_SPEED);
    int battery_life = vehicle -> battery_life - (distance / 1000) * BATTERY_CONSUMPTION_RATE;
    if (battery_life < 0) {
        battery_life = 0;
        puts("The battery is drained. Please recharge the vehicle.");
    }
    else if ((vehicle -> distance_traveled + distance) > MAX_DISTANCE) {
        distance = MAX_DISTANCE - vehicle -> distance_traveled;
        vehicle -> distance_traveled = MAX_DISTANCE;
        puts("The vehicle has reached its maximum distance limit.");
    }
    else {
        vehicle -> distance_traveled += distance;
    }
    vehicle -> speed = random_int(MIN_SPEED, MAX_SPEED);
    vehicle -> direction = random_int(MIN_DIRECTION, MAX_DIRECTION);
    vehicle -> battery_life = battery_life;
}

// Function to display the vehicle's status
void display_status(Vehicle vehicle) {
    printf("Speed: %d km/h\n", vehicle.speed);
    printf("Direction: %d degrees\n", vehicle.direction);
    printf("Battery Life: %d%%\n", vehicle.battery_life);
    printf("Distance Traveled: %d meters\n", vehicle.distance_traveled);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the vehicle
    Vehicle vehicle = {0, 0, MAX_BATTERY_LIFE, 0};
    
    // Display the initial status of the vehicle
    puts("Remote Control Vehicle Simulation Program");
    display_status(vehicle);
    
    // Loop to simulate the vehicle's movement
    while (vehicle.battery_life > 0 && vehicle.distance_traveled < MAX_DISTANCE) {
        // Prompt the user for input
        puts("Press enter to move the vehicle or CTRL + C to quit");
        getchar();
        
        // Simulate the vehicle's movement
        move_vehicle(&vehicle);
        
        // Display the status of the vehicle
        display_status(vehicle);
    }
    
    // Display the final status of the vehicle
    puts("Simulation complete");
    display_status(vehicle);
    
    return 0;
}