//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define MAXTIME 60

int main() {
   char input[MAXSIZE];
   int i, correct = 0, wrong = 0, total = 0, wpm = 0;
   clock_t start_t, end_t;
   
   printf("Welcome to the Typing Speed Test program!\n\n");
   printf("You will be given a random paragraph to type out as fast and accurately as possible.\n");
   printf("Press ENTER to begin the test.\n");
   getchar();
   
   char paragraph[] = "The quick brown fox jumps over the lazy dog. This sentence is often used to test typists' speed and accuracy.";
   
   printf("\n%s\n\n", paragraph);
   
   start_t = clock();
   
   while (1) {
      fgets(input, sizeof input, stdin);
      if (strlen(input) > strlen(paragraph)) {
         printf("You exceeded the maximum number of characters!\n");
         continue;
      }
      if (strcmp(input, paragraph) == 0) {
         printf("\nCongratulations! You typed the paragraph correctly!\n");
         break;
      }
      for (i = 0; i < strlen(input); i++) {
         if (input[i] == paragraph[i]) {
            correct++;
         } else {
            wrong++;
         }
      }
      total = correct + wrong;
      wpm = (total / 5) / ((end_t - start_t) / (double)CLOCKS_PER_SEC / 60);
      printf("\nIncorrect. Please try again.\n");
   }
   
   end_t = clock();
   
   printf("Your typing stats:\n");
   printf("Time taken: %.2lf seconds\n", (end_t - start_t) / (double)CLOCKS_PER_SEC);
   printf("Words per minute: %d\n", wpm);
   printf("Accuracy: %.2lf%%\n", (double)correct / total * 100);
   
   return 0;
}