//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define G 6.673e-11

struct planet {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

typedef struct planet Planet;

void apply_gravity(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * p1->mass * p2->mass / (dist*dist);
    double fx = force * dx / dist;
    double fy = force * dy / dist;
    double fz = force * dz / dist;
  
    p1->vx += fx / p1->mass;
    p1->vy += fy / p1->mass;
    p1->vz += fz / p1->mass;
  
    p2->vx -= fx / p2->mass;
    p2->vy -= fy / p2->mass;
    p2->vz -= fz / p2->mass;
}

void update_position(Planet *p, double timestep) {
    p->x += p->vx * timestep;
    p->y += p->vy * timestep;
    p->z += p->vz * timestep;
}

void print_planet(Planet *p) {
    printf("Planet at (%g, %g, %g) with velocity (%g, %g, %g)\n", p->x, p->y, p->z, p->vx, p->vy, p->vz);
}

int main() {
    Planet p1 = {5.97e24, 0, 0, 0, 0, 0, 0};
    Planet p2 = {6.39e23, 3.84e8, 0, 0, 0, 1022, 0};
    Planet p3 = {3.3e23, 0, 3.84e8, 0, -1022, 0, 0};

    double timestep = 3600;

    for (int i = 0; i < 100; i++) {
        apply_gravity(&p1, &p2);
        apply_gravity(&p1, &p3);
        apply_gravity(&p2, &p3);

        update_position(&p1, timestep);
        update_position(&p2, timestep);
        update_position(&p3, timestep);

        print_planet(&p1);
        print_planet(&p2);
        print_planet(&p3);

        printf("\n");
   }

   return 0;
}