//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>

#define MAX_DATA 100

int main(void) {
  int weight[MAX_DATA], calories[MAX_DATA];
  int i, j, total_weight = 0, total_calories = 0;
  float avg_weight, avg_calories;
  
  // Read user input for weight and calorie data
  printf("Enter your weights and calories for the last %d days:\n", MAX_DATA);
  for(i = 0; i < MAX_DATA; i++) {
    printf("Day %d: Weight (lbs): ", i+1);
    scanf("%d", &weight[i]);
    printf("Day %d: Calories (kcal): ", i+1);
    scanf("%d", &calories[i]);
  }
  
  // Calculate total weight and calorie data
  for(j = 0; j < MAX_DATA; j++) {
    total_weight += weight[j];
    total_calories += calories[j];
  }
  
  // Calculate and display average weight and calorie data
  avg_weight = (float) total_weight / MAX_DATA;
  avg_calories = (float) total_calories / MAX_DATA;
  
  printf("\nYour average weight for the last %d days is %.2f lbs.\n", MAX_DATA, avg_weight);
  printf("Your average calories for the last %d days is %.2f kcal.\n", MAX_DATA, avg_calories);
  
  return 0;
}