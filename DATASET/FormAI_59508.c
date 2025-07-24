//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a C Cat Language sentence: ");
  fgets(input, 100, stdin);

  char output[100];
  int currentIndex = 0;
  for(int i = 0; i < strlen(input); i++) {
    switch (input[i]) {
      case 'm':
        output[currentIndex++] = 'm';
        output[currentIndex++] = 'e';
        break;
      case 'y':
        output[currentIndex++] = 'y';
        output[currentIndex++] = 'o';
        output[currentIndex++] = 'w';
        output[currentIndex++] = 'l';
        break;
      case 'o':
        if (i + 1 < strlen(input) && input[i+1] == 'f') {
          output[currentIndex++] = 'p';
          output[currentIndex++] = 'u';
          output[currentIndex++] = 'r';
          output[currentIndex++] = 'r';
        } else {
          output[currentIndex++] = 'o';
        }
        break;
      case 'r':
        if (i + 2 < strlen(input) && input[i+1] == 'r' && input[i+2] == 'r') {
          output[currentIndex++] = 'r';
          output[currentIndex++] = 'r';
        } else {
          output[currentIndex++] = 'r';
        }
        break;
      default:
        break;
    }
  }

  printf("Translated sentence: %s", output);
  return 0;
}