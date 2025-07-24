//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// function to compute the trajectory of a projectile
void projectileMotion(float vel, float angle, float timeStep, float airResistance) {
    // initial conditions
    float xPos = 0.0;
    float yPos = 0.0;
    float xVel = vel * cos(angle * PI / 180);
    float yVel = vel * sin(angle * PI / 180);

    printf("Time(s)\txDist(m)\tyDist(m)\n");

    // loop through time steps until projectile hits the ground
    while (yPos >= 0.0) {
        printf("%.2f\t%.2f\t%.2f\n", timeStep, xPos, yPos);

        // calculate the acceleration due to air resistance
        float xAccel = -airResistance * xVel * sqrt(pow(xVel, 2.0) + pow(yVel, 2.0));
        float yAccel = -9.81 - airResistance * yVel * sqrt(pow(xVel, 2.0) + pow(yVel, 2.0));

        // update the velocities
        xVel = xVel + xAccel * timeStep;
        yVel = yVel + yAccel * timeStep;

        // update the positions
        xPos = xPos + xVel * timeStep;
        yPos = yPos + yVel * timeStep;

        // update the time
        timeStep += 0.01;
    }

    printf("The projectile hit the ground at time %.2f seconds and traveled %.2f meters.\n", timeStep, xPos);
}

int main() {
    float vel = 30.0; // initial velocity of the projectile in m/s
    float angle = 45.0; // launch angle of the projectile in degrees
    float timeStep = 0.01; // time step for simulation in seconds
    float airResistance = 0.01; // coefficient of air resistance
    projectileMotion(vel, angle, timeStep, airResistance); // call the function to simulate projectile motion
    return 0;
}