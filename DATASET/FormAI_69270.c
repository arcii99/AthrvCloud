//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>

int main() {
  int calories = 0;
  int steps = 0;
  float distance = 0.0;
  
  printf("Welcome to the Fitness Tracker! Please enter your daily information:\n");
  
  printf("Calories burned: ");
  scanf("%d", &calories);
  
  printf("Steps taken: ");
  scanf("%d", &steps);
  
  distance = steps * 0.0008; //average stride length of 0.8m
  
  printf("Distance traveled (km): %.2f\n", distance);
  printf("Calories burned: %d\n", calories);
  printf("Steps taken: %d\n", steps);
  
  return 0;
}