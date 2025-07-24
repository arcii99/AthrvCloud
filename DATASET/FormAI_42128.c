//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
/*
* This program simulates the dynamics of a double pendulum using Lagrangian mechanics.
* The user can specify the initial conditions of the system and the program outputs a file
* containing the time evolution of the system.
*/

#include <stdio.h>
#include <math.h>

#define dt 0.1 // step size
#define g 9.81 // gravitational acceleration
#define l1 1.0 // length of the first pendulum
#define l2 1.0 // length of the second pendulum
#define m1 1.0 // mass of the first pendulum
#define m2 1.0 // mass of the second pendulum

int main(){

    // set up initial conditions
    double theta1 = 0.1; // initial angle of the first pendulum
    double theta2 = 0.2; // initial angle of the second pendulum
    double omega1 = 0; // initial angular speed of the first pendulum
    double omega2 = 0; // initial angular speed of the second pendulum

    // open output file
    FILE *file = fopen("double_pendulum.dat", "w");

    // time evolution loop
    for(double t=0; t<=100; t+=dt){

        // calculate accelerations
        double denom = 2*m1 + m2 - m2*cos(2*theta1 - 2*theta2);
        double alpha1 = (-g*(2*m1+m2)*sin(theta1) - m2*g*sin(theta1-2*theta2) 
                        - 2*sin(theta1-theta2)*m2*(omega2*omega2*l2+omega1*omega1*l1*cos(theta1-theta2)))
                        / (l1*denom);
        double alpha2 = (2*sin(theta1-theta2)*((m1+m2)*omega1*omega1*l1 +g*(m1+m2)*cos(theta1)
                        + omega2*omega2*l2*m2*cos(theta1-theta2))) / (l2*denom);

        // update velocities
        omega1 += dt*alpha1;
        omega2 += dt*alpha2;

        // update angles
        theta1 += dt*omega1;
        theta2 += dt*omega2;

        // write results to file
        fprintf(file, "%f %f %f %f\n", t, theta1, theta2, omega1, omega2);
    }

    // close output file and exit program
    fclose(file);
    return 0;
}