//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
/* This C Traffic Light Controller program demonstrates a simple traffic light system.
   It operates on a loop, switching the state of the traffic light after a predetermined
   amount of time has passed. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int lightState = RED;
    clock_t startTime = clock();
    double elapsedTime = 0.0;
    
    while (1) {
        elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
        
        if (elapsedTime > 5.0) {
            startTime = clock();
            
            switch (lightState) {
                case RED:
                    lightState = GREEN;
                    printf("Traffic light is now green.\n");
                    break;
                case YELLOW:
                    lightState = RED;
                    printf("Traffic light is now red.\n");
                    break;
                case GREEN:
                    lightState = YELLOW;
                    printf("Traffic light is now yellow.\n");
                    break;
            }
        }
    }

    return 0;
}