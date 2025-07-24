//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Welcome message
  printf("Welcome to the Surrealist Smart Home Light Control!\n\n");

  // Initialize variables
  int lightsOn = 0;
  char input[50];
  time_t t;

  // Set the seed for random number generator
  srand((unsigned) time(&t));

  // Loop until user exits
  while (1) {

    // Display current status of lights
    if (lightsOn) {
      printf("The lights are currently on.\n");
    } else {
      printf("The lights are currently off.\n");
    }

    // Get user input
    printf("What would you like to do? (Type 'help' for list of commands)\n");
    fgets(input, 50, stdin);

    // Process user input
    if (strcmp(input, "help\n") == 0) {
      printf("\nList of commands:\n");
      printf(" - on: Turns the lights on\n");
      printf(" - off: Turns the lights off\n");
      printf(" - dim: Dim the lights by a random amount\n");
      printf(" - exit: Exits the program\n\n");
    } else if (strcmp(input, "on\n") == 0) {
      lightsOn = 1;
    } else if (strcmp(input, "off\n") == 0) {
      lightsOn = 0;
    } else if (strcmp(input, "dim\n") == 0) {
      int randNum = rand() % 10 + 1;
      printf("The lights have been dimmed by %d%%.\n", randNum * 10);
    } else if (strcmp(input, "exit\n") == 0) {
      printf("\nThank you for using the Surrealist Smart Home Light Control!\n");
      break;
    } else {
      printf("Invalid command. Type 'help' for list of commands.\n");
    }

    // Wait for user to press enter before continuing
    printf("\nPress enter to continue...");
    while (getchar() != '\n');
    printf("\n");
  }

  return 0;
}