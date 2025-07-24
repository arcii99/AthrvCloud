//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int total_cars = 0;
    int total_time = 0;
    int time_per_car = 0;
    int minute = 0;
    srand(time(NULL)); // seed the random number generator with current time
    
    for (int i = 0; i < 60; i++) { // simulate 60 minutes of traffic
        int num_cars = rand() % 20 + 1; // generate a random number of cars between 1 and 20
        total_cars += num_cars; // add the number of cars to the total
        
        for (int j = 0; j < num_cars; j++) { // simulate each individual car
            int speed = rand() % 30 + 30; // generate a random speed between 30 and 60 mph
            int distance = rand() % 5 + 1; // generate a random distance between 1 and 5 miles
            time_per_car = (distance / speed) * 60; // calculate how long it will take the car to travel the distance at the given speed
            total_time += time_per_car; // add the time to the total
        }
        
        minute++; // increment the minute counter
        
        if (minute == 60) { // if it's been an hour, reset the minute counter and print the results
            minute = 0;
            printf("Total number of cars that passed through is: %d\n", total_cars);
            printf("Total time taken for all the cars to pass through traffic is: %d minutes\n", total_time);
            total_cars = 0;
            total_time = 0;
        }
    }
    
    return 0;
}