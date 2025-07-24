//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 6.67e-11
#define NUM_PLANETS 10
#define MAX_POS 10000
#define MAX_MASS 1000000
#define MAX_SPEED 100

typedef struct {
    double x, y;
} Vec2;

typedef struct {
    Vec2 pos, vel, acc;
    double mass;
} Planet;

double random_double(double max) {
    return ((double) rand() / (double) RAND_MAX) * max;
}

Vec2 random_vec(double max) {
    Vec2 vec;
    vec.x = random_double(max);
    vec.y = random_double(max);
    return vec;
}

double distance(Vec2 a, Vec2 b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Vec2 direction(Vec2 a, Vec2 b) {
    Vec2 d;
    double dist = distance(a, b);
    d.x = (b.x - a.x) / dist;
    d.y = (b.y - a.y) / dist;
    return d;
}

void update_acceleration(Planet planets[]) {
    int i, j;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].acc.x = 0;
        planets[i].acc.y = 0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            Vec2 dir = direction(planets[i].pos, planets[j].pos);
            double dist = distance(planets[i].pos, planets[j].pos);
            double F = GRAVITY * planets[i].mass * planets[j].mass / (dist * dist);
            double a = F / planets[i].mass;
            planets[i].acc.x += dir.x * a;
            planets[i].acc.y += dir.y * a;
        }
    }
}

void update_velocity(Planet planets[], double dt) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].vel.x += planets[i].acc.x * dt;
        planets[i].vel.y += planets[i].acc.y * dt;
    }
}

void update_position(Planet planets[], double dt) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].pos.x += planets[i].vel.x * dt;
        planets[i].pos.y += planets[i].vel.y * dt;
    }
}

void print_planets(Planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: x=%.2f y=%.2f mass=%.2f vx=%.2f vy=%.2f ax=%.2f ay=%.2f\n",
               i + 1, planets[i].pos.x, planets[i].pos.y, planets[i].mass, planets[i].vel.x, planets[i].vel.y, planets[i].acc.x, planets[i].acc.y);
    }
}

int main() {
    int i;
    double dt = 1e-3;
    srand((unsigned) time(NULL));

    Planet planets[NUM_PLANETS];
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].pos = random_vec(MAX_POS);
        planets[i].vel = random_vec(MAX_SPEED);
        planets[i].mass = random_double(MAX_MASS);
    }

    while (1) {
        update_acceleration(planets);
        update_velocity(planets, dt);
        update_position(planets, dt);

        print_planets(planets);
    }
    return 0;
}