//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846

//Structure to hold position and velocity data
typedef struct {
    double x, y;
    double vx, vy;
} Body;

//Constants declaration
const double G = 6.67 * pow(10, -11); //Gravitational constant
const double MASS_SUN = 1.989 * pow(10, 30); //Mass of sun

//Function to calculate distance between two bodies
double distance(Body body1, Body body2) {
    double dx = body1.x - body2.x;
    double dy = body1.y - body2.y;
    return sqrt(dx * dx + dy * dy);
}

//Function to calculate acceleration due to gravity
double acceleration(Body body, double dist, double total_mass) {
    return G * total_mass / (dist * dist);
}

//Function to calculate velocity of a body
void calculate_velocity(Body *body, double ax, double ay, double dt) {
    body->vx += ax * dt;
    body->vy += ay * dt;
}

//Function to calculate position of a body
void calculate_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

//Function to initialize body with random values
Body initialize_body() {
    Body b;
    b.x = rand() % 1000;
    b.y = rand() % 1000;
    b.vx = rand() % 10 - 5;
    b.vy = rand() % 10 - 5;
    return b;
}

int main() {
    //Seed random number generator
    srand(time(NULL));

    //Declaration of variables
    int num_bodies = 5; //Number of objects in the simulation
    int num_steps = 1000; //Number of time steps in the simulation
    int i, j, k;
    double dt = 1000; //Time step in seconds
    double ax, ay, dist;
    double total_mass;

    //Array of bodies in the simulation
    Body bodies[num_bodies];

    //Assigning random values to the bodies
    for (i = 0; i < num_bodies; i++) {
        bodies[i] = initialize_body();
    }

    //Loop for simulation
    for (i = 0; i < num_steps; i++) {
        //Loop to calculate net acceleration on each body
        for (j = 0; j < num_bodies; j++) {
            ax = 0;
            ay = 0;
            total_mass = 0;
            //Loop to calculate total mass and acceleration in x and y direction due to each body
            for (k = 0; k < num_bodies; k++) {
                if (j != k) {
                    dist = distance(bodies[j], bodies[k]);
                    ax += acceleration(bodies[k], dist, MASS_SUN);
                    ay += acceleration(bodies[k], dist, MASS_SUN);
                    total_mass += MASS_SUN;
                }
            }
            //Calculating net acceleration in x and y direction on jth body
            ax = ax / total_mass;
            ay = ay / total_mass;
            //Calculating velocity and position of jth body
            calculate_velocity(&bodies[j], ax, ay, dt);
            calculate_position(&bodies[j], dt);
        }

        //Printing position of each body after each time step
        for (j = 0; j < num_bodies; j++) {
            printf("Body %d: (%lf, %lf)\n", j, bodies[j].x, bodies[j].y);
        }
    }

    return 0;
}