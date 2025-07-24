//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67408e-11 // gravitational constant

typedef struct {
  double x, y, z; // position
  double vx, vy, vz; // velocity
  double ax, ay, az; // acceleration
  double mass; // mass
} Body;

void update_velocity(Body *a, Body *b, double dt) {
  double dx = b->x - a->x;
  double dy = b->y - a->y;
  double dz = b->z - a->z;
  double dist = sqrt(dx*dx + dy*dy + dz*dz);

  // calculate gravitational force
  double f = GRAV_CONST * a->mass * b->mass / (dist * dist);
  double fx = f * dx / dist;
  double fy = f * dy / dist;
  double fz = f * dz / dist;

  // update acceleration
  a->ax += fx / a->mass;
  a->ay += fy / a->mass;
  a->az += fz / a->mass;
  b->ax -= fx / b->mass;
  b->ay -= fy / b->mass;
  b->az -= fz / b->mass;

  // update velocity
  a->vx += a->ax * dt;
  a->vy += a->ay * dt;
  a->vz += a->az * dt;
  b->vx += b->ax * dt;
  b->vy += b->ay * dt;
  b->vz += b->az * dt;
}

void update_position(Body *body, double dt) {
  body->x += body->vx * dt;
  body->y += body->vy * dt;
  body->z += body->vz * dt;
}

int main() {
  // initialize bodies
  Body sun = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.989e30};
  Body earth = {1.496e11, 0.0, 0.0, 0.0, 29783.0, 0.0, 0.0, 0.0, 0.0, 5.972e24};
  Body moon = {1.496e11+3.844e8, 0.0, 0.0, 0.0, 29783.0+1022.0, 0.0, 0.0, 0.0, 0.0, 7.342e22};

  double dt = 60.0; // time step (in seconds)
  double t = 0.0; // time

  while (1) {
    // simulate gravity for one time step
    update_velocity(&sun, &earth, dt);
    update_velocity(&sun, &moon, dt);
    update_velocity(&earth, &moon, dt);

    update_position(&sun, dt);
    update_position(&earth, dt);
    update_position(&moon, dt);

    t += dt; // increment time

    printf("t=%.0f s: sun=(%.2e, %.2e, %.2e), earth=(%.2e, %.2e, %.2e), moon=(%.2e, %.2e, %.2e)\n",
           t, sun.x, sun.y, sun.z, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
  }

  return 0;
}