//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");

  printf("Please enter the signal strength of your Wi-Fi: ");
  int signal_strength;
  scanf("%d", &signal_strength);

  if (signal_strength >= 80) {
    printf("Great signal strength! You must be close to the router.\n");
  } else if (signal_strength >= 60) {
    printf("Good signal strength. You should be able to stream videos without any problems.\n");
  } else if (signal_strength >= 40) {
    printf("Fair signal strength. You may experience some buffering when streaming videos.\n");
  } else {
    printf("Poor signal strength. You may need to move closer to the router or consider purchasing a Wi-Fi range extender.\n");
  }

  printf("\n");

  char prompt[256];
  strcpy(prompt, "Would you like to analyze another Wi-Fi signal? (y/n)");
  char user_choice;
  do {
    printf("%s ", prompt);
    scanf(" %c", &user_choice);
    printf("\n");

    if (user_choice == 'y' || user_choice == 'Y') {
      main();
    } else if (user_choice != 'n' && user_choice != 'N') {
      strcpy(prompt, "Invalid input. Please enter 'y' or 'n':");
    }

  } while (user_choice != 'n' && user_choice != 'N');

  printf("Thank you for using Wi-Fi Signal Strength Analyzer! Goodbye.\n");

  return 0;
}