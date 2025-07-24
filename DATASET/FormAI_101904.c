//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 20
#define GRAVITY 9.8 // m/s^2
#define TICK_RATE 0.1 // seconds per tick
#define SPRING_CONSTANT 10.0 // N/m
#define MASS 1.0 // kg

struct Vector2 {
  float x;
  float y;
};

struct Particle {
  struct Vector2 position;
  struct Vector2 velocity;
  struct Vector2 acceleration;
};

struct Spring {
  struct Particle *p1;
  struct Particle *p2;
  float length;
};

void update(struct Particle *p) {
  // Update the particle's position, velocity and acceleration
  p->velocity.x += p->acceleration.x * TICK_RATE;
  p->velocity.y += p->acceleration.y * TICK_RATE;
  p->position.x += p->velocity.x * TICK_RATE;
  p->position.y += p->velocity.y * TICK_RATE;
}

float calculate_distance(struct Particle *p1, struct Particle *p2) {
  float dx = p1->position.x - p2->position.x;
  float dy = p1->position.y - p2->position.y;

  return sqrt(dx * dx + dy * dy);
}

void calculate_spring_forces(struct Spring *s) {
  // Calculate the spring force acting on both particles
  float distance = calculate_distance(s->p1, s->p2);
  float displacement = fabs(distance - s->length);
  float force = SPRING_CONSTANT * displacement;

  float fx = force * (s->p1->position.x - s->p2->position.x) / distance;
  float fy = force * (s->p1->position.y - s->p2->position.y) / distance;

  s->p1->acceleration.x += fx / MASS;
  s->p1->acceleration.y += fy / MASS;

  s->p2->acceleration.x -= fx / MASS;
  s->p2->acceleration.y -= fy / MASS;
}

void update_particles(struct Particle *particles, int particle_count, struct Spring *springs, int spring_count) {
  // Reset the acceleration of each particle
  for (int i = 0; i < particle_count; i++) {
    particles[i].acceleration.x = 0;
    particles[i].acceleration.y = 0;

    update(&particles[i]);
  }

  // Calculate the spring forces
  for (int i = 0; i < spring_count; i++) {
    calculate_spring_forces(&springs[i]);
  }

  // Apply gravity to all particles
  for (int i = 0; i < particle_count; i++) {
    particles[i].acceleration.y += GRAVITY;
  }
}

void draw_particles(struct Particle *particles, int particle_count) {
  // Clear the screen
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf(" ");
    }
    printf("\n");
  }

  // Draw the particles
  for (int i = 0; i < particle_count; i++) {
    int x = (int)particles[i].position.x;
    int y = (int)particles[i].position.y;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
      continue;
    }

    printf("O");
    printf("\033[%d;%dH", y + 1, x + 1);
  }

  // Move the cursor to the bottom-left corner
  printf("\033[%d;%dH", HEIGHT + 1, 1);
  fflush(stdout);
}

int main() {
  struct Particle particles[2] = {
    { { 10, 5 }, { 0, 0 }, { 0, 0 } },
    { { 20, 5 }, { 0, 0 }, { 0, 0 } }
  };

  struct Spring springs[1] = {
    { &particles[0], &particles[1], 10 }
  };

  while (1) {
    update_particles(particles, 2, springs, 1);
    draw_particles(particles, 2);
  }

  return 0;
}