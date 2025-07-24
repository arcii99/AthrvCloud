//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTICLES 1000000

struct vector {
  float x;
  float y;
};

struct particle {
  struct vector position;
  struct vector velocity;
  float mass;
};

struct simulation {
  struct particle particles[MAX_PARTICLES];
  int num_particles;
  float time_step;
};

void simulate_step(struct simulation* s) {
  for (int i = 0; i < s->num_particles; i++) {
    struct particle* p = &s->particles[i];
    struct vector acceleration = {0, 0};

    // Calculate acceleration due to gravitational forces
    for (int j = 0; j < s->num_particles; j++) {
      if (i != j) {
        struct particle* other_p = &s->particles[j];
        struct vector diff = {other_p->position.x - p->position.x, other_p->position.y - p->position.y};
        float distance_sq = diff.x * diff.x + diff.y * diff.y;
        float distance = sqrt(distance_sq);
        struct vector force_dir = {diff.x / distance, diff.y / distance};
        float force_mag = (p->mass * other_p->mass) / distance_sq;
        struct vector force = {force_mag * force_dir.x, force_mag * force_dir.y};
        acceleration.x += force.x / p->mass;
        acceleration.y += force.y / p->mass;
      }
    }

    // Update velocity and position using acceleration and time step
    p->velocity.x += acceleration.x * s->time_step;
    p->velocity.y += acceleration.y * s->time_step;
    p->position.x += p->velocity.x * s->time_step;
    p->position.y += p->velocity.y * s->time_step;
  }
}

int main() {
  struct simulation s;
  
  // Initialize simulation with some particles
  s.time_step = 0.01;
  s.num_particles = 3;
  s.particles[0].position = (struct vector){0, 0};
  s.particles[0].velocity = (struct vector){0, 0};
  s.particles[0].mass = 100;
  s.particles[1].position = (struct vector){1, 0};
  s.particles[1].velocity = (struct vector){0, 10};
  s.particles[1].mass = 1;
  s.particles[2].position = (struct vector){-2, 0};
  s.particles[2].velocity = (struct vector){0, -5};
  s.particles[2].mass = 10;

  // Simulate for some time steps and print positions
  for (int i = 0; i < 100; i++) {
    simulate_step(&s);
    printf("Step %d: Particle 1 at (%f, %f), Particle 2 at (%f, %f), Particle 3 at (%f, %f)\n", i, s.particles[0].position.x, s.particles[0].position.y, s.particles[1].position.x, s.particles[1].position.y, s.particles[2].position.x, s.particles[2].position.y);
  }
  
  return 0;
}