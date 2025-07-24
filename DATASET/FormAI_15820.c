//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  
  printf("Please enter some text to process: ");
  fgets(input, 100, stdin);
  
  // Remove all vowels
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u' && input[i] != 'A' && input[i] != 'E' && input[i] != 'I' && input[i] != 'O' && input[i] != 'U') {
      output[j] = input[i];
      j++;
    }
  }
  output[j] = '\0';
  
  printf("Processed text: %s", output);
  
  return 0;
}