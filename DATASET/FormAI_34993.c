//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int aliens = rand() % 1000;
  int people = rand() % 1000000;

  printf("Welcome to the Alien Invasion Probability Calculator!\n");

  printf("Please enter the probability of alien life on other planets (in percentage): ");
  int probability;
  scanf("%d", &probability);

  printf("Calculating...\n");

  int invasion_probability = probability / 10;

  if (invasion_probability > 5) {
    printf("Oh no! The probability of an alien invasion is %d%%!\n", invasion_probability);
    printf("There is a %d%% chance that %d aliens will invade earth and attack its %d inhabitants!\n", 
           invasion_probability, aliens, people);
    printf("Quick, everyone grab your laser guns and get ready to save the world!\n");
  } else {
    printf("Phew, the probability of an alien invasion is only %d%%.\n", invasion_probability);
    printf("There is a %d%% chance that %d aliens will visit earth and peacefully observe its %d inhabitants.\n", 
           invasion_probability, aliens, people);
    printf("Let's welcome them with open arms and share our culture with them!\n");
  }

  return 0;
}