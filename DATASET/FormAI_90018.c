//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 0.000001 // Gravitational constant (scaled down to make simulation faster)
#define TIME_INTERVAL 10 // Time interval for simulation (in seconds)

typedef struct vec3d { // 3D Vector
    double x, y, z;
} vec3d;

typedef struct planet { // Planet properties
    char name[20];
    double mass; // kg
    double radius; // m
    vec3d position; // m
    vec3d velocity; // m/s
} planet;

vec3d add_vec3d(vec3d a, vec3d b) { // Add vectors a and b
    return (vec3d) { a.x + b.x, a.y + b.y, a.z + b.z };
}

vec3d sub_vec3d(vec3d a, vec3d b) { // Subtract vectors a and b
    return (vec3d) { a.x - b.x, a.y - b.y, a.z - b.z };
}

vec3d mul_vec3d(vec3d a, double b) { // Multiply vector a by scalar b
    return (vec3d) { a.x * b, a.y * b, a.z * b };
}

double mag_vec3d(vec3d a) { // Magnitude of vector a
    return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

vec3d norm_vec3d(vec3d a) { // Normalize vector a
    double mag = mag_vec3d(a);
    return (vec3d) { a.x / mag, a.y / mag, a.z / mag };
}

vec3d gravity(planet a, planet b) { // Gravitational force between planets a and b
    vec3d force, ab;
    double distance, magnitude;
    ab = sub_vec3d(a.position, b.position);
    distance = mag_vec3d(ab);
    magnitude = G * ((a.mass * b.mass) / pow(distance, 2));
    force = mul_vec3d(norm_vec3d(ab), magnitude);
    return force;
}

void simulate_planets(planet *planets, int num_planets, double time) { // Simulate all planets for given time
    int i, j;
    vec3d acceleration, force;
    planet *p1, *p2;
    for (i = 0; i < num_planets; i++) {
        p1 = &planets[i];
        acceleration = (vec3d) { 0, 0, 0 };
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                p2 = &planets[j];
                force = gravity(*p1, *p2);
                acceleration = add_vec3d(acceleration, mul_vec3d(force, 1 / p1->mass));
            }
        }
        p1->velocity = add_vec3d(p1->velocity, mul_vec3d(acceleration, time));
        p1->position = add_vec3d(p1->position, mul_vec3d(p1->velocity, time));
    }
}

void print_planets(planet *planets, int num_planets) { // Print planet information
    int i;
    printf("--------------------------------------------------------\n");
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: %s\n", i+1, planets[i].name);
        printf("Mass: %.3e kg\n", planets[i].mass);
        printf("Radius: %.3e m\n", planets[i].radius);
        printf("Position (x, y, z): (%.3e, %.3e, %.3e) m\n", planets[i].position.x, planets[i].position.y, planets[i].position.z);
        printf("Velocity (x, y, z): (%.3e, %.3e, %.3e) m/s\n", planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
        printf("--------------------------------------------------------\n");
    }
}

int main() {
    planet planets[] = { // Create planets and set initial properties
        { "Sun", 1.988544e30, 696340e3, { 0, 0, 0 }, { 0, 0, 0 } },
        { "Mercury", 3.285e23, 2439.7e3, { 57.91e9, 0, 0 }, { 0, 47.87e3, 0 } },
        { "Venus", 4.867e24, 6051.8e3, { 108.2e9, 0, 0 }, { 0, 35.02e3, 0 } },
        { "Earth", 5.97219e24, 6371.01e3, { 149.6e9, 0, 0 }, { 0, 29.78e3, 0 } },
        { "Mars", 6.39e23, 3389.5e3, { 227.9e9, 0, 0 }, { 0, 24.077e3, 0 } },
        { "Jupiter", 1.898e27, 69911e3, { 778.5e9, 0, 0 }, { 0, 13.07e3, 0 } },
        { "Saturn", 5.683e26, 58232e3, { 1433.5e9, 0, 0 }, { 0, 9.69e3, 0 } },
        { "Uranus", 8.6810e25, 25362e3, { 2872.5e9, 0, 0 }, { 0, 6.81e3, 0 } },
        { "Neptune", 1.024e26, 24622e3, { 4495.1e9, 0, 0 }, { 0, 5.43e3, 0 } },
    };
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    int i;
    for (i = 0; i < 1000000; i++) { // Simulate for 1 million time intervals
        simulate_planets(planets, num_planets, TIME_INTERVAL);
        if (i % 1000 == 0) { // Print planet information every 1000 time intervals
            print_planets(planets, num_planets);
        }
    }
    return 0;
}