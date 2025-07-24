//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define G 6.67e-11
#define DAY 86400
#define YEAR 31536000

struct Vector {
    double x;
    double y;
};

struct Body {
    struct Vector pos;
    struct Vector vel;
    double mass;
};

void calculate_gravity(struct Body *bodies, int size, double dt)
{
    double fx, fy, f, distance;
    struct Vector direction;

    for (int i = 0; i < size; i++)
    {
        fx = 0;
        fy = 0;

        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                distance = sqrt(pow(bodies[i].pos.x - bodies[j].pos.x, 2) + pow(bodies[i].pos.y - bodies[j].pos.y, 2));
                direction.x = (bodies[j].pos.x - bodies[i].pos.x) / distance;
                direction.y = (bodies[j].pos.y - bodies[i].pos.y) / distance;
                f = G * bodies[i].mass * bodies[j].mass / pow(distance, 2);
                fx += f * direction.x;
                fy += f * direction.y;
            }
        }

        bodies[i].vel.x += fx / bodies[i].mass * dt;
        bodies[i].vel.y += fy / bodies[i].mass * dt;
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

void run_simulation(struct Body *bodies, int size, double duration, double dt)
{
    int steps = duration / dt;

    for (int i = 0; i < steps; i++)
    {
        calculate_gravity(bodies, size, dt);

        printf("Step %d:\n", i + 1);

        for (int j = 0; j < size; j++)
        {
            printf("Body %d: (%f, %f)\n", j+1, bodies[j].pos.x, bodies[j].pos.y);
        }
    }
}

int main()
{
    struct Body sun = {{0, 0}, {0, 0}, 1.9891e30};
    struct Body earth = {{-147095000000, 0}, {0, 30300}, 5.97219e24};
    struct Body moon = {{-147095000000 - 384400000, 0}, {0, 30300 + 1022}, 7.342e22};

    struct Body bodies[] = {sun, earth, moon};
    int size = sizeof(bodies) / sizeof(struct Body);

    double duration = YEAR * 10;
    double dt = DAY;

    run_simulation(bodies, size, duration, dt);

    return 0;
}