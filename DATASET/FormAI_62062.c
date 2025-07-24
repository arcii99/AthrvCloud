//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    double x, y, z;
} vec3;

typedef struct {
    vec3 pos, vel, f;     // Position, velocity, force
    double mass, radius;  // Mass and radius
} body;

void update_forces(body *bodies, int num_bodies) {
    int i, j;
    vec3 f, r;
    double dist, force;
    
    for (i = 0; i < num_bodies; i++) {
        bodies[i].f.x = bodies[i].f.y = bodies[i].f.z = 0.0;
        for (j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            r.x = bodies[j].pos.x - bodies[i].pos.x;
            r.y = bodies[j].pos.y - bodies[i].pos.y;
            r.z = bodies[j].pos.z - bodies[i].pos.z;
            dist = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
            force = G * bodies[i].mass * bodies[j].mass / (dist*dist);
            f.x = force * r.x / dist;
            f.y = force * r.y / dist;
            f.z = force * r.z / dist;
            bodies[i].f.x += f.x;
            bodies[i].f.y += f.y;
            bodies[i].f.z += f.z;
        }
    }
}

void update_positions(body *bodies, int num_bodies, double dt) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        // Update velocity
        bodies[i].vel.x += bodies[i].f.x * dt / bodies[i].mass;
        bodies[i].vel.y += bodies[i].f.y * dt / bodies[i].mass;
        bodies[i].vel.z += bodies[i].f.z * dt / bodies[i].mass;
        // Update position
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
        bodies[i].pos.z += bodies[i].vel.z * dt;
    }
}

void print_body(body b) {
    printf("Position: (%.2f, %.2f, %.2f)     Velocity: (%.2f, %.2f, %.2f)\n",
           b.pos.x, b.pos.y, b.pos.z, b.vel.x, b.vel.y, b.vel.z);
}

int main(void) {
    // Initialize bodies
    int num_bodies = 8;
    body bodies[8] = {
        { {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.9891e30, 696340000 },
        { {57909050000.0, 0.0, 0.0}, {0.0, 47162.0, 0.0}, {0.0, 0.0, 0.0}, 3.3011e23, 2439700 },
        { {0.0, 108208930000.0, 0.0}, {-35070.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 4.8675e24, 6052000 },
        { {0.0, 0.0, 149597890000.0}, {29783.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 5.9724e24, 6371000 },
        { {-227939100000.0, 0.0, 0.0}, {0.0, -24100.0, 0.0}, {0.0, 0.0, 0.0}, 6.4171e23, 3396100 },
        { {0.0, -77910800000.0, 0.0}, {34620.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.8982e27, 69911000 },
        { {0.0, 0.0, -36525600000.0}, {0.0, 0.0, 29800.0}, {0.0, 0.0, 0.0}, 3.084e23, 2559000 },
        { {384400000.0, 0.0, 0.0}, {0.0, 1022.0, 0.0}, {0.0, 0.0, 0.0}, 7.342e22, 1737400 }
    };
    
    // Simulation parameters
    double t = 0.0;
    double dt = 86400.0;    // Days per time step
    
    printf("Initial positions and velocities:\n");
    int i;
    for (i = 0; i < num_bodies; i++) {
        print_body(bodies[i]);
    }
    
    // Simulation loop
    while (t < 365.2425 * 3) {   // Three years
        update_forces(bodies, num_bodies);
        update_positions(bodies, num_bodies, dt);
        t += dt;
    }
    
    printf("\nFinal positions and velocities:\n");
    for (i = 0; i < num_bodies; i++) {
        print_body(bodies[i]);
    }
    
    return 0;
}