//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11
#define M_SUN 1.989e30
#define M_EARTH 5.972e24
#define M_MOON 7.342e22
#define AU 1.496e11

typedef struct {
    double x, y;
} Vector;

typedef struct {
    char* name;
    double mass;
    double radius;
    Vector position;
    Vector velocity;
} Body;

Body sun = {"Sun", M_SUN,696340000.0, {0, 0}, {0, 0}};
Body earth = {"Earth", M_EARTH, 6371000.0, {AU, 0}, {0, 29783}};
Body moon = {"Moon", M_MOON, 1737100.0, {AU + 384400000.0, 0}, {0, 3057}};

void update_position(Body* body, double dt) {
    body->position.x += dt * body->velocity.x;
    body->position.y += dt * body->velocity.y;
}

double get_distance(Vector v1, Vector v2) {
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    return  sqrt(dx*dx + dy*dy);
}

void update_velocity(Body* body1, Body* body2, double dt) {
    double F = G * body1->mass * body2->mass / pow(get_distance(body1->position, body2->position), 2);
    double fx = F * (body2->position.x - body1->position.x) / get_distance(body1->position, body2->position);
    double fy = F * (body2->position.y - body1->position.y) / get_distance(body1->position, body2->position);
    body1->velocity.x += dt * fx / body1->mass;
    body1->velocity.y += dt * fy / body1->mass;
}

int main() {

    int steps = 365;
    double dt = 24 * 3600.0 / steps;

    for(int i=0; i<steps; i++) {

        update_velocity(&earth, &sun, dt);
        update_position(&earth, dt);

        update_velocity(&moon, &earth, dt);
        update_velocity(&moon, &sun, dt);
        update_position(&moon, dt);

        update_velocity(&earth, &moon, dt);
        update_position(&earth, dt);

        double distance = get_distance(earth.position, sun.position);
        double distance_moon = get_distance(moon.position, earth.position);

        printf("Day %d: Earth(%f, %f) - %f\n", i+1, earth.position.x, earth.position.y, distance / AU);
        printf("Day %d: Moon(%f, %f) - %f\n", i+1, moon.position.x, moon.position.y, distance_moon / earth.radius);
    }

    return 0;
}