//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 50           // Length of the road
#define MAX_CARS 10              // Maximum number of cars
#define MAX_SPEED 5              // Maximum speed of car
#define BRAKING_SPEED 2          // Speed reduction when the car slows down
#define REACTION_TIME 2          // Delay before the driver reacts to a change in traffic
#define TICK_LENGTH 100          // Duration of a time tick in milliseconds
#define MAX_ITERATIONS 100        // Maximum number of iterations

typedef enum {FORWARD, BACKWARD} direction_t;         // Enumeration to define direction of traffic

typedef struct {
    int position;                                     // Position of the car on the road
    int speed;                                        // Speed of the car
} car_t;

int main(void) {
    srand(time(NULL));                                // Seed the random number generator
    int tick = 0;                                      // Initialize the ticks
    
    car_t cars[MAX_CARS];                              // Initialize array of cars
    direction_t traffic_direction = FORWARD;           // Initialize traffic direction
    
    for(int i = 0; i < MAX_CARS; i++) {
        cars[i].position = 0;                          // Initialize positions of cars to 0
        cars[i].speed = rand() % (MAX_SPEED + 1);       // Initialize speeds of cars to random value between 0 and MAX_SPEED (inclusive)
    }

    while (tick < MAX_ITERATIONS) {
        printf("Tick: %d\n", tick++);
        printf("|");                                   // Print starting point of the road
        
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (i == cars[0].position) printf("o");    // Print leading car
            else if (i == ROAD_LENGTH - 1) printf("|"); // Print end point of the road
            else {
                // Determine if there is a car at the current position
                car_t* current_car = NULL;
                for (int j = 0; j < MAX_CARS; j++) {
                    if (cars[j].position == i) {
                        current_car = &cars[j];
                    }
                }
                if (current_car == NULL) printf(" ");  // Print a space if no car is present
                else printf("o");                       // Print a car if one is present
            }
        }

        printf("\n");
        
        // Update positions of cars based on speed and traffic
        for (int i = 0; i < MAX_CARS; i++) {
            int ahead_position = 0;
            for (int j = 0; j < MAX_CARS; j++) {
                if (cars[j].position > cars[i].position && ahead_position == 0) {
                    ahead_position = cars[j].position;
                }
                else if (cars[j].position > cars[i].position && cars[j].position < ahead_position) {
                    ahead_position = cars[j].position;
                }
            }
            if (ahead_position == 0) ahead_position = ROAD_LENGTH; // If no car ahead, set position to end of road
            
            // Calculate new speed based on distance to car ahead and reaction time
            int distance_to_car_ahead = ahead_position - cars[i].position;
            if (distance_to_car_ahead <= REACTION_TIME * cars[i].speed) {
                cars[i].speed = (distance_to_car_ahead - BRAKING_SPEED) / REACTION_TIME;
            }
            else {
                cars[i].speed = MAX_SPEED;
            }
            if (cars[i].speed < 0) cars[i].speed = 0;             // Speed cannot be negative
            if (cars[i].speed > MAX_SPEED) cars[i].speed = MAX_SPEED; // Speed cannot be greater than MAX_SPEED
            
            // Update position of car based on speed and direction of traffic
            if (traffic_direction == FORWARD) {
                cars[i].position += cars[i].speed;
            }
            else {
                cars[i].position -= cars[i].speed;
            }
            if (cars[i].position >= ROAD_LENGTH) cars[i].position = 0; // If car reaches end of road, wrap around to beginning
            if (cars[i].position < 0) cars[i].position = ROAD_LENGTH - 1; // If car reaches start of road, wrap around to end
        }

        // Reverse direction of traffic if all cars have passed the end of the road
        int has_cars = 0;
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].position < ROAD_LENGTH) {
                has_cars = 1;
                break;
            }
        }
        if (!has_cars) traffic_direction = BACKWARD;
        
        // Wait for next tick
        usleep(TICK_LENGTH * 1000);
    }

    return 0;
}