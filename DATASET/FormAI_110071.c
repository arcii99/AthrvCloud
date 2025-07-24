//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define SUN_MASS 1.989e30 // Mass of the sun


/* Struct for representing a planet */
typedef struct planet_struct {
    double x; // x-coordinate
    double y; // y-coordinate
    double z; // z-coordinate
    double vx; // velocity in x-direction
    double vy; // velocity in y-direction
    double vz; // velocity in z-direction
    double mass; // planet's mass
} planet;


/* Function to calculate distance between two planets */
double distance(planet p1, planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}


/* Function to calculate gravitational force between two planets */
double gravitational_force(double m1, double m2, double r) {
    return G * m1 * m2 / (r * r);
}


/* Function to calculate gravitational force on a planet by all other planets */
void calculate_gravitational_forces(planet *p, planet *planets, int num_planets) {
    p->vx = 0;
    p->vy = 0;
    p->vz = 0;
    for (int i = 0; i < num_planets; i++) {
        if (p != &planets[i]) { // planet does not exert force on itself
            double d = distance(*p, planets[i]);
            double f = gravitational_force(p->mass, planets[i].mass, d);
            double dx = planets[i].x - p->x;
            double dy = planets[i].y - p->y;
            double dz = planets[i].z - p->z;
            p->vx += f * dx / d / p->mass;
            p->vy += f * dy / d / p->mass;
            p->vz += f * dz / d / p->mass;
        }
    }
}


/* Function to update a planet's position based on the gravitational forces */
void update_position(planet *p, double step_size) {
    p->x += p->vx * step_size;
    p->y += p->vy * step_size;
    p->z += p->vz * step_size;
}


int main() {
    int num_planets = 4;
    double step_size = 3600; // 1 hour in seconds

    planet planets[num_planets];
    planets[0] = (planet) {0, 0, 0, 0, 0, 0, SUN_MASS}; // Sun
    planets[1] = (planet) {149.6e9, 0, 0, 0, 29.29e3, 0, 5.97e24}; // Earth
    planets[2] = (planet) {0, -778.5e9, 0, -47.87e3, 0, 0, 1.90e27}; // Jupiter
    planets[3] = (planet) {-1.4e11, 1.5e11, 0, 25.60e3, -23.08e3, 0, 0.64e24}; // Mars

    for (int i = 0; i < num_planets; i++) {
        calculate_gravitational_forces(&planets[i], planets, num_planets);
    }

    // Simulation loop
    for (int i = 0; i < 8760; i++) { // 1 year (8760 hours)
        for (int j = 0; j < num_planets; j++) {
            update_position(&planets[j], step_size);
            calculate_gravitational_forces(&planets[j], planets, num_planets);
        }
        printf("Year: %d\n", i+1);
        printf("Sun position: (%lf, %lf, %lf)\n", planets[0].x, planets[0].y, planets[0].z);
        printf("Earth position: (%lf, %lf, %lf)\n", planets[1].x, planets[1].y, planets[1].z);
        printf("Jupiter position: (%lf, %lf, %lf)\n", planets[2].x, planets[2].y, planets[2].z);
        printf("Mars position: (%lf, %lf, %lf)\n", planets[3].x, planets[3].y, planets[3].z);
        printf("\n");
    }

    return 0;
}