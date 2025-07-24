//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: retro
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define G 6.67408e-11  // gravitational constant
#define MAX_VEL 20000  // maximum velocity
#define MAX_MASS 2000  // maximum mass
#define FRAME_TIME 0.1 // animation frame time
#define UNIVERSE_SIZE 100  // size of the universe

typedef struct {
    double x, y;   // position
    double vx, vy; // velocity
    double fx, fy; // force
    double mass;   // mass
} body;

// Creates a new random body
body create_random_body() {
    body new_body;
    new_body.x = (double)rand() / RAND_MAX * UNIVERSE_SIZE;
    new_body.y = (double)rand() / RAND_MAX * UNIVERSE_SIZE;
    new_body.vx = ((double)rand() / RAND_MAX - 0.5) * MAX_VEL;
    new_body.vy = ((double)rand() / RAND_MAX - 0.5) * MAX_VEL;
    new_body.mass = ((double)rand() / RAND_MAX) * MAX_MASS;
    return new_body;
}

// Calculates the force between two bodies
void calculate_force(body *b1, body *b2) {
    double distance = sqrt(pow((b2->x - b1->x), 2) + pow((b2->y - b1->y), 2));
    double force = (G * b1->mass * b2->mass) / pow(distance, 2);
    double angle = atan2(b2->y - b1->y, b2->x - b1->x);
    b1->fx += force * cos(angle);
    b1->fy += force * sin(angle);
    b2->fx -= force * cos(angle);
    b2->fy -= force * sin(angle);
}

// Calculates the new position and velocity of a body after a time delta
void update_body(body *b, double dt) {
    b->vx += (b->fx / b->mass) * dt;
    b->vy += (b->fy / b->mass) * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

// Calculates the new state of the universe after a time delta by updating each body
void update_universe(body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
    }
    for (int i = 0; i < num_bodies; i++) {
        for (int j = i + 1; j < num_bodies; j++) {
            calculate_force(&bodies[i], &bodies[j]);
        }
    }
    for (int i = 0; i < num_bodies; i++) {
        update_body(&bodies[i], FRAME_TIME);
    }
}

// Prints the state of the universe (positions and velocities of all bodies)
void print_universe(body *bodies, int num_bodies) {
    printf("UNIVERSE STATE:\n");
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: (%f, %f) - (%f, %f)\n", i+1, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
}

int main() {
    // Initialization
    srand(time(NULL));
    int num_bodies;
    printf("Enter the number of bodies: ");
    scanf("%d", &num_bodies);
    body bodies[num_bodies];
    for (int i = 0; i < num_bodies; i++) {
        bodies[i] = create_random_body();
    }
    // Simulation loop
    printf("Press 'q' to quit.\n");
    while (1) {
        // Update universe state
        update_universe(bodies, num_bodies);
        // Print universe state
        print_universe(bodies, num_bodies);
        // Check for quit key
        if (tolower(getchar()) == 'q') {
            break;
        }
    }
    return 0;
}