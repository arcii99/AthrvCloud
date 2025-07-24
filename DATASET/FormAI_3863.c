//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25
#define AVERAGE_RADIUS 50
#define G 6.67430e-11

typedef struct {
    double x, y;
} vector;

typedef struct {
    double mass;
    vector velocity, force, position;
} body;

void calculate_forces(body* bodies, int num_bodies) {
    int i, j;
    for(i = 0; i < num_bodies; i++) {
        for(j = 0; j < num_bodies; j++) {
            if(i != j) {
                double distance = sqrt(pow(bodies[j].position.x - bodies[i].position.x, 2) + pow(bodies[j].position.y - bodies[i].position.y, 2));
                vector direction = {(bodies[j].position.x - bodies[i].position.x) / distance, (bodies[j].position.y - bodies[i].position.y) / distance};
                double gravitational_force = G * bodies[i].mass * bodies[j].mass / pow(distance, 2);
                bodies[i].force.x += gravitational_force * direction.x;
                bodies[i].force.y += gravitational_force * direction.y;
            }
        }
    }
}

void update_positions(body* bodies, int num_bodies, double timestep) {
    int i;
    for(i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * timestep + 0.5 * bodies[i].force.x / bodies[i].mass * pow(timestep, 2);
        bodies[i].position.y += bodies[i].velocity.y * timestep + 0.5 * bodies[i].force.y / bodies[i].mass * pow(timestep, 2);
    }
}

void update_velocities(body* bodies, int num_bodies, double timestep) {
    int i;
    for(i = 0; i < num_bodies; i++) {
        bodies[i].velocity.x += 0.5 * (bodies[i].force.x / bodies[i].mass + bodies[i].force.x / bodies[i].mass) * timestep;
        bodies[i].velocity.y += 0.5 * (bodies[i].force.y / bodies[i].mass + bodies[i].force.y / bodies[i].mass) * timestep;
    }
}

int main() {
    srand(time(NULL));

    body sun = {1.98892e30, {0, 0}, {0, 0}, {0, 0}};
    body mercury = {3.3011e23, {0, 47362}, {0, 0}, {AVERAGE_RADIUS * 0.38709893, 0}};
    body venus = {4.8675e24, {0, 35020}, {0, 0}, {AVERAGE_RADIUS * 0.72333199, 0}};
    body earth = {5.972e24, {0, 29783}, {0, 0}, {AVERAGE_RADIUS, 0}};
    body mars = {6.4185e23, {0, 24007}, {0, 0}, {AVERAGE_RADIUS * 1.52366231, 0}};
    body jupiter = {1.89813e27, {0, 13070}, {0, 0}, {AVERAGE_RADIUS * 5.20248019, 0}};
    body saturn = {5.68319e26, {0, 9690}, {0, 0}, {AVERAGE_RADIUS * 9.54149883, 0}};
    body uranus = {8.68103e25, {0, 6810}, {0, 0}, {AVERAGE_RADIUS * 19.18797948, 0}};
    body neptune = {1.0241e26, {0, 5430}, {0, 0}, {AVERAGE_RADIUS * 30.06952752, 0}};
    body pluto = {1.303e22, {0, 4748}, {0, 0}, {AVERAGE_RADIUS * 39.48211675, 0}};

    body bodies[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    int i;
    for(i = 0; i < num_bodies; i++) {
        bodies[i].position.y = (double) rand() / RAND_MAX * HEIGHT;
        bodies[i].velocity.y = (rand() % 2 == 0 ? 1 : -1) * sqrt(G * sun.mass / AVERAGE_RADIUS);
    }

    double time_elapsed = 0;
    double timestep = 86400;

    while(time_elapsed < 315360000) {
        calculate_forces(bodies, num_bodies);
        update_positions(bodies, num_bodies, timestep);
        calculate_forces(bodies, num_bodies);
        update_velocities(bodies, num_bodies, timestep);

        int x, y;
        char grid[WIDTH][HEIGHT];
        for(x = 0; x < WIDTH; x++) {
            for(y = 0; y < HEIGHT; y++) {
                grid[x][y] = ' ';
            }
        }
        for(i = 0; i < num_bodies; i++) {
            int x = (int) bodies[i].position.x * WIDTH / (2 * AVERAGE_RADIUS);
            int y = (int) bodies[i].position.y * HEIGHT / AVERAGE_RADIUS;
            grid[x][y] = '*';
        }
        for(y = 0; y < HEIGHT; y++) {
            for(x = 0; x < WIDTH; x++) {
                printf("%c", grid[x][y]);
            }
            printf("\n");
        }
        printf("\n");

        time_elapsed += timestep;
    }

    return 0;
}