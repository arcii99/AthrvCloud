//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81     // Value of gravity
#define INITIAL_VELOCITY 30.0    // Velocity of the projectile
#define DEG_TO_RAD 0.0174533    // Convert degree to radian

int main()
{
  float angle;                       // Angle of projection
  float velocity_x, velocity_y;      // X and Y velocities
  float time_of_flight;              // Time taken by projectile in the air
  float max_height;                  // Maximum height reached by the projectile
  float range;                       // Range of the projectile

  // Taking user input for angle of projection
  printf("Enter the angle of projection in degrees: ");
  scanf("%f", &angle);

  // Converting angle to radian
  angle *= DEG_TO_RAD;

  // Calculating x and y velocities
  velocity_x = INITIAL_VELOCITY * cos(angle);
  velocity_y = INITIAL_VELOCITY * sin(angle);

  // Calculating time of flight, maximum height and range
  time_of_flight = 2 * velocity_y / GRAVITY;
  max_height = pow(velocity_y, 2) / (2 * GRAVITY);
  range = velocity_x * time_of_flight;

  // Displaying the results
  printf("\nProjectile Motion Results:\n");
  printf("Angle of Projection: %f\n", angle / DEG_TO_RAD);
  printf("Initial Velocity: %f m/s\n", INITIAL_VELOCITY);
  printf("Time of Flight: %f s\n", time_of_flight);
  printf("Maximum Height: %f m\n", max_height);
  printf("Range: %f m\n", range);

  return 0;
}