//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int seed = time(NULL); // get the current time as a seed for random number generation
  srand(seed); // initialize the random number generator

  // declare arrays of phrases to use in the conspiracy theory generator
  char *nouns[] = {"government", "Illuminati", "aliens", "secret society", "Big Pharma", "corporations"};
  char *verbs[] = {"control", "manipulate", "brainwash", "enslave", "dominate", "destroy"};
  char *adjectives[] = {"powerful", "secretive", "mysterious", "dangerous", "corrupt", "evil"};
  char *subjects[] = {"world leaders", "the media", "the population", "celebrities", "scientists", "the economy"};

  // use random numbers to select random phrases from the arrays
  int nounIndex = rand() % 6;
  int verbIndex = rand() % 6;
  int adjIndex = rand() % 6;
  int subIndex = rand() % 6;

  // print out the generated conspiracy theory
  printf("Did you know that the %s %s the %s, and are trying to %s %s? They are a %s %s that is manipulating %s to their advantage.", 
         nouns[nounIndex], verbs[verbIndex], subjects[subIndex], verbs[verbIndex], subjects[subIndex], adjectives[adjIndex], nouns[nounIndex], subjects[subIndex]);

  return 0;
}