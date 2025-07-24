//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11     // Universal Gravitational Constant
#define TIMESTEP 3600     // in seconds

typedef struct {
  double x, y, z;     // Position of planet
  double vx, vy, vz;  // Velocity of planet
  double mass;        // Mass of planet
} Planet;

void update_velocity(Planet *p, double ax, double ay, double az) {
  p->vx += ax * TIMESTEP;
  p->vy += ay * TIMESTEP;
  p->vz += az * TIMESTEP;
}

void update_position(Planet *p) {
  p->x += p->vx * TIMESTEP;
  p->y += p->vy * TIMESTEP;
  p->z += p->vz * TIMESTEP;
}

double distance_between(Planet p1, Planet p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  double dz = p2.z - p1.z;
  double dist_squared = dx*dx + dy*dy + dz*dz;
  return sqrt(dist_squared);
}

double acceleration_due_to_gravity(double r, double m1, double m2) {
  return G * m2 / (r*r);   // Acceleration due to gravity between two objects
}

void update_gravity(Planet *p1, Planet *p2) {
  double r = distance_between(*p1, *p2);
  double a = acceleration_due_to_gravity(r, p1->mass, p2->mass);

  double ax = a * (p2->x - p1->x) / r;
  double ay = a * (p2->y - p1->y) / r;
  double az = a * (p2->z - p1->z) / r;

  update_velocity(p1, ax, ay, az);
}

int main() {
  Planet earth = {0, 0, 0, 0, 0, 0, 5.97e24};
  Planet moon = {384400000, 0, 0, 0, 1022, 0, 7.34e22};

  double time = 0;
  while (time < 86400 * 365 * 20) {     // simulate for 20 years
    update_gravity(&earth, &moon);
    update_gravity(&moon, &earth);

    update_position(&earth);
    update_position(&moon);

    time += TIMESTEP;
  }

  printf("Position of Earth after 20 years: (%lf, %lf, %lf) meters\n", earth.x, earth.y, earth.z);
  printf("Position of Moon after 20 years: (%lf, %lf, %lf) meters\n", moon.x, moon.y, moon.z);
  
  return 0;
}