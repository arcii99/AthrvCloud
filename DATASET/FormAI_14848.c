//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <string.h>

void compress(char* input) {
  // Initialize variables
  char compressed[100];
  int uncompressed_size = strlen(input);
  int compressed_size = 0;
  int i,j,k;

  // Process each character of the input string
  for (i = 0; i < uncompressed_size; i++) {
    int longest_match_length = 0;
    int longest_match_offset = 0;

    // Find the longest matching substring in the dictionary
    for (j = 0; j < i; j++) {
      int match_length = 0;
      while (input[j + match_length] == input[i + match_length] && i + match_length < uncompressed_size) {
        match_length++;
      }
      if (match_length > longest_match_length) {
        longest_match_length = match_length;
        longest_match_offset = i - j;
      }
    }

    // Output the compressed data
    if (longest_match_length > 0) {
      compressed[compressed_size++] = '(';
      compressed[compressed_size++] = longest_match_offset;
      compressed[compressed_size++] = longest_match_length;
      compressed[compressed_size++] = ')';
      i += longest_match_length - 1;
    } else {
      compressed[compressed_size++] = input[i];
    }
  }

  // Output the compressed data to the console
  printf("\nCompressed data: %s\n", compressed);
}

int main() {
  // Test the compression algorithm
  char input[] = "LZ77 is awesome!";
  printf("Input data: %s\n", input);
  compress(input);

  return 0;
}