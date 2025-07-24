//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *subjects[] = {
    "aliens",
    "Illuminati",
    "government",
    "Big Pharma",
    "secret society",
    "One World Order",
    "reptilian overlords",
    "time-travelers",
    "robotic AI",
    "dimensional beings"
  };
  char *verbs[] = {
    "control",
    "manipulate",
    "enslave",
    "brainwash",
    "experiment on",
    "replace",
    "destroy",
    "harvest",
    "clone",
    "worship"
  };
  char *objects[] = {
    "humans",
    "animals",
    "the environment",
    "the economy",
    "the media",
    "the internet",
    "our minds",
    "our DNA",
    "our spirituality",
    "the past"
  };

  srand(time(0));

  printf("Welcome to the Random Conspiracy Theory Generator!\n");

  int count = 1;
  while (count <= 10) {
    int subj_idx = rand() % 10;
    int verb_idx = rand() % 10;
    int obj_idx = rand() % 10;

    printf("%d. The %s %s %s.\n", count, subjects[subj_idx], verbs[verb_idx], objects[obj_idx]);
    count++;
  }

  printf("Stay woke!\n");

  return 0;
}