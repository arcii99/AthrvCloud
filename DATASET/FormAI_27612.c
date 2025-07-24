//FormAI DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <string.h>

void main() {
  // Welcome message
  printf("Welcome to the Smart Home Light Control program!\n");
  
  // Gathering information from the user
  printf("Please enter the room you would like to control the lights in: ");
  char room[20];
  scanf("%s", room);

  printf("Enter the command you would like to execute (on/off): ");
  char command[4];
  scanf("%s", command);
  
  // Validating the user input
  if (strcmp(command, "on") != 0 && strcmp(command, "off") != 0) {
    printf("Invalid command entered. Please enter either 'on' or 'off'.\n");
    return 1;
  }
  
  // Executing the command
  if (strcmp(command, "on") == 0) {
    printf("Turning on the lights in the %s...\n", room);
    
    // Code to turn on the lights in the specified room
    // ...
  } else {
    printf("Turning off the lights in the %s...\n", room);
    
    // Code to turn off the lights in the specified room
    // ...
  }
  
  // Success message
  printf("Command executed successfully. Thank you for using the Smart Home Light Control program!\n");
}