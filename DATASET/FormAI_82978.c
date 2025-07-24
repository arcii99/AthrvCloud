//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   char string[100];
   int count, mistakes = 0;
   time_t start, end;
   
   printf("Welcome to the Typing Speed Test.\n");
   printf("Please type the following sentence:\n");
   printf("The quick brown fox jumps over the lazy dog.\n");
   
   fgets(string, 100, stdin);
   
   time(&start);
   
   for (count = 0; count < 43; count++) {
      if (string[count] != "The quick brown fox jumps over the lazy dog."[count]) {
         mistakes++;
      }
   }
   
   time(&end);
   
   double time_taken = difftime(end, start);
   double speed = (43.0 / time_taken) * 60;
   
   printf("You have made %d mistakes.\n", mistakes);
   printf("Your typing speed is %.2f words per minute.\n", speed);
   
   return 0;
}