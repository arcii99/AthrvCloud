//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define constants
#define MAX_SPEED 100 // Maximum speed limit
#define MIN_DISTANCE 1 // Minimum distance between cars
#define MAX_DISTANCE 10 // Maximum distance between cars
#define MAX_CARS 50 // Maximum number of cars on the road
#define TIME_INTERVAL 1000000 // Time interval for simulation in microseconds

// Define structures
typedef struct car {
    int id;
    int speed;
    int distance;
} car;

typedef struct road {
    car cars[MAX_CARS];
    int num_cars;
    int length;
} road;

// Declare functions
void simulate_traffic(road r);
void add_new_cars(road *r, int num_cars);
void move_cars(road *r);
void print_cars(road r);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize road
    road r;
    r.num_cars = 0;
    r.length = 1000;
    
    // Add some initial cars
    add_new_cars(&r, 10);
    
    // Simulate traffic flow
    simulate_traffic(r);
    
    return 0;
}
    
// Function to simulate traffic flow
void simulate_traffic(road r) {
    // Loop until there are no more cars on the road
    while (r.num_cars > 0) {
        // Move all the cars on the road
        move_cars(&r);
        
        // Add some new cars to the road
        add_new_cars(&r, rand() % 5);
        
        // Print out the current state of the road
        print_cars(r);
        
        // Sleep for a short time interval before moving the cars again
        usleep(TIME_INTERVAL);
    }
}

// Function to add new cars to the road
void add_new_cars(road *r, int num_cars) {
    // Make sure there is room on the road for new cars
    if (r->num_cars + num_cars > MAX_CARS) {
        num_cars = MAX_CARS - r->num_cars;
    }
    
    // Add new cars with random speeds and distances between them
    for (int i = 0; i < num_cars; i++) {
        int speed = rand() % MAX_SPEED + 1;
        int distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
        
        car c;
        c.id = r->num_cars + i + 1;
        c.speed = speed;
        c.distance = distance;
        
        r->cars[r->num_cars + i] = c;
    }
    
    r->num_cars += num_cars;
}

// Function to move all the cars on the road
void move_cars(road *r) {
    // Sort cars on the road by their distance from the beginning
    for (int i = 0; i < r->num_cars - 1; i++) {
        for (int j = i + 1; j < r->num_cars; j++) {
            if (r->cars[i].distance > r->cars[j].distance) {
                car temp = r->cars[i];
                r->cars[i] = r->cars[j];
                r->cars[j] = temp;
            }
        }
    }
    
    // Move each car based on its speed and the distance to the car in front of it
    for (int i = 1; i < r->num_cars; i++) {
        int max_distance = r->cars[i].speed;
        int distance_to_next_car = r->cars[i - 1].distance - r->cars[i].distance;
        
        if (distance_to_next_car <= max_distance) {
            r->cars[i].distance = r->cars[i - 1].distance - max_distance;
        } else {
            r->cars[i].distance += max_distance;
        }
    }
    
    // Remove any cars that have gone off the end of the road
    while (r->num_cars > 0 && r->cars[r->num_cars - 1].distance >= r->length) {
        r->num_cars--;
        printf("Car %d has gone off the end of the road.\n", r->cars[r->num_cars].id);
    }
}

// Function to print out the state of the cars on the road
void print_cars(road r) {
    printf("\033[2J");
    printf("\033[0;0H");

    for (int i = 0; i < r.num_cars; i++) {
        int distance = r.cars[i].distance / 10;
        
        printf("Car %d: ", r.cars[i].id);
        
        for (int j = 0; j < distance; j++) {
            printf("-");
        }
        
        printf("o\n");
    }
}