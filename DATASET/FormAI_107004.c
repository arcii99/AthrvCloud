//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11     // gravitational constant
#define M_SUN 1.989e30    // mass of sun
#define AU 1.496e11       // astronomical unit
#define DT 86400          // time step

struct Vector {   // vector struct to represent position and velocity
    double x, y;
};

struct Body {     // body struct to represent celestial objects
    char name[20];
    double mass;
    struct Vector position;
    struct Vector velocity;
};

int main() {
    struct Body sun = {"Sun", M_SUN, {0, 0}, {0, 0}};    // initialize sun
    struct Body earth = {"Earth", 5.972e24, {AU, 0}, {0, 29780}};    // initialize earth
    struct Body moon = {"Moon", 7.349e22, {AU + 384400000, 0}, {0, 3050}};    // initialize moon
    struct Body mars = {"Mars", 6.39e23, {1.524 * AU, 0}, {0, 24100}};    // initialize mars

    struct Body bodies[] = {sun, earth, moon, mars};    // array of bodies
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);    // get number of bodies

    for (int i = 0; i < num_bodies; i++) {
        printf("%s\n", bodies[i].name);
        printf("Position: (%f, %f)\n", bodies[i].position.x, bodies[i].position.y);
        printf("Velocity: (%f, %f)\n", bodies[i].velocity.x, bodies[i].velocity.y);
        printf("\n");
    }

    double forces_x[num_bodies][num_bodies];    // 2D array to store forces in x direction
    double forces_y[num_bodies][num_bodies];    // 2D array to store forces in y direction

    for (int i = 0; i < num_bodies; i++) {
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {    // skip self-interaction
                continue;
            }
            double dx = bodies[j].position.x - bodies[i].position.x;    // x distance between bodies
            double dy = bodies[j].position.y - bodies[i].position.y;    // y distance between bodies
            double distance = sqrt(dx * dx + dy * dy);                  // distance between bodies
            double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);    // gravitational force
            forces_x[i][j] = force * dx / distance;     // force in x direction
            forces_y[i][j] = force * dy / distance;     // force in y direction
        }
    }

    for (int i = 0; i < num_bodies; i++) {
        double net_force_x = 0;
        double net_force_y = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }
            net_force_x += forces_x[i][j];
            net_force_y += forces_y[i][j];
        }
        double acceleration_x = net_force_x / bodies[i].mass;    // acceleration in x direction
        double acceleration_y = net_force_y / bodies[i].mass;    // acceleration in y direction
        bodies[i].velocity.x += acceleration_x * DT;    // update velocity in x direction using F = ma
        bodies[i].velocity.y += acceleration_y * DT;    // update velocity in y direction using F = ma
        bodies[i].position.x += bodies[i].velocity.x * DT;    // update position in x direction using v = dx/dt
        bodies[i].position.y += bodies[i].velocity.y * DT;    // update position in y direction using v = dy/dt
    }

    for (int i = 0; i < num_bodies; i++) {    // print updated positions and velocities
        printf("%s\n", bodies[i].name);
        printf("Position: (%f, %f)\n", bodies[i].position.x, bodies[i].position.y);
        printf("Velocity: (%f, %f)\n", bodies[i].velocity.x, bodies[i].velocity.y);
        printf("\n");
    }

    return 0;
}