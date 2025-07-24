//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Define our conspiracy theories
  char* theories[7] = {"The moon landing was faked", "Chemtrails are real", "The government is hiding aliens", "Vaccines cause autism",
                       "The earth is flat", "9/11 was an inside job", "The Illuminati control everything"};

  // Define our potential culprits
  char* culprits[4] = {"The government", "The Illuminati", "Big Pharma", "The lizard people"};

  // Define our potential motives
  char* motives[3] = {"To control the population", "To create a New World Order", "To profit from our suffering"};

  // Generate a random conspiracy theory
  int theory_index = rand() % 7;
  char* theory = theories[theory_index];
  
  // Generate a random culprit
  int culprit_index = rand() % 4;
  char* culprit = culprits[culprit_index];
  
  // Generate a random motive
  int motive_index = rand() % 3;
  char* motive = motives[motive_index];

  // Print out our conspiracy theory
  printf("Did you know that %s is actually a plot by %s %s? It's true!", theory, culprit, motive);

  return 0;
}