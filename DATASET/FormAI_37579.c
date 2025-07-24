//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   int num;
   srand(time(0));  // using time as seed for random number generation
   printf("Welcome to the Automated Fortune Teller! \n");
   printf("Please think of a number between 1 and 10 and press Enter to continue... \n");
   getchar();  // waiting for user to press Enter
   num = rand() % 10 + 1;  // generating a random number between 1 and 10
   switch(num) {
      case 1:
         printf("Your future looks bright!\n");
         break;
      case 2:
         printf("You will face some challenges but you will overcome them!\n");
         break;
      case 3:
         printf("You might experience a big change in your life soon!\n");
         break;
      case 4:
         printf("Your hard work will pay off soon!\n");
         break;
      case 5:
         printf("You will meet someone special soon!\n");
         break;
      case 6:
         printf("You will go on a journey that will change your perspective!\n");
         break;
      case 7:
         printf("You will receive good news from someone you haven't heard from in a long time!\n");
         break;
      case 8:
         printf("You might experience some financial problems, but they will be temporary!\n");
         break;
      case 9:
         printf("You will find a solution to a problem that has been bothering you!\n");
         break;
      case 10:
         printf("You will make a new friend who will help you in your future endeavors!\n");
         break;
   }
   return 0;
}