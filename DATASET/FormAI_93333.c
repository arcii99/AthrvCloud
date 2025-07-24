//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 2     // number of lanes in the road
#define CARS 10     // number of cars in the simulation
#define MAX_SPEED 5 // maximum speed of the cars

int main() {
    srand(time(NULL)); // seed random number generator
    
    int road[LANES][100]; // initialize empty road
    int speeds[CARS];     // array to hold speeds of each car
    
    // randomly place cars on road and initialize their speeds
    for (int i = 0; i < CARS; i++) {
        int lane = rand() % LANES;      // randomly select lane
        int position = rand() % 100;    // randomly select position on road
        speeds[i] = rand() % MAX_SPEED; // randomly initialize speed
        road[lane][position] = i + 1;   // place car on road (numbered from 1 to CARS)
    }
    
    // simulate time steps
    for (int t = 0; t < 100; t++) {
        printf("Time step %d\n", t);
        
        // update each car's position according to its speed
        for (int i = 0; i < CARS; i++) {
            int lane, position;
            for (int l = 0; l < LANES; l++) {
                for (int p = 0; p < 100; p++) {
                    if (road[l][p] == i + 1) {
                        lane = l;
                        position = p;
                    }
                }
            }
            road[lane][position] = 0; // remove car from current position
            
            // update position and wrap around the road
            position += speeds[i];
            if (position >= 100) {
                position -= 100;
            }
            
            // check for collisions with other cars
            int collided = 0;
            for (int p = position; p < position + speeds[i]; p++) {
                if (road[lane][p % 100] != 0) {
                    collided = 1;
                }
            }
            if (collided) {
                speeds[i] = 0;
            } else {
                road[lane][position] = i + 1; // place car in new position
            }
        }
        
        // print the current state of the road
        for (int l = 0; l < LANES; l++) {
            for (int p = 0; p < 100; p++) {
                if (road[l][p] != 0) {
                    printf("%d ", road[l][p]);
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}