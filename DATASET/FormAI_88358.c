//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>

// function to translate C Cat language to English
void cCatTranslator(char *cCat) {
  if (strcmp(cCat, "meow") == 0) {
    printf("Hello");
  } else if (strcmp(cCat, "purr") == 0) {
    printf("Yes");
  } else if (strcmp(cCat, "hiss") == 0) {
    printf("No");
  } else if (strcmp(cCat, "scratch") == 0) {
    printf("Goodbye");
  } else {
    printf("Translation not found");
  }
}

int main() {
  char cCat[] = "meow";
  cCatTranslator(cCat);

  return 0;
}