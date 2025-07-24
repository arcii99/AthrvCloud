//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num;
   char name[20];
   
   printf("Welcome to the Automated Fortune Teller\n");
   printf("What is your name? "); 
   scanf("%s", name); // Getting user's name
   
   printf("\nHello %s\n", name);
   printf("Please enter a number between 1 and 10: "); 
   scanf("%d", &num); // Getting user's selected number
   
   srand(time(NULL)); // Initializing random number generator
   int randNum = rand() % 10 + 1; // Generating a random number between 1 and 10
   
   printf("\n\n");
   
   if (num == randNum) {
      printf("Congratulations, %s! Your fortune is: You will be incredibly successful in the next year\n\n", name);
   } else if (num < randNum) {
      printf("Sorry, %s. Your fortune is: Your next few months will be challenging, but you will come out on top if you stay strong\n\n", name);
   } else {
      printf("Sorry, %s. Your fortune is: You may face some obstacles in the next year, but fortune will favor you if you keep your head high\n\n", name);
   }
   printf("Thank you for trying the Automated Fortune Teller!\n\n"); 
   
   return 0;
}