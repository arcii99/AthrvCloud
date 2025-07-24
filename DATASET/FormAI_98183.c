//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 //Gravitational constant
#define TIMESTEP 0.001 //Timestep

typedef struct Vector
{
    double x, y;
} Vector;

typedef struct Planet
{
    Vector position, velocity, acceleration;
    double mass, radius;
} Planet;

Vector addVectors(Vector v1, Vector v2)
{
    Vector v = {v1.x + v2.x, v1.y + v2.y};
    return v;
}

Vector subtractVectors(Vector v1, Vector v2)
{
    Vector v = {v1.x - v2.x, v1.y - v2.y};
    return v;
}

double distance(Vector v1, Vector v2)
{
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

Vector normalize(Vector v)
{
    double length = sqrt(pow(v.x, 2) + pow(v.y, 2));
    Vector normalized = {v.x / length, v.y / length};
    return normalized;
}

int main()
{
    int numPlanets = 3; //Number of planets in simulation

    Planet planets[numPlanets];

    //Initial positions, velocities, and masses of planets
    planets[0].position = (Vector){0, 0};
    planets[0].velocity = (Vector){0, 0};
    planets[0].mass = 1.989e30;
    planets[0].radius = 695700e3;

    planets[1].position = (Vector){1.471e11, 0};
    planets[1].velocity = (Vector){0, 30290};
    planets[1].mass = 5.974e24;
    planets[1].radius = 6371e3;

    planets[2].position = (Vector){-1.471e11, 0};
    planets[2].velocity = (Vector){0, -30290};
    planets[2].mass = 5.974e24;
    planets[2].radius = 6371e3;

    //Simulation loop
    for (double t = 0; t < 1000000; t += TIMESTEP)
    {
        //Calculate acceleration for each planet
        for (int i = 0; i < numPlanets; i++)
        {
            Vector netForce = {0, 0};

            for (int j = 0; j < numPlanets; j++)
            {
                if (i != j)
                {
                    double dist = distance(planets[i].position, planets[j].position);
                    double force = G * planets[i].mass * planets[j].mass / pow(dist, 2);
                    Vector forceVector = subtractVectors(planets[j].position, planets[i].position);
                    forceVector = normalize(forceVector);
                    forceVector.x *= force;
                    forceVector.y *= force;
                    netForce = addVectors(netForce, forceVector);
                }
            }

            planets[i].acceleration = (Vector){netForce.x / planets[i].mass, netForce.y / planets[i].mass};
        }

        //Update positions and velocities
        for (int i = 0; i < numPlanets; i++)
        {
            planets[i].velocity = addVectors(planets[i].velocity, (Vector){planets[i].acceleration.x * TIMESTEP, planets[i].acceleration.y * TIMESTEP});
            planets[i].position = addVectors(planets[i].position, (Vector){planets[i].velocity.x * TIMESTEP, planets[i].velocity.y * TIMESTEP});
        }

        //Output positions of planets every 10000 timesteps
        if ((int)t % 10000 == 0)
        {
            printf("t = %.2f:\n", t);

            for (int i = 0; i < numPlanets; i++)
            {
                printf("Planet %d: (%.2f, %.2f)\n", i + 1, planets[i].position.x, planets[i].position.y);
            }
        }
    }

    return 0;
}