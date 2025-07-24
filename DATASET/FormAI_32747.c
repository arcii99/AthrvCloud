//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Simulation constants
  const float GRAVITY = 9.81; // m/s^2
  const float TIME_STEP = 0.1; // seconds  
  const float COEFFICIENT_OF_RESTITUTION = 0.8; 
  const int SIMULATION_STEPS = 10000; 
    
  // Object properties
  float ball_mass = 1.0; // kg
  float ball_radius = 0.1; // m
  float ball_position = 1.5;
  float ball_velocity = 0;
    
  // Ground properties
  float ground_position = 0;
  
  // Simulation loop
  for(int i = 0; i < SIMULATION_STEPS; i++) {
    // Calculate forces
    float force_gravity = GRAVITY * ball_mass;
    float force_normal = -force_gravity;
    float force_net = force_gravity + force_normal;

    // If ball touches the ground, calculate rebound velocity
    if(ball_position - ball_radius <= ground_position) {
      ball_velocity = -COEFFICIENT_OF_RESTITUTION * ball_velocity;
    }
    
    // Update position and velocity using integration
    ball_velocity += (force_net / ball_mass) * TIME_STEP;
    ball_position += ball_velocity * TIME_STEP;
    
    // Print ball's position
    printf("Step %d : Ball position = %.2f\n", i+1, ball_position);
  }
  
  return 0;
}