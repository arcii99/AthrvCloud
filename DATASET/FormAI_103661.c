//FormAI DATASET v1.0 Category: Physics simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8 // Earth's gravitational acceleration in m/s^2

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    double initialHeight, timeElapsed, velocity, distance; 
    int numIterations = 0;
    
    printf("Enter the initial height of the object (in meters): ");
    scanf("%lf", &initialHeight);
    
    velocity = 0; // Start with zero initial velocity
    distance = initialHeight; // Start at height the object was dropped from
    
    // Loop until object reaches the ground (distance = 0)
    while(distance > 0) {
        // Calculate time elapsed for this iteration
        timeElapsed = numIterations * 0.1; // Interval of 0.1 seconds
        
        // Calculate new velocity using v = u + at
        velocity = velocity + (GRAVITY * timeElapsed);
        
        // Calculate new distance using s = ut + (1/2)at^2
        distance = initialHeight - (velocity * timeElapsed) - (0.5 * GRAVITY * timeElapsed * timeElapsed);
        
        printf("Time elapsed: %.1lf seconds || Distance fallen: %.2lf meters || Velocity: %.2lf m/s\n",  timeElapsed, initialHeight - distance, velocity);
        
        numIterations++;
    }
    
    printf("The object hit the ground after %.1lf seconds.\n", (numIterations - 1) * 0.1);
    
    return 0;
}