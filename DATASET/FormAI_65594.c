//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include<stdio.h>
#include<math.h>

// constants for simulation
#define G 6.674e-11   // gravitational constant
#define dt 0.01       // time step for simulation

// planet struct
typedef struct planet
{
    double x, y;     // position
    double vx, vy;   // velocity
    double mass;     // mass
} Planet;

// function to calculate gravitational force
void calcForce(Planet *a, Planet *b, double *fx, double *fy)
{
    double dist, force;

    // calculate distance between planets
    dist = sqrt(pow((a->x)-(b->x),2) + pow((a->y)-(b->y),2));

    // calculate force between planets
    force = (G * a->mass * b->mass) / pow(dist,2);

    // calculate force components
    *fx = force * ((b->x)-(a->x)) / dist;
    *fy = force * ((b->y)-(a->y)) / dist;
}

// function to update position and velocity
void update(Planet *p, double fx, double fy)
{
    // update velocity
    p->vx += fx / p->mass * dt;
    p->vy += fy / p->mass * dt;

    // update position
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

// main function
int main()
{
    // create array of planets
    int num_planets = 3;
    Planet planets[num_planets];

    // set initial conditions for planets
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].mass = 1.0;
    
    planets[1].x = 1.0;
    planets[1].y = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = sqrt(G*planets[0].mass / (planets[1].x - planets[0].x));
    planets[1].mass = 1.0;

    planets[2].x = 0.0;
    planets[2].y = 1.0;
    planets[2].vx = sqrt(G*planets[0].mass / (planets[2].y - planets[0].y));
    planets[2].vy = 0.0;
    planets[2].mass = 1.0;

    // simulation loop
    double fx, fy;
    for(int i=0; i<100; i++)
    {
        // reset force
        fx = 0.0;
        fy = 0.0;

        // calculate force between each planet
        for(int j=0; j<num_planets; j++)
        {
            for(int k=0; k<j; k++)
            {
                double fx_temp, fy_temp;
                calcForce(&planets[j], &planets[k], &fx_temp, &fy_temp);
                fx += fx_temp;
                fy += fy_temp;
            }
        }

        // update each planet
        for(int j=0; j<num_planets; j++)
        {
            update(&planets[j], fx, fy);
        }

        // print out planet positions
        printf("Planet 1: (%lf, %lf)\n", planets[0].x, planets[0].y);
        printf("Planet 2: (%lf, %lf)\n", planets[1].x, planets[1].y);
        printf("Planet 3: (%lf, %lf)\n", planets[2].x, planets[2].y);
        printf("\n");
    }

    return 0;
}