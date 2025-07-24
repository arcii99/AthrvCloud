//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Procedural Space Adventure!\n");
  printf("We will take you on an exciting journey through the galaxy.\n");

  // set the seed for the random number generator
  srand(time(NULL));

  // randomly generate the player's starting planet
  char* planets[] = { "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune" };
  int planet_index = rand() % 6;
  char* starting_planet = planets[planet_index];
  printf("You begin your adventure on the planet %s!\n", starting_planet);

  // randomly generate the number of alien encounters the player will have
  int num_encounters = (rand() % 4) + 1;
  printf("You will encounter %d aliens as you explore the galaxy.\n", num_encounters);

  // simulate the player's journey through space
  int i;
  for (i = 1; i <= num_encounters; i++) {
    printf("\nEncounter #%d:\n", i);

    // randomly generate the type of alien encountered
    char* aliens[] = { "Zorgon", "Groxar", "Flurnix", "Blorgon", "Korbok" };
    int alien_index = rand() % 5;
    char* alien_type = aliens[alien_index];
    printf("You have encountered an alien of the type %s!\n", alien_type);

    // randomly generate the outcome of the encounter
    int outcome = rand() % 3;
    switch (outcome) {
      case 0:
        printf("The %s is friendly and gives you valuable information.\n", alien_type);
        break;
      case 1:
        printf("The %s attacks you, but you manage to survive and escape.\n", alien_type);
        break;
      case 2:
        printf("The %s captures you and takes you to their home planet.\n", alien_type);
        break;
      default:
        printf("Uh oh, something went wrong!\n");
        break;
    }
  }

  printf("\nCongratulations, you have completed your Procedural Space Adventure!\n");
  return 0;
}