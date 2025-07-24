//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to control the smart home lights based on the input command
void light_control(char command[]) {
  if (strcmp(command, "ON") == 0) {
    printf("The lights are turned on!\n");
  } else if (strcmp(command, "OFF") == 0) {
    printf("The lights are turned off!\n");
  } else if (strcmp(command, "DIM") == 0) {
    printf("The lights are dimmed!\n");
  } else if (strcmp(command, "BRIGHTEN") == 0) {
    printf("The lights are brightened!\n");
  } else {
    printf("Invalid command entered!\n");
  }
}

int main() {
  char command[20]; // Maximum command length is 20 characters
  
  printf("Welcome to the Smart Home Light Control System!\n");
  printf("Enter your command (ON, OFF, DIM, BRIGHTEN): ");
  
  while (true) {
    scanf("%s", command);
    light_control(command);
    
    printf("Another command? (Y/N): ");
    char answer;
    scanf(" %c", &answer);
    
    if (answer == 'N') {
      printf("Goodbye!\n");
      break;
    } else if (answer != 'Y') {
      printf("Invalid response entered! Exiting...\n");
      break;
    }
    
    printf("Enter your command (ON, OFF, DIM, BRIGHTEN): ");
  }
  
  return 0;
}