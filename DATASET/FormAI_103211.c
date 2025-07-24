//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81 // Earth's gravity in m/s^2
#define DELTA_T 0.1 // delta t value for time step

typedef struct {
  double x, y; // position
  double vx, vy; // velocity
  double ax, ay; // acceleration
  double mass; // mass of object
} Particle;

void update_particle(Particle *p) {
  p->vx += p->ax * DELTA_T;
  p->vy += p->ay * DELTA_T;
  p->x += p->vx * DELTA_T;
  p->y += p->vy * DELTA_T;
}

void apply_gravity(Particle *p) {
  p->ay -= GRAVITY;
}

void apply_friction(Particle *p, double friction_coeff) {
  double friction_force = friction_coeff * p->mass * GRAVITY;

  // calculate frictional forces along x and y directions
  double fx = -1 * friction_force * (p->vx / sqrt(pow(p->vx, 2) + pow(p->vy, 2)));
  double fy = -1 * friction_force * (p->vy / sqrt(pow(p->vx, 2) + pow(p->vy, 2)));

  // update acceleration due to friction
  p->ax += fx / p->mass;
  p->ay += fy / p->mass;
}

int main() {
  Particle p = {0, 0, 10, 10, 0, 0, 1}; // initialize particle with initial velocity of (10, 10) m/s

  for (int i = 0; i < 100; i++) { // simulate for 10 seconds
    apply_gravity(&p);
    apply_friction(&p, 0.2);
    update_particle(&p);
    printf("Time: %3.1f s | Position: (%3.2f, %3.2f) m | Velocity: (%3.2f, %3.2f) m/s | Acceleration: (%3.2f, %3.2f) m/s^2\n",
           i * DELTA_T, p.x, p.y, p.vx, p.vy, p.ax, p.ay);
  }

  return 0;
}