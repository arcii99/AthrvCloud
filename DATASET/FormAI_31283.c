//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

/* Define our custom compression algorithm */
void custom_compress(char* input, int input_size, char* output, int* output_size) {
  // check input parameters
  if (input == NULL || output == NULL || output_size == NULL || *output_size == 0) {
    printf("[ERROR] Invalid input or output size for custom_compress.\n");
    return;
  }

  // initialize output variables
  int compressed_size = 0;
  char compressed_char = 0;
  int char_position = 0;
  
  // loop through input and compress each character
  for (int i = 0; i < input_size; i++) {
    char current_char = input[i];
    if (i == 0) {
      compressed_char = current_char; // initialize first char
    } else if (compressed_char == current_char && char_position < 8) {
      char_position++; // same char as previous, shift position
    } else {
      // compress current char and add it to output
      output[compressed_size] = compressed_char << char_position;
      compressed_size++;
      compressed_char = current_char;
      char_position = 0;
    }
  }

  // add final compressed char to output
  output[compressed_size] = compressed_char << char_position;
  compressed_size++;

  // update output size and return
  *output_size = compressed_size;
  return;
}

int main() {
  // initialize input and output strings
  char input[] = "Let's see how well this compression algorithm works!";
  int input_size = sizeof(input);
  char* output = malloc(input_size);
  int output_size = 0;

  // compress input using custom compression algorithm
  custom_compress(input, input_size, output, &output_size);

  // print original and compressed strings
  printf("Input: %s\n", input);
  printf("Compressed Output: ");
  for (int i = 0; i < output_size; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");

  // free output string and return
  free(output);
  return 0;
}