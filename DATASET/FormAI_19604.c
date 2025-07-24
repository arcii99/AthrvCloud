//FormAI DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool isLightOn = false;
  bool isDoorLocked = true;
  bool isACOn = false;

  printf("Welcome to Smart Home Automation!\n");

  while (true) {
    printf("\nPlease select an option:\n");
    printf("1. Turn the Light %s\n", isLightOn ? "Off" : "On");
    printf("2. %s the Door\n", isDoorLocked ? "Unlock" : "Lock");
    printf("3. Turn the AC %s\n", isACOn ? "Off" : "On");
    printf("4. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        isLightOn = !isLightOn;
        printf("The light has been turned %s\n", isLightOn ? "On" : "Off");
        break;
      case 2:
        isDoorLocked = !isDoorLocked;
        printf("The door has been %s\n", isDoorLocked ? "Locked" : "Unlocked");
        break;
      case 3:
        isACOn = !isACOn;
        printf("The AC has been turned %s\n", isACOn ? "On" : "Off");
        break;
      case 4:
        printf("Thank you for using Smart Home Automation. Have a nice day!\n");
        return 0;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }
}