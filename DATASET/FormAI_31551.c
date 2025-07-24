//FormAI DATASET v1.0 Category: Physics simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
  float velocity_y = 20; // Initial velocity in y-axis
  float velocity_x = 30; // Initial velocity in x-axis
  float angle = 45; // Angle of launch
  float gravity = 9.8; // Acceleration due to gravity
  float time = 0; // Time taken for projectile to land
  float distance = 0; // Total distance travelled by projectile
  float height = 0; // Max height attained by projectile
  float delta_t = 0.01; // Time interval
  float x = 0; // Projectile's x position
  float y = 0; // Projectile's y position

  // Convert angle to radians
  float radians = angle * 3.14 / 180;

  while (y >= 0) {
    // Update time
    time += delta_t;
    
    // Calculate new position
    x = velocity_x * time;
    y = (velocity_y * time) - (0.5 * gravity * time * time);

    // Check if the projectile is at its max height 
    if (y > height) {
      height = y;
    }

    // Print current position
    printf("Position at time %2.2f: (%2.2f, %2.2f)\n", time, x, y);

    // Update velocity
    velocity_x = velocity_x;
    velocity_y = velocity_y - (gravity * delta_t);
  }

  // Calculate total distance
  distance = x;

  // Print results
  printf("\nProjectile reached its max height of %.2f meters.\n", height);
  printf("Projectile travelled a total distance of %.2f meters.\n", distance);

  return 0;
}