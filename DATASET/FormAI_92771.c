//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
// C Planet Gravity Simulation Example Program
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67430E-11 // gravitational constant (m^3 kg^-1 s^-2)

typedef struct {
    double x, y; // position in meters
    double vx, vy; // velocity in meters per second
    double ax, ay; // acceleration in meters per second squared
    double mass; // mass in kilograms
} Body;

// function to calculate the gravitational force acting between bodies
void calc_force(Body *body1, Body *body2) {
    double dx = body2 -> x - body1 -> x;
    double dy = body2 -> y - body1 -> y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = GRAV_CONST * body1 -> mass * body2 -> mass / (distance * distance);
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    body1 -> ax += fx / body1 -> mass;
    body1 -> ay += fy / body1 -> mass;
    body2 -> ax -= fx / body2 -> mass;
    body2 -> ay -= fy / body2 -> mass;
}

int main() {
    // initialize bodies
    Body sun = {0, 0, 0, 0, 0, 1.989E30}; // mass of sun
    Body earth = {147E9, 0, 0, 30300, 0, 5.97E24}; // distance between earth and sun is 147 million km, earth starts with velocity of 30.3 km/s
    Body moon = {147E9 + 384400000, 0, 0, 30300 + 1023, 0, 7.342E22}; // distance between moon and earth is 384,400 km, moon starts with velocity of 1.023 km/s

    // simulate for one year, with a time step of one day
    double time_step = 86400; // time step in seconds
    double time_elapsed = 0;
    while (time_elapsed < 365.25 * 86400) { // simulate for one year
        // calculate acceleration and velocity for each body
        sun.ax = sun.ay = earth.ax = earth.ay = moon.ax = moon.ay = 0;
        calc_force(&sun, &earth);
        calc_force(&sun, &moon);
        calc_force(&earth, &moon);
        sun.vx += sun.ax * time_step;
        sun.vy += sun.ay * time_step;
        earth.vx += earth.ax * time_step;
        earth.vy += earth.ay * time_step;
        moon.vx += moon.ax * time_step;
        moon.vy += moon.ay * time_step;
        sun.x += sun.vx * time_step;
        sun.y += sun.vy * time_step;
        earth.x += earth.vx * time_step;
        earth.y += earth.vy * time_step;
        moon.x += moon.vx * time_step;
        moon.y += moon.vy * time_step;
        time_elapsed += time_step;
    }

    // print final positions of bodies
    printf("Final position of sun: (%g, %g)\n", sun.x, sun.y);
    printf("Final position of earth: (%g, %g)\n", earth.x, earth.y);
    printf("Final position of moon: (%g, %g)\n", moon.x, moon.y);

    return 0;
}