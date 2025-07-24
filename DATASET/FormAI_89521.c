//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Display a welcome message to the user
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // Get user input for the location of the potential invasion
  char location[20];
  printf("Please enter the location of the potential invasion: ");
  fgets(location, 20, stdin);

  // Generate a random probability value between 1 and 100
  int probability = rand() % 100 + 1;

  // Display the result to the user
  printf("\nThe probability of an alien invasion in %s is: %d%%\n", location, probability);

  // Display a closing message to the user
  printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

  return 0;
}