//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
  char cat_language[100];
  int i, len;

  printf("Enter a sentence in C Cat Language: ");
  gets(cat_language);

  len = strlen(cat_language);

  for(i=0; i<len; i++) {
    switch(cat_language[i]) {
      case 'm':
        printf("Meow ");
        break;
      case 'p':
        printf("Purr ");
        break;
      case 'h':
        printf("Hiss ");
        break;
      case 'c':
        printf("Chirp ");
        break;
      case 'y':
        printf("Yowl ");
        break;
      case 'r':
        printf("Rumble ");
        break;
      default:
        printf("%c", cat_language[i]);
    }
  }

  return 0;
}