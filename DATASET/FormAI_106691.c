//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 5 // max speed of a car
#define TOTAL_CARS 10 // total number of cars in the simuilation
#define MAX_ROAD_DISTANCE 100 // max length of the road
#define MAX_PROBABILITY 100 // max probability of a car moving forward
#define MAX_DELAY 3 // max delay in seconds between each simulation cycle
#define CRASH_POSITION 10 // position where a car crashes

struct Car {
    int position; // current position on road
    int speed; // current speed of car
};

int main() {
    // Initialization
    srand(time(NULL)); // set random seed based on current time
    struct Car cars[TOTAL_CARS]; // initialize array of cars
    int road_length = rand() % MAX_ROAD_DISTANCE + 1; // randomize road length
    int delay = rand() % (MAX_DELAY + 1); // randomize delay between cycles
    
    for(int i = 0; i < TOTAL_CARS; i++) {
        cars[i].position = i * (road_length / TOTAL_CARS); // evenly distribute cars on road
        cars[i].speed = rand() % (MAX_SPEED + 1); // randomize speed of car
    }
    
    // Simulation Loop
    int cycles = 0;
    while(1) {
        // Print Current State of Cars on Road
        printf("Cycle %d\n", cycles);
        for(int i = 0; i < road_length; i++) {
            int car_index = -1;
            for(int j = 0; j < TOTAL_CARS; j++) {
                if(cars[j].position == i) {
                    car_index = j;
                    break;
                }
            }
            if(car_index >= 0) {
                printf("Car[%d][%d]", car_index, cars[car_index].speed);
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
        
        // Move Cars Forward
        for(int i = 0; i < TOTAL_CARS; i++) {
            int probability = rand() % MAX_PROBABILITY + 1; // randomize probability of car moving forward
            if(probability <= cars[i].speed * 10) { // car can move forward
                cars[i].position += cars[i].speed;
                if(cars[i].position >= road_length) { // car reaches end of road
                    printf("Car[%d] reaches end of road.\n", i);
                    cars[i].position = -1; // mark car as finished
                } else if(cars[i].position == CRASH_POSITION) { // car crashes
                    printf("Car[%d] crashes.\n", i);
                    cars[i].position = -1; // mark car as finished
                }
            }
        }
        
        // Check if Simuilation is Finished
        int cars_finished = 0;
        for(int i = 0; i < TOTAL_CARS; i++) {
            if(cars[i].position == -1) {
                cars_finished++;
            }
        }
        if(cars_finished == TOTAL_CARS) { // all cars finished
            printf("All cars reached the end of the road.\n");
            break;
        }
        
        // Delay Between Cycles
        printf("\n");
        sleep(delay); // pause simulation
        cycles++;
    }
    
    return 0;
}