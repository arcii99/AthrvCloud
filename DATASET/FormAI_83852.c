//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeds random generator with current time
    
    int cars[20]; // array to hold number of cars at each time interval
    int maxCars = 0; // variable to hold the maximum number of cars
    
    printf("Welcome to the Traffic Flow Simulation!\n");
    printf("Get ready to experience the thrill of rush hour traffic without leaving your computer!\n");
    
    // loop to simulate traffic flow for 1 hour
    for (int i = 0; i < 60; i++) {
        int numCars = rand() % 20 + 1; // generate random number of cars
        
        printf("Minute %d: %d cars on the road!\n", i+1, numCars);
        
        if (numCars > maxCars) {
            maxCars = numCars; // update maxCars variable if new max is found
        }
        
        cars[i] = numCars; // store number of cars for current time interval
    }
    
    printf("\nSimulation complete!\n");
    printf("The maximum number of cars on the road was %d.\n", maxCars);
    printf("Here's a graph of the traffic flow:\n");
    
    // loop to print graph of traffic flow
    for (int i = 0; i < 20; i++) {
        printf("%2d: ", i+1);
        for (int j = 0; j < cars[i]; j++) {
            printf("*"); // print asterisk for each car
        }
        printf("\n");
    }
    
    return 0;
}