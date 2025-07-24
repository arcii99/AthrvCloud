//FormAI DATASET v1.0 Category: Physics simulation ; Style: detailed
#include <stdio.h>

int main() {
  // Declaring variables for velocity and time
  double velocity, time;

  // Taking user input for velocity and time
  printf("Enter the velocity of the object in m/s: ");
  scanf("%lf", &velocity);
  printf("Enter the time duration in seconds: ");
  scanf("%lf", &time);

  // Calculating displacement using the formula 's = v * t'
  double displacement = velocity * time;

  // Calculating the acceleration due to gravity
  double gravity = 9.8;

  // Calculating the total time taken for the object to hit the ground
  double total_time = (2 * velocity) / gravity;

  // Calculating the maximum height attained by the object
  double max_height = ((velocity * velocity) / (2 * gravity));

  // Printing the results
  printf("The displacement of the object is %.2lf meters.\n", displacement);
  printf("The total time taken for the object to hit the ground is %.2lf seconds.\n", total_time);
  printf("The maximum height attained by the object is %.2lf meters.\n", max_height);

  return 0;
}