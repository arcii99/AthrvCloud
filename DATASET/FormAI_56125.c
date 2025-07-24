//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   char user[20];
   int random_num;
   srand(time(NULL)); // seeds random number generator
   
   printf("Welcome to the Automated Fortune Teller!\n");
   printf("Enter your name to begin:\n");
   scanf("%s", user);
   printf("\nHello, %s! Let's get started.\n", user);
   
   printf("\nPick a number between 1 and 10:\n");
   int user_num;
   scanf("%d", &user_num);
   
   if (user_num < 1 || user_num > 10) {
      printf("\nInvalid choice. Exiting program.\n");
      return 1;
   }
   
   printf("\nYou have chosen %d.\n", user_num);
   
   random_num = rand() % 10 + 1; // generates random number
   
   if (random_num == user_num) {
      printf("\nCongratulations, %s! You have chosen the lucky number.\n", user);
   } else {
      printf("\nI'm sorry, %s, the lucky number was %d.\n", user, random_num);
   }
   
   printf("\nThanks for using the Automated Fortune Teller!\n");
   
   return 0;
}