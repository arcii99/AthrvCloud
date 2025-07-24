//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char input[50];
  int location = 0;
  printf("You wake up in a strange room. There is a locked door and a window on the wall.\n");
  while (1) {
    printf("What do you want to do? (type 'help' for possible options) ");
    fgets(input, 50, stdin);
    strtok(input, "\n"); // remove trailing newline character
    if (strcmp(input, "help") == 0) {
      printf("Possible options:\n- examine door\n- examine window\n- try to open door\n- break window\n- wait\n");
    }
    else if (strcmp(input, "examine door") == 0) {
      if (location == 0) {
        printf("The door is a heavy metal door with a small keyhole.\n");
      }
      else {
        printf("The door is still locked.\n");
      }
    }
    else if (strcmp(input, "examine window") == 0) {
      printf("The window is covered with bars. You can't see anything outside.\n");
    }
    else if (strcmp(input, "try to open door") == 0) {
      if (location == 0) {
        printf("The door is locked.\n");
      }
      else {
        printf("You successfully opened the door and escaped the room!\n");
        break; // end the game
      }
    }
    else if (strcmp(input, "break window") == 0) {
      printf("You hit the window with all your strength, but it doesn't even crack.\n");
    }
    else if (strcmp(input, "wait") == 0) {
      printf("You wait for a while, but nothing happens.\n");
    }
    else {
      printf("I'm sorry, I don't understand what you want to do. Type 'help' to see possible options.\n");
    }
  }
  return 0;
}