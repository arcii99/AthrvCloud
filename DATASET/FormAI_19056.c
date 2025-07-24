//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // number of vehicles
#define DISTANCE 100 // distance of the road
#define MAX_SPEED 5 // maximum speed of vehicles
#define DEC_RATE 1 // rate at which vehicles reduce speed on encountering another vehicle

// Vehicle struct
typedef struct {
    int position; // position of the vehicle on the road
    int speed; // speed of the vehicle
} Vehicle;

int main() {
    srand(time(NULL)); // seed random number generator
    
    Vehicle vehicles[N]; // array of vehicles
    int i, j; // loop variables
    int time = 0; // simulation time
    int collision = 0; // flag for collision
    
    // initialize vehicles
    for (i = 0; i < N; i++) {
        vehicles[i].position = i * DISTANCE / N; // spread vehicles evenly across the road
        vehicles[i].speed = rand() % MAX_SPEED + 1; // generate random speed between 1 and MAX_SPEED
    }
    
    // run simulation
    while (time < 100) {
        // update positions
        for (i = 0; i < N; i++) {
            // check if there is a vehicle in front
            for (j = i + 1; j < N; j++) {
                if (vehicles[j].position <= vehicles[i].position) {
                    // reduce speed on encountering another vehicle
                    if (vehicles[i].speed > vehicles[j].speed + DEC_RATE) {
                        vehicles[i].speed = vehicles[j].speed + DEC_RATE;
                    }
                }
            }
            
            // update position based on speed
            vehicles[i].position += vehicles[i].speed;
            
            // check for collision
            if (i < N - 1 && vehicles[i].position == vehicles[i+1].position) {
                collision = 1;
            }
        }
        
        // print current state of the road
        printf("time: %d\t", time);
        for (i = 0; i < N; i++) {
            printf("v%d: %d\t", i, vehicles[i].position);
        }
        printf("\n");
        
        // break if there is a collision
        if (collision) {
            printf("Collision detected\n");
            break;
        }
        
        time++;
    }
    
    // print final state of the road
    printf("Final state of the road:\n");
    for (i = 0; i < N; i++) {
        printf("v%d: %d\t", i, vehicles[i].position);
    }
    printf("\n");
    
    return 0;
}