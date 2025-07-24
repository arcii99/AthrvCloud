//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

// constants
#define G 6.67430e-11   // gravitational constant in m^3 kg^-1 s^-2
#define dt 0.1          // time step in seconds
#define sim_time 60     // simulation time in seconds

// function to calculate distance between two objects
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
    // object 1
    double m1 = 1.989e30;   // mass of sun
    double r1 = 695500e3;   // radius of sun
    double v1x = 0;         // initial velocity in x direction
    double v1y = 0;         // initial velocity in y direction
    double x1 = 0;          // initial x position
    double y1 = 0;          // initial y position
    
    // object 2
    double m2 = 5.972e24;   // mass of earth
    double r2 = 6.371e6;    // radius of earth
    double v2x = 0;         // initial velocity in x direction
    double v2y = 29.783e3;  // initial velocity in y direction
    double x2 = 147.09e9;   // initial x position (distance from sun)
    double y2 = 0;          // initial y position
    
    // calculate initial distance and force between objects
    double d = distance(x1, y1, x2, y2);
    double F = G*m1*m2/pow(d, 2);
    
    // calculate initial accelerations
    double a1x = F/m1 * (x2-x1)/d;   
    double a1y = F/m1 * (y2-y1)/d;
    double a2x = -a1x;              
    double a2y = -a1y;
    
    // simulation loop
    for (double t = 0; t < sim_time; t += dt) {
        // update positions
        x1 += v1x*dt;
        y1 += v1y*dt;
        x2 += v2x*dt;
        y2 += v2y*dt;
        
        // calculate new distance and force between objects
        d = distance(x1, y1, x2, y2);
        F = G*m1*m2/pow(d, 2);
        
        // calculate new accelerations
        a1x = F/m1 * (x2-x1)/d;
        a1y = F/m1 * (y2-y1)/d;
        a2x = -a1x;
        a2y = -a1y;
        
        // update velocities
        v1x += a1x*dt;
        v1y += a1y*dt;
        v2x += a2x*dt;
        v2y += a2y*dt;
        
        // print positions of objects at regular intervals
        if ((int)t % 10 == 0) {
            printf("Position of sun: (%.2e, %.2e)\n", x1, y1);
            printf("Position of earth: (%.2e, %.2e)\n", x2, y2);
        }
    }
    
    return 0;
}