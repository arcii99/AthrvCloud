//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: lively
// Welcome to the C Cat Language Translator Program!
// This program takes a cat's meows as input and translates them into human language.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  printf("Hello! I am a cat language translator. Please enter your cat's meows: ");
  scanf("%s", input);

  //loop through input string
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == 'm') {
      printf("Meow ");
    } else if(input[i] == 'p') {
      printf("Purr ");
    } else if(input[i] == 'h') {
      printf("Hiss ");
    } else if(input[i] == 'n') {
      printf("Nyan ");
    } else {
      printf("Unknown sound ");
    }
  }

  printf("\nTranslation complete. Thank you for using the C Cat Language Translator!");  
  return 0;
}