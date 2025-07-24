//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define GRAV_CONST 6.67e-11

typedef struct body_t {   // definea body as a structure with relevant properties
    char name[20];       // name of the body
    double mass;         // mass of the body in kilograms
    double radius;       // radius of the body in meters
    double pos_x;        // x position of the body in meters
    double pos_y;        // y position of the body in meters
    double vel_x;        // x component of velocity of the body in meters/second
    double vel_y;        // y component of velocity of the body in meters/second
} Body;

void update_position(Body* body, double time_step) {  // helper function to update position of a body
    body->pos_x += body->vel_x * time_step;
    body->pos_y += body->vel_y * time_step;
}

void update_velocity(Body* body, double force_x, double force_y, double time_step) {  // helper function to update velocity of a body
    double acceleration_x = force_x / body->mass;
    double acceleration_y = force_y / body->mass;
    body->vel_x += acceleration_x * time_step;
    body->vel_y += acceleration_y * time_step;
}

int main() {
    // create 4 bodies representing Sun, Earth, Moon and Mars
    // mass, radius and distance is in relative scale according to the actual solar system
    Body sun = {"Sun", 1.989e30, 695510e3, 0, 0, 0, 0};
    Body earth = {"Earth", 5.972e24, 6378e3, 147e9, 0, 0, 29.78e3};
    Body moon = {"Moon", 7.342e22, 1737e3, 147e9 + 384400e3, 0, 0, 1022};
    Body mars = {"Mars", 6.39e23, 3397e3, -228e9, 0, 0, -24.077e3};
    
    double time = 0;         // initialize time as 0
    double time_step = 3600; // time step is 1 hour
    double sun_earth_distance, sun_moon_distance, sun_mars_distance;
    double earth_moon_distance, earth_mars_distance, moon_mars_distance;
    double force_x, force_y; // force acting on each body in x and y direction
    
    while (time < 365 * 24 * 3600) {  // simulate for 1 year of solar system time
        sun_earth_distance = sqrt(pow(earth.pos_x - sun.pos_x, 2) + pow(earth.pos_y - sun.pos_y, 2));
        sun_moon_distance = sqrt(pow(moon.pos_x - sun.pos_x, 2) + pow(moon.pos_y - sun.pos_y, 2));
        sun_mars_distance = sqrt(pow(mars.pos_x - sun.pos_x, 2) + pow(mars.pos_y - sun.pos_y, 2));
        earth_moon_distance = sqrt(pow(moon.pos_x - earth.pos_x, 2) + pow(moon.pos_y - earth.pos_y, 2));
        earth_mars_distance = sqrt(pow(mars.pos_x - earth.pos_x, 2) + pow(mars.pos_y - earth.pos_y, 2));
        moon_mars_distance = sqrt(pow(mars.pos_x - moon.pos_x, 2) + pow(mars.pos_y - moon.pos_y, 2));
        
        // calculate gravitational force and update velocity and position of each body
        force_x = (GRAV_CONST * sun.mass * earth.mass / pow(sun_earth_distance, 2)) * (sun.pos_x - earth.pos_x) / sun_earth_distance;
        force_y = (GRAV_CONST * sun.mass * earth.mass / pow(sun_earth_distance, 2)) * (sun.pos_y - earth.pos_y) / sun_earth_distance;
        update_velocity(&earth, force_x, force_y, time_step);
        update_position(&earth, time_step);
        
        force_x = (GRAV_CONST * sun.mass * moon.mass / pow(sun_moon_distance, 2)) * (sun.pos_x - moon.pos_x) / sun_moon_distance;
        force_y = (GRAV_CONST * sun.mass * moon.mass / pow(sun_moon_distance, 2)) * (sun.pos_y - moon.pos_y) / sun_moon_distance;
        force_x += (GRAV_CONST * earth.mass * moon.mass / pow(earth_moon_distance, 2)) * (earth.pos_x - moon.pos_x) / earth_moon_distance;
        force_y += (GRAV_CONST * earth.mass * moon.mass / pow(earth_moon_distance, 2)) * (earth.pos_y - moon.pos_y) / earth_moon_distance;
        update_velocity(&moon, force_x, force_y, time_step);
        update_position(&moon, time_step);
        
        force_x = (GRAV_CONST * sun.mass * mars.mass / pow(sun_mars_distance, 2)) * (sun.pos_x - mars.pos_x) / sun_mars_distance;
        force_y = (GRAV_CONST * sun.mass * mars.mass / pow(sun_mars_distance, 2)) * (sun.pos_y - mars.pos_y) / sun_mars_distance;
        force_x += (GRAV_CONST * earth.mass * mars.mass / pow(earth_mars_distance, 2)) * (earth.pos_x - mars.pos_x) / earth_mars_distance;
        force_y += (GRAV_CONST * earth.mass * mars.mass / pow(earth_mars_distance, 2)) * (earth.pos_y - mars.pos_y) / earth_mars_distance;
        force_x += (GRAV_CONST * moon.mass * mars.mass / pow(moon_mars_distance, 2)) * (moon.pos_x - mars.pos_x) / moon_mars_distance;
        force_y += (GRAV_CONST * moon.mass * mars.mass / pow(moon_mars_distance, 2)) * (moon.pos_y - mars.pos_y) / moon_mars_distance;
        update_velocity(&mars, force_x, force_y, time_step);
        update_position(&mars, time_step);
        
        time += time_step;
    }
    
    // print final position and velocity of each body
    printf("Final position and velocity of each body after 1 year simulation:\n");
    printf("%s: (%.2e, %.2e) m, (%.2e, %.2e) m/s\n", sun.name, sun.pos_x, sun.pos_y, sun.vel_x, sun.vel_y);
    printf("%s: (%.2e, %.2e) m, (%.2e, %.2e) m/s\n", earth.name, earth.pos_x, earth.pos_y, earth.vel_x, earth.vel_y);
    printf("%s: (%.2e, %.2e) m, (%.2e, %.2e) m/s\n", moon.name, moon.pos_x, moon.pos_y, moon.vel_x, moon.vel_y);
    printf("%s: (%.2e, %.2e) m, (%.2e, %.2e) m/s\n", mars.name, mars.pos_x, mars.pos_y, mars.vel_x, mars.vel_y);
    
    return 0;
}