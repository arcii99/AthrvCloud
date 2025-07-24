//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5
#define ROAD_LENGTH 50
#define EMPTY '.'
#define CAR '*'
#define SLEEP_MS 1000

typedef struct Car {
    int position;
    int speed;
} Car;

void updateCarPosition(Car *car) {
    car->position += car->speed;
}

void updateCarSpeed(Car *car, int distanceToCarAhead) {
    if (distanceToCarAhead >= 0 && distanceToCarAhead <= car->speed) {
        car->speed = distanceToCarAhead - 1;
    } 
    else if (distanceToCarAhead > car->speed && car->speed < MAX_SPEED) {
        car->speed++;
    }
}

void moveCarOnRoad(char *road, Car *car) {
    int oldPosition = car->position;

    // Clear old position.
    for (int i = 0; i < MAX_SPEED; i++) {
        if (road[oldPosition + i] == CAR) {
            road[oldPosition + i] = EMPTY;
        }
    }

    updateCarPosition(car);

    // Draw new position.
    for (int i = 0; i < MAX_SPEED; i++) {
        if (road[car->position + i] == EMPTY) {
            road[car->position + i] = CAR;
        } 
        else {
            // Stop car if it hits something.
            car->speed = 0;
            car->position = oldPosition;
            for (int i = 0; i < MAX_SPEED; i++) {
                road[oldPosition + i] = CAR;
            }
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    char road[ROAD_LENGTH];

    // Initialize road.
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = EMPTY;
    }

    Car cars[MAX_CARS];
    int numCars = 0;

    // Initialize cars.
    while (numCars < MAX_CARS) {
        int pos = rand() % ROAD_LENGTH;
        if (road[pos] == EMPTY) {
            cars[numCars].position = pos;
            cars[numCars].speed = rand() % MAX_SPEED + 1;
            road[pos] = CAR;
            numCars++;
        }
    }

    // Simulation loop.
    while (1) {
        printf("%.*s\n", ROAD_LENGTH, road);

        for (int i = 0; i < numCars; i++) {
            int distanceToCarAhead = ROAD_LENGTH;
            for (int j = 0; j < numCars; j++) {
                if (cars[j].position > cars[i].position && 
                    cars[j].position - cars[i].position < distanceToCarAhead) {
                    distanceToCarAhead = cars[j].position - cars[i].position;
                }
            }
            updateCarSpeed(&cars[i], distanceToCarAhead);
        }

        for (int i = 0; i < numCars; i++) {
            moveCarOnRoad(road, &cars[i]);
        }

        // Wait a bit before updating display.
        usleep(SLEEP_MS * 1000);
        system("clear");
    }

    return 0;
}