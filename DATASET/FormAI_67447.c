//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673E-11  // gravitational constant
#define TIME_STEP 3600  // in seconds
#define NUM_PLANETS 8  // number of planets
#define NUM_COORDS 3   // x, y, z coordinates

double initial_state[NUM_PLANETS][NUM_COORDS] = {
  {0, 0, 0},           // Sun
  {0, 57.91E9, 0},     // Mercury
  {0, 108.2E9, 0},     // Venus
  {-149.6E9, 0, 0},    // Earth
  {0, -227.9E9, 0},    // Mars
  {778.5E9, 0, 0},     // Jupiter
  {0, 1.429E12, 0},    // Saturn
  {0, 2.871E12, 0}     // Uranus
};

double mass[NUM_PLANETS] = {
  1.989E30,    // Sun
  3.301E23,    // Mercury
  4.867E24,    // Venus
  5.972E24,    // Earth
  6.39E23,     // Mars
  1.898E27,    // Jupiter
  5.683E26,    // Saturn
  8.681E25     // Uranus
};

double distance(double state1[NUM_COORDS], double state2[NUM_COORDS]) {
  double x_diff = state1[0] - state2[0];
  double y_diff = state1[1] - state2[1];
  double z_diff = state1[2] - state2[2];
  return sqrt(x_diff*x_diff + y_diff*y_diff + z_diff*z_diff);
}

int main() {
  double state[NUM_PLANETS][NUM_COORDS];
  double acceleration[NUM_PLANETS][NUM_COORDS];
  double velocity[NUM_PLANETS][NUM_COORDS];
  double force[NUM_PLANETS][NUM_PLANETS][NUM_COORDS];
  
  // Initialize state and velocity arrays
  for (int i = 0; i < NUM_PLANETS; i++) {
    for (int j = 0; j < NUM_COORDS; j++) {
      state[i][j] = initial_state[i][j];
      velocity[i][j] = 0;
    }
  }
  
  // Run simulation for 1 year (in seconds)
  for (double t = 0; t <= 3.154e+7; t += TIME_STEP) {
    // Calculate force between pairs of planets
    for (int i = 0; i < NUM_PLANETS-1; i++) {
      for (int j = i+1; j < NUM_PLANETS; j++) {
        double dist = distance(state[i], state[j]);
        double magn = (G*mass[i]*mass[j]) / (dist*dist);
        double dir_vec[NUM_COORDS];
        for (int k = 0; k < NUM_COORDS; k++) {
          dir_vec[k] = (state[j][k]-state[i][k]) / dist;
          force[i][j][k] = dir_vec[k] * magn;
          force[j][i][k] = -dir_vec[k] * magn;
        }
      }
    }

    // Calculate net force and acceleration for each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
      for (int k = 0; k < NUM_COORDS; k++) {
        acceleration[i][k] = 0;
        for (int j = 0; j < NUM_PLANETS; j++) {
          acceleration[i][k] += force[i][j][k] / mass[i];
        }
        state[i][k] += velocity[i][k] * TIME_STEP + 0.5 * acceleration[i][k] * TIME_STEP * TIME_STEP;
        velocity[i][k] += 0.5 * acceleration[i][k] * TIME_STEP;
      }
    }
  }
  
  // Print final coordinates of each planet
  printf("Final state (in meters):\n");
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("Planet %d: %f, %f, %f\n", i, state[i][0], state[i][1], state[i][2]);
  }
  
  return 0;
}