//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator with current time

  char *nouns[] = {"government", "aliens", "Illuminati", "big pharma", "the deep state", "the New World Order", "the elite", "the reptilians", "the Freemasons", "the CIA"};
  char *adjectives[] = {"secret", "hidden", "invisible", "powerful", "omnipotent", "omniscient", "elusive", "mysterious", "omnipresent", "terrifying"};
  char *actions[] = {"are watching", "are controlling", "are manipulating", "are brainwashing", "are experimenting on", "are infiltrating", "are sabotaging", "are planning", "are terrorizing", "are covering up"};

  for (int i = 0; i < 10; i++) {
    int n = rand() % 10;
    int adj = rand() % 10;
    int act = rand() % 10;

    printf("The %s %s %s us.\n", adjectives[adj], nouns[n], actions[act]);
  }

  return 0;
}