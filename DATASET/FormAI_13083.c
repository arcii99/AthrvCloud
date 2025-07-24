//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to the Memory Circus!\n");
   printf("Please enter the number of clowns you would like to allocate memory for: ");
   int num_clowns;
   scanf("%d", &num_clowns);
   
   // Step right up, step right up! Watch as we allocate memory for clowns!
   int* clown_array = (int*) malloc(num_clowns * sizeof(int));
   
   if (clown_array == NULL) {
      printf("Oops, the clown allocation failed! Better luck next time.\n");
      return 1;
   }
   
   printf("Wonderful! We've successfully allocated memory for %d clowns!\n", num_clowns);
   
   // Time for the clowns to perform!
   printf("Now we need to assign each clown a unique performance ID.\n");
   for (int i = 0; i < num_clowns; i++) {
      *(clown_array + i) = i + 1;
   }
   
   printf("Amazing! Each clown has been assigned a unique performance ID!\n");
   
   // Uh oh, it's time for the clowns to leave...
   printf("But wait! We forgot to free the memory we allocated for the clowns! Let's do that now.\n");
   free(clown_array);
   
   printf("Great job, we've successfully freed the memory! The clowns can safely leave now.\n");
   
   return 0;
}