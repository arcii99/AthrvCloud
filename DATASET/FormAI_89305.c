//FormAI DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.81

double generate_random_number(double min, double max) {
    double random_number = (double)rand() / RAND_MAX;
    return min + random_number * (max - min);
}

int main() {
    srand(time(NULL)); // Seed for generating random numbers
    
    // Setting up simulation variables
    double height = generate_random_number(10, 50); // Initial height of object
    double velocity = generate_random_number(5, 20); // Initial velocity of object
    double angle = generate_random_number(0, 90); // Angle of launch
    double time_step = 0.01; // Time step for simulation
    double x_position = 0; // Initial x position of object
    double y_position = height; // Initial y position of object
    
    double x_velocity = velocity * cos(angle); // x velocity component
    double y_velocity = velocity * sin(angle); // y velocity component
    
    // Printing initial conditions
    printf("Initial height: %.2lf meters\n", height);
    printf("Initial velocity: %.2lf m/s, Angle: %.2lf degrees\n", velocity, angle);
    
    // Running simulation
    while (y_position >= 0) {
        x_position += x_velocity * time_step; // Updating x position
        y_position += y_velocity * time_step - 0.5 * GRAVITY * pow(time_step, 2); // Updating y position and accounting for gravity
        
        if (y_position < 0) {
            y_position = 0; // Preventing object from falling through ground
        }
        
        y_velocity -= GRAVITY * time_step; // Updating y velocity due to gravity
        
        // Checking for collision with ground
        if (y_position == 0) {
            printf("Object has hit the ground at x = %.2lf meters!\n", x_position);
            break;
        }
    }
    
    return 0;
}