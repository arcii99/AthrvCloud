//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x_pos = 0, y_pos = 0; //Initial position of RC vehicle
  int choice, distance; //Variables to store user inputs

  while(1) { //Infinite loop to continue running program until user chooses to exit
    printf("\n\nRemote Control Vehicle Simulation\n");
    printf("--------------------------------------\n");
    printf("Current Position: (%d, %d)\n", x_pos, y_pos);
    printf("1. Move Up\n");
    printf("2. Move Down\n");
    printf("3. Move Right\n");
    printf("4. Move Left\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter distance to move up: ");
        scanf("%d", &distance);
        y_pos += distance;
        break;
      case 2:
        printf("Enter distance to move down: ");
        scanf("%d", &distance);
        y_pos -= distance;
        break;
      case 3:
        printf("Enter distance to move right: ");
        scanf("%d", &distance);
        x_pos += distance;
        break;
      case 4:
        printf("Enter distance to move left: ");
        scanf("%d", &distance);
        x_pos -= distance;
        break;
      case 5:
        printf("Exiting program...");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}