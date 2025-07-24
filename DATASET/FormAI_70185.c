//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Simulation Parameters
#define GRAVITY 9.81f
#define DELTA_T 0.1f
#define SIM_TIME 10.0f

// Constants
#define PI 3.14159265358979323846f

// Particle structure
typedef struct {
    float x, y;
    float vx, vy;
    float mass;
} Particle;

// Simulation function
void simulate(Particle* p) {
    float fx = 0.0f, fy = 0.0f;

    // Calculate forces
    fy -= p->mass * GRAVITY;

    // Update velocity and position
    p->vx += fx/p->mass * DELTA_T;
    p->vy += fy/p->mass * DELTA_T;
    p->x += p->vx * DELTA_T;
    p->y += p->vy * DELTA_T;
}

int main() {
    Particle p = {0.0f, 10.0f, 10.0f, 0.0f, 1.0f};

    printf("Starting Simulation:\n");
    printf("Time\tX\tY\n");

    for(float t = 0.0f; t <= SIM_TIME; t += DELTA_T) {
        simulate(&p);
        printf("%f\t%f\t%f\n", t, p.x, p.y);
    }

    printf("Simulation Finished.\n");

    return 0;
}