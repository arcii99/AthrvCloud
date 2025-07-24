//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>
#define G 6.6743E-11  // universal gravitational constant
#define MAX_BODIES 100 // maximum number of celestial bodies

// define celestial body struct
typedef struct {
    double x, y;     // position
    double vx, vy;   // velocity
    double mass;     // mass
    double fx, fy;   // net force
} Body;

// function to calculate distance between two bodies
double distance(Body a, Body b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// function to calculate gravitational force between two bodies
double force(Body a, Body b) {
    return G * a.mass * b.mass / pow(distance(a, b), 2);
}

// function to update velocity and position of a body based on net force
void update(Body *b, double dt) {
    b->vx += b->fx / b->mass * dt;
    b->vy += b->fy / b->mass * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

// function to simulate gravity for a list of bodies
void simulate(Body *bodies, int n, double dt, double endTime) {
    double time = 0;
    int i, j;
    Body a, b;

    while (time < endTime) {
        // reset net forces
        for (i = 0; i < n; i++) {
            bodies[i].fx = 0;
            bodies[i].fy = 0;
        }
        // calculate net force for each pair of bodies
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                a = bodies[i];
                b = bodies[j];
                double f = force(a, b);
                double dx = b.x - a.x;
                double dy = b.y - a.y;
                double theta = atan2(dy, dx);
                double fx = f * cos(theta);
                double fy = f * sin(theta);
                bodies[i].fx += fx;
                bodies[i].fy += fy;
                bodies[j].fx -= fx;
                bodies[j].fy -= fy;
            }
        }
        // update positions and velocities for all bodies
        for (i = 0; i < n; i++) {
            update(&bodies[i], dt);
        }
        time += dt;
    }
}

int main() {
    // define celestial bodies
    Body sun = {0, 0, 0, 0, 1.989E30};
    Body earth = {1.496E11, 0, 0, 29783, 5.972E24};
    Body moon = {1.496E11 + 3.844E8, 0, 0, 3075, 7.342E22};
    Body mars = {-2.279E11, 0, 0, -24130, 6.39E23};

    // put bodies into array
    Body bodies[MAX_BODIES];
    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = moon;
    bodies[3] = mars;
    int n = 4;

    // simulate gravity
    double dt = 3600;       // time step = 1 hour
    double endTime = 365*24*3600;  // end time = 1 year
    simulate(bodies, n, dt, endTime);

    // print final positions of each body
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y);
    }

    return 0;
}