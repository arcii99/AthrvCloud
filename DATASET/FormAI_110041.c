//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double theta, x, y, vx, vy, ax, ay, t, dt;
    double m = 2.0; // mass 
    double k = 20.0; // spring constant
    double b = 0.2; // damping coefficient
    double L = 1.0; // length of spring
    double g = 9.81; // gravitational acceleration
    double omega = sqrt(k/m); // angular frequency
    
    //initial conditions
    x = 0.5; 
    y = sqrt(L*L - x*x);
    theta = atan(y / x);
    vx = 0.0; 
    vy = 0.0;
    ax = 0.0; 
    ay = 0.0;
    t = 0.0; 
    dt = 0.01;

    while (1) {
        // calculate forces
        double f_spring = -k * x;
        double f_damping = -b * vx;
        double f_gravity = -m * g * sin(theta);
        double f_total = f_spring + f_damping + f_gravity;
        
        // update acceleration
        ax = f_total / m * cos(theta);
        ay = f_total / m * sin(theta);

        // update velocity
        vx += ax * dt;
        vy += ay * dt;

        // update position
        x += vx * dt;
        y += vy * dt;

        // update angle
        theta = atan(y / x);

        // check if the ball hits the ground
        if (y < 0) {
            printf("The ball hits the ground at t = %.2f seconds.\n", t);
            break;
        }
        
        // print out the time, position, velocity, and acceleration for each time step
        printf("t = %.2f, x = %.2f, y = %.2f, vx = %.2f, vy = %.2f, ax = %.2f, ay = %.2f\n", t, x, y, vx, vy, ax, ay);

        // update time
        t += dt;
    }

    return 0;
}