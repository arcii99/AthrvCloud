//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define G 6.67408E-11

typedef struct
{
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
} Body;

Body bodies[MAX];
int N;

void calculate_forces()
{
    double dx, dy, dz, dist, f;

    for(int i=0; i<N; i++)
    {
        bodies[i].ax = 0.0;
        bodies[i].ay = 0.0;
        bodies[i].az = 0.0;
    
        for(int j=0; j<N; j++)
        {
            if(i == j) continue;

            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dz = bodies[j].z - bodies[i].z;

            dist = sqrt(dx*dx + dy*dy + dz*dz);
            f = (G * bodies[i].mass * bodies[j].mass) / (dist*dist);

            bodies[i].ax += f * dx / dist;
            bodies[i].ay += f * dy / dist;
            bodies[i].az += f * dz / dist;
        }
    }
}

void update_velocity(double timestep)
{
    for(int i=0; i<N; i++)
    {
        bodies[i].vx += bodies[i].ax * timestep;
        bodies[i].vy += bodies[i].ay * timestep;
        bodies[i].vz += bodies[i].az * timestep;
    }
}

void update_position(double timestep)
{
    for(int i=0; i<N; i++)
    {
        bodies[i].x += bodies[i].vx * timestep;
        bodies[i].y += bodies[i].vy * timestep;
        bodies[i].z += bodies[i].vz * timestep;
    }
}

int main()
{
    printf("Welcome to the Planet Gravity Simulation program, my dear Watson!\n");
    printf("I have set up an experiment with %d random planets for you to observe.\n", MAX);

    srand(time(NULL));
    for(int i=0; i<MAX; i++)
    {
        bodies[i].mass = rand() % 500 + 100;
        bodies[i].x = rand() % 500 + 100;
        bodies[i].y = rand() % 500 + 100;
        bodies[i].z = rand() % 500 + 100;
        bodies[i].vx = rand() % 50 - 25;
        bodies[i].vy = rand() % 50 - 25;
        bodies[i].vz = rand() % 50 - 25;
    }
    N = MAX;

    printf("\nThe experiment is starting now! Let us observe the planets over time.\n\n");

    int num_iterations = 10;
    double timestep = 0.001;

    for(int i=1; i<=num_iterations; i++)
    {
        calculate_forces();
        update_velocity(timestep);
        update_position(timestep);
        printf("Iteration %d:\n", i);
        for(int j=0; j<N; j++)
        {
            printf("Planet %d: Position(%.2f, %.2f, %.2f) Velocity(%.2f, %.2f, %.2f)\n",
                j+1, bodies[j].x, bodies[j].y, bodies[j].z, bodies[j].vx, bodies[j].vy, bodies[j].vz);
        }
        printf("\n");
    }

    printf("That concludes our experiment, my dear Watson! I hope you found it illuminating.\n");

    return 0;
}