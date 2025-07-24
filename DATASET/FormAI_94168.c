//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50 // maximum number of cars on the road
#define MAX_SPEED 80 // maximum speed of a car in km/h
#define MIN_SPEED 40 // minimum speed of a car in km/h 

struct Car {
    int speed; // speed of the car
    int position; // current position in meters
};

int main() {
    srand(time(NULL)); // seed for randomizing car speeds

    struct Car cars[MAX_CARS]; // array of cars
    int car_count = rand() % MAX_CARS + 1; // randomly select number of cars

    // initialize positions and random speeds of each car
    for (int i = 0; i < car_count; i++) {
        cars[i].position = i * 10; // each car is 10 meters behind the previous one
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED; // random speed between MIN_SPEED and MAX_SPEED
    }

    int seconds_elapsed = 0; // tracking time elapsed in seconds

    // simulate traffic flow for 1 hour (3600 seconds)
    for (seconds_elapsed; seconds_elapsed < 3600; seconds_elapsed++) {
        for (int i = 0; i < car_count; i++) {
            // check if there is a car in front of the current car
            if (i == car_count - 1 || cars[i+1].position - cars[i].position > 10) {
                // if not, accelerate up to maximum speed
                if (cars[i].speed < MAX_SPEED) {
                    cars[i].speed++;
                }
            } else {
                // if there is, slow down to avoid collision
                int safe_distance = (cars[i+1].position - cars[i].position) / 2; // half the distance to the car in front
                if (cars[i].speed > safe_distance) {
                    cars[i].speed = safe_distance;
                }
            }
            cars[i].position += cars[i].speed / 3600; // update position based on speed at each second
        }

        // print current positions of cars at each minute
        if (seconds_elapsed % 60 == 0) {
            printf("Minute %d:\n", seconds_elapsed / 60);
            for (int i = 0; i < car_count; i++) {
                printf("Car %d: %d meters\n", i+1, cars[i].position);
            }
            printf("\n");
        }
    }

    return 0;
}