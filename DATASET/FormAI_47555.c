//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define G 6.67430e-11 // Gravitational constant
#define SIM_TIME 10 // Simulation time in seconds
#define TIME_STEP 0.01 // Time step in seconds
#define NUM_PLANETS 3 // Number of planets in the system

// Planet structure
struct Planet {
  double x_pos;
  double y_pos;
  double z_pos;
  double x_vel;
  double y_vel;
  double z_vel;
  double mass;
} planets[NUM_PLANETS];

// Function to calculate the distance between two planets
double distance(struct Planet *planet1, struct Planet *planet2) {
  double x_diff = planet1->x_pos - planet2->x_pos;
  double y_diff = planet1->y_pos - planet2->y_pos;
  double z_diff = planet1->z_pos - planet2->z_pos;
  return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

// Function to calculate the gravitational force between two planets
double gravitational_force(struct Planet *planet1, struct Planet *planet2) {
  double dist = distance(planet1, planet2);
  double force = G * planet1->mass * planet2->mass / (dist * dist);
  return force;
}

// Function to update the velocity and position of a planet
void update_planet(struct Planet *planet, double force_x, double force_y, double force_z) {
  planet->x_vel += force_x / planet->mass * TIME_STEP;
  planet->y_vel += force_y / planet->mass * TIME_STEP;
  planet->z_vel += force_z / planet->mass * TIME_STEP;
  planet->x_pos += planet->x_vel * TIME_STEP;
  planet->y_pos += planet->y_vel * TIME_STEP;
  planet->z_pos += planet->z_vel * TIME_STEP;
}

int main() {
  srand(time(NULL)); // Seed the random number generator
  // Initialize the planets with random positions, velocities, and masses
  for (int i = 0; i < NUM_PLANETS; i++) {
    planets[i].x_pos = rand() % 10000 - 5000;
    planets[i].y_pos = rand() % 10000 - 5000;
    planets[i].z_pos = rand() % 10000 - 5000;
    planets[i].x_vel = rand() % 100 - 50;
    planets[i].y_vel = rand() % 100 - 50;
    planets[i].z_vel = rand() % 100 - 50;
    planets[i].mass = rand() % 1000000 + 100000;
  }
  // Simulation loop
  double elapsed_time = 0;
  while (elapsed_time < SIM_TIME) {
    // Calculate the forces between all pairs of planets
    double force_x[NUM_PLANETS] = {0};
    double force_y[NUM_PLANETS] = {0};
    double force_z[NUM_PLANETS] = {0};
    for (int i = 0; i < NUM_PLANETS; i++) {
      for (int j = i + 1; j < NUM_PLANETS; j++) {
        double force = gravitational_force(&planets[i], &planets[j]);
        double dist_x = planets[j].x_pos - planets[i].x_pos;
        double dist_y = planets[j].y_pos - planets[i].y_pos;
        double dist_z = planets[j].z_pos - planets[i].z_pos;
        force_x[i] += force * dist_x / distance(&planets[i], &planets[j]);
        force_y[i] += force * dist_y / distance(&planets[i], &planets[j]);
        force_z[i] += force * dist_z / distance(&planets[i], &planets[j]);
        force_x[j] -= force * dist_x / distance(&planets[i], &planets[j]);
        force_y[j] -= force * dist_y / distance(&planets[i], &planets[j]);
        force_z[j] -= force * dist_z / distance(&planets[i], &planets[j]);
      }
    }
    // Update the velocities and positions of all planets
    for (int i = 0; i < NUM_PLANETS; i++) {
      update_planet(&planets[i], force_x[i], force_y[i], force_z[i]);
    }
    // Print the positions and velocities of all planets
    for (int i = 0; i < NUM_PLANETS; i++) {
      printf("Planet %d: (%lf, %lf, %lf) - (%lf, %lf, %lf)\n", i,
             planets[i].x_pos, planets[i].y_pos, planets[i].z_pos,
             planets[i].x_vel, planets[i].y_vel, planets[i].z_vel);
    }
    // Wait for a small amount of time to simulate real time
    usleep(100000);
    // Increment the elapsed time
    elapsed_time += TIME_STEP;
  }
  return 0;
}