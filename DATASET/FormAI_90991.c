//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
  char name[50];
  int reps;
  int weight;
};

struct Workout {
  char date[20];
  int numExercises;
  struct Exercise exercises[10];
};

struct User {
  char username[20];
  int numWorkouts;
  struct Workout workouts[30];
};

struct User createUser(char username[]) {
  struct User user;
  strcpy(user.username, username);
  user.numWorkouts = 0;
  return user;
}

struct Workout createWorkout(char date[]) {
  struct Workout workout;
  strcpy(workout.date, date);
  workout.numExercises = 0;
  return workout;
}

struct Exercise createExercise(char name[], int reps, int weight) {
  struct Exercise exercise;
  strcpy(exercise.name, name);
  exercise.reps = reps;
  exercise.weight = weight;
  return exercise;
}

void addExercise(struct Workout *workout, struct Exercise *exercise) {
  if(workout->numExercises < 10) {
    workout->exercises[workout->numExercises++] = *exercise;
  }
}

void addWorkout(struct User *user, struct Workout *workout) {
  if(user->numWorkouts < 30) {
    user->workouts[user->numWorkouts++] = *workout;
  }
}

void printUserWorkouts(struct User *user) {
  printf("User: %s\n", user->username);
  printf("Workouts:\n");
  for(int i=0; i<user->numWorkouts; i++) {
    printf("%s: ", user->workouts[i].date);
    for(int j=0; j<user->workouts[i].numExercises; j++) {
      printf("%s %d x %d, ", user->workouts[i].exercises[j].name, user->workouts[i].exercises[j].reps, user->workouts[i].exercises[j].weight);
    }
    printf("\n");
  }
}

int main() {
  struct User user = createUser("JohnDoe");
  
  struct Workout workout1 = createWorkout("2021-02-01");
  struct Exercise exercise1 = createExercise("Bench Press", 10, 135);
  struct Exercise exercise2 = createExercise("Squats", 10, 185);
  addExercise(&workout1, &exercise1);
  addExercise(&workout1, &exercise2);
  addWorkout(&user, &workout1);
  
  struct Workout workout2 = createWorkout("2021-02-02");
  struct Exercise exercise3 = createExercise("Deadlift", 5, 225);
  addExercise(&workout2, &exercise3);
  addWorkout(&user, &workout2);
  
  printUserWorkouts(&user);
  return 0;
}