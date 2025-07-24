//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include<stdio.h>
#include<string.h>

void sanitizeInput(char input[]) {
  int i, j;
  int len = strlen(input);
  char temp[len];

  for (i = 0, j = 0; i < len; i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      temp[j++] = input[i];
    }
    else if (input[i] >= 65 && input[i] <= 90) {
      temp[j++] = input[i] + 32;
    }
    else if (input[i] >= 97 && input[i] <= 122) {
      temp[j++] = input[i];
    }
    else {
      continue;
    }
  }
  temp[j] = '\0';
  strcpy(input, temp);
}

int main () {
  char input[100];
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  sanitizeInput(input);
  printf("Sanitized input: %s\n", input);
  return 0;
}