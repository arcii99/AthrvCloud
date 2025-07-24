//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define TIMESTEP 86400.0 // One day timestep in seconds
#define MAX_ITERS 365 // Run simulation for 1 year

struct Vector {
    double x;
    double y;
    double z;
};

struct Body {
    char name[20];
    double mass;
    struct Vector position;
    struct Vector velocity;
};

void update_position(struct Body *b) {
    b->position.x += b->velocity.x * TIMESTEP;
    b->position.y += b->velocity.y * TIMESTEP;
    b->position.z += b->velocity.z * TIMESTEP;
}

void update_velocity(struct Body *b1, struct Body *b2) {
    struct Vector r;
    double distance;

    r.x = b2->position.x - b1->position.x;
    r.y = b2->position.y - b1->position.y;
    r.z = b2->position.z - b1->position.z;
    distance = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);

    double force = (G * b1->mass * b2->mass) / (distance * distance);
    double accel = force / b1->mass;

    b1->velocity.x += accel * (r.x / distance) * TIMESTEP;
    b1->velocity.y += accel * (r.y / distance) * TIMESTEP;
    b1->velocity.z += accel * (r.z / distance) * TIMESTEP;
}

int main() {
    struct Body sun = {"Sun", 1.989e+30, {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {"Earth", 5.97e+24, {-147095000000, 0, 0}, {0, 29785, 0}};

    printf("Running simulation...\n");
    for (int i = 0; i < MAX_ITERS; i++) {
        update_velocity(&earth, &sun);
        update_position(&earth);

        printf("%d - Earth Position - x: %f, y: %f, z: %f\n", i+1, earth.position.x, earth.position.y, earth.position.z);
    }

    return 0;
}