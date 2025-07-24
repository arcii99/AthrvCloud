//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11  //Gravitational constant
#define INTERVAL 0.01  //Time interval
#define MAX_STEPS 100000  //Maximum simulation steps
#define MASS_EARTH 5.97e24  //Earth mass
#define MASS_MOON 7.342e22  //Moon mass
#define RADIUS_EARTH 6.37e6  //Earth radius
#define RADIUS_MOON 1.74e6  //Moon radius

struct Vector {  //Vector structure to store position and velocity
    double x, y;
    double vx, vy;
};

struct Body {  //Body structure to define each celestial object
    char name[20];
    double mass;
    double radius;
    struct Vector pos;
    struct Vector vel;
};

void calculate_acceleration(struct Body *b1, struct Body *b2, struct Vector *a) {  //Calculates acceleration due to gravity
    double distance = sqrt(pow(b1->pos.x - b2->pos.x, 2) + pow(b1->pos.y - b2->pos.y, 2));
    double force = G * b1->mass * b2->mass / pow(distance, 2);
    a->x = (b2->pos.x - b1->pos.x) / distance * force / b1->mass;
    a->y = (b2->pos.y - b1->pos.y) / distance * force / b1->mass;
}

void update_velocity(struct Body *b, struct Vector *a, double interval) {  //Updates velocity based on acceleration
    b->vel.vx += a->x * interval;
    b->vel.vy += a->y * interval;
}

void update_position(struct Body *b, double interval) {  //Updates position based on velocity
    b->pos.x += b->vel.vx * interval;
    b->pos.y += b->vel.vy * interval;
}

void simulate(struct Body *b1, struct Body *b2) {  //Main simulation function
    struct Vector acceleration;
    for (int i = 0; i < MAX_STEPS; i++) {
        calculate_acceleration(b1, b2, &acceleration);
        update_velocity(b1, &acceleration, INTERVAL);
        update_position(b1, INTERVAL);
        calculate_acceleration(b2, b1, &acceleration);
        update_velocity(b2, &acceleration, INTERVAL);
        update_position(b2, INTERVAL);
        printf("Step %d: %s position = (%.2f, %.2f), %s position = (%.2f, %.2f)\n",
                i+1, b1->name, b1->pos.x/1e6, b1->pos.y/1e6, b2->name, b2->pos.x/1e6, b2->pos.y/1e6);
    }
}

int main() {
    struct Body earth = {"Earth", MASS_EARTH, RADIUS_EARTH, {0, 0, 0, 0}};
    struct Body moon = {"Moon", MASS_MOON, RADIUS_MOON, {3.84e8, 0, 0, 1022}};
    printf("Starting simulation of %s and %s\n", earth.name, moon.name);
    simulate(&earth, &moon);
    return 0;
}