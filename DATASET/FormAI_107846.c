//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_PLANETS 8 // Number of planets in the solar system

typedef struct {
    double x, y; // Cartesian Coordinates
    double vx, vy; // Velocities
    double fx, fy; // Forces
    double mass; // Mass of planet
} Planet;

// This function calculates the distances between 2 planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// This function calculates the forces between 2 planets based on their
// masses and distances between them
void calculate_force(Planet *p1, Planet *p2) {
    double d = distance(*p1, *p2);
    double f = (p1->mass * p2->mass) / (d*d);
    double fx = f * (p2->x - p1->x) / d;
    double fy = f * (p2->y - p1->y) / d;
    p1->fx += fx;
    p1->fy += fy;
    p2->fx -= fx;
    p2->fy -= fy;
}

// This function updates the positions and velocities of planets after a time interval
void update_positions_velocities(Planet *p, double dt) {
    p->vx += p->fx / p->mass * dt;
    p->vy += p->fy / p->mass * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->fx = 0.0;
    p->fy = 0.0;
}

// This thread function calculates the forces between a given planet and all other planets
void* calculate_forces_thread(void *arg) {
    int i, j;
    Planet *p1, *p2;
    double d;
    for (i = 0; i < NUM_PLANETS; i++) {
        p1 = (Planet*)arg + i;
        for (j = i+1; j < NUM_PLANETS; j++) {
            p2 = (Planet*)arg + j;
            calculate_force(p1, p2);
        }
    }
    pthread_exit(NULL);
}

// This thread function updates the position and velocity of a given planet after a time interval
void* update_positions_velocities_thread(void *arg) {
    int i;
    Planet *p;
    double dt = *((double*)arg);
    for (i = 0; i < NUM_PLANETS; i++) {
        p = (Planet*)arg + i;
        update_positions_velocities(p, dt);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t force_threads[NUM_PLANETS];
    pthread_t position_threads[NUM_PLANETS];
    int i;

    // Define initial positions, velocities and masses of planets
    Planet planets[NUM_PLANETS] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.000000001}, // Sun
        {0.0, 57910000.0, 29500.0, 0.0, 0.0, 0.3285e24}, // Mercury
        {0.0, 108209000.0, 21900.0, 0.0, 0.0, 4.87e24}, // Venus
        {0.0, 149600000.0, 17300.0, 0.0, 0.0, 5.97e24}, // Earth
        {0.0, 227939100.0, 15400.0, 0.0, 0.0, 0.64185e24}, // Mars
        {0.0, 778547200.0, 13000.0, 0.0, 0.0, 1898.13e24}, // Jupiter
        {0.0, 1433449370.0, 9700.0, 0.0, 0.0, 568.319e24}, // Saturn
        {0.0, 2870671400.0, 6800.0, 0.0, 0.0, 86.8103e24} // Uranus
    };
    int num_threads = NUM_PLANETS - 1;
    double dt = 86400.0; // Time interval of 1 day (in seconds)

    // Simulate for 1 year
    int num_steps = 365;
    for (i = 0; i < num_steps; i++) {
        // Calculate and update forces between all pairs of planets
        for (int j = 0; j < num_threads; j++) {
            pthread_create(&force_threads[j], NULL, calculate_forces_thread, planets+j+1);
        }
        for (int j = 0; j < num_threads; j++) {
            pthread_join(force_threads[j], NULL);
        }

        // Update positions and velocities of all planets
        for (int j = 0; j < num_threads; j++) {
            pthread_create(&position_threads[j], NULL, update_positions_velocities_thread, &dt);
        }
        for (int j = 0; j < num_threads; j++) {
            pthread_join(position_threads[j], NULL);
        }
        
        // Print position of Earth for each day
        printf("Day %d: Earth position: (%f, %f)\n", i+1, planets[3].x, planets[3].y);
    }
    
    pthread_exit(NULL);
}