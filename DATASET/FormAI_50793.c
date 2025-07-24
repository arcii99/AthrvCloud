//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>

int main() {
  int curr_step = 0;
  printf("--------------------\n");
  printf("| FITNESS TRACKER  |\n");
  printf("--------------------\n");

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Log steps taken\n");
    printf("2. View current step count\n");
    printf("3. Reset step count\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter number of steps taken: ");
        int steps;
        scanf("%d", &steps);
        curr_step += steps;
        printf("Steps logged successfully!\n");
        break;

      case 2:
        printf("\nCurrent step count: %d\n", curr_step);
        break;

      case 3:
        curr_step = 0;
        printf("\nStep count reset successfully!\n");
        break;

      case 4:
        printf("\nThank you for using FITNESS TRACKER!\n");
        return 0;

      default:
        printf("\nInvalid choice!\n");
    }
  }
  return 0;
}