//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
/*
 * Traffic Flow Simulation
 * Description: This program is a simulation of traffic flow on a four-lane highway with multiple entry and exit points
 * Inspired by the traffic simulation in the game Cities: Skylines
 * Author: [Your Name Here]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define HIGHWAY_LENGTH 1000
#define ENTRY_POINTS 5
#define EXIT_POINTS 3
#define MAX_SPEED 70
#define MIN_GAP 15
#define CAR_INTERVAL 5
#define SAFETY_TIME 2

// Structs
typedef struct Car {
    int id;
    int lane;
    int position;
    int speed;
    int length;
    int gap;
    int entry;
    int exit;
    bool crossed;
    bool crashed;
} Car;

typedef struct Lane {
    Car cars[HIGHWAY_LENGTH];
    int count;
    int entry;
    int exit;
} Lane;

// Function Prototypes
void init_highway(Lane highway[]);
void generate_cars(int ticks, Lane highway[]);
void move_cars(Lane highway[]);
void calculate_gap(Car *car, Lane highway[]);
void collision_detection(Car *car, Lane highway[]);
void display_highway(Lane highway[]);

int main() {
    Lane highway[4]; // Four-lane highway
    srand(time(NULL)); // Seed random number generator
    
    init_highway(highway);
    
    // Simulation loop
    int ticks = 0;
    while (ticks < 500) {
        generate_cars(ticks, highway);
        move_cars(highway);
        display_highway(highway);
        ticks++;
    }
    
    return 0;
}

void init_highway(Lane highway[]) {
    // Initialize each lane
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < HIGHWAY_LENGTH; j++) {
            highway[i].cars[j].id = 0;
            highway[i].cars[j].lane = i;
            highway[i].cars[j].position = j;
            highway[i].cars[j].speed = 0;
            highway[i].cars[j].length = 5;
            highway[i].cars[j].gap = 0;
            highway[i].cars[j].entry = -1;
            highway[i].cars[j].exit = -1;
            highway[i].cars[j].crossed = false;
            highway[i].cars[j].crashed = false;
        }
        highway[i].count = 0;
        highway[i].entry = i;
        highway[i].exit = i % EXIT_POINTS;
    }
}

void generate_cars(int ticks, Lane highway[]) {
    // Determine if a car should be generated
    if (ticks % CAR_INTERVAL == 0) {
        for (int i = 0; i < 4; i++) {
            if (rand() % 10 < 8) { // 80% chance of generating a car
                // Find the first open space in the lane
                int position = 0;
                while (highway[i].cars[position].id != 0) {
                    position++;
                    if (position >= HIGHWAY_LENGTH) {
                        return; // Lane is full
                    }
                }
                
                int speed = (rand() % (MAX_SPEED - 30)) + 30; // Min speed is 30
                speed += speed % 5; // Round speed to nearest 5mph
                Car new_car = {ticks * 1000 + position, i, position, speed, 5, 0, highway[i].entry, highway[i].exit, false, false};
                highway[i].cars[position] = new_car;
                highway[i].count++;
            }
        }
    }
}

void move_cars(Lane highway[]) {
    // Loop through each lane from right to left
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < HIGHWAY_LENGTH; j++) {
            Car *current_car = &highway[i].cars[j];
            
            if (current_car->id == 0) {
                continue; // No car at this position
            }
            
            // Calculate the gap between this car and the car in front
            calculate_gap(current_car, highway);
            
            // Check for collisions
            collision_detection(current_car, highway);
            
            // Move the car
            int new_position = current_car->position + current_car->speed / 10;
            if (new_position >= HIGHWAY_LENGTH) {
                // Car has crossed the exit point
                current_car->crossed = true;
                current_car->id = 0;
                highway[i].count--;
            } else {
                highway[i].cars[j + current_car->length].gap = current_car->gap;
                highway[i].cars[j + current_car->length].entry = current_car->entry;
                highway[i].cars[j + current_car->length].exit = current_car->exit;
                highway[i].cars[j + current_car->length].position = new_position;
                highway[i].cars[j + current_car->length].speed = current_car->speed;
                highway[i].cars[j + current_car->length].length = current_car->length;
                highway[i].cars[j + current_car->length].id = current_car->id;
                highway[i].cars[j] = (Car){0, 0, j, 0, 0, 0, -1, -1, false, false};
            }
        }
    }
}

void calculate_gap(Car *car, Lane highway[]) {
    int gap = 0;
    int j = car->position + car->length;
    
    while (j < HIGHWAY_LENGTH && gap < MIN_GAP) {
        if (highway[car->lane].cars[j].id != 0) {
            gap = highway[car->lane].cars[j].position - (car->position + car->length);
            gap -= car->speed * SAFETY_TIME / 10;
        } else {
            gap = HIGHWAY_LENGTH - (car->position + car->length);
        }
        j += highway[car->lane].cars[j].length;
    }
    
    car->gap = gap;
}

void collision_detection(Car *car, Lane highway[]) {
    int j = car->position + car->length;
    
    while (j < HIGHWAY_LENGTH) {
        if (highway[car->lane].cars[j].id != 0) {
            // Calculate the gap between this car and the car in front of it
            calculate_gap(&highway[car->lane].cars[j], highway);
            if (highway[car->lane].cars[j].gap < car->gap) {
                // Collision detected
                car->crashed = true;
                car->id = 0;
                highway[car->lane].count--;
                break;
            }
        }
        j += highway[car->lane].cars[j].length;
    }
}

void display_highway(Lane highway[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < HIGHWAY_LENGTH; j++) {
            if (highway[i].cars[j].id != 0) {
                if (highway[i].cars[j].crossed) {
                    printf("X");
                } else if (highway[i].cars[j].crashed) {
                    printf("C");
                } else {
                    printf("%d", highway[i].cars[j].id % 10);
                }
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}