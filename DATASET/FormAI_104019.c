//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
  char name[50];
  float weight;
  int reps;
  int sets;
};

struct Day {
  int month;
  int day;
  int year;
  struct Exercise exercises[10];
};

struct Workout {
  struct Day days[365];
  int num_days;
};

struct Workout createWorkout() {
  struct Workout workout;
  workout.num_days = 0;
  return workout;
}

void printWorkout(struct Workout workout) {
  printf("Workout:\n");
  for(int i = 0; i < workout.num_days; i++) {
    printf("Day %d/%d/%d:\n", workout.days[i].month, workout.days[i].day, workout.days[i].year);
    for(int j = 0; j < 10; j++) {
      if(workout.days[i].exercises[j].name[0] != '\0') {
        printf("%s: %d sets x %d reps x %.1f lbs\n", workout.days[i].exercises[j].name, workout.days[i].exercises[j].sets, workout.days[i].exercises[j].reps, workout.days[i].exercises[j].weight);
      }
    }
  }
}

void addDay(struct Workout *workout, int month, int day, int year) {
  struct Day day_struct;
  day_struct.month = month;
  day_struct.day = day;
  day_struct.year = year;
  for(int i = 0; i < 10; i++) {
    day_struct.exercises[i].name[0] = '\0';
  }
  workout->days[workout->num_days] = day_struct;
  workout->num_days++;
}

void addExercise(struct Workout *workout, int day, char *name, float weight, int sets, int reps) {
  for(int i = 0; i < 10; i++) {
    if(workout->days[day].exercises[i].name[0] == '\0') {
      strcpy(workout->days[day].exercises[i].name, name);
      workout->days[day].exercises[i].weight = weight;
      workout->days[day].exercises[i].sets = sets;
      workout->days[day].exercises[i].reps = reps;
      break;
    }
  }
}

int main() {
  struct Workout workout = createWorkout();
  addDay(&workout, 1, 1, 2022);
  addExercise(&workout, 0, "Squats", 135.0, 3, 10);
  addExercise(&workout, 0, "Bench Press", 95.0, 3, 8);
  addExercise(&workout, 0, "Deadlifts", 185.0, 3, 5);
  printWorkout(workout);
  return 0;
}