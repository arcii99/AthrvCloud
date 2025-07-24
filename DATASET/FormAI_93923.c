//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   char input;
   int count = 0, time_taken, cpm;
   clock_t t1,t2;
   srand(time(0));

   printf("\n****WELCOME TO SHAPE SHIFTING TYPING SPEED TEST*****\n\n");

   printf("Enter the number of questions you want to attempt:\n");
   int num_questions;
   scanf("%d", &num_questions);

   printf("\nType the character as shown on the screen...and then press Enter.\n");

   for(int i = 0; i < num_questions; i++) {
      char c = (rand() % 26) + 'a';
      printf("\n%c\n", c);
      t1 = clock();
      scanf(" %c", &input);
      t2 = clock();

      if(input == c) {
         count++;
         printf("CORRECT! Keep it up!\n");
         time_taken += t2 - t1; //Time taken in ticks
      }
      else {
         printf("OOPS! That's incorrect! Try again...\n");
      }
   }
   
   printf("\n\n************RESULTS***********\n");
   cpm = count/(time_taken/(double)CLOCKS_PER_SEC)*60; //Calculating characters per minute
   printf("%d questions attempted!\n",num_questions);
   printf("%d correct answers!\n",count);
   printf("Average typing speed: %d CPM\n", cpm);
   printf("Total time taken: %d seconds\n", (int)(time_taken/(double)CLOCKS_PER_SEC));
   printf("*********************************\n");

   return 0;
}