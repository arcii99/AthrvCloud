//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 to 6
int rollDice() {
   return (rand() % 6) + 1;
}

// function to take user input for the number of dice to roll
int getUserInput() {
   int numDice;

   printf("How many dice would you like to roll? ");
   scanf("%d", &numDice);

   return numDice;
}

// function to print the result of each dice roll
void printRolls(int numDice) {
   int i;
   printf("Rolling %d dice...\n", numDice);
   for (i=0; i<numDice; i++) {
      printf("Dice %d: %d\n", i+1, rollDice());
   }
}

// main function to execute the program
int main() {
   int numDice;

   printf("Welcome to the Dice Roller!\n");

   // seed the random number generator with the current time
   srand(time(NULL));

   // get user input for the number of dice to roll
   numDice = getUserInput();

   // print the result of each dice roll
   printRolls(numDice);

   return 0;
}