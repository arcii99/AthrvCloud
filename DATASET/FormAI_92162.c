//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// define constants for simulation
#define G 6.674e-11
#define STEPS_PER_SEC 100000
#define SECONDS_PER_DAY 86400.0
#define AU 1.496e11

// define planet struct
typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} planet;

int main() {
    // initialize planets
    planet sun = { 0, 0, 0, 0, 1.989e30 };
    planet mercury = { -0.39*AU, 0, 0, 47870, 3.3e23 };
    planet venus = { -0.72*AU, 0, 0, 35020, 4.87e24 };
    planet earth = { -1*AU, 0, 0, 29783, 5.97e24 };
    planet mars = { -1.52*AU, 0, 0, 24077, 6.39e23 };
    planet jupiter = { -5.2*AU, 0, 0, 13070, 1.90e27 };
    planet saturn = { -9.58*AU, 0, 0, 9690, 5.68e26 };
    planet uranus = { -19.18*AU, 0, 0, 6810, 8.68e25 };
    planet neptune = { -30.07*AU, 0, 0, 5430, 1.03e26 };
    
    // initialize time
    double t = 0;
    double dt = 1.0 / STEPS_PER_SEC;
    
    while (1) {
        // calculate gravitational forces
        double dx, dy, dist;
        double fx, fy;
        dx = mercury.x - sun.x;
        dy = mercury.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * mercury.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * mercury.mass * sun.mass / (dist*dist) * dy / dist;
        mercury.vx += fx * dt / mercury.mass;
        mercury.vy += fy * dt / mercury.mass;

        dx = venus.x - sun.x;
        dy = venus.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * venus.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * venus.mass * sun.mass / (dist*dist) * dy / dist;
        venus.vx += fx * dt / venus.mass;
        venus.vy += fy * dt / venus.mass;

        dx = earth.x - sun.x;
        dy = earth.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * earth.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * earth.mass * sun.mass / (dist*dist) * dy / dist;
        earth.vx += fx * dt / earth.mass;
        earth.vy += fy * dt / earth.mass;

        dx = mars.x - sun.x;
        dy = mars.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * mars.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * mars.mass * sun.mass / (dist*dist) * dy / dist;
        mars.vx += fx * dt / mars.mass;
        mars.vy += fy * dt / mars.mass;
        
        dx = jupiter.x - sun.x;
        dy = jupiter.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * jupiter.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * jupiter.mass * sun.mass / (dist*dist) * dy / dist;
        jupiter.vx += fx * dt / jupiter.mass;
        jupiter.vy += fy * dt / jupiter.mass;

        dx = saturn.x - sun.x;
        dy = saturn.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * saturn.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * saturn.mass * sun.mass / (dist*dist) * dy / dist;
        saturn.vx += fx * dt / saturn.mass;
        saturn.vy += fy * dt / saturn.mass;

        dx = uranus.x - sun.x;
        dy = uranus.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * uranus.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * uranus.mass * sun.mass / (dist*dist) * dy / dist;
        uranus.vx += fx * dt / uranus.mass;
        uranus.vy += fy * dt / uranus.mass;

        dx = neptune.x - sun.x;
        dy = neptune.y - sun.y;
        dist = sqrt(dx*dx + dy*dy);
        fx = -G * neptune.mass * sun.mass / (dist*dist) * dx / dist;
        fy = -G * neptune.mass * sun.mass / (dist*dist) * dy / dist;
        neptune.vx += fx * dt / neptune.mass;
        neptune.vy += fy * dt / neptune.mass;
        
        // update positions
        mercury.x += mercury.vx * dt;
        mercury.y += mercury.vy * dt;

        venus.x += venus.vx * dt;
        venus.y += venus.vy * dt;

        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        mars.x += mars.vx * dt;
        mars.y += mars.vy * dt;

        jupiter.x += jupiter.vx * dt;
        jupiter.y += jupiter.vy * dt;

        saturn.x += saturn.vx * dt;
        saturn.y += saturn.vy * dt;

        uranus.x += uranus.vx * dt;
        uranus.y += uranus.vy * dt;

        neptune.x += neptune.vx * dt;
        neptune.y += neptune.vy * dt;
        
        // print out positions
        printf("t=%lf: mercury=(%lf,%lf), venus=(%lf,%lf), earth=(%lf,%lf), mars=(%lf,%lf), jupiter=(%lf,%lf), saturn=(%lf,%lf), uranus=(%lf,%lf), neptune=(%lf,%lf)\n", t, mercury.x, mercury.y, venus.x, venus.y, earth.x, earth.y, mars.x, mars.y, jupiter.x, jupiter.y, saturn.x, saturn.y, uranus.x, uranus.y, neptune.x, neptune.y);

        // increment time
        t += dt;
    }

    return 0;
}