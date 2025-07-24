//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define G 6.6743E-11 // gravitational constant
#define SCALE_FACTOR 1E-9 // scaling down factor

typedef struct planet {
    double mass; // mass of the planet
    double x, y; // coordinates of the planet
    double vx, vy; // velocities of the planet
    double ax, ay; // accelerations of the planet
} planet;

void update_acceleration(planet* p1, planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dist = sqrt(dx*dx + dy*dy);
    double force = G * p1->mass * p2->mass / (dist * dist);
    double angle = atan2(dy, dx);
    p1->ax += force / p1->mass * cos(angle);
    p1->ay += force / p1->mass * sin(angle);
}

void update_velocity(planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_position(planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void simulate(planet* planets, int num_planets, double dt, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        // update accelerations to zero
        for (int j = 0; j < num_planets; j++) {
            planets[j].ax = 0;
            planets[j].ay = 0;
        }
        // update accelerations
        for (int j = 0; j < num_planets; j++) {
            for (int k = j+1; k < num_planets; k++) {
                update_acceleration(&planets[j], &planets[k]);
                update_acceleration(&planets[k], &planets[j]);
            }
        }
        // update velocities and positions
        for (int j = 0; j < num_planets; j++) {
            update_velocity(&planets[j], dt);
            update_position(&planets[j], dt);
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int num_planets = 5;
    planet planets[num_planets];
    // initialize planets
    for (int i = 0; i < num_planets; i++) {
        planets[i].mass = (rand() % 10 + 1) * 1E23;
        planets[i].x = (rand() % 1000) * SCALE_FACTOR;
        planets[i].y = (rand() % 1000) * SCALE_FACTOR;
        planets[i].vx = (rand() % 100) * SCALE_FACTOR;
        planets[i].vy = (rand() % 100) * SCALE_FACTOR;
        planets[i].ax = 0;
        planets[i].ay = 0;
    }
    double dt = 10.0; // time step
    int num_steps = 100; // number of steps to simulate
    simulate(planets, num_planets, dt, num_steps);
    // print final positions
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i+1);
        printf("Mass: %e kg\n", planets[i].mass);
        printf("Position: (%f, %f)\n", planets[i].x/SCALE_FACTOR, planets[i].y/SCALE_FACTOR);
    }
    return 0;
}