//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    float alpha, beta, gamma;
    float initial_velocity = 10.0;
    float acceleration = 9.81;
    float time = 0.0;
    float delta_time = 0.1;
    int num_steps = 100;
    int i;
    float x,y,z;

    alpha = 45 * M_PI / 180;
    beta = 30 * M_PI / 180;
    gamma = 60 * M_PI / 180;

    x = initial_velocity * sin(alpha) * cos(beta);
    y = initial_velocity * sin(alpha) * sin(beta);
    z = initial_velocity * cos(alpha);

    printf("Initial Velocity: %f\n", initial_velocity);
    printf("Initial Alpha Angle: %f\n", alpha);
    printf("Initial Beta Angle: %f\n", beta);
    printf("Initial Gamma Angle: %f\n", gamma);
    
    printf("x(0) = %f, y(0) = %f, z(0) = %f\n\n", x, y, z);

    for (i=0; i<=num_steps; i++) 
    {
        time = time + delta_time;

        x = x + initial_velocity * sin(alpha) * cos(beta) * delta_time;
        y = y + initial_velocity * sin(alpha) * sin(beta) * delta_time;
        z = z + initial_velocity * cos(alpha) * delta_time - 0.5 * acceleration * pow(delta_time, 2);

        alpha = alpha - gamma * delta_time;
        beta = beta - gamma * delta_time;

        printf("x(%f) = %f, y(%f) = %f, z(%f) = %f\n", time, x, time, y, time, z);
    }

    printf("\nFinal Velocity: %f\n", initial_velocity - acceleration * time);
    return 0;
}