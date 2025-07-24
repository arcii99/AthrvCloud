//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>

int main() {
  char c;

  printf("Enter a character in C Cat Language: ");
  scanf("%c", &c);

  switch (c) {
    case 'meow':
      printf("Translated to English: Hello\n");
      break;
    case 'purr':
      printf("Translated to English: Thank you\n");
      break;
    case 'hiss':
      printf("Translated to English: Goodbye\n");
      break;
    case 'growl':
      printf("Translated to English: I'm angry\n");
      break;
    case 'yawn':
      printf("Translated to English: I'm tired\n");
      break;
    default:
      printf("Unknown word in C Cat Language!\n");
  }

  return 0;
}