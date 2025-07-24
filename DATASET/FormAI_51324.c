//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONST 6.67430e-11 // gravitational constant

struct Planet {
    char name[20];
    double mass;
    double radius;
    double x, y; // coordinates
    double vx, vy; // velocities
} sun, earth, moon;

void simulate(double time_step, int steps) {
    double fx, fy, dx, dy, distance, acceleration;
    
    for (int i = 0; i < steps; i++) {
        // calculate distance between earth and sun
        dx = sun.x - earth.x;
        dy = sun.y - earth.y;
        distance = sqrt(dx*dx + dy*dy);
        
        // calculate gravitational force
        acceleration = G_CONST * sun.mass / pow(distance, 2);
        fx = acceleration * dx / distance;
        fy = acceleration * dy / distance;
        
        // calculate new velocity and position of earth
        earth.vx += fx * time_step;
        earth.vy += fy * time_step;
        earth.x += earth.vx * time_step;
        earth.y += earth.vy * time_step;
        
        // calculate distance between moon and earth
        dx = earth.x - moon.x;
        dy = earth.y - moon.y;
        distance = sqrt(dx*dx + dy*dy);
        
        // calculate gravitational force
        acceleration = G_CONST * earth.mass / pow(distance, 2);
        fx = acceleration * dx / distance;
        fy = acceleration * dy / distance;
        
        // calculate new velocity and position of moon
        moon.vx += fx * time_step;
        moon.vy += fy * time_step;
        moon.x += moon.vx * time_step;
        moon.y += moon.vy * time_step;
        
        printf("%d: Earth x = %lf, y = %lf\n", i, earth.x, earth.y);
        printf("%d: Moon x = %lf, y = %lf\n", i, moon.x, moon.y);
    }
}

int main() {
    // initialize planets
    strcpy(sun.name, "Sun");
    sun.mass = 1.989e30;
    sun.radius = 695700;
    sun.x = 0;
    sun.y = 0;
    sun.vx = 0;
    sun.vy = 0;
    
    strcpy(earth.name, "Earth");
    earth.mass = 5.97e24;
    earth.radius = 6378;
    earth.x = 150e9;
    earth.y = 0;
    earth.vx = 0;
    earth.vy = 30e3;
    
    strcpy(moon.name, "Moon");
    moon.mass = 7.342e22;
    moon.radius = 1737;
    moon.x = earth.x + 384400e3;
    moon.y = 0;
    moon.vx = earth.vx + 1023;
    moon.vy = earth.vy;
    
    simulate(500, 10);
    
    return 0;
}