//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>

int main() {
  int exercise_duration, calories_burned_per_min;
  printf("Enter exercise duration (in minutes): ");
  scanf("%d", &exercise_duration);
  printf("Enter calories burned per minute: ");
  scanf("%d", &calories_burned_per_min);

  int total_calories_burned = exercise_duration * calories_burned_per_min;

  printf("\n*** Fitness Tracker Report ***\n");
  printf("Exercise duration (minutes): %d\n", exercise_duration);
  printf("Calories burned per minute: %d\n", calories_burned_per_min);
  printf("Total calories burned: %d\n", total_calories_burned);

  if (total_calories_burned > 300) {
    printf("\nExcellent job! You burned more than 300 calories!\n");
  } else if (total_calories_burned >= 100) {
    printf("\nGood job! You burned at least 100 calories!\n");
  } else {
    printf("\nKeep working! You can do better!\n");
  }
  
  return 0;
}