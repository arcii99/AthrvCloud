//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  char *subjects[] = {"The government", "The Illuminati", "Aliens", "The Freemasons", "The New World Order"};
  char *nouns[] = {"chemtrails", "area 51", "9/11", "vaccinations", "HAARP"};
  char *verbs[] = {"controls", "manipulates", "planted", "created"};
  char *adjectives[] = {"mind-controlling", "secretive", "unbelievable", "covert"};

  int subjectIndex = rand() % 5;
  int nounIndex = rand() % 5;
  int verbIndex = rand() % 4;
  int adjIndex = rand() % 4;

  printf("Did you know that %s %s %s %s?\n", subjects[subjectIndex], verbs[verbIndex], adjectives[adjIndex], nouns[nounIndex]);

  return 0;
}