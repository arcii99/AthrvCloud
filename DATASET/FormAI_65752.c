//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));

  int num_theories = rand() % 10 + 10;

  char *theories[] = {
    "The king's advisor is a dragon in disguise",
    "The princess has been replaced by a changeling",
    "The Black Death was caused by witches",
    "The Great Famine was caused by demons",
    "The king's army is secretly controlled by vampires",
    "The pope is a werewolf",
    "The queen is a sorceress practicing dark magic",
    "The castle is built on top of a portal to the underworld",
    "The knight's code of chivalry is a cover-up for a secret cult",
    "The kingdom's treasure is cursed and will bring doom upon the land"
  };

  printf("Welcome to the Random Conspiracy Theory Generator!\n");

  for (int i = 0; i < num_theories; i++) {
    int num_pieces = rand() % 5 + 1;
    printf("Theory #%d: ", i+1);

    for (int j = 0; j < num_pieces; j++) {
      int index = rand() % 10;
      printf("%s ", theories[index]);
    }

    printf("\n\n");
  }

  return 0;
}