//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int num_cars = 10, time_period = 300; // number of cars and simulation time in seconds
    float speed_min = 20.0, speed_max = 60.0; // minimum and maximum speeds of cars
    int position[num_cars]; // stores position of each car on the road
    float speed[num_cars]; // stores speed of each car
    int count = 0; // counter for number of cars that have passed the simulation window
    srand(time(0)); // seed for random numbers

    // initialize the positions and speeds of cars randomly
    for(int i=0; i<num_cars; i++) {
        position[i] = i * 10; // assume the road is 10 meters wide and each car is separated by 10 meters
        speed[i] = (float) (rand() % (int) (speed_max - speed_min + 1.0)) + speed_min;
    }

    // simulation loop
    for(int t=0; t<time_period; t++) {
        // print the current positions of cars
        printf("Time: %d s\n", t);
        for(int i=0; i<num_cars; i++) {
            printf("Car %d: Position=%.1f m, Speed=%.1f m/s\n", i, position[i], speed[i]);
        }

        // update the positions of cars based on their speeds
        for(int i=0; i<num_cars; i++) {
            position[i] = position[i] + (int) (speed[i] * 1.0); // assume time step of 1 second
        }

        // check for collisions or if a car has passed the simulation window
        for(int i=0; i<num_cars; i++) {
            if(position[i] >= 1000) { // assume simulation window is 1000 meters long
                count++;
                position[i] = -100; // reset position of car to a negative value to represent that it has left the simulation window
            }
            for(int j=0; j<num_cars; j++) {
                if(i != j && position[i] == position[j]) {
                    // collision occurs, reduce speeds of both cars
                    speed[i] = speed[i] / 2.0;
                    speed[j] = speed[j] / 2.0;
                }
            }
        }
    }

    // print the number of cars that have passed the simulation window
    printf("Total cars that passed: %d", count);

    return 0;
}