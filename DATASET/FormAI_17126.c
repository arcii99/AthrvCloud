//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>

int main() {
  char c;

  printf("Enter a character in C Cat Language: ");
  scanf("%c", &c);

  switch(c) {
    case 'meow':
      printf("Hello!\n");
      break;
    case 'purr':
      printf("Thank you!\n");
      break;
    case 'hiss':
      printf("Goodbye!\n");
      break;
    case 'scratch':
      printf("Sorry, I didn't understand that.\n");
      break;
    default:
      printf("Invalid C Cat Language input.\n");
  }

  return 0;
}