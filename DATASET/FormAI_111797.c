//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define G 6.673e-11 // Gravitational constant

struct planet {
  char name[20];
  double mass;
  double radius;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
};

void update_speed(struct planet *p1, struct planet *p2, double d_x, double d_y, double d_z, double dt) {
  double d = sqrt(d_x*d_x + d_y*d_y + d_z*d_z); // Distance between planets
  double force = G * p1->mass * p2->mass / (d * d); // Force between planets
  double a1 = force / p1->mass; // Acceleration of p1
  double a2 = force / p2->mass; // Acceleration of p2
  p1->vx += a2 * d_x / d * dt; // Update speed of p1
  p1->vy += a2 * d_y / d * dt;
  p1->vz += a2 * d_z / d * dt;
  p2->vx -= a1 * d_x / d * dt; // Update speed of p2
  p2->vy -= a1 * d_y / d * dt;
  p2->vz -= a1 * d_z / d * dt;
}

void update_position(struct planet *p, double dt) {
  p->x += p->vx * dt; // Update position based on speed
  p->y += p->vy * dt;
  p->z += p->vz * dt;
}

int main() {
  struct planet earth = {"Earth", 5.97e24, 6371e3, 0, 0, 0, 0, 0, 0};
  struct planet moon = {"Moon", 7.34e22, 1737e3, 3.84e8, 0, 0, 0, 1022, 0};
  double dt = 60; // Time step in seconds

  for (int i = 0; i < 86400; i+=dt) { // Loop for one day
    double d_x = moon.x - earth.x;
    double d_y = moon.y - earth.y;
    double d_z = moon.z - earth.z;
    update_speed(&earth, &moon, d_x, d_y, d_z, dt);
    update_position(&earth, dt);
    update_position(&moon, dt);
  }

  printf("%s: x = %f m, y = %f m, z = %f m\n", earth.name, earth.x, earth.y, earth.z);
  printf("%s: x = %f m, y = %f m, z = %f m\n", moon.name, moon.x, moon.y, moon.z);

  return 0;
}