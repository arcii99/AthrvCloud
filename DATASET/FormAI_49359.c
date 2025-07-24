//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <math.h>

#define G 6.67259e-11  // Gravitational Constant
#define STEPS 10000    // Total number of time steps
#define DT 0.01       // Time step size

typedef struct Vector {
    double x;
    double y;
    double z;
} Vector;

typedef struct Body {
    char* name;
    double mass;
    Vector position;
    Vector velocity;
} Body;

Body bodies[] = {
    {"sun", 1.989e30, {0, 0, 0}, {0, 0, 0}},
    {"earth", 5.97e24, {147.1e9, 0, 0}, {0, 30300, 0}},
    {"mars", 6.39e23, {0, 228e9, 0}, {24000, 0, 0}},
    {"jupiter", 1.9e27, {0, 0, 778.5e9}, {0, 13000, 0}}
};
const int num_bodies = sizeof(bodies) / sizeof(Body);

void calculate_forces(Body* b1, Body* b2, Vector* force) {
    double dx = b2->position.x - b1->position.x;
    double dy = b2->position.y - b1->position.y;
    double dz = b2->position.z - b1->position.z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double magnitude = G * b1->mass * b2->mass / (distance * distance);
    force->x += magnitude * dx / distance;
    force->y += magnitude * dy / distance;
    force->z += magnitude * dz / distance;
}

void update_bodies() {
    Vector forces[num_bodies];  // Array to store the forces on each body
    for(int i = 0; i < num_bodies; i++) {
        forces[i] = (Vector){0, 0, 0};  // Initialize all forces to zero
        for(int j = 0; j < num_bodies; j++) {
            if(i != j) {
                calculate_forces(&bodies[i], &bodies[j], &forces[i]);  // Calculate the force from each body
            }
        }
    }
    for(int i = 0; i < num_bodies; i++) {
        Vector acceleration = (Vector){forces[i].x / bodies[i].mass, forces[i].y / bodies[i].mass, forces[i].z / bodies[i].mass};
        bodies[i].velocity.x += acceleration.x * DT;  // Update the velocity of the body
        bodies[i].velocity.y += acceleration.y * DT;
        bodies[i].velocity.z += acceleration.z * DT;
        bodies[i].position.x += bodies[i].velocity.x * DT;  // Update the position of the body
        bodies[i].position.y += bodies[i].velocity.y * DT;
        bodies[i].position.z += bodies[i].velocity.z * DT;
    }
}

void print_body_data(Body* b) {
    printf("%s\n", b->name);
    printf("Mass: %.2e kg\n", b->mass);
    printf("Position: (%.2e, %.2e, %.2e) m\n", b->position.x, b->position.y, b->position.z);
    printf("Velocity: (%.2e, %.2e, %.2e) m/s\n", b->velocity.x, b->velocity.y, b->velocity.z);
}

int main() {    
    for(int step = 0; step < STEPS; step++) {
        update_bodies();
    }
    
    for(int i = 0; i < num_bodies; i++) {
        print_body_data(&bodies[i]);
        printf("\n");
    }
    
    return 0;
}