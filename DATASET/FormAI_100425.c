//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
#include <stdio.h>
#include <math.h>

#define G 6.67408E-11 // Universal Gravitational Constant
#define TIME_STEP 86400 // Time step in seconds (One day)
#define NUM_BODIES 4 // Number of celestial bodies in the simulation

struct Body {
    char name[20];
    double mass; // In kilograms
    double radius; // In meters
    double x, y; // Position in meters
    double vx, vy; // Velocity in meters/second
    double ax, ay; // Acceleration in meters/second^2
} solar_system[NUM_BODIES];

void initialize_bodies() {
    // Sun
    strcpy(solar_system[0].name, "Sun");
    solar_system[0].mass = 1.989E30;
    solar_system[0].radius = 696340000;
    solar_system[0].x = 0.0;
    solar_system[0].y = 0.0;
    solar_system[0].vx = 0.0;
    solar_system[0].vy = 0.0;
    solar_system[0].ax = 0.0;
    solar_system[0].ay = 0.0;

    // Earth
    strcpy(solar_system[1].name, "Earth");
    solar_system[1].mass = 5.972E24;
    solar_system[1].radius = 6371000;
    solar_system[1].x = 147095000000;
    solar_system[1].y = 0.0;
    solar_system[1].vx = 0.0;
    solar_system[1].vy = 30300.0;
    solar_system[1].ax = 0.0;
    solar_system[1].ay = 0.0;

    // Moon
    strcpy(solar_system[2].name, "Moon");
    solar_system[2].mass = 7.342E22;
    solar_system[2].radius = 1737000;
    solar_system[2].x = 147095000000 + 384400000;
    solar_system[2].y = 0.0;
    solar_system[2].vx = 0.0;
    solar_system[2].vy = 30300.0 + 1023;
    solar_system[2].ax = 0.0;
    solar_system[2].ay = 0.0;

    // Mars
    strcpy(solar_system[3].name, "Mars");
    solar_system[3].mass = 6.39E23;
    solar_system[3].radius = 3389500;
    solar_system[3].x = 227943824000;
    solar_system[3].y = 0.0;
    solar_system[3].vx = 0.0;
    solar_system[3].vy = 24077.0;
    solar_system[3].ax = 0.0;
    solar_system[3].ay = 0.0;
}

void update_acceleration(int i) {
    int j;
    double r, fx, fy;
    for (j = 0; j < NUM_BODIES; j++) {
        if (i != j) {
            // Calculate distance between bodies
            r = sqrt(pow(solar_system[i].x - solar_system[j].x, 2) + pow(solar_system[i].y - solar_system[j].y, 2));
            // Calculate force between bodies
            fx = G * solar_system[i].mass * solar_system[j].mass * (solar_system[j].x - solar_system[i].x) / pow(r, 3);
            fy = G * solar_system[i].mass * solar_system[j].mass * (solar_system[j].y - solar_system[i].y) / pow(r, 3);
            // Update acceleration
            solar_system[i].ax += fx / solar_system[i].mass;
            solar_system[i].ay += fy / solar_system[i].mass;
        }
    }
}

void update_velocity(int i) {
    // Update velocity
    solar_system[i].vx += solar_system[i].ax * TIME_STEP;
    solar_system[i].vy += solar_system[i].ay * TIME_STEP;
}

void update_position(int i) {
    // Update position
    solar_system[i].x += solar_system[i].vx * TIME_STEP;
    solar_system[i].y += solar_system[i].vy * TIME_STEP;
}

void print_body(int i) {
    printf("%s\n", solar_system[i].name);
    printf("\tPosition: (%.3e, %.3e)\n", solar_system[i].x, solar_system[i].y);
    printf("\tVelocity: (%.3e, %.3e)\n", solar_system[i].vx, solar_system[i].vy);
}

int main() {
    int i;
    initialize_bodies();
    for (i = 0; i < 365; i++) {
        // Update acceleration for all bodies
        for (int j = 0; j < NUM_BODIES; j++) {
            solar_system[j].ax = 0.0;
            solar_system[j].ay = 0.0;
            update_acceleration(j);
        }
        // Update velocity and position for all bodies
        for (int j = 0; j < NUM_BODIES; j++) {
            update_velocity(j);
            update_position(j);
        }
    }
    // Print final positions and velocities of bodies
    for (int j = 0; j < NUM_BODIES; j++) {
        print_body(j);
    }
    return 0;
}