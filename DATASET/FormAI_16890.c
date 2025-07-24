//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>

int main() {
  int calories_burned;
  int minutes_exercised;
  int goal_calories;
  int goal_minutes;

  printf("Welcome to your Fitness Tracker!\n");
  printf("Please enter how many minutes you exercised today: ");
  scanf("%d", &minutes_exercised);
  printf("Please enter how many calories you burned today: ");
  scanf("%d", &calories_burned);
  printf("Please enter your daily goal for minutes exercised: ");
  scanf("%d", &goal_minutes);
  printf("Please enter your daily goal for calories burned: ");
  scanf("%d", &goal_calories);

  if (calories_burned >= goal_calories && minutes_exercised >= goal_minutes) {
    printf("Congratulations!\nYou reached your goals for today!");
  } else {
    printf("Oh no!\nYou did not reach your goals for today.");
  }

  return 0;
}