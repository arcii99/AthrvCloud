//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[20];
  printf("Hello there! What's your name?\n");
  scanf("%s", name);

  // Create user account
  char command[50];
  sprintf(command, "sudo adduser %s", name);
  system(command);

  // Print ASCII art greeting
  printf("\n");
  printf("          / \\  \n");
  printf("        /     \\   \n");
  printf("      /         \\  \n");
  printf("      \\           /    Hello %s!\n", name);
  printf("        \\       /    \n");
  printf("          \\   /  \n");
  printf("            -\n");

  return 0;
}