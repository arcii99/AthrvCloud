//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000], output[1000], c;
  int i, j, length;

  printf("Enter a sentence in Cat Language: ");
  fgets(input, 1000, stdin);

  length = strlen(input);

  i = 0;
  j = 0;

  while(i < length) {
    c = input[i];

    // Check if the character is 'M' or 'm'
    if(c == 'M' || c == 'm') {
      // If it is 'M' or 'm', replace it with 'C'
      output[j] = 'C';
      j++;
    }
    else {
      // If it is not 'M' or 'm', copy the character as it is
      output[j] = c;
      j++;
    }

    i++;
  }

  // Add a null character at the end of the string
  output[j] = '\0';

  printf("Translated sentence in C Language: %s", output);

  return 0;
}