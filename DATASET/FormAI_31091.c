//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
  int steps = 0;
  float calories = 0.0, distance = 0.0;
  char input;
  
  printf("Welcome to the Fitness Tracker!\n");
  
  while (1) {
    printf("\nWhat activity did you do today? (s for steps, c for calories, d for distance, q to quit) ");
    scanf(" %c", &input);
    
    switch (input) {
      case 's':
        printf("Enter the number of steps you took today: ");
        scanf("%d", &steps);
        printf("You took %d steps today\n", steps);
        break;
      case 'c':
        printf("Enter the number of calories you burned today: ");
        scanf("%f", &calories);
        printf("You burned %.2f calories today\n", calories);
        break;
      case 'd':
        printf("Enter the distance you traveled today (in miles): ");
        scanf("%f", &distance);
        printf("You traveled %.2f miles today\n", distance);
        break;
      case 'q':
        printf("Thanks for using the Fitness Tracker!\n");
        exit(0);
      default:
        printf("Invalid input. Please try again.\n");
        break;
    }
  }
  
  return 0;
}