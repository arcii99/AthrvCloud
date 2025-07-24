//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <math.h>

#define GRAVITY 6.67408E-11 // gravitational constant
#define SUN_MASS 1.989E30 // mass of the sun
#define TIME_STEP 86400 // 1 day in seconds

// define a struct for each planet in the solar system
typedef struct Planet {
    char name[20]; // name of the planet
    double mass; // mass of the planet
    double radius; // radius of the planet
    double x; // x-coordinate of the planet's position
    double y; // y-coordinate of the planet's position
    double vx; // x-component of velocity of the planet
    double vy; // y-component of velocity of the planet
} Planet;

int main() {
    // define the planets in the solar system
    Planet sun = {"Sun", SUN_MASS, 696340000, 0, 0, 0, 0};
    Planet mercury = {"Mercury", 3.285E23, 4879000, 0, 57909050000, 47888, 0};
    Planet venus = {"Venus", 4.867E24, 6051000, 0, 108208930000, 35022, 0};
    Planet earth = {"Earth", 5.972E24, 6371000, 0, 149597870000, 29783, 0};
    Planet mars = {"Mars", 6.39E23, 3389500, 0, 227939100000, 24077, 0};
    Planet jupiter = {"Jupiter", 1.898E27, 69911000, 0, 778547200000, 13069, 0};
    Planet saturn = {"Saturn", 5.683E26, 58232000, 0, 1433449370000, 9644, 0};
    Planet uranus = {"Uranus", 8.681E25, 25362000, 0, 2876679082000, 6810, 0};
    Planet neptune = {"Neptune", 1.024E26, 24622000, 0, 4498252900000, 5434, 0};

    // simulate the solar system for 1 year
    int days = 365;
    int i, j;
    for (i = 0; i < days; i++) {
        // calculate the gravitational forces between each planet
        Planet planets[] = {mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
        int num_planets = sizeof(planets) / sizeof(Planet);
        double fx[num_planets], fy[num_planets];
        for (j = 0; j < num_planets; j++) {
            // calculate the distance between the planets
            double dx = planets[j].x - sun.x;
            double dy = planets[j].y - sun.y;
            double distance = sqrt(dx*dx + dy*dy);

            // calculate the gravitational force
            double force = GRAVITY * sun.mass * planets[j].mass / (distance * distance);

            // calculate the x and y components of the force
            fx[j] = force * (dx / distance);
            fy[j] = force * (dy / distance);
        }

        // update the position and velocity of each planet
        for (j = 0; j < num_planets; j++) {
            // calculate the net force on the planet
            double net_fx = -fx[j];
            double net_fy = -fy[j];
            int k;
            for (k = 0; k < num_planets; k++) {
                if (k != j) {
                    // calculate the distance between the planets
                    double dx = planets[j].x - planets[k].x;
                    double dy = planets[j].y - planets[k].y;
                    double distance = sqrt(dx*dx + dy*dy);

                    // calculate the gravitational force
                    double force = GRAVITY * planets[k].mass * planets[j].mass / (distance * distance);

                    // calculate the x and y components of the force
                    net_fx += force * (dx / distance);
                    net_fy += force * (dy / distance);
                }
            }

            // calculate the acceleration of the planet
            double ax = net_fx / planets[j].mass;
            double ay = net_fy / planets[j].mass;

            // update the velocity of the planet
            planets[j].vx += ax * TIME_STEP;
            planets[j].vy += ay * TIME_STEP;

            // update the position of the planet
            planets[j].x += planets[j].vx * TIME_STEP;
            planets[j].y += planets[j].vy * TIME_STEP;
        }

        // print the position of each planet
        printf("Day %d:\n", i+1);
        for (j = 0; j < num_planets; j++) {
            printf("%s: (%.2e, %.2e)\n", planets[j].name, planets[j].x, planets[j].y);
        }
        printf("\n");
    }

    return 0;
}