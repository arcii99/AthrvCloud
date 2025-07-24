//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Simulation parameters
    double mass = 1.0; // kg
    double velocity = 10.0; // m/s
    double angle = 30.0; // degrees
    double x = 0.0; // m
    double y = 0.0; // m
    double timeStep = 0.01; // s
    double time = 0.0; // s
    double coefficientOfRestitution = 0.8; // Between 0 and 1
    double dragCoefficient = 0.1; // Depends on the object's shape and velocity
    double airDensity = 1.225; // kg/m^3 at sea level, depends on altitude

    // Derived parameters
    double projectedArea = 0.1 * 0.1; // m^2, assuming a spherical object with 0.1 m diameter
    double dragForceMagnitude = 0.5 * dragCoefficient * airDensity * projectedArea * velocity * velocity;

    // Calculate components of initial velocity vector
    double vx = velocity * cos(angle * PI / 180.0);
    double vy = velocity * sin(angle * PI / 180.0);

    // Simulation loop
    while (y >= 0.0)
    {
        // Calculate acceleration due to gravity
        double g = -9.81; // m/s^2
        double ax = 0.0;
        double ay = g;

        // Calculate drag force vector
        double dragForceX = -dragForceMagnitude * vx;
        double dragForceY = -dragForceMagnitude * vy;

        // Calculate net force vector
        double netForceX = dragForceX;
        double netForceY = mass * ay + dragForceY;

        // Calculate acceleration vector
        double accelX = netForceX / mass;
        double accelY = netForceY / mass;

        // Calculate new velocity vector using Euler's method
        vx += accelX * timeStep;
        vy += accelY * timeStep;

        // Calculate new position vector using Euler's method
        x += vx * timeStep;
        y += vy * timeStep;

        // Check for collision with ground
        if (y < 0.0)
        {
            // Calculate time of collision using linear interpolation
            double t = timeStep * (0.0 - y) / (vy - 0.5 * g * timeStep);

            // Calculate position vector at time of collision
            double xc = x + vx * t;
            double yc = 0.0;

            // Calculate velocity vector after collision
            double vMag = sqrt(vx * vx + vy * vy);
            double vcMag = coefficientOfRestitution * vMag;
            double vcx = vcMag * cos(angle * PI / 180.0);
            double vcy = vcMag * sin(angle * PI / 180.0);

            // Update position and velocity vectors
            x = xc + vcx * (timeStep - t);
            y = yc + vcy * (timeStep - t);
            vx = vcx;
            vy = vcy;

            // Apply damping to velocity vector
            vx *= 0.5;
            vy *= 0.5;

            // Print collision information
            printf("Collision at t = %f s, x = %f m, v = %f m/s\n", time + t, x, vcMag);
        }

        // Increment time
        time += timeStep;
    }

    return EXIT_SUCCESS;
}