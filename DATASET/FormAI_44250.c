//FormAI DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <math.h>

int main() {

  float length_m = 1.2; // Length of the pendulum in meters
  float mass_kg = 0.5; // Mass of the pendulum bob in kilograms
  float time_s = 0; // Time in seconds
  float time_step = 0.01; // Time step in seconds
  float angle = 1.5; // Initial angle of the pendulum in radians
  float velocity = 0; // Initial velocity of the pendulum in m/s
  float air_resistance = 0.1; // Coefficient of air resistance
  float g = 9.81; // Acceleration due to gravity in m/s^2
  float damping_factor = 0.1; // Damping factor due to friction

  while (time_s < 60) { // Simulate for 60 seconds
    // Calculate the acceleration of the pendulum
    float acceleration = - (g/length_m) * sin(angle) - (air_resistance/mass_kg) * velocity;

    // Update the velocity and angle of the pendulum
    velocity += acceleration * time_step;
    angle += velocity * time_step;

    // Apply damping to the velocity of the pendulum
    velocity *= (1 - damping_factor);

    // Print out the time, angle, and velocity of the pendulum
    printf("Time: %f s, Angle: %f rad, Velocity: %f m/s\n", time_s, angle, velocity);

    // Increase the time by the time step
    time_s += time_step;
  }

  return 0;
}