//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONSTANT 6.6743E-11
#define TIME_STEP 1
#define WINDOW_SIZE 600
#define G 10

typedef struct {
    double x;
    double y;
} vector;

typedef struct {
    double mass;
    vector pos;
    vector vel;
} planet;

void updateVelocity(planet *p, vector accel) {
    p->vel.x += accel.x * TIME_STEP;
    p->vel.y += accel.y * TIME_STEP;
}

void updatePosition(planet *p) {
    p->pos.x += p->vel.x * TIME_STEP;
    p->pos.y += p->vel.y * TIME_STEP;
}

vector calculateGravityVector(planet p1, planet p2) {
    vector r;
    r.x = p2.pos.x - p1.pos.x;
    r.y = p2.pos.y - p1.pos.y;

    double distance = sqrt(pow(r.x, 2) + pow(r.y, 2));
    double magnitude = (GRAV_CONSTANT * p1.mass * p2.mass) / pow(distance, 2);

    r.x = magnitude * r.x / distance;
    r.y = magnitude * r.y / distance;

    return r;
}

vector calculateAcceleration(planet *p, planet *all_planets, int num_planets) {
    vector total_gravity = {0, 0};

    for (int i = 0; i < num_planets; i++) {
        if (p == &(all_planets[i])) {
            continue;
        }

        vector gravity = calculateGravityVector(*p, all_planets[i]);
        total_gravity.x += gravity.x;
        total_gravity.y += gravity.y;
    }

    vector acceleration = {total_gravity.x / p->mass, total_gravity.y / p->mass};
    return acceleration;
}

void simulateGravity(planet *all_planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        planet *p = &(all_planets[i]);
        vector accel = calculateAcceleration(p, all_planets, num_planets);
        updateVelocity(p, accel);
        updatePosition(p);
    }
}

void drawPlanet(planet p) {
    double scale = WINDOW_SIZE / 20.0;
    double radius = sqrt(p.mass) * scale;
    double x = p.pos.x * scale + WINDOW_SIZE / 2;
    double y = p.pos.y * scale + WINDOW_SIZE / 2;

    printf("<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"blue\" />\n", x, y, radius);
}

void drawFrame(planet *all_planets, int num_planets) {
    printf("<svg viewBox=\"0 0 %d %d\" xmlns=\"http://www.w3.org/2000/svg\">\n", WINDOW_SIZE, WINDOW_SIZE);
    for (int i = 0; i < num_planets; i++) {
        drawPlanet(all_planets[i]);
    }
    printf("</svg>\n");
}

int main() {
    planet earth = {
        .mass = 5.97E24,
        .pos = {.x = 0, .y = 0},
        .vel = {.x = 0, .y = 0}
    };

    planet moon = {
        .mass = 7.34E22,
        .pos = {.x = 384400000, .y = 0},
        .vel = {.x = 0, .y = 1.02E3}
    };

    planet all_planets[] = {earth, moon};
    int num_planets = 2;

    for (int i = 0; i < 10000; i++) {
        simulateGravity(all_planets, num_planets);
        drawFrame(all_planets, num_planets);
    }
}