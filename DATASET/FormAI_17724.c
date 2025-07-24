//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HIGHWAY_LENGTH 1000
#define LANE_WIDTH 3
#define EXIT_RAMP_LENGTH 100
#define MAX_SPEED 6
#define CAR_DENSITY 0.3

typedef struct {
    int lane;
    int position;
    int speed;
    int destination;
} Car;

// helper function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // initialize the highway as a 2D array
    int highway[2][HIGHWAY_LENGTH];

    // initialize all highway cells to -1 (empty)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < HIGHWAY_LENGTH; j++) {
            highway[i][j] = -1;
        }
    }

    // randomly place cars on the highway
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < HIGHWAY_LENGTH; j++) {
            if ((double) rand() / RAND_MAX < CAR_DENSITY) {
                Car car;
                car.lane = i;
                car.position = j;
                car.speed = rand_int(0, MAX_SPEED);
                car.destination = rand_int(j + 1, HIGHWAY_LENGTH + EXIT_RAMP_LENGTH);
                highway[i][j] = car.speed == 0 ? car.lane : car.position;
            }
        }
    }

    // run the simulation for 100 time steps
    for (int time_step = 0; time_step < 100; time_step++) {
        // update the position of each car
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < HIGHWAY_LENGTH; j++) {
                if (highway[i][j] != -1) {
                    Car car;
                    car.lane = i;
                    car.position = j;
                    car.speed = highway[i][j];
                    car.destination = j + EXIT_RAMP_LENGTH;
                    highway[i][j] = -1;

                    // accelerate
                    if (car.speed < MAX_SPEED) {
                        car.speed++;
                    }

                    // move
                    int next_position = j + car.speed;
                    if (next_position >= HIGHWAY_LENGTH + EXIT_RAMP_LENGTH) {
                        // car has reached its destination
                        continue;
                    } else if (next_position >= HIGHWAY_LENGTH) {
                        // car is on the exit ramp
                        if (car.lane == 0) {
                            printf("Car in left lane exited at time step %d\n", time_step);
                        } else {
                            printf("Car in right lane exited at time step %d\n", time_step);
                        }
                        continue;
                    } else if (highway[i][next_position] == -1) {
                        // car can move forward in its own lane
                        car.position = next_position;
                    } else if (i == 1 && highway[0][j] == -1) {
                        // car can move forward by switching to the left lane
                        car.lane = 0;
                        car.position = j;
                    } else if (i == 0 && highway[1][j] == -1) {
                        // car can move forward by switching to the right lane
                        car.lane = 1;
                        car.position = j;
                    } else {
                        // car must slow down
                        car.speed--;
                    }

                    highway[car.lane][car.position] = car.speed == 0 ? car.lane : car.position;
                }
            }
        }

        // print the highway at this time step
        printf("Time step: %d\n", time_step);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < HIGHWAY_LENGTH; j++) {
                if (highway[i][j] == -1) {
                    printf(".");
                } else if (highway[i][j] == i) {
                    printf("*");
                } else {
                    printf("+");
                }
            }
            printf("\n");
        }
        printf("\n");

        // wait for a moment before continuing
        usleep(500000);
    }

    return 0;
}