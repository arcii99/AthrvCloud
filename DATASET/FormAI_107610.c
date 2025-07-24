//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[1000];
  printf("Enter a phrase in C Cat Language to translate: ");
  fgets(phrase, sizeof(phrase), stdin);
  strtok(phrase, "\n");

  if (strcmp(phrase, "meow") == 0) {
    printf("Hello\n");
  } else if (strcmp(phrase, "purr") == 0) {
    printf("Thank you\n");
  } else if (strcmp(phrase, "hiss") == 0) {
    printf("Goodbye\n");
  } else if (strcmp(phrase, "scratch") == 0) {
    printf("Sorry, I cannot do that\n");
  } else {
    printf("Translation could not be found\n");
  }

  return 0;
}