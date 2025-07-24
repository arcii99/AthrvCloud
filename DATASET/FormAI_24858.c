//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>

#define MAX_WORKOUTS 100

struct Workout {
  char name[50];
  float duration; // In minutes
  float caloriesBurned;
};

int main() {
  int numWorkouts = 0; // How many workouts the user has logged
  struct Workout workouts[MAX_WORKOUTS]; // Array of workouts

  while(1) {
    printf("Enter workout name (or 'q' to quit): ");
    fgets(workouts[numWorkouts].name, 50, stdin);
    strtok(workouts[numWorkouts].name, "\n"); // Remove trailing newline character

    if(workouts[numWorkouts].name[0] == 'q' || workouts[numWorkouts].name[0] == 'Q') {
      break; // If user types 'q', break out of loop
    }

    printf("Enter duration of the workout (in minutes): ");
    scanf("%f", &workouts[numWorkouts].duration);
    getchar(); // Consume newline character

    printf("Enter calories burned: ");
    scanf("%f", &workouts[numWorkouts].caloriesBurned);
    getchar(); // Consume newline character

    numWorkouts++; // Increment number of workouts in array
  }

  // Print out summary of workouts
  printf("\nWorkout Log:\n");
  printf("| %-50s | %12s | %18s |\n", "Name", "Duration (min)", "Calories Burned");
  printf("|----------------------------------------------------|----------------|----------------------|\n");
  for(int i=0; i<numWorkouts; i++) {
    printf("| %-50s | %12.2f | %18.2f |\n", workouts[i].name, workouts[i].duration, workouts[i].caloriesBurned);
  }

  return 0;
}