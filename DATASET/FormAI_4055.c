//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
// A physics simulation of a projectile motion
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // acceleration due to gravity in m/s^2

int main() {
  double angle, velocity, time, height, range, x, y;
  int i;

  // ask user for input values
  printf("Enter the angle of projection in degrees: ");
  scanf("%lf", &angle);
  printf("Enter the velocity of projection in m/s: ");
  scanf("%lf", &velocity);

  // convert angle to radians
  angle = angle * M_PI / 180;

  // calculate time of flight
  time = (2 * velocity * sin(angle)) / GRAVITY;

  // calculate maximum height
  height = (velocity * velocity * sin(angle) * sin(angle)) / (2 * GRAVITY);

  // calculate horizontal range
  range = (velocity * velocity * sin(2 * angle)) / GRAVITY;

  // print results
  printf("\nProjectile motion simulation:\n");
  printf("Maximum height reached: %.2lf m\n", height);
  printf("Horizontal range: %.2lf m\n", range);
  printf("Time of flight: %.2lf s\n", time);

  // plot projectile motion
  printf("\nProjectile motion plot:\n");
  for (i = 0; i <= 20; i++) {
    x = (velocity * cos(angle) * i) / 10;
    y = (velocity * sin(angle) * i - (0.5 * GRAVITY * i * i)) / 10;
    printf("Time: %.1lf s   Height: %.1lf m   Range: %.1lf m\n", i / 10.0, y, x);
  }

  return 0;
}