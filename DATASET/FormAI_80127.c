//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11   // gravitational constant

// structure for celestial body
typedef struct {
    double mass;    // mass of the body
    double x;       // x,y coordinates of the body
    double y;
    double vx;      // x,y velocity of the body
    double vy;
    double fx;      // x,y force acting on the body
    double fy;
} Body;

// function to calculate the force acting on a body
void force(Body *b1, Body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dist = sqrt(dx*dx + dy*dy);
    double f = G * b1->mass * b2->mass / (dist*dist);
    b1->fx += f * dx / dist;
    b1->fy += f * dy / dist;
    b2->fx -= f * dx / dist;
    b2->fy -= f * dy / dist;
}

int main() {
    // create solar system bodies
    Body sun = {1.989e+30, 0, 0, 0, 0, 0, 0};    // mass, x, y, vx, vy, fx, fy
    Body earth = {5.97e+24, 1.496e+11, 0, 0, 29783, 0, 0};
    Body moon = {7.34e+22, 1.496e+11+3.844e+8, 0, 0, 29783+1023, 0, 0};
  
    // simulation parameters and loop
    double dt = 60;     // time step
    double time = 0;
    while (1) {
        // calculate forces on bodies
        sun.fx = sun.fy = earth.fx = earth.fy = moon.fx = moon.fy = 0;
        force(&sun, &earth);
        force(&sun, &moon);
        force(&earth, &moon);
        // update positions and velocities of bodies
        sun.vx += sun.fx*dt/sun.mass;
        sun.vy += sun.fy*dt/sun.mass;
        sun.x += sun.vx*dt;
        sun.y += sun.vy*dt;
        earth.vx += earth.fx*dt/earth.mass;
        earth.vy += earth.fy*dt/earth.mass;
        earth.x += earth.vx*dt;
        earth.y += earth.vy*dt;
        moon.vx += moon.fx*dt/moon.mass;
        moon.vy += moon.fy*dt/moon.mass;
        moon.x += moon.vx*dt;
        moon.y += moon.vy*dt;
        // print positions of bodies
        printf("Time: %.0lf seconds\nSun:    x=%.2e m, y=%.2e m\nEarth:  x=%.2e m, y=%.2e m\nMoon:   x=%.2e m, y=%.2e m\n",
               time, sun.x, sun.y, earth.x, earth.y, moon.x, moon.y);
        time += dt;
    }
    return 0;
}