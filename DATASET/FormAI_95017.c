//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char exerciseName[20];
  int sets;
  int reps;
  int weight;
} Exercise;

typedef struct {
  char date[11];
  Exercise exercises[5];
} Workout;

typedef struct {
  Workout workouts[30];
  int currentWorkoutIndex;
} FitnessTracker;

FitnessTracker tracker;

void addWorkout(char date[11]) {
  strcpy(tracker.workouts[tracker.currentWorkoutIndex].date, date);
  tracker.currentWorkoutIndex++;
}

void addExercise(char exerciseName[20], int sets, int reps, int weight) {
  int i;
  for (i = 0; i < 5; i++) {
    if (tracker.workouts[tracker.currentWorkoutIndex - 1].exercises[i].weight == 0) {
      strcpy(tracker.workouts[tracker.currentWorkoutIndex - 1].exercises[i].exerciseName, exerciseName);
      tracker.workouts[tracker.currentWorkoutIndex - 1].exercises[i].sets = sets;
      tracker.workouts[tracker.currentWorkoutIndex - 1].exercises[i].reps = reps;
      tracker.workouts[tracker.currentWorkoutIndex - 1].exercises[i].weight = weight;
      break;
    }
  }
}

void printWorkout(int index) {
  Workout workout = tracker.workouts[index];
  printf("Date: %s\n", workout.date);
  printf("Exercises:\n");
  int i;
  for (i = 0; i < 5; i++) {
    if (workout.exercises[i].weight != 0) {
      printf("  %s: %d sets x %d reps x %d lbs\n", workout.exercises[i].exerciseName, workout.exercises[i].sets, workout.exercises[i].reps, workout.exercises[i].weight);
    }
  }
}

void printAllWorkouts() {
  int i;
  for (i = 0; i < tracker.currentWorkoutIndex; i++) {
    printWorkout(i);
  }
}

int main() {
  addWorkout("01/01/2021");
  addExercise("Bench Press", 3, 8, 135);
  addExercise("Squat", 5, 5, 185);
  addExercise("Deadlift", 1, 5, 225);

  addWorkout("01/02/2021");
  addExercise("Shoulder Press", 3, 12, 95);
  addExercise("Chest Fly", 3, 12, 40);
  addExercise("Weighted Pull-up", 3, 8, 25);

  printAllWorkouts();
  
  return 0;
}