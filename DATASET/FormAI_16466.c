//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 * This is a simulation program that models the motion 
 * of a ball dropped from a height of 10 meters.
 * The program computes the velocity, accelerations and 
 * position of the ball at every second until it hits the ground.
 */

int main(void)
{
    double height = 10.0;  // The height from which the ball is dropped
    double gravity = 9.8;  // The acceleration due to gravity
    double time = 0.0;     // The time in seconds since the ball was dropped
    double velocity = 0.0; // The velocity of the ball
    double position = height; // The position of the ball
    
    // Print the header
    printf("Time\tPosition\tVelocity\tAcceleration\n");

    // Run the simulation until the ball hits the ground
    while(position>0)
    {   
        double acceleration = -gravity; // The acceleration of the ball
        printf("%.2f\t%.2f\t%.2f\t%.2f\n",time,position,velocity,acceleration); // Print the values
        
        velocity += acceleration; // Update the velocity
        position += velocity;     // Update the position
        time++;                   // Increment the time
    }
    
    printf("%.2f\t%.2f\t%.2f\t%.2f\n",time,position,velocity,0.0); // Print the final values
    
    return 0;
}