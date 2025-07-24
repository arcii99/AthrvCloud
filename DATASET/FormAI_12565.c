//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <math.h>

#define DT 0.1 // time step
#define G 6.6743e-11 // gravitational constant
#define M_EARTH 5.972e+24 // mass of Earth
#define R_EARTH 6.371e+6 // radius of Earth
#define INIT_VEL 0 // initial velocity

int main() {
    double pos_x = 0; // initial x position
    double pos_y = R_EARTH; // initial y position
    double vel_x = INIT_VEL; // initial x velocity
    double vel_y = sqrt((G*M_EARTH)/R_EARTH); // initial y velocity (circular velocity)
    double t = 0; // initial time 

    while (pos_x >= -R_EARTH) { // loop until object hits the Earth
        double accel_x = (-1*G*M_EARTH*pos_x)/pow(sqrt(pow(pos_x,2) + pow(pos_y,2)),3); // acceleration in x direction
        double accel_y = (-1*G*M_EARTH*pos_y)/pow(sqrt(pow(pos_x,2) + pow(pos_y,2)),3); // acceleration in y direction
        vel_x += accel_x*DT; // update x velocity
        vel_y += accel_y*DT; // update y velocity
        pos_x += vel_x*DT; // update x position
        pos_y += vel_y*DT; // update y position
        t += DT; // update time
        printf("Position: (%lf, %lf) Velocity: (%lf, %lf) Time: %lf \n", pos_x, pos_y, vel_x, vel_y, t); // print position, velocity, and time
    }

    printf("Object hit the Earth at time: %lf \n", t); // print time object hit the Earth

    return 0;
}