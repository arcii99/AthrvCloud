//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500 // number of planets
#define G 0.0001 // gravitational constant
#define MAX_STEP 150 // maximum time step
#define DT 0.01 // time step size

typedef struct 
{
    double mass; // mass of the planet
    double pos[2]; // position vector of the planet
    double vel[2]; // velocity vector of the planet
    double acc[2]; // acceleration vector of the planet
} Planet;

void calculate_force(double r[], double f[], double m1, double m2)
{
    double dist = sqrt(r[0]*r[0] + r[1]*r[1]); // distance between two planets
    double unit_vector[2] = {r[0]/dist, r[1]/dist}; // unit vector in the direction of r
    double force_mag = G * m1 * m2 / (dist*dist); // magnitude of the gravitational force
    f[0] = force_mag * unit_vector[0]; // x component of the force
    f[1] = force_mag * unit_vector[1]; // y component of the force
}

void update_planet(Planet *p, double dt)
{
    p->pos[0] += p->vel[0] * dt + 0.5 * p->acc[0] * dt * dt; // update position using Verlet integration
    p->pos[1] += p->vel[1] * dt + 0.5 * p->acc[1] * dt * dt;
    p->vel[0] += 0.5 * p->acc[0] * dt; // update velocity using Verlet integration
    p->vel[1] += 0.5 * p->acc[1] * dt;
}

void run_simulation(Planet planets[])
{
    int i, j, step;
    double r[2], f[2], m1, m2;

    for(step = 0; step < MAX_STEP; step++)
    {
        for(i = 0; i < N; i++)
        {
            planets[i].acc[0] = 0.0; // set initial acceleration to zero
            planets[i].acc[1] = 0.0;

            for(j = 0; j < N; j++)
            {
                if(i == j)
                    continue; // skip if same planet

                // calculate distance between two planets
                r[0] = planets[j].pos[0] - planets[i].pos[0];
                r[1] = planets[j].pos[1] - planets[i].pos[1];

                // calculate gravitational force
                m1 = planets[i].mass;
                m2 = planets[j].mass;
                calculate_force(r, f, m1, m2);

                // update acceleration of planet i
                planets[i].acc[0] += f[0] / m1;
                planets[i].acc[1] += f[1] / m1;
            }
        }

        // update position and velocity of each planet
        for(i = 0; i < N; i++)
        {
            update_planet(&planets[i], DT);
            printf("Planet %d: pos=(%.2f, %.2f) vel=(%.2f, %.2f)\n", i+1, planets[i].pos[0], planets[i].pos[1], planets[i].vel[0], planets[i].vel[1]);
        }
        printf("\n");
    }
}

int main()
{
    int i;
    Planet planets[N];

    // initialize planet positions, velocities, and masses
    for(i = 0; i < N; i++)
    {
        planets[i].mass = ((double) rand()) / RAND_MAX * 10.0; // random mass between 0 and 10
        planets[i].pos[0] = ((double) rand()) / RAND_MAX * 500.0 - 250.0; // random x position between -250 and 250
        planets[i].pos[1] = ((double) rand()) / RAND_MAX * 500.0 - 250.0; // random y position between -250 and 250
        planets[i].vel[0] = ((double) rand()) / RAND_MAX * 10.0 - 5.0; // random x velocity between -5 and 5
        planets[i].vel[1] = ((double) rand()) / RAND_MAX * 10.0 - 5.0; // random y velocity between -5 and 5
        planets[i].acc[0] = 0.0;
        planets[i].acc[1] = 0.0;
    }

    run_simulation(planets);

    return 0;
}