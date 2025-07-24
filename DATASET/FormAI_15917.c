//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
  // Definition of variables
  float height, speed, angle;
  const float g = 9.81; // Acceleration due to gravity in m/s^2 
  printf("Welcome to the physics simulation program!\n");
  
  // User input
  printf("Enter the initial height of the object: ");
  scanf("%f", &height);
  printf("Enter the initial speed of the object: ");
  scanf("%f", &speed);
  printf("Enter the angle of projection in degrees: ");
  scanf("%f", &angle);
  angle = angle * M_PI / 180; // Convert angle to radians
  
  // Computation of time and horizontal and vertical components of velocity
  float t_max = sqrt((2 * height) / g); // Time of flight
  float v_x = speed * cos(angle); //Horizontal velocity
  float v_y = speed * sin(angle); //Vertical velocity
  float t;
  
  // Simulation loop
  for (t = 0.0; t <= t_max; t += 0.1) {
    float x = v_x * t;
    float y = height + (v_y * t) - (0.5 * g * t * t);

    // Output position and time
    printf("Time: %.2f s\t", t);
    printf("Position: (%.2f, %.2f)\n", x, y);
  }
  return 0;
}