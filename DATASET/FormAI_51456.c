//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {
  char input[50];
  int count = 0;

  printf("Enter your name:\n");
  gets(input);

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ';' || input[i] == '|' || input[i] == '`' || input[i] == '&' || input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' || input[i] == '<' || input[i] == '>' || input[i] == '$' || input[i] == '\\' || input[i] == '\'' || input[i] == '\"') {
      count++;
    }
  }

  if (count > 0) {
    printf("Potential intrusion detected. Please enter a valid input.\n");
  } else {
    printf("Welcome, %s!\n", input);
  }

  return 0;
}