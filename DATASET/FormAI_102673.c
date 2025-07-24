//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define MASS_EARTH 5.98e24 // mass of Earth
#define RADIUS_EARTH 6.38e6 // radius of Earth

/*
 * struct to represent planet
 */
typedef struct {
    double mass; // mass of planet
    double x; // x-coordinate of position
    double y; // y-coordinate of position
    double vx; // x-component of velocity
    double vy; // y-component of velocity
} planet_t;

/*
 * function to calculate distance between two planets
 */
double distance(planet_t p1, planet_t p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/*
 * function to calculate gravitational force between two planets
 */
double force(planet_t p1, planet_t p2) {
    double dist = distance(p1, p2);
    return (G * p1.mass * p2.mass) / pow(dist, 2);
}

/*
 * function to calculate acceleration of planet
 */
void acceleration(planet_t *p, planet_t *planets, int num_planets) {
    double ax = 0;
    double ay = 0;

    for (int i = 0; i < num_planets; i++) {
        if (p != &planets[i]) { // don't calculate force on itself
            double f = force(*p, planets[i]);
            double ang = atan2(planets[i].y - p->y, planets[i].x - p->x); // angle between planets

            ax += (f / p->mass) * cos(ang);
            ay += (f / p->mass) * sin(ang);
        }
    }

    p->vx += ax;
    p->vy += ay;
}

/*
 * function to update position of planet
 */
void update_position(planet_t *p) {
    p->x += p->vx;
    p->y += p->vy;
}

/*
 * main function
 */
int main() {
    planet_t earth = {MASS_EARTH, RADIUS_EARTH, 0, 0, 0};
    planet_t moon = {7.36e22, RADIUS_EARTH + 3.84e8, 0, 0, 1022}; // mass of moon and distance from Earth

    planet_t planets[] = {earth, moon};
    int num_planets = sizeof(planets) / sizeof(planet_t);

    double time = 0;

    while (1) {
        // update velocity and position of planets
        for (int i = 0; i < num_planets; i++) {
            acceleration(&planets[i], planets, num_planets);
            update_position(&planets[i]);
        }

        time += 1; // increase time by 1 second

        printf("Time: %.0f seconds\n", time);
        printf("Earth: x=%.2f, y=%.2f, vx=%.2f, vy=%.2f\n", earth.x, earth.y, earth.vx, earth.vy);
        printf("Moon: x=%.2f, y=%.2f, vx=%.2f, vy=%.2f\n", moon.x, moon.y, moon.vx, moon.vy);
        printf("----------------------------\n");
    }

    return 0;
}