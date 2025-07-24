//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random seed

   char *subjects[] = {"The government", "The illuminati", "The aliens", "The lizard people", "The New World Order"}; // potential subjects of conspiracy theories
   char *verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is hiding", "is planning"}; // potential verbs used in conspiracy theories
   char *objects[] = {"our thoughts", "the weather", "the media", "the economy", "the future"}; // potential objects of conspiracy theories

   int num_theories = 10; // generate 10 conspiracy theories
   for (int i = 1; i <= num_theories; i++) {
       int subj_index = rand() % 5; // choose a random subject
       int verb_index = rand() % 5; // choose a random verb
       int obj_index = rand() % 5; // choose a random object

       printf("%d. %s %s %s.\n", i, subjects[subj_index], verbs[verb_index], objects[obj_index]); // print the conspiracy theory
   }

   return 0;
}