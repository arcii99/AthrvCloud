//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Input string to be compressed
  char input_string[] = "this is a test string to be compressed";

  // Initialize output string
  char output_string[1024] = {0};

  // Initialize counters
  int count = 1, output_index = 0;

  // Loop through each character in input string
  for (int i = 0; i < strlen(input_string); i++) {
    // If current character matches the next character
    if (input_string[i] == input_string[i+1]) {
      count++;
    }
    // If current character does not match the next character
    else {
      // Encode the character count and character value
      output_string[output_index++] = count + '0';
      output_string[output_index++] = input_string[i];
      count = 1;
    }
  }

  // Print the input and output strings
  printf("Input string: %s\n", input_string);
  printf("Output string: %s\n", output_string);

  return 0;
}