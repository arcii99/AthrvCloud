//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>

int main() {

  printf("Welcome to the one and only C Fitness Tracker!\n");
  printf("Let's get started on tracking your fitness journey!\n");

  int bicepCurls;
  printf("Enter the number of bicep curls you completed in your workout: ");
  scanf("%d", &bicepCurls);

  int pushups;
  printf("Enter the number of pushups you completed in your workout: ");
  scanf("%d", &pushups);

  int situps;
  printf("Enter the number of situps you completed in your workout: ");
  scanf("%d", &situps);

  int squats;
  printf("Enter the number of squats you completed in your workout: ");
  scanf("%d", &squats);

  int totalReps = bicepCurls + pushups + situps + squats;

  printf("Total reps completed: %d\n", totalReps);

  if (totalReps >= 100) {
    printf("Great job! You are a fitness guru!\n");
  } else if (totalReps >= 50) {
    printf("Not bad, keep it up!\n");
  } else {
    printf("Looks like you've got some work to do...\n");
  }

  return 0;

}