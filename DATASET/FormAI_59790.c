//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROAD_LENGTH 100 // maximum road length
#define MAX_CARS 20 // maximum cars on road

// function to generate a random integer between min and max
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main(void) {
    // variables for road conditions
    int road[MAX_ROAD_LENGTH] = {0}; // 0 indicates empty space, 1 indicates a car
    int road_length = random_int(20, MAX_ROAD_LENGTH);
    int traffic_density = random_int(5, MAX_CARS);

    // variables for simulation
    int time_step = 0; // time elapsed in simulation
    int collision = 0; // indicates if collision has occurred
    int num_cars = 0; // number of cars on the road
    int car_positions[MAX_CARS]; // array to store positions of cars on road

    // seed the random number generator
    srand(time(NULL));

    // randomly place cars on the road
    for(int i = 0; i < traffic_density; i++) {
        int car_position = random_int(0, road_length - 1);
        road[car_position] = 1;
        car_positions[num_cars++] = car_position;
    }

    // start the simulation
    while(!collision) {
        // clear the screen
        system("cls");

        // update car positions
        for(int i = 0; i < num_cars; i++) {
            // move the car forward if there is no car in front of it
            if(car_positions[i] < road_length - 1 && road[car_positions[i] + 1] == 0) {
                road[car_positions[i]] = 0;
                car_positions[i]++;
                road[car_positions[i]] = 1;
            }
            // stop the car if there is a car in front of it
            else {
                road[car_positions[i]] = 1;
            }
        }

        // check for collisions
        for(int i = 0; i < num_cars - 1; i++) {
            if(car_positions[i] == car_positions[i+1]) {
                collision = 1;
                break;
            }
        }

        // print the road
        for(int i = 0; i < road_length; i++) {
            if(road[i] == 1) {
                printf("|X|");
            }
            else {
                printf("|_|");
            }
        }
        printf("\n");

        // increment time step
        time_step++;

        // delay for human observation
        for(int i = 0; i < 100000000; i++) {}

        // end the simulation if maximum time step reached or collision occurred
        if(time_step > 100 || collision) {
            break;
        }
    }

    // print the results of the simulation
    if(collision) {
        printf("Collision occurred after %d time steps.\n", time_step);
    }
    else {
        printf("No collision occurred within %d time steps.\n", time_step); 
    }

    return 0;
}