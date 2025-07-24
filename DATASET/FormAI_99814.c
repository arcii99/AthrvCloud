//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include <stdio.h>
#include <math.h>
#define G 6.674e-11  // gravitational constant
#define AU 149.6e9    // 1 astronomical unit
#define DAY 86400     // 1 day in seconds

// struct to represent a planet
typedef struct {
    char name[20];   // planet name
    double mass;     // planet mass in kg
    double radius;   // planet radius in m
    double x;        // x position in m
    double y;        // y position in m
    double vx;       // x velocity in m/s
    double vy;       // y velocity in m/s
} Planet;

void update(Planet *p, double fx, double fy, double dt) {
    // update position
    p->x += p->vx * dt;
    p->y += p->vy * dt;

    // update velocity
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
}

double distance(double x1, double y1, double x2, double y2) {
    // calculate distance between two points
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void simulate(Planet *planets, int num_planets, double dt, int num_years) {
    // simulate the solar system for a number of years
    double t = 0;
    int year = 1;
    while (year <= num_years) {
        // print current year
        printf("Year %d\n", year);

        // calculate forces between planets
        double fx[num_planets], fy[num_planets];
        for (int i = 0; i < num_planets; i++) {
            fx[i] = fy[i] = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;

                // calculate distance and force between two planets
                double dist = distance(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
                double f = G * planets[i].mass * planets[j].mass / pow(dist, 2);

                // calculate x and y components of force
                double theta = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x);
                fx[i] += f * cos(theta);
                fy[i] += f * sin(theta);
            }
        }

        // update each planet
        for (int i = 0; i < num_planets; i++) {
            update(&planets[i], fx[i], fy[i], dt);
        }

        // print state of each planet
        for (int i = 0; i < num_planets; i++) {
            printf("%s position: (%e, %e) velocity: (%e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }

        // update time
        t += dt;
        if (t >= DAY) {
            t -= DAY;
            year++;
        }
    }
}

int main() {
    // create array of planets
    Planet planets[] = {
        {"Sun", 1.989e30, 696340000, 0, 0, 0, 0},
        {"Mercury", 3.3011e23, 2439000, 0, -0.3871*AU, 47000, 0},
        {"Venus", 4.8675e24, 6051800, 0.7233*AU, 0, 0, -35000},
        {"Earth", 5.9724e24, 6371000, AU, 0, 0, 29783},
        {"Mars", 6.4171e23, 3396200, 0, 1.524*AU, -24000, 0},
        {"Jupiter", 1.8982e27, 71492000, 5.203*AU, 0, 0, -13070},
        {"Saturn", 5.6834e26, 60268000, 9.539*AU, 0, 0, -9690},
        {"Uranus", 8.6810e25, 25559000, 19.18*AU, 0, 0, -6810},
        {"Neptune", 1.0241e26, 24764000, 30.07*AU, 0, 0, -5430}
    };
    int num_planets = 9;

    // simulate the solar system for 10 years with a timestep of 1 hour
    simulate(planets, num_planets, 3600, 10);

    return 0;
}