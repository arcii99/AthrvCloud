//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: invasive
#include<stdio.h>
#include<math.h>
#define G 6.6743e-11

// Defining a structure to hold planet details
struct planet
{
    char name[20];
    double mass, x, y, z, dx, dy, dz, fx, fy, fz;
};

// Function to calculate the force between two planets
void calculate_force(struct planet *p1, struct planet *p2)
{
    double distance, force;
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;

    distance = sqrt(dx*dx + dy*dy + dz*dz);

    force = G * p1->mass * p2->mass / (distance * distance);

    p1->fx += force * dx / distance;
    p1->fy += force * dy / distance;
    p1->fz += force * dz / distance;

    p2->fx -= force * dx / distance;
    p2->fy -= force * dy / distance;
    p2->fz -= force * dz / distance;
}

// Function to update the position and velocity of a planet
void update(struct planet *p, double time_step)
{
    p->dx += p->fx / p->mass * time_step;
    p->dy += p->fy / p->mass * time_step;
    p->dz += p->fz / p->mass * time_step;

    p->x += p->dx * time_step;
    p->y += p->dy * time_step;
    p->z += p->dz * time_step;

    p->fx = 0.0;
    p->fy = 0.0;
    p->fz = 0.0;
}

int main()
{
    struct planet planets[3] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 29780, 0, 0, 0, 0},
        {"Mars", 6.39e23, 2.279e11, 0, 0, 0, 24130, 0, 0, 0, 0},
        {"Venus", 4.87e24, 0, 1.08e11, 0, -34800, 0, 0, 0, 0, 0},
    };

    int i, j, k;
    double time_step = 100.0;
    int num_steps = 10000;

    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < 3; j++) {
            for (k = j+1; k < 3; k++) {
                calculate_force(&planets[j], &planets[k]);
            }
            update(&planets[j], time_step);
            printf("%s: (%lf,%lf,%lf)\n", planets[j].name, 
                                        planets[j].x, planets[j].y, planets[j].z);
        }
    }

    return 0;
}