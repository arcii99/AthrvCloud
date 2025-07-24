//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT 100

int main() {
   int i, j, k, count = 0;
   int time_limit = 10; //10 seconds timer limit
   int score = 0; //user score
   char input_str[MAX_INPUT] = { 0 }; //user input string
   char test_str[] = "The quick brown fox jumps over the lazy dog"; //test string
   time_t start_time, end_time; //start and end time for timer
   
   printf("\nWelcome to the typing speed test program!\n");
   printf("You have %d seconds to type the following sentence:\n\n", time_limit);
   printf("%s\n\n", test_str);

   //start timer
   start_time = time(NULL);
   
   //get user input
   fgets(input_str, MAX_INPUT, stdin);

   //end timer
   end_time = time(NULL);

   //calculate elapsed time in seconds
   double elapsed_time = difftime(end_time, start_time);

   //count number of correct characters
   for (i = 0; test_str[i] != '\0'; i++) {
      if (test_str[i] == input_str[i]) {
         count++;
      }
   }

   //calculate typing speed in words per minute
   double words_per_minute = (((double)count / (double)i) * 60) / elapsed_time;

   //calculate user score
   score = (int)words_per_minute * 10;

   //print user score
   printf("\nCongratulations! Your typing speed is %.2f words per minute.\n", words_per_minute);
   printf("Your score is %d.\n\n", score);

   return 0;
}