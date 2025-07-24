//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 3
#define SIMULATION_TIME 10

struct planet {
  char name[50];
  double mass;
  double position[3]; // x, y, z
  double velocity[3];
};

struct planet planets[NUM_PLANETS];

const double G = 6.67430e-11; // gravitational constant

void simulate_planets() {
  double force[NUM_PLANETS][3] = {0}; // initialize all values to zero

  // calculate forces between planets
  for (int i = 0; i < NUM_PLANETS; i++) {
    for (int j = i + 1; j < NUM_PLANETS; j++) {
      double dx = planets[j].position[0] - planets[i].position[0];
      double dy = planets[j].position[1] - planets[i].position[1];
      double dz = planets[j].position[2] - planets[i].position[2];
      double distance = sqrt(dx*dx + dy*dy + dz*dz);

      double f = G * planets[i].mass * planets[j].mass / (distance * distance);
      double fx = f * dx / distance;
      double fy = f * dy / distance;
      double fz = f * dz / distance;

      force[i][0] += fx;
      force[i][1] += fy;
      force[i][2] += fz;
      force[j][0] -= fx; // Newton's 3rd law
      force[j][1] -= fy;
      force[j][2] -= fz;
    }
  }

  // update positions and velocities
  for (int i = 0; i < NUM_PLANETS; i++) {
    double ax = force[i][0] / planets[i].mass;
    double ay = force[i][1] / planets[i].mass;
    double az = force[i][2] / planets[i].mass;
    planets[i].velocity[0] += ax * SIMULATION_TIME;
    planets[i].velocity[1] += ay * SIMULATION_TIME;
    planets[i].velocity[2] += az * SIMULATION_TIME;
    planets[i].position[0] += planets[i].velocity[0] * SIMULATION_TIME;
    planets[i].position[1] += planets[i].velocity[1] * SIMULATION_TIME;
    planets[i].position[2] += planets[i].velocity[2] * SIMULATION_TIME;
  }
}

int main() {
  // initialize planets
  strcpy(planets[0].name, "Earth");
  planets[0].mass = 5.972e24;
  planets[0].position[0] = 0;
  planets[0].position[1] = 0;
  planets[0].position[2] = 0;
  planets[0].velocity[0] = 0;
  planets[0].velocity[1] = 0;
  planets[0].velocity[2] = 0;

  strcpy(planets[1].name, "Mars");
  planets[1].mass = 6.39e23;
  planets[1].position[0] = 200e6;
  planets[1].position[1] = 0;
  planets[1].position[2] = 0;
  planets[1].velocity[0] = 0;
  planets[1].velocity[1] = 24000;
  planets[1].velocity[2] = 0;

  strcpy(planets[2].name, "Jupiter");
  planets[2].mass = 1.898e27;
  planets[2].position[0] = 0;
  planets[2].position[1] = 778e6;
  planets[2].position[2] = 0;
  planets[2].velocity[0] = 13000;
  planets[2].velocity[1] = 0;
  planets[2].velocity[2] = 0;

  for (double t = 0; t < SIMULATION_TIME; t++) {
    simulate_planets();
  }

  // print final positions and velocities
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s:\n", planets[i].name);
    printf("   Position: (%f, %f, %f)\n", planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    printf("   Velocity: (%f, %f, %f)\n", planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
  }

  return 0;
}