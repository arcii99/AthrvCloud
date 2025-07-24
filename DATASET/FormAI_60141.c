//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

// Function to generate a random number between 0 and MAX
int generateRandom() {
   srand(time(NULL));
   return rand() % MAX;
}

int main() {

   int num1, num2;

   // Generate two random numbers between 0 and MAX
   num1 = generateRandom();
   num2 = generateRandom();

   printf("What is the sum of %d and %d?\n", num1, num2);

   int userAnswer;
   scanf("%d", &userAnswer);

   // Calculate the correct answer
   int correctAnswer = num1 + num2;

   if(userAnswer == correctAnswer) {
      printf("Congratulations! Your answer is correct.\n");
   } else {
      printf("Sorry, your answer is incorrect. The correct sum is %d.\n", correctAnswer);
   }

   return 0;
}