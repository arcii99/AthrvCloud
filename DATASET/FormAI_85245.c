//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define GRAV_CONST 6.6743e-11 // Gravitational Constant
#define TIME_STEP 1 // Time step for simulation
#define PIXEL_SIZE 2 // Size of one pixel
#define NUM_PLANETS 3 // number of planets

// Struct for holding planet data
typedef struct {
    double x; // x position
    double y; // y position
    double mass; // mass
    double vx; // x velocity
    double vy; // y velocity
} planet;

// Function to calculate distance between two planets
double distance(planet p1, planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

// Function to calculate force on planet
void calculate_forces(planet *planets, int num_planets) {
    int i, j;
    double dx, dy;
    double dist, force;

    for (i = 0; i < num_planets; i++) {
        planets[i].vx = 0;
        planets[i].vy = 0;
        for (j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            dist = sqrt(pow(dx, 2) + pow(dy, 2));
            force = (GRAV_CONST * planets[i].mass * planets[j].mass) / pow(dist, 2);
            planets[i].vx += force * (dx / dist) / planets[i].mass;
            planets[i].vy += force * (dy / dist) / planets[i].mass;
        }
    }
}

// Function to update planet positions and velocities
void update_planets(planet *planets, int num_planets, double time_step) {
    int i;
    for (i = 0; i < num_planets; i++) {
        planets[i].x += planets[i].vx * time_step;
        planets[i].y += planets[i].vy * time_step;
    }
}

// Function to draw planet positions on console
void draw_console(planet *planets, int num_planets) {
    int i, j;
    int x, y;

    for (i = 0; i < num_planets; i++) {
        x = (int)(planets[i].x / PIXEL_SIZE);
        y = (int)(planets[i].y / PIXEL_SIZE);
        for (j = 0; j < PIXEL_SIZE; j++) {
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to draw planet positions on screen
void draw_graphics(planet *planets, int num_planets) {
    // Code to draw planet positions on screen
}

int main() {
    planet planets[NUM_PLANETS];
    int i, j;

    // Initialize planets
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = rand() % 10000;
        planets[i].y = rand() % 10000;
        planets[i].mass = (rand() % 10000) / 100.0;
        planets[i].vx = 0;
        planets[i].vy = 0;
    }

    // Simulation loop
    for (i = 0; i < 100000; i++) {
        calculate_forces(planets, NUM_PLANETS);
        update_planets(planets, NUM_PLANETS, TIME_STEP);
        draw_console(planets, NUM_PLANETS);
        //draw_graphics(planets, NUM_PLANETS);
    }

    return 0;
}