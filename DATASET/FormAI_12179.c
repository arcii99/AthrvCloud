//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

struct planet {
    char name[20];
    double mass; // mass in kg
    double radius; // radius in km
    double distance; // distance from sun in km
    double velocity; // velocity in km/s
    double angle; // angle in radians
};

struct planet planets[NUM_PLANETS] = {
    {"Mercury", 3.301e23, 2439.7, 57909100, 47.36, 0},
    {"Venus", 4.867e24, 6051.8, 108208930, 35.02, 0},
    {"Earth", 5.972e24, 6371, 149597870, 29.78, 0},
    {"Mars", 6.417e23, 3389.5, 227936640, 24.077, 0},
    {"Jupiter", 1.898e27, 69911, 778369000, 13.07, 0},
    {"Saturn", 5.683e26, 58232, 1427034000, 9.69, 0},
    {"Uranus", 8.681e25, 25362, 2870658186, 6.81, 0},
    {"Neptune", 1.024e26, 24622, 4498396441, 5.43, 0}
};

const double G = 6.673e-11; // gravitational constant in m^3 kg^-1 s^-2
const double TIME_STEP = 86400; // time step in seconds (1 day)

void update_position(struct planet *p) {
    double x, y;
    double radius = p->distance;
    double angle = p->angle;
    x = radius * cos(angle);
    y = radius * sin(angle);
    printf("%s: x=%.2f km, y=%.2f km\n", p->name, x, y);
}

void update_velocity(struct planet *p) {
    double force = 0;
    int i;
    for (i=0; i<NUM_PLANETS; i++) {
        if (p != &planets[i]) { // exclude self
            double distance = sqrt(pow(p->distance, 2) + pow(planets[i].distance, 2) - 2 * p->distance * planets[i].distance * cos(p->angle - planets[i].angle));
            force += G * p->mass * planets[i].mass / pow(distance, 2);
        }
    }
    double acceleration = force / p->mass;
    p->velocity += acceleration * TIME_STEP;
    printf("%s: velocity=%.2f km/s\n", p->name, p->velocity);
}

void update_angle(struct planet *p) {
    double distance = p->distance;
    double velocity = p->velocity * 1000; // convert to m/s
    double period = 2 * M_PI * distance / velocity;
    p->angle = fmod(p->angle + TIME_STEP / period, 2 * M_PI);
}

int main(void) {
    int i;
    for (i=0; i<NUM_PLANETS; i++) {
        struct planet *p = &planets[i];
        printf("%s:\n", p->name);
        update_position(p);
        update_velocity(p);
        update_angle(p);
        printf("\n");
    }
    return 0;
}