//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input_string[1000];
  int i, length;
  printf("Enter a string: ");
  fgets(input_string, 1000, stdin);
  length = strlen(input_string);
  for (i = 0; i < length; i++) {
    if (input_string[i] == ' ') {
      input_string[i] = '_'; // Replacing spaces with underscores
    } else if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
      input_string[i] += 32; // Converting uppercase letters to lowercase
    } else if (input_string[i] >= 'a' && input_string[i] <= 'z') {
      input_string[i] -= 32; // Converting lowercase letters to uppercase
    }
  }
  printf("Processed string: %s\n", input_string);
  return 0;
}