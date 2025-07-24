//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.6743e-11 // gravitational constant

typedef struct {
    double x, y;
} Vector;

typedef struct {
    Vector pos, vel;
    double mass;
} Body;

void print_body(Body * b) {
    printf("Position: (%lf, %lf)\n", b->pos.x, b->pos.y);
    printf("Velocity: (%lf, %lf)\n", b->vel.x, b->vel.y);
    printf("Mass: %lf\n", b->mass);
}

void update_position(Body * b, double dt) {
    b->pos.x += b->vel.x * dt;
    b->pos.y += b->vel.y * dt;
}

void update_velocity(Body * b, Vector accel, double dt) {
    b->vel.x += accel.x * dt;
    b->vel.y += accel.y * dt;
}

double calc_distance(Body * b1, Body * b2) {
    double dx = b2->pos.x - b1->pos.x;
    double dy = b2->pos.y - b1->pos.y;
    return sqrt(dx*dx + dy*dy);
}

double calc_magnitude(Vector v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

Vector calc_gravity(Body * b1, Body * b2) {
    double r = calc_distance(b1, b2);
    double f = G * b1->mass * b2->mass / (r*r);
    double dx = b2->pos.x - b1->pos.x;
    double dy = b2->pos.y - b1->pos.y;
    Vector dir = { dx/r, dy/r };
    Vector force = { f*dir.x, f*dir.y };
    return force;
}

Vector calc_net_gravity(Body * b, Body * bodies[], int num_bodies) {
    Vector net_force = { 0.0, 0.0 };
    for (int i = 0; i < num_bodies; i++) {
        if (bodies[i] != b) {
            Vector gravity = calc_gravity(b, bodies[i]);
            net_force.x += gravity.x;
            net_force.y += gravity.y;
        }
    }
    return net_force;
}

void simulate(double t_max, double dt, Body * bodies[], int num_bodies) {
    int num_steps = t_max / dt;
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            Body * b = bodies[i];
            Vector net_gravity = calc_net_gravity(b, bodies, num_bodies);
            update_velocity(b, net_gravity, dt);
        }
        for (int i = 0; i < num_bodies; i++) {
            Body * b = bodies[i];
            update_position(b, dt);
        }
    }
}

int main() {
    srand(time(NULL));

    // create three bodies
    Body body1 = { {0,0}, {0,0}, 5.97e24 }; // earth
    Body body2 = { {384400000,0}, {0,1022}, 7.342e22 }; // moon
    Body body3 = { {0,1000000}, {1000,-300}, 10000 }; // spacecraft

    // put them in an array
    Body * bodies[3];
    bodies[0] = &body1;
    bodies[1] = &body2;
    bodies[2] = &body3;

    // run simulation
    double t_max = 60*60*24*30; // one month
    double dt = 60*60; // one hour
    simulate(t_max, dt, bodies, 3);

    // print final positions and velocities
    for (int i = 0; i < 3; i++) {
        printf("Body %d:\n", i+1);
        print_body(bodies[i]);
    }

    return 0;
}