//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>

// This program simulates a ball bouncing up and down with conservation of energy and momentum

int main() {
    double mass = 0.5; // mass of the ball
    double radius = 0.1; // radius of the ball
    double height = 1.0; // starting height of the ball above the ground
    double gravity = 9.81; // acceleration due to gravity
    double bounce_coeff = 0.8; // coefficient of restitution for the ball

    double velocity = sqrt(2 * mass * gravity * height); // velocity of the ball at the starting height
    double momentum = mass * velocity; // momentum of the ball at the starting height
    double kinetic_energy = 0.5 * mass * pow(velocity, 2); // kinetic energy of the ball at the starting height

    printf("Starting height: %.2f m\n", height);
    printf("Starting velocity: %.2f m/s\n", velocity);
    printf("Starting momentum: %.2f kg*m/s\n", momentum);
    printf("Starting kinetic energy: %.2f J\n", kinetic_energy);
    printf("\n");

    double time_step = 0.01; // time step for the simulation
    double time = 0.0; // current time in the simulation

    while (height > 0.0) {
        double acceleration = -gravity; // acceleration of the ball due to gravity
        double delta_time = time_step; // delta time for the current step

        if (height - radius <= 0.0) { // check if the ball is touching or below the ground
            velocity *= -bounce_coeff; // reverse the direction of the velocity due to the bounce
            delta_time = fabs(height - radius) / velocity; // calculate the time until the next bounce
        }

        height += velocity * delta_time + 0.5 * acceleration * pow(delta_time, 2); // update the height
        velocity += acceleration * delta_time; // update the velocity
        momentum = mass * velocity; // update the momentum
        kinetic_energy = 0.5 * mass * pow(velocity, 2); // update the kinetic energy
        time += delta_time; // update the time

        printf("Time: %.2f s\n", time);
        printf("Height: %.2f m\n", height);
        printf("Velocity: %.2f m/s\n", velocity);
        printf("Momentum: %.2f kg*m/s\n", momentum);
        printf("Kinetic energy: %.2f J\n", kinetic_energy);
        printf("\n");
    }

    return 0;
}