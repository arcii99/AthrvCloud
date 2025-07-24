//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  
  char *nouns[] = {"government", "aliens", "illuminati", "big pharma", "lizard people", "world banks", "secret society", "new world order", "reptilian overlords", "deep state"};
  char *verbs[] = {"control", "manipulate", "brainwash", "infiltrate", "silence", "spy on", "assassinate", "indoctrinate", "subjugate", "dominate"};
  char *adjectives[] = {"evil", "power-hungry", "diabolical", "corrupt", "scheming", "manipulative", "sinister", "malevolent", "wicked", "deceptive"};
  
  int num_theories = 10; // generate 10 conspiracy theories
  
  for (int i = 0; i < num_theories; i++) {
    int num_nouns = sizeof(nouns) / sizeof(char *);
    int num_verbs = sizeof(verbs) / sizeof(char *);
    int num_adjectives = sizeof(adjectives) / sizeof(char *);
    
    // randomly generate a conspiracy theory
    int index_noun = rand() % num_nouns;
    int index_verb = rand() % num_verbs;
    int index_adj = rand() % num_adjectives;
    
    // print the conspiracy theory
    printf("%d. The %s %s the %s.\n", i+1, adjectives[index_adj], nouns[index_noun], verbs[index_verb]);
  }
  
  return 0;
}