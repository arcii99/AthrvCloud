//FormAI DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char bootSequence[100];
   printf("Welcome to the C System Boot Optimizer!\n");
   
   // Get the user's boot sequence
   printf("Enter your boot sequence: ");
   scanf("%s", bootSequence);
   
   // Ensure valid input
   int length = strlen(bootSequence);
   if (length == 0) {
      printf("Invalid input. Please try again.");
      exit(1);
   }
   
   // Check for any areas of optimization
   int i, j, swaps = 0;
   for (i = 0; i < length - 1; i++) {
      for (j = 0; j < length - i - 1; j++) {
         if (bootSequence[j] > bootSequence[j+1]) {
            char temp = bootSequence[j];
            bootSequence[j] = bootSequence[j+1];
            bootSequence[j+1] = temp;
            swaps++;
         }
      }
   }
   
   // Display results
   printf("Optimized boot sequence: %s\n", bootSequence);
   printf("Total number of swaps: %d\n", swaps);
   
   return 0;
}