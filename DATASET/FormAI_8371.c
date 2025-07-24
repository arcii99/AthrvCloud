//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITATIONAL_CONSTANT 6.67408e-11

typedef struct {
    double x, y;
} Vector;

typedef struct {
    Vector position, velocity, force;
    double mass;
} Body;

double calculateDistance(Vector a, Vector b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Vector calculateDirection(Vector a, Vector b)
{
    double distance = calculateDistance(a, b);
    Vector direction = {(b.x - a.x) / distance, (b.y - a.y) / distance};
    return direction;
}

Vector calculateGravitationalForce(Body a, Body b)
{
    Vector direction = calculateDirection(a.position, b.position);
    double distance = calculateDistance(a.position, b.position);
    double magnitude = (GRAVITATIONAL_CONSTANT * a.mass * b.mass) / pow(distance, 2);
    Vector force = {direction.x * magnitude, direction.y * magnitude};
    return force;
}

int main()
{
    srand(time(0));
    const int numBodies = 5;
    Body bodies[numBodies];

    for (int i = 0; i < numBodies; i++)
    {
        bodies[i].position.x = (double)rand() / RAND_MAX * 100;
        bodies[i].position.y = (double)rand() / RAND_MAX * 100;
        bodies[i].velocity.x = (double)rand() / RAND_MAX * 10;
        bodies[i].velocity.y = (double)rand() / RAND_MAX * 10;
        bodies[i].mass = (double)rand() / RAND_MAX * 0.0000001;
        bodies[i].force.x = 0;
        bodies[i].force.y = 0;
    }

    double timestep = 0.1;
    int numTimesteps = 1000;

    for (int t = 0; t < numTimesteps; t++)
    {
        for (int i = 0; i < numBodies; i++)
        {
            for (int j = 0; j < numBodies; j++)
            {
                if (i != j)
                {
                    Vector force = calculateGravitationalForce(bodies[i], bodies[j]);
                    bodies[i].force.x += force.x;
                    bodies[i].force.y += force.y;
                }
            }
        }

        for (int i = 0; i < numBodies; i++)
        {
            bodies[i].position.x += bodies[i].velocity.x * timestep;
            bodies[i].position.y += bodies[i].velocity.y * timestep;

            bodies[i].velocity.x += (bodies[i].force.x / bodies[i].mass) * timestep;
            bodies[i].velocity.y += (bodies[i].force.y / bodies[i].mass) * timestep;

            bodies[i].force.x = 0;
            bodies[i].force.y = 0;
        }

        // Output positions for plotting
        for (int i = 0; i < numBodies; i++)
        {
            printf("%lf %lf ", bodies[i].position.x, bodies[i].position.y);
        }
        printf("\n");
    }

    return 0;
}