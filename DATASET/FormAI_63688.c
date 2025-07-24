//FormAI DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include<stdio.h>
#include<math.h>

// Defining constants
#define APPROXIMATION_ERROR 1e-6
#define GRAVITATIONAL_CONSTANT 6.67430e-11

void update_position(double *position, double *velocity, double acceleration, double time_step){
    *position += (*velocity)*time_step + 0.5*acceleration*pow(time_step,2);
    *velocity += acceleration*time_step;
}

void calculate_acceleration(double *acceleration, double *position, double mass, double gravitational_constant){
    double distance = sqrt(pow(*position,2));
    *acceleration = ((-1)*gravitational_constant*mass)/pow(distance,2);
}

int main(){
    // Defining initial values for position, velocity and acceleration
    double position = 7000000; // m
    double velocity = 0; // m/s
    double acceleration;

    // Defining values for mass and time_step
    double mass = 5.972e24; // kg
    double time_step = 1; // s

    // Printing initial values of position and velocity
    printf("Initial position: %f m\n", position);
    printf("Initial velocity: %f m/s\n", velocity);

    // Updating position and velocity at each time step
    int i = 1;
    while(position>=0){
        // (1) Calculate acceleration
        calculate_acceleration(&acceleration, &position, mass, GRAVITATIONAL_CONSTANT);

        // (2) Update position and velocity
        update_position(&position, &velocity, acceleration, time_step);

        // Printing position and velocity
        printf("Position after %d s: %f m\n", i*time_step, position);
        printf("Velocity after %d s: %f m/s\n", i*time_step, velocity);

        i++;
    }
    return 0;
}