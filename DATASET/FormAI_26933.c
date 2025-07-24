//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
  printf("Before we begin, please answer the following questions:\n\n");

  int num_of_people;
  printf("How many people do you know who have been abducted by aliens? ");
  scanf("%d", &num_of_people);

  if (num_of_people == 0) {
    printf("\nYou must have some really boring friends...\n");
  } else {
    printf("\nWow, %d of your friends have been abducted? You might want to consider new friends...\n", num_of_people);
  }

  int num_of_cows;
  printf("\nHow many cows have you seen mutilated on your farm (or nearby fields)? ");
  scanf("%d", &num_of_cows);

  if (num_of_cows == 0) {
    printf("\nWell, that's a relief. At least the aliens aren't after your livestock...\n");
  } else if (num_of_cows < 5) {
    printf("\nHmm, %d cows may not be enough evidence of an alien invasion, but it's still something to be concerned about...\n", num_of_cows);
  } else {
    printf("\nHoly cow, %d mutilated cows?! You might want to consider moving to a new planet...\n", num_of_cows);
  }

  int num_of_reports;
  printf("\nHow many UFO sightings have you reported to MUFON (Mutual UFO Network)? ");
  scanf("%d", &num_of_reports);

  if (num_of_reports == 0) {
    printf("\nHmm, you might want to start keeping track of those sightings...\n");
  } else {
    printf("\n%s\n", "Great! The more reports, the higher the probability of an alien invasion...");
  }

  srand(time(NULL));
  int invasion_probability = rand() % 101;
  printf("\nCalculating invasion probability... Done! Your chance of an alien invasion is %d%%.\n", invasion_probability);

  printf("\n%s\n", "Remember, always keep a towel with you and don't panic!");

  return 0;
}