//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1.0)

#define GRAVITY 6.67384e-11

#define SUN_MASS 1.989e30
#define EARTH_MASS 5.972e24
#define MOON_MASS 7.342e22

#define AU 149.6e9 // Astronomical Unit

struct Vector {
    double x, y, z;
};

struct Object {
    struct Vector position;
    struct Vector velocity;
    double mass;
};

void calculate_force(struct Object *obj1, struct Object *obj2, struct Vector *force) {
    double distance, magnitude;

    force->x = obj2->position.x - obj1->position.x;
    force->y = obj2->position.y - obj1->position.y;
    force->z = obj2->position.z - obj1->position.z;

    distance = sqrt(force->x * force->x + force->y * force->y + force->z * force->z);
    magnitude = GRAVITY * obj1->mass * obj2->mass / (distance * distance);

    force->x *= magnitude / distance;
    force->y *= magnitude / distance;
    force->z *= magnitude / distance;
}

void update_position(struct Object *obj, struct Vector force, double time_step) {
    obj->velocity.x += force.x / obj->mass * time_step;
    obj->velocity.y += force.y / obj->mass * time_step;
    obj->velocity.z += force.z / obj->mass * time_step;

    obj->position.x += obj->velocity.x * time_step;
    obj->position.y += obj->velocity.y * time_step;
    obj->position.z += obj->velocity.z * time_step;
}

void print_object(struct Object *obj) {
    printf("Position (m): (%f, %f, %f)\n", obj->position.x, obj->position.y, obj->position.z);
}

void simulate() {
    struct Object sun, earth, moon;
    struct Vector force;

    sun.mass = SUN_MASS;

    earth.position.x = -1 * AU;
    earth.velocity.y = 30000;
    earth.mass = EARTH_MASS;

    moon.position.x = earth.position.x - 384400000;
    moon.velocity.y = earth.velocity.y + 1022;
    moon.mass = MOON_MASS;

    double time = 0;
    double time_step = 60 * 60 * 24; // 1 day

    while (time < 5 * 365 * 24 * 60 * 60) { // 5 years
        calculate_force(&sun, &earth, &force);
        update_position(&earth, force, time_step);

        calculate_force(&earth, &moon, &force);
        update_position(&moon, force, time_step);

        if (((int) time) % (365 * 24 * 60 * 60) == 0) { // Print once per year
            printf("Year %d:\n", (int) (time / (365 * 24 * 60 * 60)));
            printf("Sun:\n");
            print_object(&sun);
            printf("Earth:\n");
            print_object(&earth);
            printf("Moon:\n");
            print_object(&moon);
        }

        time += time_step;
    }
}

int main() {
    printf("Welcome to the simulation of the solar system!\n");
    printf("Unfortunately, the apocalypse has left Earth uninhabitable, but with our advanced technology, we can still explore the universe.\n");
    printf("Let's see what our solar system looks like after five years of travel.\n");
    printf("\n");

    simulate();

    printf("\n");
    printf("Thanks for exploring with us!\n");

    return 0;
}