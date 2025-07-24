//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>   // standard input/output library
#include <stdlib.h>  // standard library for memory allocation and exit functions
#include <time.h>    // library for time function
#include <stdbool.h> // library for boolean type

int main() {
  srand(time(NULL));  // seed for random number generation

  // define variables we'll use
  int alien_count, attack_probability;
  bool invasion_possible;

  printf("Welcome to the Alien Invasion Probability Calculator.\n\n");

  printf("Enter the number of aliens you think might invade Earth: ");
  scanf("%d", &alien_count);

  // calculate a random percentage for the attack probability
  attack_probability = rand() % 101;
  printf("\nThe attack probability is %d%%\n", attack_probability);

  // determine if invasion is possible based on probability and number of aliens
  if (alien_count < 10 && attack_probability < 50) {
    invasion_possible = false;
  } else if (alien_count < 100 && attack_probability < 25) {
    invasion_possible = false;
  } else if (alien_count < 1000 && attack_probability < 10) {
    invasion_possible = false;
  } else {
    invasion_possible = true;
  }

  // print results
  if (invasion_possible) {
    printf("\nThere is a high probability of alien invasion!\n");
  } else {
    printf("\nAlien invasion is unlikely at this time.\n");
  }

  return 0;
}