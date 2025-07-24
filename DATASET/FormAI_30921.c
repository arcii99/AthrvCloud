//FormAI DATASET v1.0 Category: Physics simulation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main() {
  printf("Welcome to the Physics Simulator!\n");

  // User input
  double velocity, height, angle;
  printf("Enter the initial velocity (m/s): ");
  scanf("%lf", &velocity);
  printf("Enter the initial height (m): ");
  scanf("%lf", &height);
  printf("Enter the launch angle (degree): ");
  scanf("%lf", &angle);

  // Convert angle to radians
  double radian = M_PI / 180 * angle;

  // Initialize constants
  const double gravity = 9.8; // in m/s^2
  const double time_interval = 0.1; // in seconds

  // Initialize variables
  double x_pos = 0;
  double y_pos = height;
  double x_vel = velocity * cos(radian);
  double y_vel = velocity * sin(radian);

  // Simulate projectile motion
  while (y_pos >= 0) {
    // Calculate new position and velocity after time interval
    x_pos += x_vel * time_interval;
    y_vel = y_vel - gravity * time_interval;
    y_pos = y_pos + y_vel * time_interval;

    // Print current position
    printf("x_pos: %f, y_pos: %f\n", x_pos, y_pos);

    // Check if projectile hits the ground
    if (y_pos < 0) {
      printf("The projectile has hit the ground!\n");
    }
  }

  return 0;
}