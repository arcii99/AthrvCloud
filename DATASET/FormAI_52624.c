//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

void translate(char str[]) {
  int i, j, length;
  char c;

  length = strlen(str);
  for(i = 0; i < length; i++) {
    c = str[i];

    if(c == 'c' || c == 'C') {
      printf("Meow ");
    }
    else if(c == 'a' || c == 'A') {
      printf("Purr ");
    }
    else if(c == 't' || c == 'T') {
      printf("Hiss ");
    }
    else {
      printf("%c ", c);
    }
  }
}

int main() {
  char input[100];

  printf("Enter a sentence in Cat Language: ");
  fgets(input, 100, stdin);

  printf("Translating to Human Language...\n");
  translate(input);

  return 0;
}