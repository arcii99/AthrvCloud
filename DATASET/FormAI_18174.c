//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>

float g = 9.81; // Acceleration due to gravity
float k = 0.05; // Air resistance constant
float dt = 0.1; // Time step size

typedef struct {
  float x;
  float y;
  float vx;
  float vy;
} Particle;

void update(Particle *p) {
  // Update the velocity
  p->vx -= k * p->vx * dt;
  p->vy -= (g + k * p->vy) * dt;

  // Update the position
  p->x += p->vx * dt;
  p->y += p->vy * dt;
}

int main() {
  Particle p = {0, 0, 10, 30}; // Particle starting position and velocity

  printf("Time\tX\tY\n");

  for (int i = 0; i < 50; i++) {
    printf("%.1f\t%.2f\t%.2f\n", i * dt, p.x, p.y);
    update(&p);
  }

  return 0;
}