//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81

int main() {
  float angle, velocity, distance, height, time;
  printf("Enter the angle of projection: ");
  scanf("%f", &angle);
  printf("Enter the initial velocity of the projectile: ");
  scanf("%f", &velocity);

  angle = angle * (M_PI / 180.0); // convert to radians
  float x_velocity = velocity * cos(angle); // horizontal velocity
  float y_velocity = velocity * sin(angle); // vertical velocity

  time = (2 * y_velocity) / GRAVITY; // total time in air
  distance = x_velocity * time; // horizontal distance traveled
  height = (y_velocity * y_velocity) / (2 * GRAVITY); // maximum height achieved

  printf("\nThe projectile will travel a distance of: %.2f meters", distance);
  printf("\nThe maximum height achieved by the projectile: %.2f meters", height);
  printf("\n\nTrajectory of the projectile:\n");

  for (float t = 0; t <= time; t += 0.1) {
    float x = x_velocity * t;
    float y = y_velocity * t - 0.5 * GRAVITY * t * t;
    printf("Time: %.2f seconds, Height: %.2f meters, Distance: %.2f meters\n", t, y, x);
  }

  return 0;
}