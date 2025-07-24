//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant

// Structure to hold information about each object in the solar system
typedef struct {
  double mass;     // mass in kg
  double x,y,z;    // position in m
  double vx,vy,vz; // velocity in m/s
} Object;

int main() {
  // Create array of objects for the solar system
  Object objects[] = {
    { 1.98e30, 0, 0, 0, 0, 0 },          // Sun
    { 5.97e24, 1.5e11, 0, 0, 2.98e4, 0 }, // Earth
    { 7.34e22, 3.84e8+1.5e11, 0, 0, 1.02e3+2.98e4, 0 } // Moon
  };
  int numObjects = sizeof(objects) / sizeof(Object);

  // Set up simulation parameters
  double dt = 86400.0;  // Time step in seconds (1 day)
  double endTime = 365*86400.0; // End time in seconds (1 year)

  // Perform simulation
  for (double time = 0; time <= endTime; time += dt) {
    // Print current time and positions of all objects
    printf("Time: %.0lf s\n", time);
    for (int i = 0; i < numObjects; i++)
      printf("Object %d: (%.2e, %.2e, %.2e)\n", i, objects[i].x, objects[i].y, objects[i].z);

    // Calculate forces between all pairs of objects
    for (int i = 0; i < numObjects; i++) {
      for (int j = i+1; j < numObjects; j++) {
        // Calculate distance between objects
        double dx = objects[j].x - objects[i].x;
        double dy = objects[j].y - objects[i].y;
        double dz = objects[j].z - objects[i].z;
        double r = sqrt(dx*dx + dy*dy + dz*dz);

        // Calculate gravitational force between objects
        double F = G * objects[i].mass * objects[j].mass / (r*r);

        // Calculate force components and add to each object's total force
        objects[i].vx += F * dx / (r * objects[i].mass);
        objects[i].vy += F * dy / (r * objects[i].mass);
        objects[i].vz += F * dz / (r * objects[i].mass);
        objects[j].vx -= F * dx / (r * objects[j].mass);
        objects[j].vy -= F * dy / (r * objects[j].mass);
        objects[j].vz -= F * dz / (r * objects[j].mass);
      }
    }

    // Update positions and velocities of all objects
    for (int i = 0; i < numObjects; i++) {
      objects[i].x += objects[i].vx * dt;
      objects[i].y += objects[i].vy * dt;
      objects[i].z += objects[i].vz * dt;
    }
  }

  return 0;
}