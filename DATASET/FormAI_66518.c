//FormAI DATASET v1.0 Category: Physics simulation ; Style: creative
#include <stdio.h>
#include <math.h>

// Define constants
#define MASS 10.0     // Mass of object in kg
#define GRAVITY 9.81  // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.01 // Time step in seconds
#define STOP_TIME 10.0 // Stop time in seconds
#define DRAG_COEFF 0.2 // Drag coefficient

// Define global variables
double position = 0;   // Initial position
double velocity = 0;   // Initial velocity
double time = 0;       // Starting time
double force = 0;      // Force acting on object
double acceleration = 0; // Acceleration of object
double drag = 0; // Drag acting on object

int main() {
  // Header
  printf("Simulation of a Falling Object With Air Resistance\n");
  printf("----------------------------------------------\n");

  // Loop through time
  while (time <= STOP_TIME) {
    // Calculate force
    force = MASS * GRAVITY;
    
    // Calculate drag
    drag = DRAG_COEFF * velocity * velocity;
    
    // Calculate acceleration
    acceleration = (force - drag) / MASS;
    
    // Update velocity and position using Euler's method
    velocity += acceleration * TIME_STEP;
    position += velocity * TIME_STEP;

    // Print values for current time
    printf("Time: %.2lf s, Position: %.2lf m, Velocity %.2lf m/s\n", time, position, velocity);
    
    // Increment time
    time += TIME_STEP;
  }

  printf("----------------------------------------------\n");
  printf("Final Position: %.2lf m, Final Velocity: %.2lf m/s\n", position, velocity);

  // Exit program
  return 0;
}