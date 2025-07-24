//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant, m^3/(kg*s^2)

struct vector {
    double x;
    double y;
};

struct planet {
    double mass;
    struct vector pos;
    struct vector vel;
};

void update_position(struct planet *p, double dt) {
    // Update position using velocity and time step dt
    p->pos.x += dt * p->vel.x;
    p->pos.y += dt * p->vel.y;
}

void update_velocity(struct planet *p, double dt, struct vector force) {
    // Update velocity using force and time step dt
    p->vel.x += dt * force.x / p->mass;
    p->vel.y += dt * force.y / p->mass;
}

struct vector force_between(struct planet p1, struct planet p2) {
    // Calculate the force between two planets using the gravitational force formula
    double r = sqrt(pow(p2.pos.x - p1.pos.x, 2) + pow(p2.pos.y - p1.pos.y, 2)); // distance between planets
    double f = G * p1.mass * p2.mass / pow(r, 2); // gravitational force
    struct vector direction = {
        (p2.pos.x - p1.pos.x) / r,
        (p2.pos.y - p1.pos.y) / r
    };
    struct vector force = {
        f * direction.x,
        f * direction.y
    };
    return force;
}

void simulate(struct planet planets[], int num_planets, double dt, double duration) {
    int i, j;
    for(double t = 0; t < duration; t += dt) {
        // Calculate net force on each planet
        for(i = 0; i < num_planets; i++) {
            struct vector net_force = {0, 0};
            for(j = 0; j < num_planets; j++) {
                if(i != j) { // Avoid self-interaction
                    struct vector force = force_between(planets[i], planets[j]);
                    net_force.x += force.x;
                    net_force.y += force.y;
                }
            }
            // Update velocity and position
            update_velocity(&planets[i], dt, net_force);
        }
        for(i = 0; i < num_planets; i++) {
            update_position(&planets[i], dt);
        }
    }
}

int main() {
    // Define planets
    struct planet earth = {.mass = 5.97e24, .pos = {0, 0}, .vel = {0, 0}};
    struct planet sun = {.mass = 1.99e30, .pos = {1.496e11, 0}, .vel = {0, 2.978e4}};
    struct planet mars = {.mass = 6.39e23, .pos = {2.279e11, 0}, .vel = {0, 2.407e4}};
    struct planet planets[] = {earth, sun, mars};
    int num_planets = sizeof(planets) / sizeof(struct planet);
    
    // Simulate system
    double dt = 3600; // time step, in seconds
    double duration = 365 * 24 * 3600; // duration of simulation, in seconds (1 year)
    simulate(planets, num_planets, dt, duration);
    
    // Print final positions
    int i;
    for(i = 0; i < num_planets; i++) {
        printf("Planet %d final position: (%.2f, %.2f)\n", i+1, planets[i].pos.x, planets[i].pos.y);
    }
    
    return 0;
}