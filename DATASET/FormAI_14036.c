//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitize(char* input);

int main() {
  int size = 256;
  char* input = malloc(size * sizeof(char));

  printf("Enter your input (maximum length is 255 characters): ");
  fgets(input, size, stdin);
  
  char* sanitizedInput = sanitize(input);
  printf("Sanitized input: %s\n", sanitizedInput);
  
  free(input);
  free(sanitizedInput);
  
  return 0;
}

char* sanitize(char* input) {
  char* output = (char*) malloc(strlen(input)+1);
  int i = 0;
  int j = 0;
  while(input[i] != '\0') {
    if (j > strlen(input)) {
      printf("Error: input exceeded maximum length\n");
      exit(1);
    }
    if (isalpha(input[i]) || isspace(input[i])) {
      output[j] = input[i];
      j++;
    }
    i++;
  }
  output[j] = '\0';
  return output;
}