//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define TIME_STEP 0.1 // Time step for the simulation

typedef struct {
  double x, y; // Coordinates
  double vx, vy; // Velocity
  double ax, ay; // Acceleration
  double mass; // Mass
} Body;

void update_velocity(Body *b, Body *other, int num_bodies) {
  b->ax = b->ay = 0; // Set acceleration to zero first

  for (int i = 0; i < num_bodies; i++) {
    if (b != &other[i]) {
      double dx = other[i].x - b->x;
      double dy = other[i].y - b->y;
      double r = sqrt(dx * dx + dy * dy);
      double f = G * b->mass * other[i].mass / (r * r); // Calculate force
      b->ax += f * dx / r; // Update acceleration
      b->ay += f * dy / r;
    }
  }

  b->vx += b->ax * TIME_STEP; // Update velocity
  b->vy += b->ay * TIME_STEP;
}

void update_position(Body *b) {
  b->x += b->vx * TIME_STEP; // Update position
  b->y += b->vy * TIME_STEP;
}

void simulate(Body *bodies, int num_bodies, double duration) {
  int num_steps = (int)(duration / TIME_STEP);

  for (int step = 0; step < num_steps; step++) {
    for (int i = 0; i < num_bodies; i++) {
      update_velocity(&bodies[i], bodies, num_bodies); // Update velocity
    }

    for (int i = 0; i < num_bodies; i++) {
      update_position(&bodies[i]); // Update position
    }
  }
}

int main() {
  Body bodies[] = {
    {0, 0, 0, 0, 5.97e24,}, // Earth
    {384400000, 0, 0, 1023.055, 7.34e22} // Moon
  };
  int num_bodies = sizeof(bodies) / sizeof(Body);

  simulate(bodies, num_bodies, 86400); // Simulate for one day

  for (int i = 0; i < num_bodies; i++) {
    printf("Body %d:\n", i+1);
    printf("Position: x=%f, y=%f\n", bodies[i].x, bodies[i].y);
    printf("Velocity: vx=%f, vy=%f\n", bodies[i].vx, bodies[i].vy);
    printf("Acceleration: ax=%f, ay=%f\n", bodies[i].ax, bodies[i].ay);
  }

  return 0;
}