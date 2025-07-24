//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
   char sentence[100] = "The quick brown fox jumps over the lazy dog.";
   int n = strlen(sentence);
   char input[100];
   int i = 0, errors = 0, time_limit = 30, speed;
   double time_taken;
   clock_t start, end;

   // Welcome message and instructions for the user
   printf("Welcome to the Typing Speed Test!\n");
   printf("Type the given sentence as fast and accurately as you can.\n");
   printf("Press enter to start the timer and begin typing:\n");
   getchar();

   // Get the start time for the typing test
   start = clock();

   // Keep accepting user input until time limit is reached
   while ((double)(clock() - start) / CLOCKS_PER_SEC < time_limit) {
      // Get user input
      fgets(input, 100, stdin);

      // Check input against sentence
      for (int j = 0; j < strlen(input); j++) {
         if (input[j] != sentence[i]) {
            errors++;
         }
         i++;
      }
   }

   // Get the end time for the typing test
   end = clock();

   // Calculate speed and time taken
   time_taken = (double)(end - start) / CLOCKS_PER_SEC;
   speed = (int)(((double)(n - errors) / time_taken) * 60);

   // Display results to the user
   printf("\nTime taken: %.2lf seconds\n", time_taken);
   printf("Number of errors: %d\n", errors);
   printf("Your typing speed is: %d words per minute.\n", speed);

   return 0;
}