//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
   // Declaring variables
   int *p;

   printf("Welcome to the Memory Management Stand-up Comedy!\n");
   printf("Get ready to laugh and learn some C memory management!\n");

   printf("Knock, knock!\n");
   printf("Who's there?\n");
   printf("Malloc.\n");
   printf("Malloc who?\n");
   printf("Malloc me some memory, please?\n");

   // Allocating memory using malloc
   p = (int*) malloc(5 * sizeof(int));

   if(p == NULL) {
      printf("Oops! Looks like we ran out of memory.\n");
      exit(1); 
   }

   printf("Why did the programmer quit his job? Because he didn't get arrays.\n");

   // Filling up allocated memory
   for(int i = 0; i < 5; i++) {
      *(p + i) = i * 10;
   }

   printf("Why was the RAM cold? Because it left its Windows open!\n");

   // Printing contents of allocated memory
   for(int i = 0; i < 5; i++) {
      printf("*(p + %d) : %d\n", i, *(p + i));
   }

   printf("Why do Java developers wear glasses? Because they can't C++!\n");

   // Reallocating memory using realloc
   p = (int*) realloc(p, 10 * sizeof(int));

   if(p == NULL) {
      printf("Oops! Looks like we ran out of memory.\n");
      exit(1); 
   }

   printf("Why do programmers prefer dark mode? Because light attracts bugs!\n");

   // Filling up reallocated memory
   for(int i = 5; i < 10; i++) {
      *(p + i) = i * 10;
   }

   // Printing contents of reallocated memory
   for(int i = 0; i < 10; i++) {
      printf("*(p + %d) : %d\n", i, *(p + i));
   }

   printf("Thanks for coming to our Memory Management Stand-up Comedy!\n");
   printf("We hope you've learned how to malloc, realloc, and free with a smile!\n");

   // Freeing allocated memory
   free(p);

   return 0;
}