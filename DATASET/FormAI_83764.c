//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  int i, j;

  printf("Enter a sentence in C Cat Language: ");
  fgets(input, sizeof(input), stdin);

  //start translation
  for (i = 0, j = 0; i < strlen(input); i++, j++) {
    switch(input[i]) {
      case 'C':
        output[j] = 'M';
        output[j+1] = 'E';
        j++;
        break;
      case 'a':
        output[j] = 'i';
        break;
      case 't':
        output[j] = 'c';
        break;
      case ' ':
        output[j] = ' ';
        break;
      default:
        printf("Error: invalid character encountered.");
        return 1;
    }
  }
  //end translation

  output[j] = '\0';

  printf("Translated sentence: %s\n", output);

  return 0;
}