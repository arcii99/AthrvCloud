//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // to generate random numbers

  int pushUpGoal = 100;
  int sitUpGoal = 50;
  int squatGoal = 75;

  int pushUpCount = 0;
  int sitUpCount = 0;
  int squatCount = 0;

  int caloriesBurned = 0;
  int waterDrank = 0;

  printf("Welcome to the Post-Apocalyptic Fitness Tracker!\n");
  printf("To survive the harsh conditions of the new world, you must stay in shape.\n");
  printf("Your fitness goals are:\n");
  printf("- Push-ups: %d reps\n", pushUpGoal);
  printf("- Sit-ups: %d reps\n", sitUpGoal);
  printf("- Squats: %d reps\n", squatGoal);

  while (pushUpCount < pushUpGoal || sitUpCount < sitUpGoal || squatCount < squatGoal) {
    int exercise = rand() % 3; // 0 for push-ups, 1 for sit-ups, 2 for squats

    switch (exercise) {
      case 0:
        printf("\nDo some push-ups!\n");
        pushUpCount += rand() % 10 + 1; // generate a random number of reps between 1 and 10
        printf("- You did %d push-ups.\n", pushUpCount);
        break;
      case 1:
        printf("\nDo some sit-ups!\n");
        sitUpCount += rand() % 5 + 1; // generate a random number of reps between 1 and 5
        printf("- You did %d sit-ups.\n", sitUpCount);
        break;
      case 2:
        printf("\nDo some squats!\n");
        squatCount += rand() % 7 + 1; // generate a random number of reps between 1 and 7
        printf("- You did %d squats.\n", squatCount);
        break;
      default:
        break;
    }

    caloriesBurned += rand() % 50 + 1; // generate a random number of calories burned between 1 and 50
    waterDrank += rand() % 2 + 1; // generate a random amount of water drunk between 1 and 2 liters

    printf("- You burned %d calories and drank %d liters of water.\n", caloriesBurned, waterDrank);
  }

  printf("\nCongratulations! You completed your fitness goals in the post-apocalyptic world.\n");
  printf("You burned a total of %d calories and drank %d liters of water.\n", caloriesBurned, waterDrank);

  return 0;
}