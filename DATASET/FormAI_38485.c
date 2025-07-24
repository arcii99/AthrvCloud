//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>

int main() {
  char command[10];

  printf("Welcome to C Drone Remote Control!\n");
  printf("Type 'help' for a list of available commands.\n");

  while(1) {
    printf(">> ");
    scanf("%s", command);

    if(strcmp(command, "up") == 0) {
      printf("Drone going up.\n");
    } else if(strcmp(command, "down") == 0) {
      printf("Drone going down.\n");
    } else if(strcmp(command, "left") == 0) {
      printf("Drone going left.\n");
    } else if(strcmp(command, "right") == 0) {
      printf("Drone going right.\n");
    } else if(strcmp(command, "forward") == 0) {
      printf("Drone going forward.\n");
    } else if(strcmp(command, "back") == 0) {
      printf("Drone going back.\n");
    } else if(strcmp(command, "hover") == 0) {
      printf("Drone hovering.\n");
    } else if(strcmp(command, "land") == 0) {
      printf("Drone landing.\n");
      break;
    } else if(strcmp(command, "help") == 0) {
      printf("\nAvailable commands:\n");
      printf("up\n");
      printf("down\n");
      printf("left\n");
      printf("right\n");
      printf("forward\n");
      printf("back\n");
      printf("hover\n");
      printf("land\n");
      printf("help\n\n");
    } else {
      printf("Invalid command. Type 'help' for a list of available commands.\n");
    }
  }

  printf("Thank you for using C Drone Remote Control!\n");

  return 0;
}