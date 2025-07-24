//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {"The Government", "The Illuminati", "Aliens", "The Freemasons", "Big Pharma", "The Vatican"};
char *verbs[] = {"are controlling", "are manipulating", "are hiding", "are experimenting with", "are spying on", "are communicating with"};
char *objects[] = {"our thoughts", "the weather", "our DNA", "the stock market", "the media", "the youth"};

int main() {

   srand(time(NULL)); // Seed the random number generator

   // Generate a random conspiracy theory
   int subjectIndex = rand() % 6;
   int verbIndex = rand() % 6;
   int objectIndex = rand() % 6;

   printf("Did you know that %s %s %s?\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);

   return 0;
}