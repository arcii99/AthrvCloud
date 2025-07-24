//FormAI DATASET v1.0 Category: Physics simulation ; Style: invasive
#include <stdio.h>
#include <math.h>

// Define constants
#define MASS 0.1
#define COLLISION_DIST 0.01
#define GRAVITY 9.81

// Define particle and world structures
typedef struct {
    double x, y;
    double velocity_x, velocity_y;
} Particle;

typedef struct {
    Particle particles[50];
    int num_particles;
    double wall_top, wall_bottom, wall_left, wall_right;
} World;

// Function to update particle positions
void update_particle(Particle *p, double dt) {
    p->velocity_y += GRAVITY * dt;
    p->x += p->velocity_x * dt;
    p->y += p->velocity_y * dt;
}

// Function to check for collisions between particles
void check_collisions(Particle *p1, Particle *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double distance = sqrt(dx*dx + dy*dy);

    if (distance < COLLISION_DIST) {
        double vx1 = p1->velocity_x;
        double vy1 = p1->velocity_y;
        double vx2 = p2->velocity_x;
        double vy2 = p2->velocity_y;
        p1->velocity_x = (vx1*(MASS - MASS) + (2*MASS)*vx2)/(MASS + MASS);
        p1->velocity_y = (vy1*(MASS - MASS) + (2*MASS)*vy2)/(MASS + MASS);
        p2->velocity_x = (vx2*(MASS - MASS) + (2*MASS)*vx1)/(MASS + MASS);
        p2->velocity_y = (vy2*(MASS - MASS) + (2*MASS)*vy1)/(MASS + MASS);
    }
}

// Function to simulate the world
void simulate_world(World *world, double dt, int steps) {
    // Perform multiple time steps
    for (int i=0; i<steps; i++) {
        // Update particle positions
        for (int j=0; j<world->num_particles; j++) {
            update_particle(&world->particles[j], dt);
        }
        // Check for wall collisions
        for (int j=0; j<world->num_particles; j++) {
            Particle *p = &world->particles[j];
            if (p->x < world->wall_left || p->x > world->wall_right) {
                p->velocity_x *= -1;
            }
            if (p->y < world->wall_top || p->y > world->wall_bottom) {
                p->velocity_y *= -1;
            }
        }
        // Check for particle collisions
        for (int j=0; j<world->num_particles; j++) {
            for (int k=j+1; k<world->num_particles; k++) {
                check_collisions(&world->particles[j], &world->particles[k]);
            }
        }
    }
}

int main() {
    // Create world with 5 particles
    World world;
    world.num_particles = 5;
    world.wall_top = 0.0;
    world.wall_bottom = 1.0;
    world.wall_left = 0.0;
    world.wall_right = 1.0;
    world.particles[0] = (Particle){0.1, 0.1, 1.0, 0.0};
    world.particles[1] = (Particle){0.9, 0.1, -1.0, 0.0};
    world.particles[2] = (Particle){0.5, 0.5, 0.0, 0.0};
    world.particles[3] = (Particle){0.1, 0.8, 3.0, 0.0};
    world.particles[4] = (Particle){0.9, 0.8, -3.0, 0.0};

    // Simulate world for 1 second in 1000 steps
    double dt = 0.001;
    int steps = 1000;
    simulate_world(&world, dt, steps);

    // Print final particle positions
    for (int i=0; i<world.num_particles; i++) {
        printf("Particle %d: x=%f, y=%f\n", i+1, world.particles[i].x, world.particles[i].y);
    }

    return 0;
}