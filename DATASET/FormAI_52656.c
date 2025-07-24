//FormAI DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY -9.81  // acceleration due to gravity
#define BOUNCE_FACTOR 0.7  // factor of energy lost on each bounce
#define TIME_STEP 0.01  // time step of simulation

int main() {
    double height = 10.0;  // initial height of ball
    double velocity = 0.0;  // initial velocity of ball
    double time = 0.0;  // time elapsed in simulation
    double energy_loss = 1.0;  // energy loss factor due to bouncing
    
    while (height > 0.0) {
        // update position and velocity based on acceleration due to gravity
        height += velocity * TIME_STEP;
        velocity += GRAVITY * TIME_STEP;
        time += TIME_STEP;
        
        if (height < 0.0) {
            // ball has hit the ground, so simulate bouncing
            height = 0.0;
            velocity *= -BOUNCE_FACTOR;
            energy_loss *= BOUNCE_FACTOR;
            
            if (velocity < 0.01) {
                // ball has stopped bouncing, end simulation
                break;
            }
        }
        
        printf("Time: %.2f s | Height: %.2f m | Velocity: %.2f m/s | Energy Loss: %.2f\n", time, height, velocity, energy_loss);
    }
    
    return EXIT_SUCCESS;
}