//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Initialize random number generator
   
   char* subjects[] = {"The Government", "The Illuminati", "Aliens", "Big Pharma", "The Media", "The Deep State"};
   char* verbs[] = {"is controlling", "is manipulating", "is hiding", "is conspiring with", "is brainwashing", "is surveilling"};
   char* objects[] = {"the weather", "our minds", "the stock market", "the internet", "the elections", "the truth"};
   
   int num_theories = 10; // Number of conspiracy theories to generate
   int theory_length = 5; // Number of words in each theory
   
   for (int i = 0; i < num_theories; i++) {
      printf("Theory %d: ", i+1);
      for (int j = 0; j < theory_length; j++) {
         // Generate random indexes for subjects, verbs, and objects
         int sub_index = rand() % 6;
         int verb_index = rand() % 6;
         int obj_index = rand() % 6;
         // Use indexes to select words from arrays
         printf("%s %s %s ", subjects[sub_index], verbs[verb_index], objects[obj_index]);
      }
      printf("\n");
   }
   
   return 0;
}