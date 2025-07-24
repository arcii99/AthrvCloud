//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare function signatures
bool is_valid_integer(char *input);
bool is_valid_float(char *input);

int main(void) {
  char input[50];

  // Loop until a valid integer is input by the user 
  while (true) {
    printf("Enter an integer: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      fprintf(stderr, "Error: fgets failed\n");
      exit(EXIT_FAILURE);
    }
    if (is_valid_integer(input)) {
      printf("Valid integer entered: %d\n", atoi(input));
      break;
    } else {
      printf("Invalid input, please try again.\n");
    }
  }

  // Loop until a valid float is input by the user
  while (true) {
    printf("Enter a float: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      fprintf(stderr, "Error: fgets failed\n");
      exit(EXIT_FAILURE);
    }
    if (is_valid_float(input)) {
      printf("Valid float entered: %.2f\n", atof(input));
      break;
    } else {
      printf("Invalid input, please try again.\n");
    }
  }

  return 0;
}

// Function to check if input string can be converted to a valid integer
bool is_valid_integer(char *input) {
  int i = 0;
  if (input[0] == '-') {
    i++;
  }
  for (; input[i] != '\0'; i++) {
    if (input[i] < '0' || input[i] > '9') {
      return false;
    }
  }
  return true;
}

// Function to check if input string can be converted to a valid float
bool is_valid_float(char *input) {
  int i = 0;
  if (input[0] == '-') {
    i++;
  }
  bool decimal_flag = false;
  for (; input[i] != '\0'; i++) {
    if (input[i] == '.') {
      if (decimal_flag) {
        return false;
      } 
      decimal_flag = true;
      continue;
    }
    if (input[i] < '0' || input[i] > '9') {
      return false;
    }
  }
  return decimal_flag;
}