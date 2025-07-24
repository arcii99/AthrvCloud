//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   char sentence[] = "The quick brown fox jumps over the lazy dog.";
   int i, j, length = 0, errors = 0;
   float accuracy;
   clock_t start_time, end_time;
   
   // determine the length of the sentence
   while(sentence[length] != '\0') {
      length++;
   }
   
   printf("Type the following sentence as fast as you can:\n%s\n", sentence);
   
   start_time = clock();
   
   for(i = 0; i < length; i++) {
      char c = getchar();
      if(c != sentence[i]) {
         errors++;
      }
   }
   
   end_time = clock();
   float time_taken = ((float) (end_time - start_time)) / CLOCKS_PER_SEC;
   
   // calculate the accuracy of the typing
   accuracy = (((float) length - errors) / length) * 100;
   
   printf("\nYou typed the sentence in %.2f seconds.\n", time_taken);
   printf("Your accuracy rate is %.2f%%\n", accuracy);
   
   return 0;
}