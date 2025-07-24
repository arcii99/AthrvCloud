//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define G 6.673e-11   // gravitational constant in m^3*kg^-1*s^-2
#define AU 1.496e11   // astronomical unit in meters

typedef struct {
    double x, y;    // position in m
    double vx, vy;  // velocity in m/s
    double mass;    // mass in kg
} Body;

void update_vel(Body *bodies, int num_bodies, double time_step) {
    int i, j;
    double dx, dy, dist, F;
    for (i = 0; i < num_bodies; i++) {
        for (j = i+1; j < num_bodies; j++) {
            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dist = sqrt(dx*dx + dy*dy);
            F = G * bodies[i].mass * bodies[j].mass / (dist*dist);
            bodies[i].vx += F * dx / (bodies[i].mass * dist) * time_step;
            bodies[i].vy += F * dy / (bodies[i].mass * dist) * time_step;
            bodies[j].vx -= F * dx / (bodies[j].mass * dist) * time_step;
            bodies[j].vy -= F * dy / (bodies[j].mass * dist) * time_step;
        }
    }
}

void update_pos(Body *bodies, int num_bodies, double time_step) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        bodies[i].x += bodies[i].vx * time_step;
        bodies[i].y += bodies[i].vy * time_step;
    }
}

void simulate(Body *bodies, int num_bodies, double time_step, int num_steps) {
    int i, j;
    for (i = 0; i < num_steps; i++) {
        update_vel(bodies, num_bodies, time_step);
        update_pos(bodies, num_bodies, time_step);
        printf("%d\t", i);
        for (j = 0; j < num_bodies; j++) {
            printf("%.3e\t%.3e\t", bodies[j].x/AU, bodies[j].y/AU);
        }
        printf("\n");
    }
}

int main() {
    Body sun = {0, 0, 0, 0, 1.989e30};
    Body earth = {AU, 0, 0, 29.78e3, 5.972e24};
    Body moon = {AU + 3.844e8, 0, 0, 29.78e3+1.022e3, 7.342e22};
    Body bodies[] = {sun, earth, moon};
    int num_bodies = sizeof(bodies)/sizeof(Body);
    double time_step = 3600;
    int num_steps = 365*24;
    simulate(bodies, num_bodies, time_step, num_steps);
    return 0;
}