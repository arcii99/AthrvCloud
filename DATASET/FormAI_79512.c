//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define TIME_STEP 3600 // simulation time step in seconds
#define NUM_PLANETS 4 // number of planets in the simulation
#define DURATION 31556926.6 // duration of simulation in seconds (1 earth year)


// Structure to hold information about a planet
struct Planet {
  char name[20]; // name of planet
  double mass; // mass of planet in kg
  double x, y, z; // position of planet in m
  double vx, vy, vz; // velocity of planet in m/s
};

// Function to calculate distance between two planets
double getDistance(struct Planet a, struct Planet b) {
  double x_diff = b.x - a.x;
  double y_diff = b.y - a.y;
  double z_diff = b.z - a.z;
  return sqrt(x_diff*x_diff + y_diff*y_diff + z_diff*z_diff);
}

// Function to calculate the force between two planets
double getForce(double mass_a, double mass_b, double distance) {
  return (G * mass_a * mass_b) / pow(distance, 2);
}

// Function to update the positions and velocities of all planets in the simulation
void updatePlanets(struct Planet planets[NUM_PLANETS]) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    double force_x = 0, force_y = 0, force_z = 0;
    for (int j = 0; j < NUM_PLANETS; j++) {
      if (i == j) continue; // skip if planet is interacting with itself
      double distance = getDistance(planets[i], planets[j]);
      double force = getForce(planets[i].mass, planets[j].mass, distance);
      double x_diff = planets[j].x - planets[i].x;
      double y_diff = planets[j].y - planets[i].y;
      double z_diff = planets[j].z - planets[i].z;
      force_x += force * x_diff / distance;
      force_y += force * y_diff / distance;
      force_z += force * z_diff / distance;
    }
    // update velocities
    planets[i].vx += force_x / planets[i].mass * TIME_STEP;
    planets[i].vy += force_y / planets[i].mass * TIME_STEP;
    planets[i].vz += force_z / planets[i].mass * TIME_STEP;
    // update positions
    planets[i].x += planets[i].vx * TIME_STEP;
    planets[i].y += planets[i].vy * TIME_STEP;
    planets[i].z += planets[i].vz * TIME_STEP;
  }
}

int main() {

  // create array of planets to simulate
  struct Planet planets[NUM_PLANETS] = {
    {"Earth", 5.972e24, 0, 0, 0, 0, 0, 0},
    {"Mars", 6.39e23, 227939200e1, 0, 0, 0, 24077.7, 0},
    {"Jupiter", 1.898e27, 778500000e1, 0, 0, 0, 13069.7, 0},
    {"Saturn", 5.683e26, 1429400000e1, 0, 0, 0, 9643.4, 0}
  };
  
  // print initial positions of planets
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s: (%f, %f, %f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
  }

  // main simulation loop
  double time = 0;
  while (time < DURATION) {
    updatePlanets(planets);
    time += TIME_STEP;
  }

  // print final positions of planets
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s: (%f, %f, %f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
  }

  return 0;
}