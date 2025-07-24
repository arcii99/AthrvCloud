//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>

int main() {
  char c;

  // Get user input
  printf("Enter a sentence in C Cat Language: ");
  scanf("%c", &c);

  // Translate C Cat Language to English
  switch(c) {
    case 'm': printf("meow"); break;
    case 'p': printf("purrr"); break;
    case 'h': printf("hiss"); break;
    case 'c': printf("cat"); break;
    case 'f': printf("food"); break;
    case 'w': printf("water"); break;
    case 's': printf("sleep"); break;
    case 'y': printf("yes"); break;
    case 'n': printf("no"); break;
    case 't': printf("toy"); break;
    case 'o': printf("outside"); break;
    case 'i': printf("inside"); break;
    case 'r': printf("rat"); break;
    default: printf("unknown");
  }

  return 0;
}