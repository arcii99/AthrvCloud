//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char name[20];
   int age;
   double height;

   printf("Hello there! Let's get to know each other better! What is your name? \n");
   scanf("%s", name);
   
   // Loop until user enters a valid age
   while(1) {
      printf("How old are you, %s? \n", name);
      if(scanf("%d", &age) == 1 && age > 0 && age < 120) {
         break; // valid input
      }
      printf("Oops! That doesn't look like a valid age. Please try again.\n");
      while(getchar() != '\n'); // clear input buffer
   }

   // Loop until user enters a valid height
   while(1) {
      printf("What is your height in meters, %s? \n", name);
      if(scanf("%lf", &height) == 1 && height > 0.0 && height < 3.0) {
         break; // valid input
      }
      printf("Oops! That doesn't look like a valid height. Please try again.\n");
      while(getchar() != '\n'); // clear input buffer
   }

   printf("Nice to meet you, %s! Let me summarize what I learned about you:\n", name);
   printf("Age: %d years\n", age);
   printf("Height: %.2lf meters\n", height);
   
   return 0;
}