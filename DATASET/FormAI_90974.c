//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

const float G = 6.674 * pow(10, -11); // gravitational constant

typedef struct {
    float x, y; // position
    float vx, vy; // velocity
    float ax, ay; // acceleration
    float m; // mass
} Body;

#define NUM_BODIES 3

Body bodies[NUM_BODIES] = {
    { .x = 0, .y = 0, .vx = 0, .vy = 0, .ax = 0, .ay = 0, .m = 5.97e24 }, // Earth
    { .x = 6371000 + 35000, .y = 0, .vx = 0, .vy = 7500, .ax = 0, .ay = 0, .m = 50000 }, // Satellite
    { .x = -150000000000, .y = 0, .vx = 0, .vy = -3000, .ax = 0, .ay = 0, .m = 2e30 } // Sun
};

void calculate_accelerations(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        float fx = 0, fy = 0;

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;

            float dx = bodies[j].x - bodies[i].x;
            float dy = bodies[j].y - bodies[i].y;
            float r = sqrt(dx*dx + dy*dy);
            float f = G * bodies[i].m * bodies[j].m / (r*r);

            fx += f * dx / r;
            fy += f * dy / r;
        }

        bodies[i].ax = fx / bodies[i].m;
        bodies[i].ay = fy / bodies[i].m;
    }
}

void update_bodies(Body *bodies, int num_bodies, float dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void print_bodies(Body *bodies, int num_bodies, int t) {
    printf("Time: %d seconds\n", t);

    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: (%.2e, %.2e), (%.2e, %.2e)\n", i+1, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }

    printf("\n");
}

void simulate(Body *bodies, int num_bodies, float dt, int t) {
    print_bodies(bodies, num_bodies, t);

    if (t > 1000) return;

    calculate_accelerations(bodies, num_bodies);
    update_bodies(bodies, num_bodies, dt);

    simulate(bodies, num_bodies, dt, t+1);
}

int main() {
    simulate(bodies, NUM_BODIES, 10, 0);

    return 0;
}