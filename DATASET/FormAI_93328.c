//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   srand(time(NULL)); //seed the random number generator with the current time

   int num1 = rand() % 10 + 1;  //generate a random number from 1-10
   int num2 = rand() % 10 + 1;  //generate another random number from 1-10

   printf("I have generated two random numbers between 1-10. Guess the sum of these numbers!\n");

   int guess;
   scanf("%d",&guess); //get guess from user

   while(guess != num1 + num2){  //loop until user guesses correctly
      printf("Sorry, that's not correct. Please try again! Guess the sum of %d and %d: ", num1, num2);
      scanf("%d",&guess); //get guess from user
   }

   printf("Congratulations, you guessed correctly! The sum of %d and %d is indeed %d.\n", num1, num2, num1+num2);

   return 0;
}