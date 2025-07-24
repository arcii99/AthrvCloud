//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>

// The time travel calculator - a program that calculates the distance 
// and time travelled by a time traveller using an imaginary time machine

int main() {
  
  printf("Welcome to the Time Travel Calculator!\n\n");

  // Get input from user
  int distance;
  printf("Enter the distance you wish to travel (in light years): ");
  scanf("%d", &distance);

  printf("\nCalculating...\n\n");

  // Calculate time travelled
  int speed_of_light = 299792458; // in meters per second
  int distance_in_meters = distance * 946073047 * speed_of_light; // convert light years to meters
  int time_travelled = distance_in_meters / speed_of_light;

  // Calculate distance travelled
  int spaceship_speed;
  printf("Enter the speed of your spaceship (in meters per second): ");
  scanf("%d", &spaceship_speed);

  int distance_travelled = time_travelled * spaceship_speed;

  // Output results
  printf("Congratulations! You have travelled %d light years in %d years.\n", distance, time_travelled);
  printf("You have travelled a distance of %d meters at a speed of %d meters per second.\n", distance_travelled, spaceship_speed);

  return 0;
}