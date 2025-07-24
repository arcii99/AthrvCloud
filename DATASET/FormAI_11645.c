//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11         // Gravitational constant
#define DELTA_T 0.1            // Time step
#define STEPS 1000             // Number of time steps to simulate

typedef struct {
  double x, y;                 // Position
  double vx, vy;               // Velocity
  double ax, ay;               // Acceleration
  double m;                    // Mass
} body;

int main() {
  body planet = {0, 0, 0, 0, 0, 5.972e24};  // Earth
  body moon = {384400000, 0, 0, 1022, 0, 7.342e22};  // Moon

  for (int i=0; i<STEPS; i++) {
    double distance = sqrt(pow(planet.x-moon.x, 2) + pow(planet.y-moon.y, 2));
    double force = G * planet.m * moon.m / pow(distance, 2);
    double fx = force * (moon.x-planet.x) / distance;
    double fy = force * (moon.y-planet.y) / distance;

    // Update planet
    planet.ax = fx / planet.m;
    planet.ay = fy / planet.m;
    planet.vx += planet.ax * DELTA_T;
    planet.vy += planet.ay * DELTA_T;
    planet.x += planet.vx * DELTA_T;
    planet.y += planet.vy * DELTA_T;

    // Update moon
    moon.ax = -fx / moon.m;
    moon.ay = -fy / moon.m;
    moon.vx += moon.ax * DELTA_T;
    moon.vy += moon.ay * DELTA_T;
    moon.x += moon.vx * DELTA_T;
    moon.y += moon.vy * DELTA_T;

    printf("Step %d: Planet=(%.3f,%.3f) Moon=(%.3f,%.3f)\n",
           i, planet.x, planet.y, moon.x, moon.y);
  }

  return 0;
}