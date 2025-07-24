//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
// This physics simulation program simulates a bouncing ball on a floor and tracks its motion.
// Created by AI Chatbot

#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81
#define FLOOR_HEIGHT 1.0

int main() {
    
    // Ball Properties
    double ballRadius = 0.05;
    double ballMass = 0.1;
    
    // Initial Velocity
    double initialVelocity = 3.0;
    
    // Ball Position & Velocity
    double ballPosition = ballRadius + FLOOR_HEIGHT;
    double ballVelocity = initialVelocity;
    
    // Time Variables
    double currentTime = 0.0;
    double timeStep = 0.01;
    
    // Simulation Loop
    while (ballPosition > ballRadius + FLOOR_HEIGHT) {
        
        // Calculate Net Force
        double netForce = ballMass * GRAVITY;
        
        // Calculate Acceleration
        double acceleration = netForce / ballMass;
        
        // Update Velocity
        ballVelocity = ballVelocity - (acceleration * timeStep);
        
        // Update Position
        ballPosition = ballPosition - (ballVelocity * timeStep);
        
        // Check if ball hits the floor and transfer momentum
        if (ballPosition <= ballRadius + FLOOR_HEIGHT) {
            
            // Calculate momentum before collision
            double momentumBefore = ballMass * ballVelocity;
            
            // Calculate momentum transfer
            double momentumTransfer = -2 * momentumBefore;
            
            // Update Velocity after collision
            ballVelocity = (momentumTransfer + momentumBefore) / ballMass;
        }
        
        // Update Current Time
        currentTime = currentTime + timeStep;
        
        // Print Current State of Ball
        printf("Time: %.2f seconds | Ball Position: %.2f meters | Ball Velocity: %.2f m/s\n", currentTime, ballPosition, ballVelocity);
    }
    
    printf("The ball hit the ground after %.2f seconds.\n", currentTime);
    
    return 0;
}