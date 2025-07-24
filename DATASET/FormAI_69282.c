//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include<stdio.h>
#include<math.h>

#define G 6.674e-11 // Gravitational Constant
#define M_sun 1.989e30 // Mass of sun
#define M_earth 5.972e24 // Mass of earth
#define M_moon 7.346e22 // Mass of moon
#define R_earth 6.371e6 // Radius of earth
#define R_moon 1.737e6 // Radius of moon
#define AU 1.496e11 // Astronomical Unit
#define PI 3.14159265358979323846

struct planet {
    char name[20];
    double mass;
    double radius;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
};

struct planet sun, earth, moon;

double distance(double x1, double y1, double x2, double y2);
double acceleration(double m1, double m2, double r);

int main() {
    // Initializing the sun
    sprintf(sun.name, "Sun");
    sun.mass = M_sun;
    sun.radius = 0;
    sun.x_pos = 0;
    sun.y_pos = 0;
    sun.x_vel = 0;
    sun.y_vel = 0;

    // Initializing the earth
    sprintf(earth.name, "Earth");
    earth.mass = M_earth;
    earth.radius = R_earth;
    earth.x_pos = AU;
    earth.y_pos = 0;
    earth.x_vel = 0;
    earth.y_vel = sqrt((G*M_sun)/AU);

    // Initializing the moon
    sprintf(moon.name, "Moon");
    moon.mass = M_moon;
    moon.radius = R_moon;
    moon.x_pos = AU + 3.844e8;
    moon.y_pos = 0;
    moon.x_vel = 0;
    moon.y_vel = sqrt((G*M_sun)/distance(moon.x_pos, moon.y_pos, sun.x_pos, sun.y_pos));

    // Printing initial positions and velocities
    printf("%10s  %15s  %15s\n", "Planet", "Position", "Velocity");
    printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", sun.name, sun.x_pos, sun.y_pos, sun.x_vel, sun.y_vel);
    printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", earth.name, earth.x_pos, earth.y_pos, earth.x_vel, earth.y_vel);
    printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", moon.name, moon.x_pos, moon.y_pos, moon.x_vel, moon.y_vel);
    printf("\n");

    // Setting time step and simulation time
    double dt = 86400; // 1 day
    double T = 365*24*60*60; // 1 year

    for (double t = 0; t <= T; t += dt) {

        // Calculating distance between earth and sun
        double r_earth_sun = distance(earth.x_pos, earth.y_pos, sun.x_pos, sun.y_pos);

        // Calculating gravitational force on earth due to sun
        double F_earth_sun = acceleration(earth.mass, sun.mass, r_earth_sun);

        // Calculating gravitational force on moon due to sun
        double F_moon_sun = acceleration(moon.mass, sun.mass, distance(moon.x_pos, moon.y_pos, sun.x_pos, sun.y_pos));

        // Calculating gravitational force on moon due to earth
        double F_moon_earth = acceleration(moon.mass, earth.mass, distance(moon.x_pos, moon.y_pos, earth.x_pos, earth.y_pos));

        // Calculating acceleration of earth
        double a_earth = F_earth_sun / earth.mass;

        // Calculating acceleration of moon in x direction
        double a_moon_x = (F_moon_sun*cos(PI/2 - atan2(moon.y_pos - sun.y_pos, moon.x_pos - sun.x_pos)) + F_moon_earth*cos(PI/2 - atan2(moon.y_pos - earth.y_pos, moon.x_pos - earth.x_pos))) / moon.mass;

        // Calculating acceleration of moon in y direction
        double a_moon_y = (F_moon_sun*sin(PI/2 - atan2(moon.y_pos - sun.y_pos, moon.x_pos - sun.x_pos)) + F_moon_earth*sin(PI/2 - atan2(moon.y_pos - earth.y_pos, moon.x_pos - earth.x_pos))) / moon.mass;

        // Updating velocity of earth in x direction
        earth.x_vel += a_earth*dt;

        // Updating velocity of moon in x direction
        moon.x_vel += a_moon_x*dt;

        // Updating velocity of earth in y direction
        earth.y_vel += a_earth*dt;

        // Updating velocity of moon in y direction
        moon.y_vel += a_moon_y*dt;

        // Updating position of earth in x direction
        earth.x_pos += earth.x_vel*dt;

        // Updating position of moon in x direction
        moon.x_pos += moon.x_vel*dt;

        // Updating position of earth in y direction
        earth.y_pos += earth.y_vel*dt;

        // Updating position of moon in y direction
        moon.y_pos += moon.y_vel*dt;

        // Printing positions and velocities every 10 days
        if (fmod(t, 10*86400) == 0) {
            printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", sun.name, sun.x_pos, sun.y_pos, sun.x_vel, sun.y_vel);
            printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", earth.name, earth.x_pos, earth.y_pos, earth.x_vel, earth.y_vel);
            printf("%10s  (%.4e, %.4e)  (%.4e, %.4e)\n", moon.name, moon.x_pos, moon.y_pos, moon.x_vel, moon.y_vel);
            printf("\n");
        }
    }

    return 0;
}

// Function to calculate distance between two points in 2D space
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate acceleration between two objects
double acceleration(double m1, double m2, double r) {
    return G * m1 * m2 / (r*r);
}