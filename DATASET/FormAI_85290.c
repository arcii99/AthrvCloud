//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int steps = 0;
  float calories = 0.0;
  int heart_rate = 0;
  int distance = 0;
  int sleep_hours = 0;
  char mood[50];

  printf("Welcome to the Surrealist C Fitness Tracker!\n");
  printf("Let's start with counting your steps...\n");
  printf("Enter the number of steps you have taken today: ");
  scanf("%d", &steps);
  printf("%d steps, an interesting number indeed...\n", steps);

  printf("\nNow, let's calculate the calories burned...\n");
  calories = steps * 0.04;
  printf("You have burned %.2f calories, how enlightening...\n", calories);

  printf("\nNext, let's check your heart rate...\n");
  printf("Enter your current heart rate: ");
  scanf("%d", &heart_rate);
  printf("Hmm, %d beats per minute, quite musical...\n", heart_rate);

  printf("\nLet's see how far you have gone...\n");
  distance = steps / 2;
  printf("You have traveled %d meters, fascinating...\n", distance);

  printf("\nHow many hours did you sleep last night?\n");
  scanf("%d", &sleep_hours);

  printf("\nLastly, tell me your current mood in one word:\n");
  scanf("%s", mood);

  printf("\n\n\nCongratulations on completing your Surrealist C Fitness Tracker for today!\n");
  printf("Summary:\n");
  printf("Number of Steps: %d\n", steps);
  printf("Calories Burned: %.2f\n", calories);
  printf("Heart Rate: %d bpm\n", heart_rate);
  printf("Distance Traveled: %d meters\n", distance);
  printf("Hours of Sleep: %d\n", sleep_hours);
  printf("Your Current Mood: %s\n", mood);

  return 0;
}