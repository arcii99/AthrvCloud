//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

// define the planets in our solar system

typedef struct {
    char *name;
    double radius;
    double mass;
    double x, y, z; // position
    double vx, vy, vz; // velocity
} Planet;

Planet sun = {
    .name = "Sun",
    .mass = 1.989e30,
    .radius = 696340e3,
    .x = 0, .y = 0, .z = 0,
    .vx = 0, .vy = 0, .vz = 0
};

Planet mercury = {
    .name = "Mercury",
    .mass = 3.3e23,
    .radius = 2439.7e3,
    .x = 69.8e9, .y = 0, .z = 0,
    .vx = 0, .vy = 38.9e3, .vz = 0
};

Planet venus = {
    .name = "Venus",
    .mass = 4.87e24,
    .radius = 6051.8e3,
    .x = 108.9e9, .y = 0, .z = 0,
    .vx = 0, .vy = 35.0e3, .vz = 0
};

Planet earth = {
    .name = "Earth",
    .mass = 5.97e24,
    .radius = 6371e3,
    .x = 152.1e9, .y = 0, .z = 0,
    .vx = 0, .vy = 29.8e3, .vz = 0
};

Planet moon = {
    .name = "Moon",
    .mass = 7.342e22,
    .radius = 1737.4e3,
    .x = 152.1e9, .y = 384.4e6, .z = 0,
    .vx = -1022, .vy = 0, .vz = 0
};

Planet mars = {
    .name = "Mars",
    .mass = 6.42e23,
    .radius = 3389.5e3,
    .x = 249.2e9, .y = 0, .z = 0,
    .vx = 0, .vy = 24.1e3, .vz = 0
};

Planet jupiter = {
    .name = "Jupiter",
    .mass = 1.898e27,
    .radius = 69911e3,
    .x = 816.6e9, .y = 0, .z = 0,
    .vx = 0, .vy = 13.1e3, .vz = 0
};

Planet saturn = {
    .name = "Saturn",
    .mass = 5.68e26,
    .radius = 58232e3,
    .x = 1514.5e9, .y = 0, .z = 0,
    .vx = 0, .vy = 9.7e3, .vz = 0
};

Planet uranus = {
    .name = "Uranus",
    .mass = 8.68e25,
    .radius = 25362e3,
    .x = 3003.6e9, .y = 0, .z = 0,
    .vx = 0, .vy = 6.8e3, .vz = 0
};

Planet neptune = {
    .name = "Neptune",
    .mass = 1.02e26,
    .radius = 24622e3,
    .x = 4545.7e9, .y = 0, .z = 0,
    .vx = 0, .vy = 5.4e3, .vz = 0
};

// function to calculate the distance between two planets

double distance(Planet p1, Planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// function to update the velocity and position of a planet

void update(Planet *p, double dt, Planet *planets, int num_planets) {
    double ax = 0, ay = 0, az = 0;
    for (int i = 0; i < num_planets; i++) {
        if (p != &planets[i]) {
            double d = distance(*p, planets[i]);
            double f = G * p->mass * planets[i].mass / (d * d);
            ax += f * (planets[i].x - p->x) / d;
            ay += f * (planets[i].y - p->y) / d;
            az += f * (planets[i].z - p->z) / d;
        }
    }
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// function to print out planet positions and velocities

void print_state(Planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("%s\n", planets[i].name);
        printf("x: %f y: %f z: %f\n", planets[i].x, planets[i].y, planets[i].z);
        printf("vx: %f vy: %f vz: %f\n", planets[i].vx, planets[i].vy, planets[i].vz);
        printf("\n");
    }
}

int main() {
    Planet planets[] = {sun, mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune};
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    double dt = 86400; // time step of one day in seconds
    for (int i = 0; i < 365*5; i++) {
        for (int j = 0; j < num_planets; j++) {
            update(&planets[j], dt, planets, num_planets);
        }
    }
    print_state(planets, num_planets);
    return 0;
}