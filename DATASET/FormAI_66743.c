//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    double mass;
    Vector3D position;
    Vector3D velocity;
} Body;

void update_velocity(Body *bodies, int num_bodies, double dt) {
    int i, j;
    double force_mag, distance, fx, fy, fz;
    
    for (i = 0; i < num_bodies; i++) {
        fx = fy = fz = 0.0;
        for (j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            distance = sqrt(pow(bodies[i].position.x - bodies[j].position.x, 2)
                            + pow(bodies[i].position.y - bodies[j].position.y, 2)
                            + pow(bodies[i].position.z - bodies[j].position.z, 2));
            force_mag = G * bodies[i].mass * bodies[j].mass / pow(distance, 2);
            fx += force_mag * (bodies[j].position.x - bodies[i].position.x) / distance;
            fy += force_mag * (bodies[j].position.y - bodies[i].position.y) / distance;
            fz += force_mag * (bodies[j].position.z - bodies[i].position.z) / distance;
        }
        bodies[i].velocity.x += fx * dt / bodies[i].mass;
        bodies[i].velocity.y += fy * dt / bodies[i].mass;
        bodies[i].velocity.z += fz * dt / bodies[i].mass;
    }
}

void update_position(Body *bodies, int num_bodies, double dt) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position.z += bodies[i].velocity.z * dt;
    }
}

int main() {
    Body earth = {5.97e24, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    Body moon = {7.34e22, {384400000.0, 0.0, 0.0}, {0.0, 1022.0, 0.0}};
    int i;
    double time = 0.0;
    double time_step = 86400.0; // 1 day in seconds
    
    for (i = 0; i < 365; i++) {
        printf("Time: %lf\n", time);
        printf("Earth Position: (%lf, %lf, %lf)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon Position: (%lf, %lf, %lf)\n", moon.position.x, moon.position.y, moon.position.z);
        update_velocity(&earth, 2, time_step);
        update_position(&earth, 2, time_step);
        time += time_step;
    }
    
    return 0;
}