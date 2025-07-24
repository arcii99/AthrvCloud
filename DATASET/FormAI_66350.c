//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 10
#define GRAVITY_CONSTANT 6.6743e-11

typedef struct {
    double x, y;
} vec2;

typedef struct {
    vec2 position;
    vec2 velocity;
    double mass;
} planet;

planet planets[NUM_PLANETS];

void update_velocity(int i) {
    vec2 total_force = {0, 0};
    for(int j=0; j<NUM_PLANETS; j++) {
        if(i != j) {
            double distance_squared = pow(planets[i].position.x-planets[j].position.x, 2) + pow(planets[i].position.y-planets[j].position.y, 2);
            double force_magnitude = GRAVITY_CONSTANT * planets[i].mass * planets[j].mass / distance_squared;
            double angle = atan2(planets[j].position.y-planets[i].position.y, planets[j].position.x-planets[i].position.x);
            vec2 force = {cos(angle)*force_magnitude, sin(angle)*force_magnitude};
            total_force.x += force.x;
            total_force.y += force.y;
        }
    }
    double acceleration_x = total_force.x / planets[i].mass;
    double acceleration_y = total_force.y / planets[i].mass;
    planets[i].velocity.x += acceleration_x * 0.05;
    planets[i].velocity.y += acceleration_y * 0.05;
}

void update_position(int i) {
    planets[i].position.x += planets[i].velocity.x * 0.05;
    planets[i].position.y += planets[i].velocity.y * 0.05;
}

void print_planet(int i) {
    printf("Planet %d: Mass=%.2e Pos=(%.2e, %.2e) Vel=(%.2e, %.2e)\n", i, planets[i].mass,
           planets[i].position.x, planets[i].position.y, planets[i].velocity.x, planets[i].velocity.y);
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize planets
    for(int i=0; i<NUM_PLANETS; i++) {
        double mass = (double)rand()/RAND_MAX * 1e24 + 1e22;
        double x = (double)rand()/RAND_MAX * 1e11 - 5e10;
        double y = (double)rand()/RAND_MAX * 1e11 - 5e10;
        double vx = (double)rand()/RAND_MAX * 1e5 - 5e4;
        double vy = (double)rand()/RAND_MAX * 1e5 - 5e4;
        planets[i] = (planet){{x, y}, {vx, vy}, mass};
    }

    // simulation loop
    for(int step=0; step<100; step++) {
        printf("Step %d:\n", step);
        for(int i=0; i<NUM_PLANETS; i++) {
            update_velocity(i);
        }
        for(int i=0; i<NUM_PLANETS; i++) {
            update_position(i);
            print_planet(i);
        }
    }

    return 0;
}