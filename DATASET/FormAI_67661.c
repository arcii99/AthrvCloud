//FormAI DATASET v1.0 Category: Smart home automation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temp = 0; // initialize temperature variable
  int light = 0; // initialize light variable
  int door = 0; // initialize door variable

  printf("Welcome to Smart Home Automation!\n");

  while(1) { // repeat continuously
    printf("\nCurrent temperature is %d degrees Celsius\n", temp);
    printf("Current light level is %d percent\n", light);
    printf("Door is currently %s\n", door ? "open" : "closed");

    printf("What action do you want to perform?\n");
    printf("1. Change temperature\n");
    printf("2. Change light level\n");
    printf("3. Open/close door\n");
    printf("4. Exit program\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter new temperature: ");
        scanf("%d", &temp);
        break;
      case 2:
        printf("Enter new light level: ");
        scanf("%d", &light);
        break;
      case 3:
        door = !door; // toggle door state
        printf("Door is now %s\n", door ? "open" : "closed");
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0; // program should never reach here
}