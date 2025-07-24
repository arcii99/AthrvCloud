//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11  //Gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    double mass;
} Body;

void update_velocity(Body *bodies, int n, double time_step) {
    for (int i = 0; i < n; i++) {
        Vector acceleration = {0, 0, 0};
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Vector direction;
                direction.x = bodies[j].position.x - bodies[i].position.x;
                direction.y = bodies[j].position.y - bodies[i].position.y;
                direction.z = bodies[j].position.z - bodies[i].position.z;
                double distance = sqrt(direction.x*direction.x + direction.y*direction.y + direction.z*direction.z);
                double force = GRAV_CONST * bodies[i].mass * bodies[j].mass / (distance*distance);
                acceleration.x += force * direction.x / (bodies[i].mass);
                acceleration.y += force * direction.y / (bodies[i].mass);
                acceleration.z += force * direction.z / (bodies[i].mass);
            }
        }
        bodies[i].velocity.x += acceleration.x * time_step;
        bodies[i].velocity.y += acceleration.y * time_step;
        bodies[i].velocity.z += acceleration.z * time_step;
    }
}

void update_position(Body *bodies, int n, double time_step) {
    for (int i = 0; i < n; i++) {
        bodies[i].position.x += bodies[i].velocity.x * time_step;
        bodies[i].position.y += bodies[i].velocity.y * time_step;
        bodies[i].position.z += bodies[i].velocity.z * time_step;
    }
}

void simulate(Body *bodies, int n, double time_step, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        update_velocity(bodies, n, time_step);
        update_position(bodies, n, time_step);
        printf("STEP %d:\n", i+1);
        for (int j = 0; j < n; j++) {
            printf("Body %d: \nPosition: (%f, %f, %f)\nVelocity: (%f, %f, %f)\nMass: %f\n",
                   j+1,
                   bodies[j].position.x, bodies[j].position.y, bodies[j].position.z,
                   bodies[j].velocity.x, bodies[j].velocity.y, bodies[j].velocity.z,
                   bodies[j].mass);
        }
        printf("-------------------------------------------\n");
    }
}

int main() {
    Body bodies[3];
    bodies[0].position.x = 0;
    bodies[0].position.y = 0;
    bodies[0].position.z = 0;
    bodies[0].velocity.x = 0;
    bodies[0].velocity.y = 0;
    bodies[0].velocity.z = 0;
    bodies[0].mass = 5.972e24;

    bodies[1].position.x = 0;
    bodies[1].position.y = 6371e3;
    bodies[1].position.z = 0;
    bodies[1].velocity.x = 7.9e3;
    bodies[1].velocity.y = 0;
    bodies[1].velocity.z = 0;
    bodies[1].mass = 1000;

    bodies[2].position.x = 0;
    bodies[2].position.y = -6371e3;
    bodies[2].position.z = 0;
    bodies[2].velocity.x = -7.9e3;
    bodies[2].velocity.y = 0;
    bodies[2].velocity.z = 0;
    bodies[2].mass = 1000;

    double time_step = 1;
    int num_steps = 100;

    simulate(bodies, 3, time_step, num_steps);
    return 0;
}