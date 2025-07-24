//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: automated
#include <stdio.h>
#include <math.h>

#define G 6.6743E-11

typedef struct {
  double x, y;
} vec2;

typedef struct {
  vec2 pos;
  vec2 vel;
  double mass;
} body;

body bodies[] = {
   {{0.0, 0.0}, {0.0, 0.0}, 1.98E30},
   {{6.876E8, 0.0}, {0.0, 30.0E3}, 5.97E24},
   {{1.08E9, 0.0}, {0.0, 24.0E3}, 6.39E23}
};

const int num_bodies = sizeof(bodies) / sizeof(body);

vec2 force(body b1, body b2) {
  vec2 r = { b2.pos.x - b1.pos.x, b2.pos.y - b1.pos.y };
  double d = sqrt(pow(r.x, 2) + pow(r.y, 2));
  double f = G * b1.mass * b2.mass / pow(d, 2);
  vec2 u = { r.x / d, r.y / d };
  return (vec2){ f * u.x, f * u.y };
}

void update(body *bodies, int num_bodies, double dt) {
  vec2 forces[num_bodies];
  for (int i = 0; i < num_bodies; i++) {
    vec2 f = { 0.0, 0.0 };
    for (int j = 0; j < num_bodies; j++) {
      if (i == j) {
        continue;
      }
      vec2 fij = force(bodies[i], bodies[j]);
      f.x += fij.x;
      f.y += fij.y;
    }
    forces[i] = f;
  }
  for (int i = 0; i < num_bodies; i++) {
    body *b = &bodies[i];
    vec2 f = forces[i];
    b->pos.x += b->vel.x * dt;
    b->pos.y += b->vel.y * dt;
    b->vel.x += f.x / b->mass * dt;
    b->vel.y += f.y / b->mass * dt;
  }
}

int main() {
  const double dt = 1.0;
  const int num_steps = 1000;
  for (int i = 0; i < num_steps; i++) {
    printf("step %d:\n", i);
    for (int j = 0; j < num_bodies; j++) {
      body b = bodies[j];
      printf("body %d: (%.3f, %.3f)\n", j, b.pos.x, b.pos.y);
    }
    update(bodies, num_bodies, dt);
  }
  return 0;
}