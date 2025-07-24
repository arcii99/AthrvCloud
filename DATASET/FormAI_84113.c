//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   // Universal gravitational constant
#define dt 3600         // Change in time per iteration (in seconds)
#define num_planets 3   // Number of planets in simulation

typedef struct {
    char name[20];
    double mass;    // Mass of planet (in kg)
    double x;       // x-coordinate of position (in m)
    double y;       // y-coordinate of position (in m)
    double vx;      // x-coordinate of velocity (in m/s)
    double vy;      // y-coordinate of velocity (in m/s)
} planet;

void update_position(planet *p) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void update_velocity(planet *p, double fx, double fy) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
}

void calculate_force(planet p[], double force[][2]) {
    int i, j;
    double dx, dy, distance, f;

    for (i = 0; i < num_planets; i++) {
        force[i][0] = force[i][1] = 0.0;
        for (j = 0; j < num_planets; j++) {
            if (i == j) continue;
            dx = p[j].x - p[i].x;
            dy = p[j].y - p[i].y;
            distance = sqrt(dx*dx + dy*dy);
            f = G * p[i].mass * p[j].mass / (distance * distance);
            force[i][0] += f * dx / distance;
            force[i][1] += f * dy / distance;
        }
    }
}

int main() {
    planet p[num_planets];  // Array of planets
    double force[num_planets][2];  // Array of forces acting on each planet
    int i, j;

    // Initialize planets
    strcpy(p[0].name, "Sun");
    p[0].mass = 1.989e30;
    p[0].x = p[0].y = p[0].vx = p[0].vy = 0.0;
    strcpy(p[1].name, "Earth");
    p[1].mass = 5.97e24;
    p[1].x = 1.496e11;
    p[1].y = 0.0;
    p[1].vx = 0.0;
    p[1].vy = 29783.0;
    strcpy(p[2].name, "Mars");
    p[2].mass = 6.39e23;
    p[2].x = 2.279e11;
    p[2].y = 0.0;
    p[2].vx = 0.0;
    p[2].vy = 24130.0;

    // Run simulation
    for (i = 0; i < 365*24; i++) {   // 1 year of simulation
        calculate_force(p, force);
        for (j = 0; j < num_planets; j++) {
            update_velocity(&p[j], force[j][0], force[j][1]);
            update_position(&p[j]);
            printf("%s: x = %.2f m, y = %.2f m\n", p[j].name, p[j].x, p[j].y);
        }
    }

    return 0;
}