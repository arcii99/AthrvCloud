//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include<stdio.h>

int main() {
  int choice;
  printf("Welcome to the immersive C Drone Remote Control Example Program\n");

  do {
    printf("\nPlease select an action:\n");
    printf("1. Takeoff Drone\n");
    printf("2. Land Drone\n");
    printf("3. Move Drone Forward\n");
    printf("4. Move Drone Backward\n");
    printf("5. Move Drone Left\n");
    printf("6. Move Drone Right\n");
    printf("7. Rotate Drone Left\n");
    printf("8. Rotate Drone Right\n");
    printf("9. Exit Program\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Drone taking off...\n");
        break;
      case 2:
        printf("Drone landing...\n");
        break;
      case 3:
        printf("Moving drone forward...\n");
        break;
      case 4:
        printf("Moving drone backward...\n");
        break;
      case 5:
        printf("Moving drone left...\n");
        break;
      case 6:
        printf("Moving drone right...\n");
        break;
      case 7:
        printf("Rotating drone left...\n");
        break;
      case 8:
        printf("Rotating drone right...\n");
        break;
      case 9:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice, please select again.\n");
        break;
    }

  } while(choice != 9);

  return 0;
}