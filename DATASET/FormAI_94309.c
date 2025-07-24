//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

/* Define constants */
const double G = 6.674e-11;  // gravitational constant (m^3 / kg * s^2)
const double AU = 149.6e9;   // astronomical unit (m)

/* Define planet struct */
struct planet {
  char name[20];
  double mass;              // in kg
  double radius;            // in m
  double x, y, z;           // position in m
  double vx, vy, vz;        // velocity in m/s
};

/* Define function to calculate distance between two planets */
double distance(struct planet p1, struct planet p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  double dz = p2.z - p1.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

/* Define function to calculate gravitational force between two planets */
double force(struct planet p1, struct planet p2) {
  double r = distance(p1, p2);
  return G * p1.mass * p2.mass / (r*r);
}

int main() {
  /* Declare planets */
  struct planet planets[NUM_PLANETS] = {
    {"Sun", 1.989e30, 696.3e6, 0, 0, 0, 0, 0, 0},
    {"Mercury", 3.285e23, 2.44e6, 0, 57.9e9, 0, 0, 47.87e3, 0},
    {"Venus", 4.867e24, 6.052e6, 0, 108.2e9, 0, 0, 35.02e3, 0},
    {"Earth", 5.972e24, 6.371e6, 0, 149.6e9, 0, 0, 29.78e3, 0},
    {"Mars", 6.39e23, 3.39e6, 0, 227.9e9, 0, 0, 24.13e3, 0},
    {"Jupiter", 1.898e27, 69.91e6, 0, 778.6e9, 0, 0, 13.07e3, 0},
    {"Saturn", 5.683e26, 58.23e6, 0, 1.434e12, 0, 0, 9.69e3, 0},
    {"Uranus", 8.681e25, 25.36e6, 0, 2.871e12, 0, 0, 6.81e3, 0}
  };

  /* Set simulation parameters */
  double dt = 3600 * 24; // time step in seconds
  double t = 0;          // current time in seconds
  double tf = 3600 * 24 * 365 * 5; // final simulation time in seconds

  /* Run simulation */
  while (t < tf) {
    /* Calculate forces on each planet */
    for (int i = 0; i < NUM_PLANETS; i++) {
      double fx = 0, fy = 0, fz = 0;
      for (int j = 0; j < NUM_PLANETS; j++) {
        if (i == j) continue;
        double f = force(planets[i], planets[j]);
        double dx = planets[j].x - planets[i].x;
        double dy = planets[j].y - planets[i].y;
        double dz = planets[j].z - planets[i].z;
        fx += f * dx / distance(planets[i], planets[j]);
        fy += f * dy / distance(planets[i], planets[j]);
        fz += f * dz / distance(planets[i], planets[j]);
      }
      /* Update velocity and position of planet */
      planets[i].vx += fx / planets[i].mass * dt;
      planets[i].vy += fy / planets[i].mass * dt;
      planets[i].vz += fz / planets[i].mass * dt;
      planets[i].x += planets[i].vx * dt;
      planets[i].y += planets[i].vy * dt;
      planets[i].z += planets[i].vz * dt;
    }
    /* Increment time */
    t += dt;
  }

  /* Print final positions of each planet */
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s: (%.2f AU, %.2f AU, %.2f AU)\n", planets[i].name,
           planets[i].x / AU, planets[i].y / AU, planets[i].z / AU);
  }

  return 0;
}