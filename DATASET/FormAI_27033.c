//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

double planetPosX[3] = {0.0, 3.0, 5.0};  // x coordinates of 3 planets
double planetPosY[3] = {0.0, 4.0, -2.0};  // y coordinates of 3 planets
double planetVelX[3] = {0.0, 0.0, 0.0};  // velocities of 3 planets in x direction
double planetVelY[3] = {0.0, 0.0, 0.0};  // velocities of 3 planets in y direction
double planetMass[3] = {10.0, 20.0, 30.0};  // masses of 3 planets
double G = 1.0;  // gravitational constant

void updatePositionVelocity(double dt)
{
    double distance, force, forceX, forceY;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                distance = sqrt(pow((planetPosX[i] - planetPosX[j]), 2) + pow((planetPosY[i] - planetPosY[j]), 2));
                force = G * planetMass[i] * planetMass[j] / pow(distance, 2);
                forceX = force * (planetPosX[j] - planetPosX[i]) / distance;
                forceY = force * (planetPosY[j] - planetPosY[i]) / distance;

                planetVelX[i] += forceX / planetMass[i] * dt;
                planetVelY[i] += forceY / planetMass[i] * dt;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        planetPosX[i] += planetVelX[i] * dt;
        planetPosY[i] += planetVelY[i] * dt;
    }
}

int main(void)
{
    double totalTime = 10.0;  // total time for simulation
    double dt = 0.01;  // time step

    printf("Initial positions:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Planet %d: (%f, %f)\n", i+1, planetPosX[i], planetPosY[i]);
    }

    for (double t = 0.0; t < totalTime; t += dt)
    {
        updatePositionVelocity(dt);
    }

    printf("Final positions after %f seconds:\n", totalTime);

    for (int i = 0; i < 3; i++)
    {
        printf("Planet %d: (%f, %f)\n", i+1, planetPosX[i], planetPosY[i]);
    }

    return 0;
}