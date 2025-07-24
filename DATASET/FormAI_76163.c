//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#include <math.h>

// Define system constants
#define G 6.67430e-11
#define YEAR 3.1536e7

// Define Planet struct
typedef struct {
    char name[15];
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Planet;

// Define function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    // Define the planets
    Planet sun = {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Planet mercury = {"Mercury", 3.285e23, 0.387098, 0.0, 0.0, 0.0, 47.87e3, 0.0};
    Planet venus = {"Venus", 4.8675e24, 0.723332, 0.0, 0.0, 0.0, 35.02e3, 0.0};
    Planet earth = {"Earth", 5.972e24, 1.0, 0.0, 0.0, 0.0, 29.78e3, 0.0};
    Planet mars = {"Mars", 6.39e23, 1.524, 0.0, 0.0, 0.0, 24.077e3, 0.0};

    Planet planets[] = {sun, mercury, venus, earth, mars};
    int num_planets = sizeof(planets) / sizeof(Planet);

    // Define simulation parameters
    double dt = 1 * YEAR;
    double t_max = 5 * YEAR;

    // Run simulation
    for (double t = 0; t < t_max; t += dt) {
        // Update planet positions
        for (int i = 1; i < num_planets; i++) {
            Planet p1 = planets[i];
            double fx = 0, fy = 0, fz = 0;
            for (int j = 0; j < num_planets; j++) {
                if (j != i) {
                    Planet p2 = planets[j];
                    double d = distance(p1, p2);
                    double force = G * p1.mass * p2.mass / (d * d);
                    fx += force * (p2.x - p1.x) / d;
                    fy += force * (p2.y - p1.y) / d;
                    fz += force * (p2.z - p1.z) / d;
                }
            }
            p1.vx += fx / p1.mass * dt;
            p1.vy += fy / p1.mass * dt;
            p1.vz += fz / p1.mass * dt;
            p1.x += p1.vx * dt;
            p1.y += p1.vy * dt;
            p1.z += p1.vz * dt;
            planets[i] = p1;
        }

        // Print planet positions
        printf("t = %fs\n", t);
        for (int i = 0; i < num_planets; i++) {
            Planet p = planets[i];
            printf("%s: (%.0fm, %.0fm, %.0fm)\n", p.name, p.x, p.y, p.z);
        }
        printf("\n");
    }

    return 0;
}