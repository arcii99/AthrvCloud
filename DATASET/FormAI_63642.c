//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: introspective
#include <stdio.h>
#include <math.h>
 
#define PI 3.14159265358979323846
 
#define SUN_MASS 1.9891e+30
#define EARTH_MASS 5.97219e+24
#define AU 1.496e+11
 
#define G 6.67430e-11
 
typedef struct {
    double x, y;
} vec2;
 
typedef struct {
    vec2 position;
    vec2 velocity;
    double mass;
    double radius; /* For display purposes only */
} body;
 
int main()
{
    /* Define the initial state of the solar system */
    body sun = {
        .position = {0, 0},
        .velocity = {0, 0},
        .mass = SUN_MASS,
        .radius = 6.955e+8 /* Sun radius in meters */
    };
 
    body earth = {
        .position = {1 * AU, 0},
        .velocity = {0, 29.78e3 /* Earth orbital velocity in m/s */},
        .mass = EARTH_MASS,
        .radius = 6.3781e+6 /* Earth radius in meters */
    };
     
    /*
     * Integrate the equations of motion numerically using the
     * velocity Verlet algorithm.
     */
 
    double time_step = 86400.0; /* One day in seconds */
    double duration = 365 * 60 * 60 * 24.0; /* One year in seconds */
    int steps = (int)(duration / time_step);
 
    vec2 acceleration;
 
    for (int i = 0; i < steps; i++) {
        /* Compute the acceleration of the Earth due to gravity */
        vec2 delta = {earth.position.x - sun.position.x,
                      earth.position.y - sun.position.y};
        double r = sqrt(delta.x*delta.x + delta.y*delta.y);
        double f = G * sun.mass * earth.mass / (r*r);
        acceleration.x = -f / earth.mass * delta.x / r;
        acceleration.y = -f / earth.mass * delta.y / r;
 
        /* Update the position of the Earth */
        earth.position.x += earth.velocity.x * time_step
                          + 0.5 * acceleration.x * time_step * time_step;
        earth.position.y += earth.velocity.y * time_step
                          + 0.5 * acceleration.y * time_step * time_step;
 
        /* Compute the new acceleration of the Earth */
        vec2 delta2 = {earth.position.x - sun.position.x,
                      earth.position.y - sun.position.y};
        double r2 = sqrt(delta2.x*delta2.x + delta2.y*delta2.y);
        double f2 = G * sun.mass * earth.mass / (r2*r2);
        vec2 acceleration2;
        acceleration2.x = -f2 / earth.mass * delta2.x / r2;
        acceleration2.y = -f2 / earth.mass * delta2.y / r2;
 
        /* Update the velocity of the Earth */
        earth.velocity.x += 0.5 * (acceleration.x + acceleration2.x) * time_step;
        earth.velocity.y += 0.5 * (acceleration.y + acceleration2.y) * time_step;
 
        /* Output the state of the Earth */
        printf("%f %f\n", earth.position.x, earth.position.y);
    }
 
    return 0;     
}