//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define LIGHT_CYCLE 10
#define GREEN_LIGHT 4

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int in_count = 0; // number of cars in the input queue
    int out_count = 0; // number of cars in the output queue
    int cars_on_road = 0; // number of cars on the road
    int cars_passed = 0; // number of cars that have successfully passed through the intersection
    
    int input_queue[MAX_CARS]; // queue for cars waiting to enter the intersection
    int output_queue[MAX_CARS]; // queue for cars that have passed through the intersection
    
    int light_timer = 0; // timer for the traffic light
    int light_color = 0; // 0 = green, 1 = red
    
    while (cars_passed < MAX_CARS) { // loop until all cars have passed
        // check if a car arrives at the input queue
        if (rand() % 2 == 0 && in_count < MAX_CARS - cars_on_road) {
            input_queue[in_count++] = 1; // add a car to the input queue
        }
        
        // check if the traffic light changes color
        if (++light_timer >= LIGHT_CYCLE) {
            light_timer = 0; // reset the timer
            light_color = !light_color; // change the light color
            
            // if the light is green, move cars from the input queue to the road
            if (light_color == 0 && in_count > 0 && cars_on_road < GREEN_LIGHT) {
                int cars_to_move = GREEN_LIGHT - cars_on_road; // determine how many cars can move
                if (in_count < cars_to_move) {
                    cars_to_move = in_count; // only move as many cars as there are in the queue
                }
                for (int i = 0; i < cars_to_move; i++) {
                    input_queue[--in_count] = 0; // remove the car from the input queue
                    cars_on_road++; // add the car to the road
                }
            }
        }
        
        // move cars from the road to the output queue
        for (int i = 0; i < cars_on_road; i++) {
            if (rand() % 2 == 0) { // 50% chance of a car passing through the intersection
                output_queue[out_count++] = 1; // add the car to the output queue
                cars_on_road--; // remove the car from the road
                cars_passed++; // add to the number of cars that have passed
            }
        }
        
        // print the current state of the simulation
        printf("Input Queue: ");
        for (int i = 0; i < in_count; i++) {
            printf("%d ", input_queue[i]);
        }
        printf("\n");
        
        printf("Road: ");
        for (int i = 0; i < cars_on_road; i++) {
            printf("%d ", 1);
        }
        printf("\n");
        
        printf("Output Queue: ");
        for (int i = 0; i < out_count; i++) {
            printf("%d ", output_queue[i]);
        }
        printf("\n\n");
    }
    
    return 0; // end of program
}