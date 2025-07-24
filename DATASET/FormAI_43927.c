//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input_string, int input_length, int i);

int main() {
  char input[MAX_INPUT_LENGTH];

  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  int input_length = strlen(input);
  if (input[input_length-1] == '\n') {
    input[input_length-1] = '\0';
    input_length--;
  }

  char* sanitized_input = sanitize_input(input, input_length, 0);
  printf("Sanitized input: %s\n", sanitized_input);

  free(sanitized_input);

  return 0;
}

char* sanitize_input(char* input_string, int input_length, int i) {
  if (i == input_length) {
    char* output_string = (char*)malloc((input_length+1)*sizeof(char));
    memcpy(output_string, input_string, input_length+1);
    return output_string;
  }

  if (isalpha(input_string[i])) {
    input_string[i] = tolower(input_string[i]);
    return sanitize_input(input_string, input_length, ++i);
  } else if (isdigit(input_string[i])) {
    return sanitize_input(input_string, input_length, ++i);
  } else {
    input_string[i] = '_';
    return sanitize_input(input_string, input_length, ++i);
  }
}