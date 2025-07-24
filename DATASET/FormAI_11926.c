//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: unmistakable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11 // gravitational constant

/**********************************************/
/*              Data Structures              */
/**********************************************/

struct Vector {
    double x, y, z; // cartesian coordinates
};

typedef struct Vector vector;

struct Body {
    double mass, radius; // physical properties
    vector position, velocity, force; // kinematic properties
};

typedef struct Body body;

/**********************************************/
/*                 Functions                  */
/**********************************************/

vector calculate_gravitational_force(body b1, body b2) {
    vector direction;
    double distance, scalar_force;

    direction.x = b2.position.x - b1.position.x;
    direction.y = b2.position.y - b1.position.y;
    direction.z = b2.position.z - b1.position.z;

    distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
    scalar_force = G * b1.mass * b2.mass / pow(distance, 2);

    direction.x /= distance;
    direction.y /= distance;
    direction.z /= distance;

    vector force;
    force.x = direction.x * scalar_force;
    force.y = direction.y * scalar_force;
    force.z = direction.z * scalar_force;

    return force;
}

void update_body(body *b, double time_step) {
    // update velocity
    b->velocity.x += b->force.x / b->mass * time_step;
    b->velocity.y += b->force.y / b->mass * time_step;
    b->velocity.z += b->force.z / b->mass * time_step;

    // update position
    b->position.x += b->velocity.x * time_step;
    b->position.y += b->velocity.y * time_step;
    b->position.z += b->velocity.z * time_step;

    // reset force
    b->force.x = 0;
    b->force.y = 0;
    b->force.z = 0;
}

void print_body_info(body b) {
    printf("Body Mass: %lf\n", b.mass);
    printf("Body Radius: %lf\n", b.radius);
    printf("Body Position: (%lf, %lf, %lf)\n", b.position.x, b.position.y, b.position.z);
    printf("Body Velocity: (%lf, %lf, %lf)\n", b.velocity.x, b.velocity.y, b.velocity.z);
    printf("Body Force: (%lf, %lf, %lf)\n\n", b.force.x, b.force.y, b.force.z);
}

/**********************************************/
/*                 Main Loop                  */
/**********************************************/

int main() {
    // initialize random generator
    srand(time(NULL));

    // initialize bodies
    body sun = {
        .mass = 1.989e30,
        .radius = 695500e3,
        .position = {0, 0, 0},
        .velocity = {0, 0, 0},
        .force = {0, 0, 0}
    };

    body earth = {
        .mass = 5.97e24,
        .radius = 6371e3,
        .position = {1.496e11, 0, 0},
        .velocity = {0, 29.78e3, 0},
        .force = {0, 0, 0}
    };

    body moon = {
        .mass = 7.342e22,
        .radius = 1737.1e3,
        .position = {1.496e11 + 384400e3, 0, 0},
        .velocity = {0, 29.78e3 + 1022, 0},
        .force = {0, 0, 0}
    };

    body mars = {
        .mass = 6.39e23,
        .radius = 3389.5e3,
        .position = {227.9e9, 0, 0},
        .velocity = {0, 24.077e3, 0},
        .force = {0, 0, 0}
    };

    // simulation parameters
    double time_step = 86400; // 1 day
    double simulation_time = 365.25 * 24 * 3600; // 1 year

    // simulation loop
    for (double t = 0; t < simulation_time; t += time_step) {
        // calculate gravitational forces
        sun.force = calculate_gravitational_force(sun, earth);
        sun.force = calculate_gravitational_force(sun, moon);
        sun.force = calculate_gravitational_force(sun, mars);
        earth.force = calculate_gravitational_force(earth, sun);
        earth.force = calculate_gravitational_force(earth, moon);
        moon.force = calculate_gravitational_force(moon, sun);
        moon.force = calculate_gravitational_force(moon, earth);
        mars.force = calculate_gravitational_force(mars, sun);

        // update bodies
        update_body(&sun, time_step);
        update_body(&earth, time_step);
        update_body(&moon, time_step);
        update_body(&mars, time_step);

        // print information
        printf("\n----- Time: %f -----\n\n", t);
        printf("Sun:\n");
        print_body_info(sun);
        printf("Earth:\n");
        print_body_info(earth);
        printf("Moon:\n");
        print_body_info(moon);
        printf("Mars:\n");
        print_body_info(mars);
    }

    return 0;
}