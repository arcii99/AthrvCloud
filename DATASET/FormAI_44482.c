//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: calm
#include <stdio.h>
#include <math.h>
#define G 6.674e-11

struct planet {
  char name[20];
  double mass; // kg
  double x, y, z; // position in m
  double vx, vy, vz; // velocity in m/s
  double ax, ay, az; // acceleration in m/s^2
};

void update_acceleration(struct planet *p, struct planet planets[], int n) {
  // Calculate gravitational forces between planets
  for (int i = 0; i < n; i++) {
    if (p == &planets[i]) continue;
    double dx = planets[i].x - p->x;
    double dy = planets[i].y - p->y;
    double dz = planets[i].z - p->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p->mass * planets[i].mass / (r*r);
    p->ax += f * dx / r / p->mass;
    p->ay += f * dy / r / p->mass;
    p->az += f * dz / r / p->mass;
  }
}

void update_velocity(struct planet *p, double dt) {
  p->vx += p->ax * dt;
  p->vy += p->ay * dt;
  p->vz += p->az * dt;
}

void update_position(struct planet *p, double dt) {
  p->x += p->vx * dt;
  p->y += p->vy * dt;
  p->z += p->vz * dt;
}

void print_planet(struct planet *p) {
  printf("%s: (%g, %g, %g)\n", p->name, p->x, p->y, p->z);
}

int main() {
  // Three planets: Earth, Moon, and Sun
  struct planet planets[3] = {
    {"Earth", 5.97e24, -1.47e11, 0, 0, 0, -3.028e4, 0},
    {"Moon", 7.35e22, -1.47e11+3.84e8, 0, 0, 1.022e3-3.028e4, -1.023e3, 0},
    {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0}
  };
  int n = sizeof(planets) / sizeof(struct planet);

  double dt = 86400; // one day
  int steps = 365; // one Earth year

  for (int i = 0; i < steps; i++) {
    for (int j = 0; j < n; j++) {
      struct planet *p = &planets[j];
      p->ax = p->ay = p->az = 0;
      update_acceleration(p, planets, n);
      update_velocity(p, dt);
      update_position(p, dt);
    }
  }

  for (int i = 0; i < n; i++) {
    print_planet(&planets[i]);
  }

  return 0;
}