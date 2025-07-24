//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  char* subjects[] = {"The Government", "The Illuminati", "The Reptilians", "The Deep State", "The Freemasons", "The New World Order"};
  char* verbs[] = {"are controlling", "are manipulating", "are brainwashing", "are influencing", "are sabotaging", "are surveilling"};
  char* nouns[] = {"our elections", "our media", "our food supply", "our weather", "our minds", "our DNA"};

  int num_subjects = sizeof(subjects) / sizeof(char*);
  int num_verbs = sizeof(verbs) / sizeof(char*);
  int num_nouns = sizeof(nouns) / sizeof(char*);

  printf("CONSPIRACY ALERT: ");

  for (int i = 0; i < 5; i++) {
    int r_subject = rand() % num_subjects;
    int r_verb = rand() % num_verbs;
    int r_noun = rand() % num_nouns;

    printf("%s %s %s, ", subjects[r_subject], verbs[r_verb], nouns[r_noun]);
  }

  int r_subject = rand() % num_subjects;
  int r_verb = rand() % num_verbs;
  int r_noun = rand() % num_nouns;

  printf("and %s %s %s!", subjects[r_subject], verbs[r_verb], nouns[r_noun]);

  return 0;
}