//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
  char original_string[MAX_SIZE], compressed_string[MAX_SIZE];
  int frequency[MAX_SIZE], visited[MAX_SIZE];

  printf("Enter the original string to compress: ");
  fgets(original_string, MAX_SIZE, stdin);
  original_string[strlen(original_string) - 1] = '\0'; // Remove the newline character at the end.

  // Initialize the frequency array to 1 for all characters.
  for (int i = 0; i < MAX_SIZE; i++) {
    frequency[i] = 1;
    visited[i] = 0;
  }

  // Calculate the frequency of each character in the string.
  int length = strlen(original_string);
  for (int i = 0; i < length; i++) {
    frequency[(int)(original_string[i])]++;
  }

  // Build the compressed string using the frequency array.
  int compressed_length = 0;
  for (int i = 0; i < length; i++) {
    int index = (int)(original_string[i]);
    if (!visited[index]) { // If this character has not been visited yet.
      visited[index] = 1;
      compressed_string[compressed_length++] = original_string[i];
      compressed_string[compressed_length++] = (char)(frequency[index] + '0'); // Append the frequency of the character as a digit.
    }
  }
  compressed_string[compressed_length] = '\0';

  printf("The compressed string is: %s\n", compressed_string);

  return 0;
}