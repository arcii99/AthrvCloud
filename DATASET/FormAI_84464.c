//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  char *conspiracies[] = {
    "The moon landing was faked",
    "The government is hiding the cure for cancer",
    "Area 51 contains evidence of extraterrestrial life",
    "The Illuminati controls the world's governments",
    "The world is run by a secret cabal of billionaires",
    "9/11 was an inside job",
    "The government is behind the rise of AI",
    "The earth is actually flat",
    "The Loch Ness monster is real",
    "Chemtrails are being used for mind control",
    "The JFK assassination was a conspiracy"
  };

  srand(time(NULL)); // Seed random number generator with current time

  int random_index = rand() % 11; // Generate random index for choosing conspiracy theory

  printf("Did you know that %s?\n", conspiracies[random_index]);

  return 0;
}