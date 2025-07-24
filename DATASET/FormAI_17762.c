//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant
#define DT 0.01      // time step

typedef struct {
    double x, y;    // position
    double vx, vy;  // velocity
    double ax, ay;  // acceleration
    double mass;    // mass
} Body;

Body bodies[] = {
    // add your unique body configurations here
};

void compute_acceleration(Body *b, int num_bodies) {
    // base case: no other bodies, no acceleration
    if (num_bodies <= 1) {
        b->ax = 0;
        b->ay = 0;
        return;
    }
    
    // sum up the forces on the body from all other bodies
    double fx = 0, fy = 0;
    for (int i = 0; i < num_bodies; i++) {
        if (bodies + i == b) continue;  // skip self
        double dx = bodies[i].x - b->x;
        double dy = bodies[i].y - b->y;
        double dist = sqrt(dx*dx + dy*dy);
        double force = G * b->mass * bodies[i].mass / (dist*dist);
        fx += force * dx / dist;
        fy += force * dy / dist;
    }
    
    // update the body's acceleration
    b->ax = fx / b->mass;
    b->ay = fy / b->mass;
}

void update_velocity(Body *b) {
    b->vx += b->ax * DT;
    b->vy += b->ay * DT;
}

void update_position(Body *b) {
    b->x += b->vx * DT;
    b->y += b->vy * DT;
}

void simulate_gravity(Body *bodies, int num_bodies, int num_steps) {
    // base case: no more steps
    if (num_steps <= 0) return;
    
    // calculate acceleration for each body
    for (int i = 0; i < num_bodies; i++) {
        compute_acceleration(bodies + i, num_bodies);
    }
    
    // update velocity and position for each body
    for (int i = 0; i < num_bodies; i++) {
        update_velocity(bodies + i);
        update_position(bodies + i);
    }
    
    // simulate next step recursively
    simulate_gravity(bodies, num_bodies, num_steps - 1);
}

int main() {
    int num_bodies = sizeof(bodies) / sizeof(Body);
    int num_steps = 1000;  // simulate for 1000 steps
    
    simulate_gravity(bodies, num_bodies, num_steps);
    
    // print final positions of each body
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: x = %lf, y = %lf\n", i+1, bodies[i].x, bodies[i].y);
    }
    
    return 0;
}