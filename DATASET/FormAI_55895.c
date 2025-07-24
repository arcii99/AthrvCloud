//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589
#define G 6.6743E-11

struct planet {
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

double distance(double p1[], double p2[]) {
    return sqrt(pow(p2[0]-p1[0],2) + pow(p2[1]-p1[1],2) + pow(p2[2]-p1[2],2));
}

int main() {

    // Initialize the planets
    struct planet sun = {"Sun", 1.989E30, {0,0,0}, {0,0,0}, {0,0,0}};
    struct planet earth = {"Earth", 5.97E24, {-147095000000,0,0}, {0,29000,0}, {0,0,0}};
    struct planet mars = {"Mars", 6.39E23, {0,-204366000000,0}, {-24130,0,0}, {0,0,0}};

    // Calculate the initial distance and force between the planets
    double d_earth_sun = distance(earth.position, sun.position);
    double d_mars_sun = distance(mars.position, sun.position);
    double f_earth_sun = G * earth.mass * sun.mass / pow(d_earth_sun,2);
    double f_mars_sun = G * mars.mass * sun.mass / pow(d_mars_sun,2);
    double force_earth_sun[3] = {f_earth_sun, 0, 0};
    double force_mars_sun[3] = {0, -f_mars_sun, 0};

    // Initialize time and time step
    double t = 0;
    double dt = 3600;

    // Run simulation for 1 year
    double t_final = 31536000;
    while (t < t_final) {
        // Calculate acceleration for each planet
        for (int i=0; i<3; i++) {
            earth.acceleration[i] = force_earth_sun[i] / earth.mass;
            mars.acceleration[i] = force_mars_sun[i] / mars.mass;
        }

        // Calculate new positions and velocities
        for (int i=0; i<3; i++) {
            earth.position[i] += earth.velocity[i] * dt + 0.5 * earth.acceleration[i] * pow(dt,2);
            mars.position[i] += mars.velocity[i] * dt + 0.5 * mars.acceleration[i] * pow(dt,2);
            earth.velocity[i] += earth.acceleration[i] * dt;
            mars.velocity[i] += mars.acceleration[i] * dt;
        }

        // Update distance and force
        d_earth_sun = distance(earth.position, sun.position);
        d_mars_sun = distance(mars.position, sun.position);
        f_earth_sun = G * earth.mass * sun.mass / pow(d_earth_sun,2);
        f_mars_sun = G * mars.mass * sun.mass / pow(d_mars_sun,2);
        force_earth_sun[0] = f_earth_sun * earth.position[0]/d_earth_sun;
        force_earth_sun[1] = f_earth_sun * earth.position[1]/d_earth_sun;
        force_earth_sun[2] = f_earth_sun * earth.position[2]/d_earth_sun;
        force_mars_sun[0] = f_mars_sun * mars.position[0]/d_mars_sun;
        force_mars_sun[1] = f_mars_sun * mars.position[1]/d_mars_sun;
        force_mars_sun[2] = f_mars_sun * mars.position[2]/d_mars_sun;

        // Increment time
        t += dt;

        // Print planet positions and velocities
        printf("t=%.2lf Earth: x=%.2lf y=%.2lf z=%.2lf vx=%.2lf vy=%.2lf vz=%.2lf\n", t/3600/24, earth.position[0], earth.position[1], earth.position[2], earth.velocity[0], earth.velocity[1], earth.velocity[2]);
        printf("       Mars: x=%.2lf y=%.2lf z=%.2lf vx=%.2lf vy=%.2lf vz=%.2lf\n\n", mars.position[0], mars.position[1], mars.position[2], mars.velocity[0], mars.velocity[1], mars.velocity[2]);
    }

    return 0;
}