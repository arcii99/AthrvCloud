//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x = 0, y = 0; // values for x and y coordinates
    int vx = 10, vy = 5; // values for x and y velocities
    int ax = 0, ay = -10; // values for x and y accelerations
    int t = 0; // time variable
    int dt = 1; // time increment
    
    while (y >= 0) { // loop while object is still in air
        x = x + vx * dt + 0.5 * ax * dt * dt; // calculate new x coordinate
        y = y + vy * dt + 0.5 * ay * dt * dt; // calculate new y coordinate
        
        vx = vx + ax * dt; // calculate new x velocity
        vy = vy + ay * dt; // calculate new y velocity
        
        t = t + dt; // increment time
        
        printf("Time: %d seconds, x: %d meters, y: %d meters\n", t, x, y);
    }
    
    printf("The object hit the ground at a time of %d seconds and a distance of %d meters.\n", t, x);
    
    return 0;
}