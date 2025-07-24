//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = malloc(sizeof(char) * 100);
  int count = 0;
  
  while (1) {
    printf("Enter a command: ");
    fgets(input, 100, stdin);

    if (strstr(input, "sudo") != NULL) {
      printf("Attempted sudo-command detected!\n");
    }

    for (int i = 0; i < strlen(input); i++) {
      if (input[i] == '(' && input[i+1] != ')') {
        printf("Possible shell command injection detected!\n");
      }
    }

    count++;
    if (count == 10) {
      printf("Too many attempts. Exiting.\n");
      exit(1);
    }
  }

  free(input);
  return 0;
}