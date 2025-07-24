//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67384e-11 // Gravitational constant in N*(m/kg)^2
#define INTERVAL 86400 // Simulation interval in seconds
#define SIMULATION_TIME 31536000 // Total simulation time in seconds

typedef struct vector {
    double x;
    double y;
} vector;

typedef struct planet {
    char* name;
    double mass;
    vector position;
    vector velocity;
    vector acceleration;
} planet;

vector add_vectors(vector a, vector b) {
    vector result = {a.x + b.x, a.y + b.y};
    return result;
}

vector subtract_vectors(vector a, vector b) {
    vector result = {a.x - b.x, a.y - b.y};
    return result;
}

double magnitude(vector a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

vector scale_vector(vector a, double d) {
    vector result = {a.x * d, a.y * d};
    return result;
}

vector calculate_gravitational_force(planet p1, planet p2) {
    vector distance = subtract_vectors(p1.position, p2.position);
    double r = magnitude(distance);
    double f = G * p1.mass * p2.mass / (r * r);
    return scale_vector(distance, -f / r);
}

void update_planet(planet* p, vector force) {
    p->acceleration = scale_vector(force, 1 / p->mass);
    p->velocity = add_vectors(p->velocity, scale_vector(p->acceleration, INTERVAL));
    p->position = add_vectors(p->position, scale_vector(p->velocity, INTERVAL));
}

void simulate_planet_gravity(planet* planets, int num_planets) {
    int i, j;
    for (i = 0; i < num_planets; i++) {
        vector force = {0, 0};
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                vector f = calculate_gravitational_force(planets[i], planets[j]);
                force = add_vectors(force, f);
            }
        }
        update_planet(&planets[i], force);
    }
}

int main() {
    planet sun = {"Sun", 1.989e30, {0, 0}, {0, 0}, {0, 0}};
    planet earth = {"Earth", 5.972e24, {1.495e11, 0}, {0, 29783}, {0, 0}};
    planet moon = {"Moon", 7.342e22, {1.495e11 + 3.844e8, 0}, {0, 29783 + 1022}, {0, 0}};
    planet mars = {"Mars", 6.39e23, {2.279e11, 0}, {0, 24007}, {0, 0}};
    planet planets[] = {sun, earth, moon, mars};
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    int num_iterations = SIMULATION_TIME / INTERVAL;
    int i, j;
    for (i = 0; i < num_iterations; i++) {
        simulate_planet_gravity(planets, num_planets);
        for (j = 0; j < num_planets; j++) {
            printf("%s: (%f, %f)\n", planets[j].name, planets[j].position.x, planets[j].position.y);
        }
        printf("\n");
    }
    return 0;
}