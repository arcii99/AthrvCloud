//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Constants
#define G 6.673e-11       //Gravitational constant
#define M_CENTER 5.972e24 //Mass of center/planet
#define R_CENTER 6.371e6  //Radius of center/planet

//Function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

//Function to calculate gravitational force
double force(double m1, double m2, double r) {
    return G * m1 * m2 / pow(r, 2);
}

//Function to update velocity and position of object
void update(double *vx, double *vy, double *x, double *y, double fx, double fy, double mass, double time_step) {
    double ax = fx / mass;
    double ay = fy / mass;
    *vx += ax * time_step;
    *vy += ay * time_step;
    *x += *vx * time_step;
    *y += *vy * time_step;
}

int main() {
    //Input values
    double mass = 100;  //Mass of object
    double x = 1e6;     //Initial x position of object
    double y = 1e6;     //Initial y position of object
    double vx = 1000;   //Initial x velocity of object
    double vy = 1000;   //Initial y velocity of object

    //Simulation parameters
    double time_step = 1;  //Time step in seconds
    int steps = 10000;     //Number of time steps to simulate

    //Calculate initial distance and force between object and planet
    double dist = distance(x, y, 0, 0);
    double f = force(mass, M_CENTER, dist);

    //Simulate motion
    for (int i = 0; i < steps; i++) {
        //Calculate new distance and force between object and planet
        dist = distance(x, y, 0, 0);
        f = force(mass, M_CENTER, dist);

        //Calculate x and y force components
        double fx = f * x / dist;
        double fy = f * y / dist;

        //Update velocity and position of object
        update(&vx, &vy, &x, &y, fx, fy, mass, time_step);

        //Check for collision with planet
        if (dist <= R_CENTER) {
            printf("Object collided with planet after %d seconds.\n", i);
            break;
        }
    }

    return 0;
}