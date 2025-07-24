//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>

int main() {
    // Define variables
    float time, acceleration, velocity, distance;
    
    // Ask for user input
    printf("Enter time (in seconds): ");
    scanf("%f", &time);
    printf("Enter acceleration (in meters per second squared): ");
    scanf("%f", &acceleration);
    printf("Enter initial velocity (in meters per second): ");
    scanf("%f", &velocity);
    printf("Enter initial distance (in meters): ");
    scanf("%f", &distance);
    
    // Calculate new values
    velocity = velocity + acceleration * time;
    distance = distance + (velocity * time) + (0.5 * acceleration * time * time);
    
    // Print out results
    printf("New velocity is %f meters/second\n", velocity);
    printf("New distance is %f meters\n", distance);
    
    return 0;
}