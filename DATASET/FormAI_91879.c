//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81

int main() {
    float mass1, mass2, distance, force, acceleration1, acceleration2, velocity1 = 0, velocity2 = 0, time = 0;
    
    printf("Enter the mass of the first body: ");
    scanf("%f", &mass1);
    
    printf("Enter the mass of the second body: ");
    scanf("%f", &mass2);
    
    printf("Enter the distance between the bodies: ");
    scanf("%f", &distance);
    
    force = (GRAVITY * mass1 * mass2) / (distance * distance);
    
    acceleration1 = force / mass1;
    acceleration2 = force / mass2;
    
    while (distance > 0) {
        printf("Time: %.2fs\n", time);
        printf("Distance: %.2fm\n", distance);
        printf("Velocity 1: %.2fm/s\n", velocity1);
        printf("Velocity 2: %.2fm/s\n", velocity2);
        
        velocity1 += acceleration1 * 0.01;
        velocity2 += acceleration2 * 0.01;
        
        distance -= ((velocity1 + velocity2) / 2) * 0.01;
        
        time += 0.01;
    }
    
    printf("The bodies have collided at %.2fs.\n", time);
    
    return 0;
}