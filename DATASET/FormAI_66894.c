//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: visionary
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

// Struct to hold planet data
typedef struct {
    char name[10];
    double mass;    // kg
    double radius;  // km
    double dist;    // km
    double theta;   // radians
    double omega;   // radians per day
    double eccentricity;
} Planet;

// Constants
const double G = 6.67430e-11; // gravitational constant in m^3 kg^-1 s^-2
const double SUN_MASS = 1.989e30; // kg
const double SUN_RADIUS = 695700; // km
const double AU = 149.6e6; // km (1 astronomical unit)
const double DAY = 86400.0; // seconds

// Function prototypes
void initialize_planets(Planet* planets);
void update_positions(Planet* planets, double dt);

int main() {
    Planet planets[NUM_PLANETS];
    double dt = 0.01 * DAY; // time step size (in seconds)

    initialize_planets(planets);

    // Simulation loop
    for (int i = 0; i < 36500; i++) {
        update_positions(planets, dt);
    }

    // Print final positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%f, %f)\n", planets[i].name, planets[i].dist * cos(planets[i].theta), planets[i].dist * sin(planets[i].theta));
    }

    return 0;
}

void initialize_planets(Planet* planets) {
    // Data from NASA
    // https://nssdc.gsfc.nasa.gov/planetary/factsheet/

    Planet sun = { "Sun", SUN_MASS, SUN_RADIUS, 0, 0, 0, 0 };
    planets[0] = sun;

    Planet mercury = { "Mercury", 0.330e24, 2439.7, 0.3871 * AU, 0, 2.408 / DAY, 0.205 };
    planets[1] = mercury;

    Planet venus = { "Venus", 4.87e24, 6051.8, 0.7233 * AU, 0, 6.052 / DAY, 0.007 };
    planets[2] = venus;

    Planet earth = { "Earth", 5.97e24, 6371.0, 1.000 * AU, 0, 1.000 / DAY, 0.017 };
    planets[3] = earth;

    Planet mars = { "Mars", 0.642e24, 3389.5, 1.5237 * AU, 0, 0.531 / DAY, 0.094 };
    planets[4] = mars;

    Planet jupiter = { "Jupiter", 1898e24, 69911, 5.2029 * AU, 0, 0.084 / DAY, 0.049 };
    planets[5] = jupiter;

    Planet saturn = { "Saturn", 568e24, 58232, 9.5388 * AU, 0, 0.034 / DAY, 0.057 };
    planets[6] = saturn;

    Planet uranus = { "Uranus", 86.8e24, 25362, 19.1914 * AU, 0, 0.012 / DAY, 0.046 };
    planets[7] = uranus;

    // Start all planets off at perihelion
    for (int i = 1; i < NUM_PLANETS; i++) {
        double r = planets[i].dist * (1 - planets[i].eccentricity);
        planets[i].theta = acos(-1.0) - (acos(r / planets[i].dist) - planets[i].eccentricity * sin(acos(r / planets[i].dist)));
    }
}

void update_positions(Planet* planets, double dt) {
    double x[NUM_PLANETS] = { 0 };
    double y[NUM_PLANETS] = { 0 };
    double fx[NUM_PLANETS] = { 0 };
    double fy[NUM_PLANETS] = { 0 };

    // Calculate force on each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i == j) {
                continue;
            }

            double dx = planets[j].dist * cos(planets[j].theta) - planets[i].dist * cos(planets[i].theta);
            double dy = planets[j].dist * sin(planets[j].theta) - planets[i].dist * sin(planets[i].theta);
            double r = sqrt(dx * dx + dy * dy);
            double f = G * planets[i].mass * planets[j].mass / (r * r);

            fx[i] += f * dx / r;
            fy[i] += f * dy / r;
        }
    }

    // Update positions and velocities
    for (int i = 0; i < NUM_PLANETS; i++) {
        x[i] = planets[i].dist * cos(planets[i].theta);
        y[i] = planets[i].dist * sin(planets[i].theta);

        double ax = fx[i] / planets[i].mass;
        double ay = fy[i] / planets[i].mass;

        planets[i].omega += sqrt(ax * ax + ay * ay) * dt;
        planets[i].theta += planets[i].omega * dt;

        while (planets[i].theta < 0) {
            planets[i].theta += 2 * acos(-1.0);
        }
        while (planets[i].theta >= 2 * acos(-1.0)) {
            planets[i].theta -= 2 * acos(-1.0);
        }

        planets[i].dist = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
}