//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define PARTICLES 100
#define BOX_SIZE 10
#define TIME 1000
#define DELTA_T 0.01
#define MASS 1

typedef struct _particle
{
    double x; // x position
    double y; // y position
    double vx; // x velocity
    double vy; // y velocity
} Particle;

double randDouble(double a, double b)
{
    return (b - a) * ((double)rand() / (double)RAND_MAX) + a;
}

double distance(Particle p1, Particle p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void update(Particle *p, double fx, double fy)
{
    double ax = fx / MASS;
    double ay = fy / MASS;

    p->vx += ax * DELTA_T;
    p->vy += ay * DELTA_T;
    p->x += p->vx * DELTA_T;
    p->y += p->vy * DELTA_T;
}

int main()
{
    Particle particles[PARTICLES];
    int i, j, t;
    double fx, fy, r;

    srand((unsigned int) time(NULL));

    for (i = 0; i < PARTICLES; i++)
    {
        particles[i].x = randDouble(0, BOX_SIZE);
        particles[i].y = randDouble(0, BOX_SIZE);
        particles[i].vx = randDouble(-1, 1);
        particles[i].vy = randDouble(-1, 1);
    }

    for (t = 0; t < TIME; t++)
    {
        for (i = 0; i < PARTICLES; i++)
        {
            fx = fy = 0.0;

            // calculate the force on each particle
            for (j = 0; j < PARTICLES; j++)
            {
                if (i == j)
                {
                    continue;
                }

                r = distance(particles[i], particles[j]);
                fx += (particles[i].x - particles[j].x) / (r * r * r);
                fy += (particles[i].y - particles[j].y) / (r * r * r);
            }

            // update the particle's position and velocity
            update(&particles[i], fx, fy);
        }

        // print out the current state of the system
        printf("t = %d\n", t);
        for (i = 0; i < PARTICLES; i++)
        {
            printf("%lf %lf\n", particles[i].x, particles[i].y);
        }
    }

    return 0;
}