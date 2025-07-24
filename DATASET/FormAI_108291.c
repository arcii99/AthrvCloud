//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  srand(time(NULL));  //initialize random number generator
  
  int rolls;  //number of rolls
  int sides;  //number of sides on dice
  
  printf("Welcome to the Dice Roller!\n");
  printf("How many rolls would you like to make? ");
  scanf("%d", &rolls);  //get user input for number of rolls
  
  printf("How many sides does the dice have? ");
  scanf("%d", &sides);  //get user input for number of dice sides
  
  int total = 0;  //initialize running total of rolls
  
  printf("\nRolling...\n");
  for (int i = 1; i <= rolls; i++) {
    int roll = rand() % sides + 1;  //generate random number between 1 and number of sides
    printf("Roll %d: %d\n", i, roll);  //display roll result
    total += roll;  //add roll result to running total
  }
  
  float average = (float) total / rolls;  //calculate average of rolls
  
  printf("\nTotal: %d\n", total);  //display total of all rolls
  printf("Average: %.2f\n", average);  //display average of rolls
  
  return 0;
}