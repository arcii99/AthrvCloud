//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* Define constants for the simulation */
#define NUM_ROADS 4
#define NUM_LANES 2
#define MAX_CARS 10
#define MAX_SPEED 45
#define ROAD_LENGTH 1000

/* Define the structure for a car */
typedef struct {
    int id;
    int speed;
    int currPos;
    int lane;
    bool isStopped;
} Car;

void printRoad(Car road[NUM_ROADS][NUM_LANES], int tick);
void moveCar(Car* car, Car road[NUM_ROADS][NUM_LANES]);

int main() {
    /* Initialize random seed */
    srand(time(NULL));
    
    /* Initialize the road with no cars */
    Car road[NUM_ROADS][NUM_LANES] = {0};
    
    /* Start the simulation */
    for (int tick = 0; tick < 100; tick++) {
        /* Add a car to the road with a 20% chance */
        if ((rand() % 100) < 20) {
            int lane = rand() % NUM_LANES;
            int speed = (rand() % MAX_SPEED) + 1;
            int id = tick + 1;
            Car newCar = {id, speed, 0, lane, false};
            /* Check if there's room on the road */
            bool added = false;
            for (int i = 0; i < NUM_ROADS && !added; i++) {
                if (road[i][lane].id == 0) {
                    road[i][lane] = newCar;
                    added = true;
                }
            }
        }
        
        /* Move each car on the road */
        for (int i = 0; i < NUM_ROADS; i++) {
            for (int j = 0; j < NUM_LANES; j++) {
                if (road[i][j].id != 0) {
                    moveCar(&road[i][j], road);
                }
            }
        }
        
        /* Print the road */
        printRoad(road, tick);
    }
    
    return 0;
}

/* Prints the road with the current positions of all the cars */
void printRoad(Car road[NUM_ROADS][NUM_LANES], int tick) {
    printf("Tick %d:\n", tick);
    for (int i = 0; i < NUM_ROADS; i++) {
        printf("Road %d: ", i+1);
        for (int j = 0; j < NUM_LANES; j++) {
            if (road[i][j].id == 0) {
                printf(". ");
            } else {
                printf("%d ", road[i][j].id);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Moves a car on the road */
void moveCar(Car* car, Car road[NUM_ROADS][NUM_LANES]) {
    /* Check if the car is at the end of the road */
    if (car->currPos + car->speed >= ROAD_LENGTH) {
        road[car->lane][car->currPos / ROAD_LENGTH] = (Car){0};
        return;
    }
    
    /* Check if there's a car in front of this car */
    int nextPos = car->currPos + car->speed;
    int nextLane = car->lane;
    for (int i = car->currPos + 1; i <= nextPos; i++) {
        if (road[car->lane][i / ROAD_LENGTH].id != 0) {
            /* Check if the car can switch lanes */
            if (car->lane > 0 && road[car->lane-1][i / ROAD_LENGTH].id == 0) {
                nextPos = i - 1;
                nextLane = car->lane - 1;
            } else if (car->lane < NUM_LANES - 1 && road[car->lane+1][i / ROAD_LENGTH].id == 0) {
                nextPos = i - 1;
                nextLane = car->lane + 1;
            } else {
                car->speed = 0;
                car->isStopped = true;
                return;
            }
        }
    }
    /* Update the car's position */
    road[car->lane][car->currPos / ROAD_LENGTH] = (Car){0};
    car->currPos = nextPos;
    car->lane = nextLane;
    road[car->lane][car->currPos / ROAD_LENGTH] = *car;
}