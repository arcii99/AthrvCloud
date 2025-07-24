//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100 // maximum number of cars in simulation
#define MAX_SPEED 80 // maximum speed limit of road in km/h
#define TIME_STEP 1 // time step in seconds

typedef struct car_t {
    int speed;
    int position;
} car;

int main(void) {
    srand(time(NULL)); // seed random number generator
    
    int speed_limit = rand() % (MAX_SPEED + 1); // generate random speed limit
    printf("Speed limit: %d km/h\n", speed_limit);
    
    int num_cars = rand() % (MAX_CARS + 1); // generate random number of cars
    car cars[num_cars];
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % (speed_limit + 1); // generate random speed
        cars[i].position = i * 10; // set initial position
    }
    
    int time_elapsed = 0;
    while (1) {
        printf("\nTime elapsed: %d seconds\n", time_elapsed);
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: Speed = %d km/h, Position = %d m\n", i+1, cars[i].speed, cars[i].position);
            int next_distance = 0;
            for (int j = i+1; j < num_cars; j++) {
                next_distance += cars[j].position - cars[j-1].position;
                if (next_distance <= 10) { // apply notional "rule of the road"
                    cars[i].speed = cars[j].speed; // adjust speed to car in front
                    break;
                }
            }
            if (cars[i].speed < speed_limit) { // accelerate if below speed limit
                cars[i].speed += 1;
            }
            cars[i].position += cars[i].speed * TIME_STEP; // update position
        }
        time_elapsed += TIME_STEP; // increment time
        printf("Press ENTER to continue, or X to exit.\n");
        char c = getchar();
        if (c == 'x' || c == 'X') { // exit program if X is pressed
            break;
        }
    }
    
    return 0;
}