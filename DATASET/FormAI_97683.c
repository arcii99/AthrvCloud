//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define DT 24*60*60 // time step
#define TOTAL_TIME 365*24*60*60 // total simulation time

/* Define a struct to store positional information of celestial objects */
typedef struct {
    double x, y; // 2D positions
    double vx, vy; // velocity components
    double m; // mass
} object;

int main() {
    /* Define the celestial objects in our solar system*/
    object sun = {0, 0, 0, 0, 1.989e30}; // mass of the sun
    object earth = {1.495979e11, 0, 0, 29783, 5.97e24}; // distance from sun, velocity, mass
    object mars = {-2.492429e11, 0, 0, -24100, 6.39e23};
    object venus = {0, -1.082082e11, -35260, 0, 4.87e24};

    /* Set up file output for plotting */
    FILE *output_file = fopen("solar_system.dat", "w");
    fprintf(output_file, "%f %f %f %f %f %f %f %f\n", sun.x, sun.y, earth.x, earth.y, mars.x, mars.y, venus.x, venus.y);

    /* Simulation loop */
    double time = 0;
    while (time < TOTAL_TIME) {
        /* Calculate the gravitational force on each object */
        double fx_sun = 0, fy_sun = 0, fx_earth = 0, fy_earth = 0, fx_mars = 0, fy_mars = 0, fx_venus = 0, fy_venus = 0;
        double r_sun_earth = sqrt(pow(earth.x - sun.x, 2) + pow(earth.y - sun.y, 2));
        double r_sun_mars = sqrt(pow(mars.x - sun.x, 2) + pow(mars.y - sun.y, 2));
        double r_sun_venus = sqrt(pow(venus.x - sun.x, 2) + pow(venus.y - sun.y, 2));
        double r_earth_mars = sqrt(pow(mars.x - earth.x, 2) + pow(mars.y - earth.y, 2));
        double r_earth_venus = sqrt(pow(venus.x - earth.x, 2) + pow(venus.y - earth.y, 2));
        double r_mars_venus = sqrt(pow(mars.x - venus.x, 2) + pow(mars.y - venus.y, 2));
        double force_sun_earth = G * sun.m * earth.m / pow(r_sun_earth, 2);
        double force_sun_mars = G * sun.m * mars.m / pow(r_sun_mars, 2);
        double force_sun_venus = G * sun.m * venus.m / pow(r_sun_venus, 2);
        double force_earth_mars = G * earth.m * mars.m / pow(r_earth_mars, 2);
        double force_earth_venus = G * earth.m * venus.m / pow(r_earth_venus, 2);
        double force_mars_venus = G * mars.m * venus.m / pow(r_mars_venus, 2);
        fx_sun = force_sun_earth * (earth.x - sun.x) / r_sun_earth + force_sun_mars * (mars.x - sun.x) / r_sun_mars + force_sun_venus * (venus.x - sun.x) / r_sun_venus;
        fy_sun = force_sun_earth * (earth.y - sun.y) / r_sun_earth + force_sun_mars * (mars.y - sun.y) / r_sun_mars + force_sun_venus * (venus.y - sun.y) / r_sun_venus;
        fx_earth = -force_sun_earth * (earth.x - sun.x) / r_sun_earth + force_earth_mars * (mars.x - earth.x) / r_earth_mars + force_earth_venus * (venus.x - earth.x) / r_earth_venus;
        fy_earth = -force_sun_earth * (earth.y - sun.y) / r_sun_earth + force_earth_mars * (mars.y - earth.y) / r_earth_mars + force_earth_venus * (venus.y - earth.y) / r_earth_venus;
        fx_mars = -force_sun_mars * (mars.x - sun.x) / r_sun_mars - force_earth_mars * (mars.x - earth.x) / r_earth_mars + force_mars_venus * (venus.x - mars.x) / r_mars_venus;
        fy_mars = -force_sun_mars * (mars.y - sun.y) / r_sun_mars - force_earth_mars * (mars.y - earth.y) / r_earth_mars + force_mars_venus * (venus.y - mars.y) / r_mars_venus;
        fx_venus = -force_sun_venus * (venus.x - sun.x) / r_sun_venus - force_earth_venus * (venus.x - earth.x) / r_earth_venus - force_mars_venus * (venus.x - mars.x) / r_mars_venus;
        fy_venus = -force_sun_venus * (venus.y - sun.y) / r_sun_venus - force_earth_venus * (venus.y - earth.y) / r_earth_venus - force_mars_venus * (venus.y - mars.y) / r_mars_venus;

        /* Update the velocity and positions */
        sun.vx += fx_sun / sun.m * DT;
        sun.vy += fy_sun / sun.m * DT;
        sun.x += sun.vx * DT;
        sun.y += sun.vy * DT;
        earth.vx += fx_earth / earth.m * DT;
        earth.vy += fy_earth / earth.m * DT;
        earth.x += earth.vx * DT;
        earth.y += earth.vy * DT;
        mars.vx += fx_mars / mars.m * DT;
        mars.vy += fy_mars / mars.m * DT;
        mars.x += mars.vx * DT;
        mars.y += mars.vy * DT;
        venus.vx += fx_venus / venus.m * DT;
        venus.vy += fy_venus / venus.m * DT;
        venus.x += venus.vx * DT;
        venus.y += venus.vy * DT;

        /* Write the positions to the output file */
        fprintf(output_file, "%f %f %f %f %f %f %f %f\n", sun.x, sun.y, earth.x, earth.y, mars.x, mars.y, venus.x, venus.y);

        /* Increment time */
        time += DT;
    }

    /* Close the output file */
    fclose(output_file);
    
    return 0;
}