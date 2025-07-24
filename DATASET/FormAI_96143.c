//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scientific
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
    //Setting up the initial conditions of the Solar System
    double G = 6.67e-11; //Gravitational constant (units: N*m^2/kg^2)
    double M_sun = 1.989e30; //Mass of the Sun (units: kg)
    double M_earth = 5.97e24; //Mass of Earth (units: kg)
    double M_moon = 7.35e22; //Mass of Moon (units: kg)
    double R_earth = 1.5e11; //Distance between Earth and Sun (units: m)
    double R_moon = 3.84e8; //Distance between Moon and Earth (units: m)
    double v_earth = 3e4; //Velocity of Earth (units: m/s)
    double v_moon = 1e3; //Velocity of Moon (units: m/s)
    double x_earth = 0; //Initial position of Earth (units: m)
    double x_moon = R_moon; //Initial position of Moon (units: m)
    double y_earth = R_earth; //Initial height of Earth (units: m)
    double y_moon = R_earth + R_moon; //Initial height of Moon (units: m)
    double t = 0; //Time (units: s)
    double dt = 60; //Time step (units: s)

    //Calculating the gravitational force between Earth and Sun
    double F_gravity = (G * M_sun * M_earth) / pow(R_earth, 2);

    //Calculating the gravitational force between Earth and Moon
    double F_gravity_moon = (G * M_earth * M_moon) / pow(R_moon, 2);

    while (1)
    {
        //Calculating the distance between Earth and Sun
        double R = sqrt(pow(x_earth, 2) + pow(y_earth, 2));

        //Calculating the angle between Earth and Sun
        double theta = atan(y_earth / x_earth);

        //Calculating the x and y components of the gravitational force between Earth and Sun
        double F_gravity_x = -F_gravity * cos(theta);
        double F_gravity_y = -F_gravity * sin(theta);

        //Updating the velocity of Earth
        double v_x_earth = v_earth * cos(theta) + (F_gravity_x / M_earth) * dt;
        double v_y_earth = v_earth * sin(theta) + (F_gravity_y / M_earth) * dt;

        //Updating the x and y positions of Earth
        x_earth += v_x_earth * dt;
        y_earth += v_y_earth * dt;

        //Calculating the distance between Earth and Moon
        double R_moon_earth = sqrt(pow(x_moon - x_earth, 2) + pow(y_moon - y_earth, 2));

        //Calculating the angle between Earth and Moon
        double theta_moon_earth = atan((y_moon - y_earth) / (x_moon - x_earth));

        //Calculating the x and y components of the gravitational force between Earth and Moon
        double F_gravity_x_moon = -F_gravity_moon * cos(theta_moon_earth);
        double F_gravity_y_moon = -F_gravity_moon * sin(theta_moon_earth);

        //Updating the velocity of Moon
        double v_x_moon = v_moon * cos(theta_moon_earth) + (F_gravity_x_moon / M_moon) * dt;
        double v_y_moon = v_moon * sin(theta_moon_earth) + (F_gravity_y_moon / M_moon) * dt;

        //Updating the x and y positions of Moon
        x_moon += v_x_moon * dt;
        y_moon += v_y_moon * dt;

        //Printing the x and y positions of Earth and Moon
        printf("Time: %lf seconds\n", t);
        printf("Position of Earth: (%lf, %lf)\n", x_earth, y_earth);
        printf("Position of Moon: (%lf, %lf)\n", x_moon, y_moon);
        printf("\n");

        //Updating the time
        t += dt;
    }

    return 0;
}