//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Solar System Simulation Program!\n\n");

  // Planets information
  char planets[8][10] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
  float distances[8] = {57.9, 108.2, 149.6, 227.9, 778.3, 1427.0, 2871.0, 4497.1};
  float periods[8] = {0.241, 0.615, 1.000, 1.881, 11.86, 29.46, 84.01, 164.8};

  // Ask user for time increment
  float time_increment;
  printf("Enter a time increment (in Earth days): ");
  scanf("%f", &time_increment);

  // Initialize planet positions
  float positions[8] = {0};

  // Simulation loop
  for (int i = 0; ; i++) {
    // Print current positions
    printf("Day %d: ", i);
    for (int j = 0; j < 8; j++) {
      printf("%s: %.2f AU, ", planets[j], positions[j]);
    }
    printf("\n");

    // Update positions according to periods and time increment
    for (int j = 0; j < 8; j++) {
      positions[j] = distances[j] * ((i * time_increment) / periods[j]);
    }
  }

  return 0;
}