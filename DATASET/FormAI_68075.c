//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67e-11     // Gravitational constant
#define SIM_TIME 86400  // Simulation time in seconds (1 earth day)
#define TICK_TIME 3600  // Time interval for calculations in seconds (1 hour)

// Struct to represent a celestial body
typedef struct {
  double mass;
  double x_pos;
  double y_pos;
  double z_pos;
  double x_vel;
  double y_vel;
  double z_vel;
} Body;

// Function to calculate distance between two celestial bodies
double distance(Body body1, Body body2) {
  return sqrt(pow(body2.x_pos - body1.x_pos, 2) +
              pow(body2.y_pos - body1.y_pos, 2) +
              pow(body2.z_pos - body1.z_pos, 2));
}

// Function to calculate gravitational force between two celestial bodies
double force(Body body1, Body body2) {
  double dist = distance(body1, body2);
  return (G * body1.mass * body2.mass) / pow(dist, 2);
}

// Function to calculate acceleration of a celestial body due to gravitational forces
void calculateAcceleration(Body* body, Body* bodies, int numBodies) {
  double x_acc = 0;
  double y_acc = 0;
  double z_acc = 0;
  
  for (int i = 0; i < numBodies; i++) {
    if (body != &bodies[i]) {
      double f = force(*body, bodies[i]);
      x_acc += f * (bodies[i].x_pos - body->x_pos) / distance(*body, bodies[i]);
      y_acc += f * (bodies[i].y_pos - body->y_pos) / distance(*body, bodies[i]);
      z_acc += f * (bodies[i].z_pos - body->z_pos) / distance(*body, bodies[i]);
    }
  }
  
  body->x_vel += x_acc * TICK_TIME;
  body->y_vel += y_acc * TICK_TIME;
  body->z_vel += z_acc * TICK_TIME;
}

// Function to update position of a celestial body based on velocity and time
void updatePosition(Body* body) {
  body->x_pos += body->x_vel * TICK_TIME;
  body->y_pos += body->y_vel * TICK_TIME;
  body->z_pos += body->z_vel * TICK_TIME;
}

int main() {
  srand(time(NULL));  // Seed random number generator
  
  int numBodies = 10;  // Number of celestial bodies in simulation
  Body bodies[numBodies];  // Array to hold celestial bodies

  // Initialize celestial bodies randomly
  for (int i = 0; i < numBodies; i++) {
    bodies[i].mass = (double)rand() / RAND_MAX * 1e24;  // Random mass between 0 and 1e24 kg
    bodies[i].x_pos = (double)rand() / RAND_MAX * 1e11;  // Random position between 0 and 1e11 m
    bodies[i].y_pos = (double)rand() / RAND_MAX * 1e11;  // Random position between 0 and 1e11 m
    bodies[i].z_pos = (double)rand() / RAND_MAX * 1e11;  // Random position between 0 and 1e11 m
    bodies[i].x_vel = (double)rand() / RAND_MAX * 1e4;   // Random velocity between 0 and 1e4 m/s
    bodies[i].y_vel = (double)rand() / RAND_MAX * 1e4;   // Random velocity between 0 and 1e4 m/s
    bodies[i].z_vel = (double)rand() / RAND_MAX * 1e4;   // Random velocity between 0 and 1e4 m/s
  }
  
  // Run simulation for specified time
  for (int t = 0; t < SIM_TIME; t += TICK_TIME) {
    // Update position and velocity of all bodies
    for (int i = 0; i < numBodies; i++) {
      calculateAcceleration(&bodies[i], bodies, numBodies);
      updatePosition(&bodies[i]);
    }
  }

  return 0;
}