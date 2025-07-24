//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  int i, j, k, len;
  
  printf("Enter a string: ");
  scanf("%s", input);
  
  len = strlen(input);
  
  // Reverse the string
  for (i = len-1, j = 0; i >= 0; i--, j++) {
    output[j] = input[i];
  }
  output[j] = '\0';
  
  // Convert to uppercase
  for (k = 0; k < len; k++) {
    if (output[k] >= 'a' && output[k] <= 'z') {
      output[k] -= 32;
    }
  }
  
  // Replace vowels with '*'
  for (k = 0; k < len; k++) {
    if (output[k] == 'A' || output[k] == 'E' || output[k] == 'I' || output[k] == 'O' || output[k] == 'U') {
      output[k] = '*';
    }
  }
  
  // Print the output
  printf("Input String : %s\n", input);
  printf("Output String: %s\n", output);
  
  return 0;
}