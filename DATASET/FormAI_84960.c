//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 256

char sanitize_input(char input[]) {
  char clean_input[MAX_INPUT_LEN];
  char c;
  int i, j;

  j = 0;
  for (i = 0; i < strlen(input); i++) {
    c = input[i];
    if (isalpha(c)) {
      // Convert to uppercase
      clean_input[j++] = toupper(c);
    } else if (isdigit(c)) {
      clean_input[j++] = c;
    }
  }
  clean_input[j] = '\0';
 
  printf("Clean input: %s\n", clean_input);
  return 0;
}

int main() {
  char input[MAX_INPUT_LEN];

  printf("Enter input:\n");
  fgets(input, MAX_INPUT_LEN, stdin);

  sanitize_input(input);

  return 0;
}