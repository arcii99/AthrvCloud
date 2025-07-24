//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy Physics Simulation Program!\n");
    printf("Today we will simulate the bouncing of a ball on a trampoline!\n\n");
    srand(time(NULL));
    
    double ball_height = 10.0;
    double ball_velocity = 0.0;
    double ball_acceleration = -9.81;
    double trampoline_height = 5.0;
    double trampoline_stiffness = 1000.0;
    double trampoline_damping = 50.0;
    double time_step = 0.01;
    double time = 0.0;
    
    while (ball_height >= trampoline_height) {
        // Calculate the force exerted by the trampoline on the ball
        double trampoline_force = trampoline_stiffness * (ball_height - trampoline_height) + trampoline_damping * ball_velocity;
        
        // Update the ball's acceleration and velocity
        ball_acceleration = (trampoline_force / 1.0) + (-9.81);
        ball_velocity += ball_acceleration * time_step;
        
        // Update the ball's position and time
        ball_height += ball_velocity * time_step;
        time += time_step;
        
        // Print out the current height of the ball
        printf("Time: %.2f seconds\n", time);
        printf("Ball height: %.2f meters\n\n", ball_height);
        
        // Add some randomness to the ball's position and velocity
        ball_height += ((double)rand() / RAND_MAX) * 0.2;
        ball_velocity += ((double)rand() / RAND_MAX) * 0.2 - 0.1;
    }
    
    // The ball has stopped bouncing, print out the final time and height
    printf("The ball stopped bouncing at %.2f seconds with a height of %.2f meters.\n", time, ball_height);
    
    return 0;
}