//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GRAV_CONST 6.67408e-11 // gravitational constant in m^3 kg^-1 s^-2 

// Define a structure for celestial bodies
typedef struct {
  char name[50]; // name of the celestial body
  double mass; // mass of the celestial body in kg
  double x; // x position of celestial body in m
  double y; // y position of celestial body in m
  double vx; // x velocity of celestial body in m/s
  double vy; // y velocity of celestial body in m/s
} CelestialBody;

// Define a function to calculate the force exerted by one celestial body on another
void calculateForce(CelestialBody *body1, CelestialBody *body2) {
  double dx = body2->x - body1->x; // distance between bodies in x direction
  double dy = body2->y - body1->y; // distance between bodies in y direction
  double distance = sqrt(dx*dx + dy*dy); // magnitude of distance
  double force = GRAV_CONST * body1->mass * body2->mass / (distance * distance); // magnitude of gravitational force
  double theta = atan2(dy, dx); // angle between bodies
  double fx = force * cos(theta); // force in x direction
  double fy = force * sin(theta); // force in y direction
  // Add force to acceleration of body1
  body1->vx += fx / body1->mass;
  body1->vy += fy / body1->mass;
  // Subtract force from acceleration of body2
  body2->vx -= fx / body2->mass;
  body2->vy -= fy / body2->mass;
}

// Define a function to update the position and velocity of a celestial body
void updatePosition(CelestialBody *body, double timeStep) {
  body->x += body->vx * timeStep;
  body->y += body->vy * timeStep;
}

int main() {
  // Create the sun
  CelestialBody sun = {"Sun", 1.989e30, 0, 0, 0, 0};
  // Create the earth
  CelestialBody earth = {"Earth", 5.9742e24, 1.49598e11, 0, 0, 29790};
  // Create the moon
  CelestialBody moon = {"Moon", 7.342e22, 1.49598e11+3.844e8, 0, 0, 29790+1022};
  
  // Set up the simulation
  double timeStep = 60*60*24; // time step of one day
  int numSteps = 365; // number of steps in the simulation
  int i, j;
  for (i = 0; i < numSteps; i++) {
    // Update the positions and velocities of the bodies
    updatePosition(&sun, timeStep);
    updatePosition(&earth, timeStep);
    updatePosition(&moon, timeStep);
    // Calculate the forces between the bodies
    // Sun-Earth
    calculateForce(&sun, &earth);
    // Sun-Moon
    calculateForce(&sun, &moon);
    // Earth-Moon
    calculateForce(&earth, &moon);
    // Print the positions of the Earth and Moon
    printf("Step %d: Earth (%lf, %lf) Moon (%lf, %lf)\n", i+1, earth.x, earth.y, moon.x, moon.y);
  }
  return 0; // end program
}