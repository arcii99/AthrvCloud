//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void addExercise(int calories);

int totalCalories = 0; // initialize total number of calories burned to 0
int goalCalories = 2000; // initialize daily goal to 2000 calories

int main() {
  printf("Welcome to the Fitness Tracker!\n");
  printf("Your daily goal is set to %d calories.\n\n", goalCalories);

  while(1) {
    printf("Enter the number of calories burned from an exercise (enter 0 to exit): ");
    int calories;
    scanf("%d", &calories);

    if(calories == 0) { // user wants to exit
      printf("\nYou burned %d calories today!\n", totalCalories);

      if(totalCalories >= goalCalories) {
        printf("Congratulations, you met your daily goal!\n");
      } else {
        printf("Better luck next time, you did not meet your daily goal.\n");
      }

      return 0;
    }

    addExercise(calories); // add the calories burned to the total
    printf("Total Calories: %d\n\n", totalCalories);
  }
}

void addExercise(int calories) {
  totalCalories += calories;
}