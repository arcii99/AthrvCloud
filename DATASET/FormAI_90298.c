//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include <stdio.h>
#include <math.h>

#define G 6.6743E-11 // Gravitational constant
#define TIME_STEP 86400 // One day in seconds
#define N_PLANETS 3 // Number of planets

typedef struct {
    char name[20];
    double mass; // kg
    double radius; // m
    double x; // m
    double y; // m
    double z; // m
    double vx; // m/s
    double vy; // m/s
    double vz; // m/s
} Planet;

void calculate_gravity(Planet *a, Planet *b, double *ax, double *ay, double *az) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G*a->mass*b->mass / (r*r);
    *ax = f*dx/r / a->mass;
    *ay = f*dy/r / a->mass;
    *az = f*dz/r / a->mass;
}

void update_velocity(Planet *p, double ax, double ay, double az, double time_step) {
    p->vx += ax*time_step;
    p->vy += ay*time_step;
    p->vz += az*time_step;
}

void update_position(Planet *p, double time_step) {
    p->x += p->vx*time_step;
    p->y += p->vy*time_step;
    p->z += p->vz*time_step;
}

int main() {
    Planet planets[N_PLANETS] = {
        {"Earth", 5.97E24, 6.37E6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Venus", 4.87E24, 6.05E6, 1.08E11, 0.0, 0.0, 0.0, 35000.0, 0.0},
        {"Mars", 6.39E23, 3.39E6, 0.0, 2.28E11, 0.0, -24000.0, 0.0, 0.0}
    };

    double ax, ay, az;
    for (int i = 0; i < N_PLANETS; i++) {
        for (int j = i+1; j < N_PLANETS; j++) {
            calculate_gravity(&planets[i], &planets[j], &ax, &ay, &az);
            update_velocity(&planets[i], ax, ay, az, TIME_STEP);
            update_velocity(&planets[j], -ax, -ay, -az, TIME_STEP);
        }
    }

    for (int i = 0; i < N_PLANETS; i++) {
        update_position(&planets[i], TIME_STEP);
        printf("%s: x=%.2f km, y=%.2f km, z=%.2f km\n", planets[i].name, planets[i].x/1000, planets[i].y/1000, planets[i].z/1000);
    }

    return 0;
}