//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct Exercise {
  char name[50];
  int duration;
  float caloriesBurned;
};

void addExercise(struct Exercise *exercise) {
  printf("Enter exercise name: ");
  scanf("%s", exercise->name);
  printf("Enter exercise duration in minutes: ");
  scanf("%d", &exercise->duration);
  printf("Enter calories burned: ");
  scanf("%f", &exercise->caloriesBurned);
}

void displayExercise(struct Exercise *exercise) {
  printf("Exercise Name: %s\n", exercise->name);
  printf("Duration: %d minutes\n", exercise->duration);
  printf("Calories Burned: %.2f\n", exercise->caloriesBurned);
}

int main() {
  printf("C Fitness Tracker\n\n");

  struct Exercise exercise1;
  addExercise(&exercise1);
  printf("\nExercise Added:\n");
  displayExercise(&exercise1);

  return 0;
}