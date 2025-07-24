//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100      // Maximum number of cars on the road
#define MAX_SPEED 100     // Maximum speed limit on the road
#define MAX_DISTANCE 1000 // Maximum distance between two intersections

/* Struct for a car */
typedef struct {
    int id;          // Unique ID for the car
    int speed;       // Speed of the car
    int distance;    // Distance from the previous car on the road
    int position;    // Position of the car on the road
} Car;

/* Struct for a road */
typedef struct {
    int length;      // Length of the road
    int speed_limit; // Speed limit of the road
    Car cars[MAX_CARS]; // Array of cars on the road
} Road;

/* Function to initialize a road */
void init_road(Road *road, int length, int speed_limit) {
    road->length = length;
    road->speed_limit = speed_limit;
    for (int i = 0; i < MAX_CARS; i++) {
        road->cars[i].id = -1; // Set ID to -1 to denote no car
    }
}

/* Function to add a car to the road */
void add_car(Road *road, Car car) {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].id == -1) { // Find the first empty index
            road->cars[i] = car;
            break;
        }
    }
}

/* Function to remove a car from the road */
void remove_car(Road *road, int car_id) {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].id == car_id) { // Find the car with the given ID
            road->cars[i].id = -1;
            break;
        }
    }
}

/* Function to update the position and distance of each car on the road */
void update_cars(Road *road) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].id != -1) { // If there is a car at this index
            if (i == 0) { // If this is the first car on the road
                road->cars[i].distance = -1; // Distance from previous car is -1
                road->cars[i].position += road->cars[i].speed; // Move the car forward
            } else { // If this is not the first car on the road
                int prev_car_index = i - 1; // Index of the previous car
                int prev_car_distance = road->cars[prev_car_index].distance; // Distance from previous car
                int prev_car_speed = road->cars[prev_car_index].speed; // Speed of previous car
                int relative_speed = road->cars[i].speed - prev_car_speed; // Relative speed difference
                int braking_distance = (road->cars[i].speed * road->cars[i].speed) / (2 * MAX_SPEED); // Braking distance
                int safe_distance = MAX_DISTANCE + (relative_speed * braking_distance); // Safe distance (minimum distance to keep from next car)
                int actual_distance = prev_car_distance - road->cars[i].position; // Actual distance from previous car
                if (actual_distance <= safe_distance) { // If the distance is less than safe distance
                    road->cars[i].speed = prev_car_speed; // Adjust speed to previous car
                    road->cars[i].distance = actual_distance; // Distance from previous car is actual distance
                } else { // If the distance is greater than safe distance
                    road->cars[i].distance = actual_distance; // Distance from previous car is actual distance
                    road->cars[i].position += road->cars[i].speed; // Move the car forward
                }
            }
            if (road->cars[i].position > road->length) { // If the car passes the end of the road
                remove_car(road, road->cars[i].id); // Remove the car from the road
            }
        }
    }
}

/* Function to print the current state of the road */
void print_road(Road *road) {
    printf("Length: %d\n", road->length);
    printf("Speed limit: %d\n", road->speed_limit);
    printf("Cars:\n");
    for (int i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].id != -1) { // If there is a car at this index
            printf(" ID: %d, Speed: %d, Distance: %d, Position: %d\n", road->cars[i].id, road->cars[i].speed, road->cars[i].distance, road->cars[i].position);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed

    Road road;
    init_road(&road, 500, 80); // Initialize a road with length 500 and speed limit 80

    // Add 10 random cars to the road
    for (int i = 0; i < 10; i++) {
        Car car;
        car.id = i;
        car.speed = rand() % MAX_SPEED + 1; // Random speed between 1 and MAX_SPEED
        car.distance = rand() % MAX_DISTANCE + 1; // Random distance between 1 and MAX_DISTANCE
        car.position = rand() % road.length; // Random position between 0 and length of road
        add_car(&road, car);
    }

    // Simulate the traffic flow for 1000 steps
    for (int i = 0; i < 1000; i++) {
        update_cars(&road);
        print_road(&road);
    }

    return 0;
}