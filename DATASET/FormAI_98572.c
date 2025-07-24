//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 6.674e-11; // gravitational constant
const double M = 5.97e24; // mass of the Earth

struct planet {
  double x, y; // position
  double vx, vy; // velocity
  double m; // mass
};

void simulate(struct planet p[], int n, double dt) {
  // calculate net force on each planet
  double fx, fy, r, f;
  for (int i = 0; i < n; i++) {
    fx = fy = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      r = sqrt(pow(p[j].x - p[i].x, 2) + pow(p[j].y - p[i].y, 2));
      f = G * p[i].m * p[j].m / pow(r, 2);
      fx += f * (p[j].x - p[i].x) / r;
      fy += f * (p[j].y - p[i].y) / r;
    }
    // update velocity and position
    p[i].vx += fx / p[i].m * dt;
    p[i].vy += fy / p[i].m * dt;
    p[i].x += p[i].vx * dt;
    p[i].y += p[i].vy * dt;
  }
}

int main() {
  // initialize planets
  struct planet earth = {0, 0, 0, 0, M};
  struct planet moon = {384e6, 0, 0, 1022, 7.35e22};
  struct planet mars = {227.9e9, 0, 0, 24080, 6.39e23};
  struct planet planets[] = {earth, moon, mars};
  int n = sizeof(planets) / sizeof(struct planet);

  // simulate gravity for 1 year
  double dt = 86400; // time step of one day
  int steps = 365; // number of steps in one year
  for (int i = 0; i < steps; i++) {
    simulate(planets, n, dt);
  }

  // print final positions and velocities
  printf("Earth: (%g, %g) vel: (%g, %g)\n", earth.x, earth.y, earth.vx, earth.vy);
  printf("Moon: (%g, %g) vel: (%g, %g)\n", moon.x, moon.y, moon.vx, moon.vy);
  printf("Mars: (%g, %g) vel: (%g, %g)\n", mars.x, mars.y, mars.vx, mars.vy);

  return 0;
}