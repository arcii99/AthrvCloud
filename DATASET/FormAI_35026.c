//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
  char input_string[100]; // Declare the input string
  printf("Enter a string: ");
  fgets(input_string, 100, stdin); // Read the input string from the user
  input_string[strcspn(input_string, "\n")] = '\0'; // Remove the newline character from fgets

  char output_string[100];
  int output_index = 0; // Keep track of current index in output_string

  for (int i = 0; i < strlen(input_string); i++) {
    // Convert each uppercase character in input_string to lowercase and add to output_string
    if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
      output_string[output_index++] = input_string[i] + ('a' - 'A');
    }
    // Ignore any non-alphabetic characters and add to output_string
    else if ((input_string[i] >= 'a' && input_string[i] <= 'z') || (input_string[i] >= '0' && input_string[i] <= '9')) {
      output_string[output_index++] = input_string[i];
    }
  }

  output_string[output_index] = '\0'; // Properly terminate output_string
  
  printf("Input string: %s\n", input_string);
  printf("Output string: %s\n", output_string);

  return 0;
}