//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>

struct Exercise {
  char name[100];
  int sets;
  int reps;
  float weight;
};

int main() {
  
  struct Exercise exercises[10];
  int num_exercises = 0;
  
  printf("Welcome to the Fitness Tracker! \n\n");
  printf("How many exercises have you completed today? ");
  scanf("%d", &num_exercises);
  
  for (int i = 0; i < num_exercises; i++) {
    printf("\nExercise %d:\n", i+1);
    printf("Enter exercise name: ");
    scanf("%s", exercises[i].name);
    printf("Enter number of sets: ");
    scanf("%d", &exercises[i].sets);
    printf("Enter number of reps: ");
    scanf("%d", &exercises[i].reps);
    printf("Enter weight lifted: ");
    scanf("%f", &exercises[i].weight);
  }
  
  printf("\n\nYou completed the following exercises today: \n");
  for (int i = 0; i < num_exercises; i++) {
    printf("Exercise %d: %s\n", i+1, exercises[i].name);
    printf("Sets: %d, Reps: %d, Weight: %.2f\n\n", exercises[i].sets, exercises[i].reps, exercises[i].weight);
  }
  
  return 0;
}