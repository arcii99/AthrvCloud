//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

struct planet {
    double x;
    double y;
    double vx;
    double vy;
    double mass;
};

int main(){
    const double G = 6.6743e-11;    // gravitational constant
    const int dt = 3600;            // time step in seconds
    const int num_planets = 3;      // number of planets in simulation
    
    struct planet planets[num_planets];
    
    // set initial conditions for each planet
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].mass = 5.972e24;     // mass of Earth
    
    planets[1].x = 149.6e9;         // distance from Sun to Earth
    planets[1].y = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = 29.29e3;        // velocity of Earth relative to Sun
    planets[1].mass = 1.989e30;     // mass of Sun
    
    planets[2].x = 149.6e9;         // distance from Sun to Earth
    planets[2].y = 450.0e9;        // arbitrary y coordinate
    planets[2].vx = -29.29e3/2;    // half the velocity of Earth
    planets[2].vy = 0.0;
    planets[2].mass = 5.972e24;     // mass of Earth
    
    // simulate gravity interactions
    for (int i = 0; i < 86400*365; i += dt) {
        // calculate net force on each planet
        double fx[num_planets];
        double fy[num_planets];
        for (int j = 0; j < num_planets; j++) {
            
            double net_fx = 0.0;
            double net_fy = 0.0;
            
            for (int k = 0; k < num_planets; k++) {
                if (j == k) continue;
                double dx = planets[k].x - planets[j].x;
                double dy = planets[k].y - planets[j].y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * planets[j].mass * planets[k].mass / (r*r);
                net_fx += f * dx / r;
                net_fy += f * dy / r;
            }
            
            fx[j] = net_fx;
            fy[j] = net_fy;
            
        }
        
        // update positions and velocities
        for (int j = 0; j < num_planets; j++) {
            planets[j].vx += fx[j] / planets[j].mass * dt;
            planets[j].vy += fy[j] / planets[j].mass * dt;
            planets[j].x += planets[j].vx * dt;
            planets[j].y += planets[j].vy * dt;
        }
        
        // output positions
        printf("%f\t%f\t%f\t%f\n", planets[0].x, planets[0].y, planets[1].x, planets[1].y);
    }
    
    return 0;
}