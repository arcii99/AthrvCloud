//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11 // gravitational constant
#define DAY 86400 // seconds in a day

// planet struct
struct planet {
    char name[20];
    double mass; // kg
    double radius; // km
    double x; // x-coordinate in km
    double y; // y-coordinate in km
    double vx; // x-velocity in km/s
    double vy; // y-velocity in km/s
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double angle(double x1, double y1, double x2, double y2) {
    return atan2(y2 - y1, x2 - x1);
}

double gravitational_force(double m1, double m2, double r) {
    return G * m1 * m2 / (r * r);
}

double acceleration(double force, double mass) {
    return force / mass;
}

void update_planet(struct planet *p, double ax, double ay, double dt) {
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main(void) {
    srand(time(NULL)); // seed the random function with the current time
    
    // create our planets
    struct planet sun = {"Sun", 1.989e30, 696340, 0, 0, 0, 0};
    struct planet earth = {"Earth", 5.972e24, 6371, 147093162, 0, 0, 29.783 * 1000};
    struct planet mars = {"Mars", 6.39e23, 3389.5, 227939100, 0, 0, 24.077 * 1000};
    struct planet venus = {"Venus", 4.867e24, 6051.8, 108208930, 0, 0, 35.02 * 1000};
    struct planet mercury = {"Mercury", 3.3011e23, 2439.7, 57909227, 0, 0, 47.87 * 1000};
    
    struct planet planets[] = {sun, earth, mars, venus, mercury};
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    
    // simulation parameters
    double dt = 0.01 * DAY; // time step
    double t = 0; // current time
    double tf = 365 * DAY; // final time
    
    // simulation loop
    while (t < tf) {
        // calculate gravitational forces between all planets
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    double d = distance(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
                    double f = gravitational_force(planets[i].mass, planets[j].mass, d);
                    double theta = angle(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
                    double ax = acceleration(f * cos(theta), planets[i].mass);
                    double ay = acceleration(f * sin(theta), planets[i].mass);
                    update_planet(&planets[i], ax, ay, dt);
                }
            }
        }
        // update time
        t += dt;
    }
    
    // print final positions of planets
    for (int i = 0; i < num_planets; i++) {
        printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y);
    }
    
    return 0;
}