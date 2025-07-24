//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define NUM_PLANETS 8
#define GRAVITY 6.67e-11

// Define a structure to hold the properties of a planet
typedef struct planet {
    char name[30];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
} Planet;

// Initialize the properties of the planets
void init_planets(Planet planets[]) {
    // Sun
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.989e+30;
    planets[0].radius = 695508;
    planets[0].position[0] = 0;
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 0;
    planets[0].velocity[2] = 0;

    // Mercury
    strcpy(planets[1].name, "Mercury");
    planets[1].mass = 3.285e+23;
    planets[1].radius = 2439.7;
    planets[1].position[0] = 4.6e+10;
    planets[1].position[1] = 0;
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 0;
    planets[1].velocity[1] = 4.7e+04;
    planets[1].velocity[2] = 0;

    // Venus
    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.867e+24;
    planets[2].radius = 6051.8;
    planets[2].position[0] = 1.074e+11;
    planets[2].position[1] = 0;
    planets[2].position[2] = 0;
    planets[2].velocity[0] = 0;
    planets[2].velocity[1] = 3.5e+04;
    planets[2].velocity[2] = 0;

    // Earth
    strcpy(planets[3].name, "Earth");
    planets[3].mass = 5.972e+24;
    planets[3].radius = 6371;
    planets[3].position[0] = 1.496e+11;
    planets[3].position[1] = 0;
    planets[3].position[2] = 0;
    planets[3].velocity[0] = 0;
    planets[3].velocity[1] = 2.9783e+04;
    planets[3].velocity[2] = 0;

    // Mars
    strcpy(planets[4].name, "Mars");
    planets[4].mass = 6.39e+23;
    planets[4].radius = 3389.5;
    planets[4].position[0] = 2.28e+11;
    planets[4].position[1] = 0;
    planets[4].position[2] = 0;
    planets[4].velocity[0] = 0;
    planets[4].velocity[1] = 2.4077e+04;
    planets[4].velocity[2] = 0;

    // Jupiter
    strcpy(planets[5].name, "Jupiter");
    planets[5].mass = 1.898e+27;
    planets[5].radius = 69911;
    planets[5].position[0] = 7.784e+11;
    planets[5].position[1] = 0;
    planets[5].position[2] = 0;
    planets[5].velocity[0] = 0;
    planets[5].velocity[1] = 1.307e+04;
    planets[5].velocity[2] = 0;

    // Saturn
    strcpy(planets[6].name, "Saturn");
    planets[6].mass = 5.683e+26;
    planets[6].radius = 58232;
    planets[6].position[0] = 1.429e+12;
    planets[6].position[1] = 0;
    planets[6].position[2] = 0;
    planets[6].velocity[0] = 0;
    planets[6].velocity[1] = 9.691e+03;
    planets[6].velocity[2] = 0;

    // Uranus
    strcpy(planets[7].name, "Uranus");
    planets[7].mass = 8.681e+25;
    planets[7].radius = 25362;
    planets[7].position[0] = 2.871e+12;
    planets[7].position[1] = 0;
    planets[7].position[2] = 0;
    planets[7].velocity[0] = 0;
    planets[7].velocity[1] = 6.81e+03;
    planets[7].velocity[2] = 0;
}

// Calculate the gravitational force between two planets
void calculate_force(Planet p1, Planet p2, double force[]) {
    double distance = sqrt(pow(p1.position[0]-p2.position[0], 2) + 
                           pow(p1.position[1]-p2.position[1], 2) + 
                           pow(p1.position[2]-p2.position[2], 2));
    double magnitude = GRAVITY * p1.mass * p2.mass / pow(distance, 2);
    force[0] = magnitude * (p2.position[0] - p1.position[0]) / distance;
    force[1] = magnitude * (p2.position[1] - p1.position[1]) / distance;
    force[2] = magnitude * (p2.position[2] - p1.position[2]) / distance;
}

// Calculate the acceleration of a planet
void calculate_acceleration(Planet planets[], int i, double acceleration[]) {
    double force[3] = {0.0, 0.0, 0.0};
    for(int j=0; j<NUM_PLANETS; j++) {
        if(i != j) {
            double f[3] = {0.0, 0.0, 0.0};
            calculate_force(planets[i], planets[j], f);
            force[0] += f[0];
            force[1] += f[1];
            force[2] += f[2];
        }
    }
    acceleration[0] = force[0] / planets[i].mass;
    acceleration[1] = force[1] / planets[i].mass;
    acceleration[2] = force[2] / planets[i].mass;
}

// Update the position and velocity of a planet
void update_planet(Planet *planet, double dt) {
    double acceleration[3] = {0.0, 0.0, 0.0};
    calculate_acceleration(&(*planet), 0, acceleration);
    planet->velocity[0] += acceleration[0] * dt;
    planet->velocity[1] += acceleration[1] * dt;
    planet->velocity[2] += acceleration[2] * dt;
    planet->position[0] += planet->velocity[0] * dt;
    planet->position[1] += planet->velocity[1] * dt;
    planet->position[2] += planet->velocity[2] * dt;
}

// Draw the Solar System
void draw_solar_system(Planet planets[], int num_steps, double dt) {
    printf("Running simulation...\n");
    for(int i=0; i<num_steps; i++) {
        for(int j=0; j<NUM_PLANETS; j++) {
            update_planet(&planets[j], dt);
        }
        printf("Step %d:\n", i+1);
        for(int j=0; j<NUM_PLANETS; j++) {
            printf("%s:\n", planets[j].name);
            printf("  position = (%.2f, %.2f, %.2f)\n", planets[j].position[0],
                   planets[j].position[1], planets[j].position[2]);
            printf("  velocity = (%.2f, %.2f, %.2f)\n", planets[j].velocity[0],
                   planets[j].velocity[1], planets[j].velocity[2]);
        }
        printf("\n");
    }
    printf("Simulation complete.\n");
}

int main() {
    // Initialize the random seed
    srand(time(NULL));
    // Initialize the properties of the planets
    Planet planets[NUM_PLANETS];
    init_planets(planets);
    // Simulate the Solar System for 365 days
    int num_steps = 365;
    double dt = 24*60*60;
    draw_solar_system(planets, num_steps, dt);
    return 0;
}