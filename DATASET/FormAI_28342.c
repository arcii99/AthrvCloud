//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11  // gravitational constant

struct celestial_body {
    double mass;  // in kilograms
    double position[3];  // x, y, and z coordinates in meters
    double velocity[3];  // velocity components in meters per second
};

void update_body(struct celestial_body* b, double force[3], double time_step) {
    double acceleration[3];
    for (int i = 0; i < 3; i++) {
        acceleration[i] = force[i] / b->mass;
        b->velocity[i] += acceleration[i] * time_step;
        b->position[i] += b->velocity[i] * time_step;
    }
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void gravitational_force(struct celestial_body* b1, struct celestial_body* b2, double force[3]) {
    double r = distance(b1->position[0], b1->position[1], b1->position[2], 
                        b2->position[0], b2->position[1], b2->position[2]);
    double f = (G * b1->mass * b2->mass) / (r * r);
    for (int i = 0; i < 3; i++) {
        force[i] = f * (b2->position[i] - b1->position[i]) / r;
    }
}

int main() {
    struct celestial_body sun = {1.989e30, {0, 0, 0}, {0, 0, 0}};
    struct celestial_body earth = {5.9736e24, {1.496e11, 0, 0}, {0, 29783, 0}};
    double time_step = 3600;  // seconds
    
    for (int i = 0; i < 8760; i++) {  // simulate one year of orbit
        double force[3];
        gravitational_force(&sun, &earth, force);
        update_body(&earth, force, time_step);
        printf("Earth position: (%e, %e, %e)\n", earth.position[0], earth.position[1], earth.position[2]);
    }
    
    return 0;
}