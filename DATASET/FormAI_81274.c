//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  char *nouns[] = {"radiation", "chemtrails", "aliens", "government", "illuminati", "big pharma", "black helicopters"};
  char *verbs[] = {"control", "manipulate", "infect", "poison", "brainwash"};
  char *adjectives[] = {"dangerous", "toxic", "mysterious", "secretive", "unknown"};
  char *conspiracies[] = {"The government is using %s to %s the population", "The illuminati is behind %s and is using it to %s the masses", "Aliens are using %s to %s and infect humans"};

  // generate random conspiracy theory
  int n = rand() % 7;
  int v = rand() % 5;
  int adj = rand() % 5;
  int c = rand() % 3;

  // print the conspiracy theory
  printf("Did you know that...\n");
  printf(conspiracies[c], adjectives[adj], verbs[v]);
  printf("using %s? It's all part of a bigger plan...\n", nouns[n]);

  return 0;
}