//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>

int main() {
  char cat[100];
  printf("Enter a sentence in Cat Language: ");
  fgets(cat, 100, stdin);
  
  printf("Translated into English: ");
  for(int i = 0; i < strlen(cat); i++) {
    if(cat[i] == 'm') {
      printf("meow");
    } else if(cat[i] == 'p') {
      printf("purr");
    } else if(cat[i] == 'y') {
      printf("yeow");
    } else {
      printf("%c", cat[i]);
    }
  }

  return 0;
}