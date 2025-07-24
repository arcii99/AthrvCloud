//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>

struct FitnessTracker {
  float weight;
  int steps;
  float distance;
  int caloriesBurned;
};

void displayData(struct FitnessTracker ft) {
  printf("Weight: %.2f kg\n", ft.weight);
  printf("Steps: %d\n", ft.steps);
  printf("Distance: %.2f km\n", ft.distance);
  printf("Calories Burned: %d kcal\n\n", ft.caloriesBurned);
}

void updateData(struct FitnessTracker *ft, int newSteps, float newDistance) {
  ft->steps += newSteps;
  ft->distance += newDistance;
  ft->caloriesBurned += (int)(newDistance * 50);
}

int main() {
  struct FitnessTracker user = {65.8, 0, 0, 0};
  printf("Fitness Tracker\n\n");
  printf("Initial Data:\n");
  displayData(user);

  updateData(&user, 5000, 4.2);
  printf("Updated Data:\n");
  displayData(user);

  updateData(&user, 3000, 2.5);
  printf("Updated Data:\n");
  displayData(user);

  return 0;
}