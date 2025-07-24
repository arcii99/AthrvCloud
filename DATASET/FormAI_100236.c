//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the constants for the simulation */
#define G 6.6743 * pow(10, -11) /* Gravitational constant */
#define DT 0.001 /* Time step */
#define MASS_EARTH 5.972 * pow(10, 24) /* Mass of the Earth */
#define RADIUS_EARTH 6371 * pow(10, 3) /* Radius of the Earth */
#define MASS_SUN 1.989 * pow(10, 30) /* Mass of the Sun */
#define RADIUS_SUN 695700 * 1000 /* Radius of the Sun */

/* Define the structure for each celestial body */
typedef struct {
    double mass; /* Mass of the body */
    double x, y; /* Position of the body */
    double vx, vy; /* Velocity of the body */
} body;

/* Define the function to calculate the gravitational force between two bodies */
void calculateForce(body b1, body b2, double *Fx, double *Fy) {
    double dx = b2.x - b1.x;
    double dy = b2.y - b1.y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = G * b1.mass * b2.mass / (distance * distance);
    *Fx = force * dx / distance;
    *Fy = force * dy / distance;
}

int main() {
    int numBodies = 3;
    body bodies[numBodies];
    /* Initialize the bodies */
    bodies[0].mass = MASS_EARTH;
    bodies[0].x = 0;
    bodies[0].y = 0.25 * RADIUS_EARTH;
    bodies[0].vx = 30000;
    bodies[0].vy = 0;
    bodies[1].mass = 1000;
    bodies[1].x = 0;
    bodies[1].y = RADIUS_EARTH + 1000;
    bodies[1].vx = -5000;
    bodies[1].vy = 0;
    bodies[2].mass = MASS_SUN;
    bodies[2].x = 0;
    bodies[2].y = -50 * RADIUS_SUN;
    bodies[2].vx = 0;
    bodies[2].vy = 1000;

    /* Run the simulation */
    int numSteps = 100000;
    for (int step = 0; step < numSteps; step++) {
        /* Calculate the forces on each body */
        double Fx[numBodies], Fy[numBodies];
        for (int i = 0; i < numBodies; i++) {
            Fx[i] = 0;
            Fy[i] = 0;
            for (int j = 0; j < numBodies; j++) {
                if (i != j) {
                    double forceX, forceY;
                    calculateForce(bodies[i], bodies[j], &forceX, &forceY);
                    Fx[i] += forceX;
                    Fy[i] += forceY;
                }
            }
        }

        /* Update the velocities and positions of each body */
        for (int i = 0; i < numBodies; i++) {
            double ax = Fx[i] / bodies[i].mass;
            double ay = Fy[i] / bodies[i].mass;
            bodies[i].vx += ax * DT;
            bodies[i].vy += ay * DT;
            bodies[i].x += bodies[i].vx * DT;
            bodies[i].y += bodies[i].vy * DT;

            /* Check for collision with Earth */
            if (i != 0) {
                double dx = bodies[i].x - bodies[0].x;
                double dy = bodies[i].y - bodies[0].y;
                double distance = sqrt(dx*dx + dy*dy);
                if (distance < RADIUS_EARTH) {
                    printf("Collision with Earth at step %d\n", step);
                    exit(0);
                }
            }
        }
    }
    return 0;
}