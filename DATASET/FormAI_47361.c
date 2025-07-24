//FormAI DATASET v1.0 Category: Physics simulation ; Style: creative
#include <stdio.h>

int main() {
  float mass1, mass2, distance, force;

  printf("Enter the mass of the first object: ");
  scanf("%f", &mass1);
  printf("Enter the mass of the second object: ");
  scanf("%f", &mass2);
  printf("Enter the distance between the two objects: ");
  scanf("%f", &distance);

  /* Calculate the gravitational force */
  force = (6.67E-11 * mass1 * mass2) / (distance * distance);

  printf("\nThe gravitational force between the two objects is %f N", force);

  /* Now let's simulate the motion of these objects! */
  float time, velocity1 = 0, velocity2 = 0, acceleration1, acceleration2;
  printf("\n\nEnter the time interval for the simulation (in seconds): ");
  scanf("%f", &time);
  
  /* Calculate the initial acceleration */
  acceleration1 = force / mass1;
  acceleration2 = force / mass2;

  /* Simulate the motion */
  for (int i = 0; i < 10; i++) {
    /* Calculate new velocities */
    velocity1 += acceleration1 * time;
    velocity2 += acceleration2 * time;

    /* Calculate new positions */
    distance += (velocity1 + velocity2) / 2 * time;

    /* Update acceleration based on the new distance */
    force = (6.67E-11 * mass1 * mass2) / (distance * distance);
    acceleration1 = force / mass1;
    acceleration2 = force / mass2;

    printf("\nAt time %f s, the distance between the objects is %f m", i*time, distance);
  }

  return 0;
}