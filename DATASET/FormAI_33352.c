//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_LANES 4
#define LANE_CAPACITY 25
#define SIM_DURATION 3600 // in seconds
#define CAR_RATE 5 // in seconds - how often a car will attempt to enter the highway
#define MAX_SPEED 70 // in mph
#define MIN_SPEED 20 //in mph
#define TRAFFIC_DENSITY 30 // in percentage
#define HOUR_SECS 3600 // in seconds - length of one hour

int main(void) {
    srand(time(NULL)); //initialize random number generator

    int clock = 0; //initialize clock to zero seconds
    int num_cars_entered = 0; //initialize number of cars entered to zero
    int num_cars_exited = 0; //initialize number of cars exited to zero
    int num_cars_just_entered = 0; //initialize number of cars that just entered to zero
    int num_cars_just_exited = 0; //initialize number of cars that just exited to zero

    int lanes[NUM_OF_LANES][LANE_CAPACITY]; //initialize lanes with capacity

    //initialize lanes with -1 to indicate available space
    for (int i = 0; i < NUM_OF_LANES; i++) {
        for (int j = 0; j < LANE_CAPACITY; j++) {
            lanes[i][j] = -1;
        }
    }

    while (clock < SIM_DURATION) {
        num_cars_just_entered = 0;
        num_cars_just_exited = 0;

        //simulate car entry with a certain rate and random speed and lane selection
        if ((rand() % CAR_RATE) == 0) {
            double rand_speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED; //random speed between MIN_SPEED and MAX_SPEED
            int rand_lane = rand() % NUM_OF_LANES; //random lane selection

            //find the first available space in the selected lane
            int i = 0;
            while (lanes[rand_lane][i] != -1 && i < LANE_CAPACITY) {
                i++;
            }

            //if there is an available space, add the car to the selected lane
            if (i < LANE_CAPACITY) {
                lanes[rand_lane][i] = rand_speed;
                num_cars_entered++;
                num_cars_just_entered++;
            }
        }

        //simulate car exit with a probabilistic approach based on traffic density, speed and lane selection
        for (int i = 0; i < NUM_OF_LANES; i++) {
            for (int j = LANE_CAPACITY - 1; j >= 0; j--) {
                if (lanes[i][j] != -1) { //if there is a car at the current position
                    double rand_exit_prob = (rand() % 101); //generate a random number between 0 and 100 to be used as exit probability

                    if (rand_exit_prob < (TRAFFIC_DENSITY * lanes[i][j])/1000) { //exit probability is proportional to traffic density and speed
                        lanes[i][j] = -1; //remove car from lane
                        num_cars_exited++;
                        num_cars_just_exited++;
                    }
                    else {
                        //simulate car movement by updating its position (speed and time taken to cover that distance are assumed to be the same) and lane if there is an available adjacent lane
                        int next_lane = i;
                        while (next_lane == i || next_lane < 0 || next_lane >= NUM_OF_LANES) { //find a different lane than the current one that has available space
                            next_lane = i + ((rand() % 3) - 1); //random lane selection (either i-1, i or i+1)
                        }
                        int next_pos = j - lanes[i][j] * HOUR_SECS / 3600; //position of the car in the next second
                        if (next_lane >= 0 && next_lane < NUM_OF_LANES && next_pos >= 0 && next_pos < LANE_CAPACITY && lanes[next_lane][next_pos] == -1) { //if the next position is valid and available
                            lanes[next_lane][next_pos] = lanes[i][j]; //move the car to the next position
                            lanes[i][j] = -1; //remove car from current position
                        }
                    }
                }
            }
        }

        //print the current state of the simulation (number of cars entered and exited, and the occupancy of each lane)
        printf("Time: %d seconds\n", clock);
        printf("Cars Entered: %d\n", num_cars_just_entered);
        printf("Cars Exited: %d\n", num_cars_just_exited);
        for (int i = 0; i < NUM_OF_LANES; i++) {
            printf("Lane[%d]: ", i);
            for (int j = 0; j < LANE_CAPACITY; j++) {
                if (lanes[i][j] == -1) {
                    printf(". ");
                }
                else {
                    printf("C ");
                }
            }
            printf("\n");
        }
        printf("\n");

        //increment the clock
        clock++;
    }

    //print the final state of the simulation
    printf("Final State\n");
    printf("Time: %d seconds\n", clock);
    printf("Cars Entered: %d\n", num_cars_entered);
    printf("Cars Exited: %d\n", num_cars_exited);
    for (int i = 0; i < NUM_OF_LANES; i++) {
        printf("Lane[%d]: ", i);
        for (int j = 0; j < LANE_CAPACITY; j++) {
            if (lanes[i][j] == -1) {
                printf(". ");
            }
            else {
                printf("C ");
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}