//FormAI DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *input_str = NULL;
  int *input_int = NULL;

  printf("Enter a string: ");
  if (scanf("%ms", &input_str) != 1) {
    fprintf(stderr, "Error: Failed to read input string.\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter a integer: ");
  if (scanf("%d", input_int) != 1) {
    fprintf(stderr, "Error: Failed to read input integer.\n");
    free(input_str);
    exit(EXIT_FAILURE);
  }
  
  if (*input_int < 0 || *input_int > strlen(input_str)) {
    fprintf(stderr, "Error: Invalid input integer.\n");
    free(input_str);
    free(input_int);
    exit(EXIT_FAILURE);
  }
  
  char *output_str = (char *)malloc((*input_int + 1) * sizeof(char));
  strncpy(output_str, input_str, *input_int);
  output_str[*input_int] = '\0';

  printf("The first %d characters of the input string is: %s\n", *input_int, output_str);

  free(input_str);
  free(input_int);
  free(output_str);
  
  return 0;
}