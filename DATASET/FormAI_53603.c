//FormAI DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[1000], output[1000];
  int i = 0, j = 0;

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  while (input[i]) {
    if (input[i] == 'v' && input[i+1] == 'i' && input[i+2] == 's' && input[i+3] == 'i' && input[i+4] == 'o' && input[i+5] == 'n' && input[i+6] == 'a' && input[i+7] == 'r' && input[i+8] == 'y') {
      output[j++] = 'p';
      output[j++] = 'r';
      output[j++] = 'o';
      output[j++] = 'g';
      output[j++] = 'r';
      output[j++] = 'a';
      output[j++] = 'm';
      output[j++] = 'm';
      output[j++] = 'i';
      output[j++] = 'n';
      output[j++] = 'g';
    }
    else {
      output[j++] = input[i];
    }
    i++;
  }
  output[j] = '\0';
  
  printf("Processed string: %s", output);

  return 0;
}