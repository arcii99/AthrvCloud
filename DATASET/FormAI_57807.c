//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8 // m/s^2

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    float height = rand() % 100 + 1; // Generate a random height from 1 to 100 meters
    float velocity = 0; // Initialize the velocity to 0 m/s
    float time = 0; // Initialize the time to 0 seconds
    
    printf("Starting height: %.2f m\n", height);
    
    while (height > 0) {
        time += 0.1; // Increment the time by 0.1 seconds
        float acceleration = -GRAVITY; // Calculate the acceleration due to gravity
        
        float wind_force = rand() % 10 - 5; // Generate a random wind force from -5 to 5 N
        float air_resistance = -0.5 * wind_force / 70; // Calculate the air resistance
        
        acceleration += air_resistance; // Add the air resistance to the acceleration
        
        velocity += acceleration * 0.1; // Calculate the new velocity
        height += velocity * 0.1; // Calculate the new height
        
        if (height < 0) { // If the height is negative, set it to 0 and break out of the loop
            height = 0;
            break;
        }
        
        printf("Time: %.2f s\tHeight: %.2f m\n", time, height); // Print the current time and height
    }
    
    printf("Time of landing: %.2f s\n", time); // Print the time of landing
    
    return 0;
}