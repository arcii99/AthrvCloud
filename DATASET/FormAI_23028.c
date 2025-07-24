//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <time.h>

int main() {
   char text[] = "The quick brown fox jumps over the lazy dog"; // collection of words to be typed
   int i = 0, j = 0, correct = 0, incorrect = 0, accuracy = 0, time_taken = 0;
   clock_t begin, end;
   double time_spent;

   printf("Type the following text as fast as possible and press enter:\n");
   printf("%s\n", text);

   begin = clock();
   while (text[i] != '\0') { // loop through each character in the text
      char input = getchar(); // get user input

      if (input == text[i]) { // if input matches expected character
         correct++;
      }
      else {
         incorrect++;
      }
      i++; 
   }
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   time_taken = (int) time_spent;

   accuracy = (correct * 100) / (correct + incorrect); // calculate accuracy percentage

   printf("Total time taken: %d seconds", time_taken);
   printf("Accuracy: %d%%\n", accuracy);

   return 0;
}