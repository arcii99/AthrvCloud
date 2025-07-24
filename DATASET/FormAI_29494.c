//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONSTANT 6.674 * pow(10, -11) // Gravitational constant
#define MASS_EARTH 5.97 * pow(10, 24)      // Earth's mass in kg
#define RADIUS_EARTH 6371000               // Earth's radius in meters

typedef struct {
    double x, y; // Position coordinates
    double mass; // Mass of the object in kg
    double fx, fy; // Forces acting on the object
    double vx, vy; // Velocity components of the object
} Object;

Object earth, moon;

double distance(Object obj1, Object obj2) {
    double dx = obj2.x - obj1.x;
    double dy = obj2.y - obj1.y;
    return sqrt(dx * dx + dy * dy);
}

double force(double distance, double mass1, double mass2) {
    return GRAV_CONSTANT * ((mass1 * mass2) / (distance * distance));
}

void reset_forces(Object *obj) {
    (*obj).fx = (*obj).fy = 0;
}

void apply_forces(Object *obj1, Object *obj2) {
    double dist = distance(*obj1, *obj2);
    double f = force(dist, (*obj1).mass, (*obj2).mass);
    double fx = f * ((*obj2).x - (*obj1).x) / dist;
    double fy = f * ((*obj2).y - (*obj1).y) / dist;
    (*obj1).fx += fx;
    (*obj1).fy += fy;
}

void update_velocity(Object *obj, double time) {
    (*obj).vx += (*obj).fx / (*obj).mass * time;
    (*obj).vy += (*obj).fy / (*obj).mass * time;
}

void update_position(Object *obj, double time) {
    (*obj).x += (*obj).vx * time;
    (*obj).y += (*obj).vy * time;
}

int main() {
    /* Initialize Earth */
    earth.x = 0;
    earth.y = 0;
    earth.mass = MASS_EARTH;

    /* Initialize Moon */
    moon.x = 384400000;
    moon.y = 0;
    moon.mass = 7.34 * pow(10, 22);

    /* Initialize simulation parameters */
    double time = 0;
    double timestep = 60;
    double sim_time = 2592000; // One month
    int steps = sim_time / timestep;

    /* Execute simulation */
    for (int i = 0; i < steps; i++) {
        reset_forces(&earth);
        reset_forces(&moon);
        apply_forces(&earth, &moon);
        apply_forces(&moon, &earth);
        update_velocity(&earth, timestep);
        update_velocity(&moon, timestep);
        update_position(&earth, timestep);
        update_position(&moon, timestep);
        time += timestep;

        /* Print out position and velocity of Moon */
        printf("Time: %.0f s\n", time);
        printf("Moon Position: (%.0f, %.0f) m\n", moon.x, moon.y);
        printf("Moon Velocity: (%.0f, %.0f) m/s\n\n", moon.vx, moon.vy);
    }

    return 0;
}