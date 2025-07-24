//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define ROAD_LENGTH 100
#define MIN_SPEED 40
#define MAX_SPEED 80

int main() {
    int cars[MAX_CARS] = {0}; // array containing the positions of each car
    int speed[MAX_CARS] = {0}; // array containing the speed of each car
    int num_cars = 10; // the number of cars on the road
    int time_step = 1; // the time step of the simulation
    int iterations = 1000; // the number of iterations of the simulation
    int i, j; // loop variables

    srand(time(NULL)); // seed the random number generator

    // initialize the positions and speeds of the cars randomly
    for (i = 0; i < num_cars; i++) {
        cars[i] = rand() % ROAD_LENGTH;
        speed[i] = MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED + 1);
    }
    
    // start the simulation
    for (i = 0; i < iterations; i++) {
        
        // print the current state of the road
        printf("\nIteration %d:\n", i);
        for (j = 0; j < ROAD_LENGTH; j++) {
            if (j == 0) printf("S");
            else if (j == ROAD_LENGTH-1) printf("F");
            else if (j == cars[0]) printf("C");
            else if (j == cars[num_cars-1]) printf("C");
            else {
                int k;
                for (k = 1; k < num_cars-1; k++) {
                    if (cars[k] == j) printf("C");
                }
                printf("-");
            }
        }
        printf("\n");
        
        // update the positions and speeds of the cars
        for (j = 0; j < num_cars; j++) {
            // calculate the distance to the next car
            int dist_to_next_car = ROAD_LENGTH;
            int k;
            for (k = 0; k < num_cars; k++) {
                if (k == j) continue;
                int dist = cars[k] - cars[j];
                if (dist < 0) dist += ROAD_LENGTH;
                if (dist < dist_to_next_car) dist_to_next_car = dist;
            }
            // update the speed of the car
            if (dist_to_next_car <= speed[j]) speed[j] = dist_to_next_car-1;
            else {
                int rand_num = rand() % 100;
                if (rand_num < 20) speed[j]--; // 20% chance to slow down
                else if (rand_num > 80) speed[j]++; // 20% chance to speed up
            }
            if (speed[j] < 0) speed[j] = 0;
            if (speed[j] > MAX_SPEED) speed[j] = MAX_SPEED;
            // update the position of the car
            cars[j] = (cars[j] + speed[j]) % ROAD_LENGTH;
        }
    }
    
    return 0;
}