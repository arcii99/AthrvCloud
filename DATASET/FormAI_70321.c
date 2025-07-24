//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67e-11
#define EARTH_MASS 5.97e24
#define EARTH_RADIUS 6371000
#define TIME_STEP 1000

struct planet {
  double mass;
  double radius;
  double x, y;
  double vx, vy;
  double ax, ay;
};

typedef struct planet Planet;

double distance(Planet p1, Planet p2) {
  double x_diff = p2.x - p1.x;
  double y_diff = p2.y - p1.y;
  return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

double force(Planet p1, Planet p2) {
  double dist = distance(p1, p2);
  return GRAV_CONST * p1.mass * p2.mass / pow(dist, 2);
}

void update_acceleration(Planet *p, Planet *planets, int n) {
  double ax = 0, ay = 0;
  for (int i = 0; i < n; i++) {
    if (p != &planets[i]) {
      double f = force(*p, planets[i]);
      double dist = distance(*p, planets[i]);
      double angle = atan2(planets[i].y - p->y, planets[i].x - p->x);
      ax += f * cos(angle) / p->mass;
      ay += f * sin(angle) / p->mass;
    }
  }
  p->ax = ax;
  p->ay = ay;
}

void update_velocity(Planet *p, double dt) {
  p->vx += p->ax * dt;
  p->vy += p->ay * dt;
}

void update_position(Planet *p, double dt) {
  p->x += p->vx * dt;
  p->y += p->vy * dt;
}

void simulate(Planet *planets, int n, double duration) {
  double t = 0;
  while (t < duration) {
    for (int i = 0; i < n; i++) {
      update_acceleration(&planets[i], planets, n);
    }
    for (int i = 0; i < n; i++) {
      update_velocity(&planets[i], TIME_STEP);
      update_position(&planets[i], TIME_STEP);
    }
    t += TIME_STEP;
  }
}

int main() {
  Planet earth = { EARTH_MASS, EARTH_RADIUS, 0, 0, 0, 0, 0, 0 };
  Planet moon = { EARTH_MASS / 81.3, 1738100, 0, 384400000, 1022, 0, 0, 0 };
  Planet spacecraft = { 5000, 10, 0, EARTH_RADIUS + 500000, 7777, 0, 0, 0 };
  Planet planets[] = { earth, moon, spacecraft };
  int n_planets = sizeof(planets) / sizeof(Planet);
  double duration = 3600 * 24 * 30;
  simulate(planets, n_planets, duration);
  printf("Moon position: (%f, %f)\n", moon.x, moon.y);
  printf("Spacecraft position: (%f, %f)\n", spacecraft.x, spacecraft.y);
  return 0;
}