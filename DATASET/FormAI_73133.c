//FormAI DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA_T 0.01
#define GRAVITY 9.8

typedef struct Vector {
  double x;
  double y;
} Vector;

typedef struct Particle {
  Vector position;
  Vector velocity;
  Vector acceleration;
  double mass;
} Particle;

Particle create_particle(double x, double y, double m) {
  Particle p = { {x, y}, {0, 0}, {0, 0}, m };
  return p;
}

void update_particle(Particle *p, double delta_t) {
  p->position.x += p->velocity.x * delta_t;
  p->position.y += p->velocity.y * delta_t;

  p->velocity.x += p->acceleration.x * delta_t;
  p->velocity.y += p->acceleration.y * delta_t;

  p->acceleration.x = 0;
  p->acceleration.y = -p->mass * GRAVITY;
}

void apply_force(Particle *p, Vector force) {
  p->acceleration.x += force.x / p->mass;
  p->acceleration.y += force.y / p->mass;
}

double distance(Vector v1, Vector v2) {
  double dx = v2.x - v1.x;
  double dy = v2.y - v1.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  Particle p1 = create_particle(0, 0, 1);
  Particle p2 = create_particle(3, 4, 1);

  for (int i = 0; i < 100; i++) {
    Vector force = {0, 0};
    
    double dist = distance(p1.position, p2.position);
    double magnitude = GRAVITY * p1.mass * p2.mass / (dist * dist);

    force.x = magnitude * (p2.position.x - p1.position.x) / dist;
    force.y = magnitude * (p2.position.y - p1.position.y) / dist;

    apply_force(&p1, force);
    apply_force(&p2, (Vector){ -force.x, -force.y });

    update_particle(&p1, DELTA_T);
    update_particle(&p2, DELTA_T);

    printf("t = %d, p1 = (%f, %f), p2 = (%f, %f)\n", i, p1.position.x, p1.position.y, p2.position.x, p2.position.y);
  }
  
  return EXIT_SUCCESS;
}