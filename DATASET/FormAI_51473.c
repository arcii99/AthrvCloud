//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define G 6.67408E-11    // gravitational constant

typedef struct {
    double x, y, z;     // position
    double vx, vy, vz;  // velocity
    double mass;        // mass
} body;

void update_velocity(body *b1, body *b2, double delta_time) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dz = b2->z - b1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * b1->mass * b2->mass / (distance*distance);
    double fx = f * dx / distance;
    double fy = f * dy / distance;
    double fz = f * dz / distance;
    b1->vx += fx / b1->mass * delta_time;
    b1->vy += fy / b1->mass * delta_time;
    b1->vz += fz / b1->mass * delta_time;
    b2->vx -= fx / b2->mass * delta_time;
    b2->vy -= fy / b2->mass * delta_time;
    b2->vz -= fz / b2->mass * delta_time;
}

void update_position(body *b, double delta_time) {
    b->x += b->vx * delta_time;
    b->y += b->vy * delta_time;
    b->z += b->vz * delta_time;
}

int main() {
    // define bodies
    body sun = {0, 0, 0, 0, 0, 0, 1.989E30};
    body earth = {1.496E11, 0, 0, 0, 29780, 0, 5.972E24};
    body moon = {1.496E11 + 384400E3, 0, 0, 0, 29780 + 1022, 0, 7.342E22};
    
    // simulation parameters
    double delta_time = 86400;  // 1 day
    int steps = 365;            // simulate for 1 year
    
    // simulation loop
    for (int i = 0; i < steps; i++) {
        update_velocity(&earth, &sun, delta_time);
        update_velocity(&moon, &earth, delta_time);
        update_velocity(&moon, &sun, delta_time);
        
        update_position(&earth, delta_time);
        update_position(&moon, delta_time);
        
        printf("Day %d: Earth position: x=%f y=%f z=%f\n", i+1, earth.x, earth.y, earth.z);
        printf("Day %d: Moon position: x=%f y=%f z=%f\n", i+1, moon.x, moon.y, moon.z);
    }
    
    return 0;
}