//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

typedef struct planet_t {
  double x, y, z; // position (in meters)
  double vx, vy, vz; // velocity (in meters/second)
  double mass; // mass (in kilograms)
  double fx, fy, fz; // force being applied on the planet (in newtons)
} planet;

planet* planet_create(double x, double y, double z, double vx, double vy, double vz, double mass) {
  planet* p = (planet*) malloc(sizeof(planet));
  p->x = x;
  p->y = y;
  p->z = z;
  p->vx = vx;
  p->vy = vy;
  p->vz = vz;
  p->mass = mass;
  return p;
}

void planet_destroy(planet* p) {
  free(p);
}

void planet_print(planet* p) {
  printf("x = %f meters\n", p->x);
  printf("y = %f meters\n", p->y);
  printf("z = %f meters\n", p->z);
  printf("vx = %f meters/second\n", p->vx);
  printf("vy = %f meters/second\n", p->vy);
  printf("vz = %f meters/second\n", p->vz);
  printf("mass = %f kg\n", p->mass);
}

void planet_apply_force(planet* p1, planet* p2) {
  double r = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
  double f = G * p1->mass * p2->mass / pow(r, 2);
  p1->fx += f * (p2->x - p1->x) / r;
  p1->fy += f * (p2->y - p1->y) / r;
  p1->fz += f * (p2->z - p1->z) / r;
}

void planet_update(planet* p, double dt) {
  p->vx += p->fx / p->mass * dt;
  p->vy += p->fy / p->mass * dt;
  p->vz += p->fz / p->mass * dt;
  p->x += p->vx * dt;
  p->y += p->vy * dt;
  p->z += p->vz * dt;
  p->fx = 0;
  p->fy = 0;
  p->fz = 0;
}

int main() {
  planet* earth = planet_create(0, 0, 0, 0, 0, 0, 5.97e24);
  planet* moon = planet_create(384400000, 0, 0, 0, 1022, 0, 7.35e22);
  planet* mars = planet_create(0, 227939200000.0, 0, -24000, 0, 0, 6.42e23);
  planet* jupiter = planet_create(778369000000.0, 0, 0, 0, 13100, 0, 1.90e27);
  planet* saturn = planet_create(1433536000000.0, 0, 0, 0, 9600, 0, 5.68e26);
  planet* uranus = planet_create(2876679082000.0, 0, 0, 0, 6800, 0, 8.68e25);
  planet* neptune = planet_create(4503443661000.0, 0, 0, 0, 5400, 0, 1.02e26);

  double dt = 3600; // timestep (in seconds)
  double t = 0; // current time (in seconds)
  double end = 365 * 24 * 3600; // end time (in seconds)

  while (t < end) {
    planet_apply_force(earth, moon);
    planet_apply_force(earth, mars);
    planet_apply_force(earth, jupiter);
    planet_apply_force(earth, saturn);
    planet_apply_force(earth, uranus);
    planet_apply_force(earth, neptune);
    planet_apply_force(moon, earth);
    planet_apply_force(mars, earth);
    planet_apply_force(jupiter, earth);
    planet_apply_force(saturn, earth);
    planet_apply_force(uranus, earth);
    planet_apply_force(neptune, earth);
    planet_update(earth, dt);
    planet_update(moon, dt);
    planet_update(mars, dt);
    planet_update(jupiter, dt);
    planet_update(saturn, dt);
    planet_update(uranus, dt);
    planet_update(neptune, dt);
    t += dt;
  }

  printf("Earth:\n");
  planet_print(earth);
  planet_destroy(earth);
  printf("\n");
  printf("Moon:\n");
  planet_print(moon);
  planet_destroy(moon);
  printf("\n");
  printf("Mars:\n");
  planet_print(mars);
  planet_destroy(mars);
  printf("\n");
  printf("Jupiter:\n");
  planet_print(jupiter);
  planet_destroy(jupiter);
  printf("\n");
  printf("Saturn:\n");
  planet_print(saturn);
  planet_destroy(saturn);
  printf("\n");
  printf("Uranus:\n");
  planet_print(uranus);
  planet_destroy(uranus);
  printf("\n");
  printf("Neptune:\n");
  planet_print(neptune);
  planet_destroy(neptune);

  return 0;
}