//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100];
  int i = 0, j = 0;

  printf("Enter Input: ");
  fgets(input, sizeof(input), stdin);

  while(input[i] != '\0') {
    if(isalpha(input[i])) {
      input[j++] = input[i];
    }
    i++;
  }
  input[j] = '\0';

  printf("\nSanitized Input: %s\n", input);

  return 0;
}