//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Smart Home Light Control!\n\n");
  
  int lightStatus = 0; // 0 means lights are off
  printf("The lights are currently off. Would you like to turn them on? (yes or no)\n");
  char userChoice[10]; // To store user input
  scanf("%s", userChoice);
  
  while (1) { // Infinite loop
    if (strcmp(userChoice, "yes") == 0) {
      if (lightStatus == 1) {
        printf("The lights are already on.\n");
      } else {
        printf("Turning the lights on!\n");
        lightStatus = 1;
      }
    } else if (strcmp(userChoice, "no") == 0) {
      if (lightStatus == 0) {
        printf("The lights are already off.\n");
      } else {
        printf("Turning the lights off!\n");
        lightStatus = 0;
      }
    } else {
      printf("Sorry, I did not understand that. Please enter 'yes' or 'no'.\n");
    }
    
    // Ask the user what they want to do next
    printf("What would you like to do next? (type 'exit' to quit)\n");
    scanf("%s", userChoice);
    
    // Check if the user wants to exit
    if (strcmp(userChoice, "exit") == 0) {
      printf("Thanks for using the Smart Home Light Control! Goodbye!\n");
      break;
    }
  }
  
  return 0;
}