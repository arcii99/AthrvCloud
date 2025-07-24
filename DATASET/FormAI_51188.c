//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>

int main() {
  printf("\nWelcome to the C Fitness Tracker!\nLet's get you started on your fitness journey!\n");

  int exerciseTime, caloriesBurned;
  printf("How many minutes did you exercise?\n");
  scanf("%d", &exerciseTime);

  // We'll assume a person burns 5 calories a minute during cardio exercise
  caloriesBurned = exerciseTime * 5;

  printf("Great job! You burned %d calories during your workout!\n", caloriesBurned);

  int waterIntake;
  printf("How many ounces of water did you drink today?\n");
  scanf("%d", &waterIntake);

  if(waterIntake >= 64) {
    printf("Fantastic! You hit your daily water intake goal!\n");
  }
  else {
    printf("Don't forget to drink more water! Remember to aim for at least 64 ounces per day.\n");
  }

  int proteinIntake, proteinGoal;
  printf("How many grams of protein did you eat today?\n");
  scanf("%d", &proteinIntake);

  printf("What is your daily protein goal in grams?\n");
  scanf("%d", &proteinGoal);

  if(proteinIntake >= proteinGoal) {
    printf("You crushed your daily protein goal! Good work!\n");
  }
  else {
    printf("Keep working towards your protein goal! Make sure to eat enough protein to build strong muscles.\n");
  }

  return 0;
}