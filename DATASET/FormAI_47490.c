//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lightsOn = 0;

  printf("Welcome to your Smart Home Light Control system!\n");
  printf("Please enter a command:\n");

  while (1) {
    char input[10];
    fgets(input, 10, stdin);
	
    if (strcmp(input, "lights on\n") == 0) {
      if (!lightsOn) {
        printf("Turning on lights...\n");
        lightsOn = 1;
      } else {
        printf("Lights are already on.\n");
      }
    } else if (strcmp(input, "lights off\n") == 0) {
      if (lightsOn) {
        printf("Turning off lights...\n");
        lightsOn = 0;
      } else {
        printf("Lights are already off.\n");
      }
    } else if (strcmp(input, "help\n") == 0) {
      printf("Here are the available commands:\n");
      printf(" - lights on\n");
      printf(" - lights off\n");
      printf(" - help\n");
    } else {
      printf("Command not recognized, please try again.\n");
    }
  }

  return 0;
}