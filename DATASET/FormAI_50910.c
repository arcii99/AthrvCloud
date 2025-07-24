//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

double sun_mass = 1.989e30; /* in kg */

struct Vector3 {
    double x;
    double y;
    double z;
};

struct Body {
    double mass; /* in kg */
    struct Vector3 position;
    struct Vector3 velocity;
};

struct Body planets[NUM_PLANETS] = {
    /* mass, position (m), velocity (m/s) */
    {3.301e23, {-4.841e12, -1.160e12, 2.052e11}, {2.963e4, -1.171e4, -1.136e3}}, /* Mercury */
    {4.869e24, {-1.613e12, -5.775e11, 9.841e10}, {4.052e4, -1.498e4, -5.167e3}}, /* Venus */
    {5.974e24, {2.553e10, 1.459e11, -3.323e6}, {-2.939e4, 5.211e3, 1.192e0}}, /* Earth */
    {6.419e23, {2.205e12, -6.251e11, -4.261e10}, {1.389e4, 4.038e4, -6.624e2}}, /* Mars */
    {1.899e27, {7.074e11, -1.348e12, 7.568e9}, {8.500e3, 4.609e3, -1.999e2}}, /* Jupiter */
    {5.685e26, {6.315e11, -2.600e12, 1.389e10}, {5.292e3, 1.215e3, -1.659e2}}, /* Saturn */
    {8.682e25, {-2.738e12, -6.324e11, 4.097e10}, {1.381e3, -5.134e3, -1.490e2}}, /* Uranus */
    {1.024e26, {1.838e12, 9.383e11, -8.566e10}, {-2.189e3, 5.096e3, 1.107e2}} /* Neptune */
};

double G = 6.6743e-11; /* gravitational constant */

void update_planets(double delta_t) {
    struct Vector3 acceleration[NUM_PLANETS] = {{0}}; /* initialize to zero vector */
    
    /* calculate accelerations due to gravity from other planets */
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue; /* skip self-gravity */
            double r = sqrt(pow(planets[i].position.x - planets[j].position.x, 2) +
                            pow(planets[i].position.y - planets[j].position.y, 2) +
                            pow(planets[i].position.z - planets[j].position.z, 2));
            double F = G * planets[i].mass * planets[j].mass / pow(r, 2);
            struct Vector3 direction = {(planets[j].position.x - planets[i].position.x) / r,
                                        (planets[j].position.y - planets[i].position.y) / r,
                                        (planets[j].position.z - planets[i].position.z) / r};
            acceleration[i].x += F / planets[i].mass * direction.x;
            acceleration[i].y += F / planets[i].mass * direction.y;
            acceleration[i].z += F / planets[i].mass * direction.z;
        }
    }

    /* update positions and velocities */
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].position.x += planets[i].velocity.x * delta_t;
        planets[i].position.y += planets[i].velocity.y * delta_t;
        planets[i].position.z += planets[i].velocity.z * delta_t;

        planets[i].velocity.x += acceleration[i].x * delta_t;
        planets[i].velocity.y += acceleration[i].y * delta_t;
        planets[i].velocity.z += acceleration[i].z * delta_t;
    }
}

void print_planets() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: mass = %.2e kg, position = (%.2e, %.2e, %.2e) m, velocity = (%.2e, %.2e, %.2e) m/s\n",
               i, planets[i].mass, planets[i].position.x, planets[i].position.y, planets[i].position.z,
               planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
    }
}

int main() {
    double time = 0;
    double delta_t = 1000; /* in seconds */

    while (time < 3.154e7 * 10) { /* simulate 10 years */
        printf("Time: %.2e seconds\n", time);

        update_planets(delta_t);
        print_planets();

        time += delta_t;
        printf("\n");
    }

    return 0;
}