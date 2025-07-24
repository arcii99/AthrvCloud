//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {

  int choice, distance = 0, speed = 0, duration = 0;

  printf("Welcome to Robot Movement Control\n");

  while (1) {
    printf("\nPlease select an option:\n1. Move robot\n2. Check distance travelled\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the speed of the robot in km/hr: ");
        scanf("%d", &speed);
        printf("Enter the duration of the movement in minutes: ");
        scanf("%d", &duration);
        distance += (speed * duration) / 60;
        printf("\nRobot has travelled %d km!\n", distance);
        break;
      case 2:
        printf("\nRobot has travelled %d km in total!\n", distance);
        break;
      case 3:
        printf("\nThank you for using Robot Movement Control!\n");
        exit(0);
      default:
        printf("\nInvalid option, please try again.\n");
    }
  }

  return 0;
}