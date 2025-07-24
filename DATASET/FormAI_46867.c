//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[100];

  printf("Enter a phrase in C Cat Language: ");
  fgets(phrase, 100, stdin);

  // Replace "meow" with "printf("
  char* ptr = strstr(phrase, "meow");
  while(ptr) {
    strncpy(ptr, "printf(", 7);
    ptr = strstr(ptr + 7, "meow");
  }

  // Replace "purr" with ");"
  ptr = strstr(phrase, "purr");
  while(ptr) {
    strncpy(ptr, ");", 2);
    ptr = strstr(ptr + 2, "purr");
  }

  // Replace "hiss" with "//"
  ptr = strstr(phrase, "hiss");
  while(ptr) {
    strncpy(ptr, "//", 2);
    ptr = strstr(ptr + 2, "hiss");
  }

  printf("\nEquivalent C code:\n%s", phrase);

  return 0;
}