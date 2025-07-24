//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please provide a command.\n");
    return 1;
  }

  char buffer[1024];
  char *command = argv[1];
  for (int i = 2; i < argc; i++) {
    sprintf(buffer, "%s %s", buffer, argv[i]);
  }
  strcat(command, buffer);

  printf("Command: %s\n", command);

  int status = system(command);
  if (status == -1) {
    printf("Error: Failed to run command.\n");
    return 1;
  }

  printf("Command successfully executed.\n");

  return 0;
}