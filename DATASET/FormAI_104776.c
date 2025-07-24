//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct FitnessTracker {
  char *name;
  int age;
  double weight; // in kg 
  double height; // in cm
  double bmi;
  int dailySteps;
};

void calculateBmi(struct FitnessTracker *tracker) {
  tracker->bmi = tracker->weight / ((tracker->height / 100) * (tracker->height / 100));
}

void updateSteps(struct FitnessTracker *tracker, int steps) {
  tracker->dailySteps += steps;
}

void printTrackerInformation(struct FitnessTracker *tracker) {
  printf("Name: %s, Age: %d\n", tracker->name, tracker->age);
  printf("Weight: %.2f kg, Height: %.2f cm, BMI: %.2f\n", tracker->weight, tracker->height, tracker->bmi);
  printf("Daily steps: %d\n", tracker->dailySteps);
}

int main() {
  struct FitnessTracker myTracker;
  myTracker.name = "John Doe";
  myTracker.age = 30;
  myTracker.weight = 75.5;
  myTracker.height = 178.5;
  myTracker.dailySteps = 0;

  calculateBmi(&myTracker);
  printTrackerInformation(&myTracker);

  // simulate adding daily steps through the week
  srand(time(NULL));
  for (int i = 0; i < 7; i++) {
    int dailySteps = rand() % (15000 - 5000 + 1) + 5000;
    updateSteps(&myTracker, dailySteps);
    printf("Added %d steps for day %d\n", dailySteps, i+1);
    printTrackerInformation(&myTracker);
  }
  
  return 0;
}