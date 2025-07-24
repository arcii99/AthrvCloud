//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int steps = rand() % 10000 + 1; // random number of steps between 1 and 10000
  float distance = steps * (rand() % 10 + 1) / 1000.0; // random distance between 0.1 and 10 kilometers
  int calories = steps * (rand() % 10 + 1) / 100; // random calories burned between 1 and 100
  float sleep = (float) (rand() % 6 + 1) + (rand() % 60) / 60.0; // random sleep time between 1 and 6.59 hours

  printf("Welcome to the Surreal Fitness Tracker!\n\n");

  printf("Today you walked %d steps, which is about %.2f kilometers and burned %d calories.\n", steps, distance, calories);

  if (calories < 50) {
    printf("Come on, you can do better than that!\n");
  } else if (calories < 100) {
    printf("Not bad, but there's still room for improvement.\n");
  } else if (calories < 500) {
    printf("Great job! You're making progress.\n");
  } else {
    printf("Wow, you've burned a lot of calories today! Keep it up!\n");
  }

  printf("\nDid you know that walking %.2f kilometers burns about %.0f calories?\n", distance, distance * 50);

  printf("\nNow let's talk about sleep. Last night you slept for %.2f hours.", sleep);

  if (sleep < 4) {
    printf(" That's not enough sleep for an adult!");
  } else if (sleep < 7) {
    printf(" You need a bit more sleep to feel fully rested.");
  } else if (sleep < 9) {
    printf(" You're getting enough sleep, keep it up!");
  } else {
    printf(" That's a lot of sleep, are you feeling okay?");
  }

  printf("\n\nThanks for using the Surreal Fitness Tracker! Keep up the good work!\n");

  return 0;
}