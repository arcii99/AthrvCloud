//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  const char *theories[10] = {"The government is hiding the cure for cancer",
                              "Aliens have taken over the White House",
                              "The moon landing was faked",
                              "Big Pharma is suppressing natural remedies",
                              "The Illuminati controls the world",
                              "Chemtrails are poisoning our air",
                              "The Loch Ness monster is real",
                              "9/11 was an inside job",
                              "The Bermuda Triangle is a portal to another dimension",
                              "Elvis Presley is still alive"};
  const char *connectives[5] = {"because", "due to", "as a result of", "in order to", "for the purpose of"};
  const char *reasons[10] = {"maintaining power and control", "overthrowing the world order", "pleasing their alien overlords", "achieving immortality", "harvesting human organs", "unleashing a global pandemic", "summoning ancient deities", "obtaining unlimited wealth", "creating a new world order", "bringing about the end of the world"};

  srand(time(0)); // seed random number generator

  for (i = 0; i < 10; i++) {
    int theoryIndex = rand() % 10; // select random index from theories array
    int connectiveIndex = rand() % 5; // select random index from connectives array
    int reasonIndex = rand() % 10; // select random index from reasons array

    printf("%s %s %s.\n", theories[theoryIndex], connectives[connectiveIndex], reasons[reasonIndex]); // print random conspiracy theory
  }

  return 0;
}