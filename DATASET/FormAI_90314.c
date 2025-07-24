//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   //seed the random number generator
   srand(time(0));

   //arrays of possible subjects and conspiracies
   char* subjects[] = { "the moon landing", "chemtrails", "911", "vaccinations", "Big Pharma", "aliens" };
   char* conspiracies[] = { "is a government hoax", "contains mind-controlling chemicals", "was an inside job", "causes autism", "is keeping the cure for cancer secret", "are controlling world leaders" };

   //generate a random index for each
   int subjectIndex = rand() % 6;
   int conspiracyIndex = rand() % 6;

   //output the conspiracy theory
   printf("Did you know that %s %s?\n", subjects[subjectIndex], conspiracies[conspiracyIndex]);

   return 0;
}