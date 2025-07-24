//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define AU 1.495978707e11 // Astronomical unit

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    double mass;
    Vector2D position;
    Vector2D velocity;
} Body;

double distance(Body* body1, Body* body2) {
    double dx = body1->position.x - body2->position.x;
    double dy = body1->position.y - body2->position.y;
    return sqrt(dx * dx + dy * dy);
}

Vector2D direction(Body* body1, Body* body2) {
    Vector2D dir;
    double dist = distance(body1, body2);
    dir.x = (body2->position.x - body1->position.x) / dist;
    dir.y = (body2->position.y - body1->position.y) / dist;
    return dir;
}

void gravity(Body* body1, Body* body2) {
    Vector2D dir = direction(body1, body2);
    double dist = distance(body1, body2);
    double force = G * body1->mass * body2->mass / (dist * dist);
    double fx = force * dir.x;
    double fy = force * dir.y;
    body1->velocity.x += fx / body1->mass;
    body1->velocity.y += fy / body1->mass;
    body2->velocity.x -= fx / body2->mass;
    body2->velocity.y -= fy / body2->mass;
}

int main() {
    Body sun = { 1.9885e30, { 0, 0 }, { 0, 0 } };
    Body earth = { 5.97237e24, { AU, 0 }, { 0, 29.783e3 } };
    Body moon = { 7.342e22, { AU + 384400e3, 0 }, { 0, 29.783e3 + 1022 } };

    double time_step = 3600; // 1 hour in seconds
    for (int i = 0; i < 365 * 24; i++) {
        gravity(&sun, &earth);
        gravity(&sun, &moon);
        gravity(&earth, &moon);

        earth.position.x += earth.velocity.x * time_step;
        earth.position.y += earth.velocity.y * time_step;
        moon.position.x += moon.velocity.x * time_step;
        moon.position.y += moon.velocity.y * time_step;
        
        printf("Day %d: Earth (%f, %f) Moon (%f, %f)\n", i + 1, earth.position.x / AU, earth.position.y / AU, moon.position.x / AU, moon.position.y / AU);
    }
    
    return 0;
}