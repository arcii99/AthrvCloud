//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>

int main() {
  int days;
  printf("How many days would you like to track your fitness for?: ");
  scanf("%d", &days);
  int caloriesBurned[days], total = 0;
  recordCalories(caloriesBurned, days);
  displayCalories(caloriesBurned, days, total);
  return 0;
}

void recordCalories(int caloriesBurned[], int days) {
  if (days == 0) {
    return;
  }
  printf("How many calories did you burn on day %d?: ", days);
  scanf("%d", &caloriesBurned[days-1]);
  recordCalories(caloriesBurned, days-1);
}

void displayCalories(int caloriesBurned[], int days, int total) {
  if (days == 0) {
    printf("You burned a total of %d calories over %d days.", total, days);
    return;
  }
  printf("On day %d, you burned %d calories.\n", days, caloriesBurned[days-1]);
  total += caloriesBurned[days-1];
  displayCalories(caloriesBurned, days-1, total);
}