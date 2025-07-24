//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with current time
  
  char* nouns[] = { "aliens", "Illuminati", "government", "big pharma", "the elites" };
  char* verbs[] = { "are manipulating", "are plotting against", "are controlling", "are brainwashing", "are covering up the truth about" };
  char* adjectives[] = { "insidious", "diabolical", "malevolent", "sinister", "cunning" };
  char* endings[] = { "to achieve global domination.",
                      "to keep the population in a state of fear.",
                      "to perpetuate their power and wealth.",
                      "to destroy our individual freedoms.",
                      "to usher in a new world order." };
   
  // generate the conspiracy theory
  int nounIndex = rand() % 5; // pick a random noun
  int verbIndex = rand() % 5; // pick a random verb
  int adjIndex = rand() % 5; // pick a random adjective
  int endingIndex = rand() % 5; // pick a random ending
  
  printf("Did you know that the %s %s society is %s %s?\n", adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex], endings[endingIndex]);
  
  return 0;
}