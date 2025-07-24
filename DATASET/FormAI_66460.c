//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum size of input
#define MAX_INPUT_SIZE 1024

// function to check if the input is suspicious
int is_suspicious(char* input) {
  int len = strlen(input);
  int count = 0;

  // check for consecutive spaces
  for (int i = 0; i < len - 1; i++) {
    if (input[i] == ' ' && input[i+1] == ' ') {
      count++;
    }
    if (count >= 3) {
      return 1;
    }
  }

  // check for semicolons or pipes to separate commands
  if (strstr(input, ";") != NULL || strstr(input, "|") != NULL) {
    return 1;
  }

  return 0;
}

int main() {
  char input[MAX_INPUT_SIZE];

  printf("Enter a command: ");

  // read input from user
  fgets(input, MAX_INPUT_SIZE, stdin);

  // remove trailing newline
  input[strcspn(input, "\n")] = 0;

  // check if input is suspicious
  if (is_suspicious(input)) {
    printf("Intrusion detected!\n");
  } else {
    printf("Command accepted.\n");
  }

  return 0;
}