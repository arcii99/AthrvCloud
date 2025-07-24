//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>

#define GRAVITY 9.8 // m/s^2

int main() {
    float velocity = 0;
    float time = 0;
    float distance = 0;
    float height = 5; // meters
    float mass = 70; // kg
    
    // Calculate initial velocity required to reach height
    velocity = sqrt(2 * GRAVITY * height);
    printf("Initial velocity: %.2f m/s\n", velocity);
    
    // Simulate jumping off a platform
    while (height > 0) {
        time += 0.1; // Increment time by 0.1s
        distance = velocity * time - 0.5 * GRAVITY * time * time;
        height = height - distance;
        
        // Calculate new velocity after falling for 0.1s
        velocity = velocity - GRAVITY * 0.1;
        
        // Calculate new mass after losing 0.1% due to air resistance
        mass = mass * 0.999;
        
        printf("Time: %.2f s | Height: %.2f m | Velocity: %.2f m/s | Mass: %.2f kg\n", 
                time, height, velocity, mass);
    }
    
    printf("The object hit the ground after %.2f s\n", time);
    
    return 0;
}