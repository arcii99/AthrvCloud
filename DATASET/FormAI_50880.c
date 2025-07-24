//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    double g = 9.81; // gravitational acceleration
    double l = 0.5; // length of the pendulum
    double theta0 = PI/4.0; // initial angle of the pendulum
    double dt = 0.01; // time step
    double tmax = 10.0; // maximum simulation time
    
    double theta = theta0; // initialize pendulum angle
    double omega = 0.0; // initialize pendulum angular velocity
    
    for (double t=0.0; t<tmax; t+=dt) {
        
        // calculate pendulum acceleration
        double alpha = -g/l*sin(theta);
        
        // update pendulum velocity and angle
        omega += alpha*dt;
        theta += omega*dt;
        
        // print pendulum angle and time to console
        printf("Time: %lf, Angle: %lf\n", t, theta);
    }
    
    return 0;
}