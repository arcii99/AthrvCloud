//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(0)); //seed for random function

    int time_passed = 0; //initialize time passed
    int vehicles_passed = 0; //initialize vehicles passed
    
    int green_light_time = 10; //time allowed for green light
    int red_light_time = 20; //time allowed for red light
    int total_time = 300; //total simulation time in seconds

    while (time_passed < total_time) {

         //simulate traffic flow for one cycle
        int cars_arrived = rand() % 20 + 1; //generate random number of cars arrived
        int cars_passed = rand() % 10 + 1; //generate random number of cars that pass through intersection
        int cycle_time = green_light_time + red_light_time; //total time for one cycle

        printf("Time elapsed: %d seconds\n", time_passed);
        printf("%d cars arrived at the intersection\n", cars_arrived);

        if (time_passed % cycle_time < green_light_time) { //check if it's green light time
            printf("Green light on!\n");
            printf("%d cars passed the intersection\n", cars_passed);
            vehicles_passed += cars_passed; //add passed vehicles to total
        }
        else {
            printf("Red light on!\n");
        }

        time_passed += cycle_time; //increment time passed by one cycle
        printf("\n");
    }

    printf("Simulation ended\n");
    printf("Vehicles passed through intersection: %d\n", vehicles_passed);
    
    return 0;
}