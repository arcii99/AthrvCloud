//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void red_light(int count);  // function declaration for red light
void yellow_light(int count);  // function declaration for yellow light
void green_light(int count);  // function declaration for green light

int main() {
    int count = 0;  // initialize count
    
    // call the recursive functions to simulate the traffic light
    printf("Starting the traffic light...\n");
    green_light(count);  // start with green light
    
    return 0;
}

void red_light(int count) {
    printf("Red Light\n");
    count++;  // increment counter
    
    if (count == 3) {  // after 3 red lights, stop the simulation
        printf("Simulation Complete\n");
        return;
    }
    
    yellow_light(count);  // move to yellow light
}

void yellow_light(int count) {
    printf("Yellow Light\n");
    count++;  // increment counter
    
    green_light(count);  // move to green light
}

void green_light(int count) {
    printf("Green Light\n");
    count++;  // increment counter
    
    red_light(count);  // move to red light
}