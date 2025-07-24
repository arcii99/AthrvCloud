//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <math.h>

#define MAX_BODIES 10

struct vector {
    double x, y, z;
};

struct body {
    double mass;
    struct vector position, velocity, acceleration;
};

void update_acceleration(struct body *bodies, int num_bodies) {
    int i, j;
    double distance, magnitude, delta_x, delta_y, delta_z;
    struct vector force;
    
    for (i = 0; i < num_bodies; i++) {
        for (j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }
            
            delta_x = bodies[j].position.x - bodies[i].position.x;
            delta_y = bodies[j].position.y - bodies[i].position.y;
            delta_z = bodies[j].position.z - bodies[i].position.z;
            distance = sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);
            magnitude = bodies[j].mass / (distance * distance);
            force.x = magnitude * delta_x;
            force.y = magnitude * delta_y;
            force.z = magnitude * delta_z;
            bodies[i].acceleration.x += force.x / bodies[i].mass;
            bodies[i].acceleration.y += force.y / bodies[i].mass;
            bodies[i].acceleration.z += force.z / bodies[i].mass;
        }
    }
}

void update_velocity(struct body *bodies, int num_bodies, double time_delta) {
    int i;
    
    for (i = 0; i < num_bodies; i++) {
        bodies[i].velocity.x += bodies[i].acceleration.x * time_delta;
        bodies[i].velocity.y += bodies[i].acceleration.y * time_delta;
        bodies[i].velocity.z += bodies[i].acceleration.z * time_delta;
    }
}

void update_position(struct body *bodies, int num_bodies, double time_delta) {
    int i;
    
    for (i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * time_delta;
        bodies[i].position.y += bodies[i].velocity.y * time_delta;
        bodies[i].position.z += bodies[i].velocity.z * time_delta;
    }
}

int main() {
    struct body bodies[MAX_BODIES] = {
        { 1.0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } },
        { 0.5, { 10.0, 10.0, 10.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } }
    };
    int num_bodies = 2;
    double time = 0.0;
    double time_delta = 0.01;
    int num_steps = 100000;
    int i, j;
    
    for (i = 0; i < num_steps; i++) {
        update_acceleration(bodies, num_bodies);
        update_velocity(bodies, num_bodies, time_delta);
        update_position(bodies, num_bodies, time_delta);
        time += time_delta;
    }
    
    for (i = 0; i < num_bodies; i++) {
        printf("Body %d position: (%f, %f, %f)\n", i, bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
    }
    
    return 0;
}