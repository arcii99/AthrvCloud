//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
   int dice, rolls, sum = 0; //initialize variables
   
   srand(time(NULL)); //initialize random seed
   
   printf("How many dice do you want to roll? ");
   scanf("%d", &dice); //get number of dice to roll
   
   printf("How many times do you want to roll? ");
   scanf("%d", &rolls); //get number of times to roll each dice
   
   for (int i = 0; i < rolls; i++) { //loop through each roll
      printf("Roll %d: ", i+1); 
      for (int j = 0; j < dice; j++) { //loop through each dice
         int result = rand()%6 + 1; //generate random number between 1 and 6
         printf("%d ", result); 
         sum += result; //add result to total sum
      }
      printf("\n");
   }
   
   printf("Total sum of all rolls: %d", sum); //print total sum of all rolls
   
   return 0;
}