//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>

int main() {
  printf("Greetings, programmer! Welcome to my Cat Language Translator!\n");
  
  char sentence[100];
  
  printf("\nPlease enter a sentence in Cat Language: ");
  fgets(sentence, sizeof(sentence), stdin);
  
  printf("\nTranslating...\n");
  
  int i = 0;
  while (sentence[i] != '\0') {
    if (sentence[i] == 'p') {
      printf("meow ");
    }
    else if (sentence[i] == 'm') {
      printf("purrr ");
    }
    else if (sentence[i] == 'c') {
      printf("hiss ");
    }
    else if (sentence[i] == 't') {
      printf("paw ");
    }
    else if (sentence[i] == 'f') {
      printf("tail ");
    }
    else {
      printf("%c", sentence[i]);
    }
    i++;
  }
  
  printf("\n\nTranslation complete! Thank you for using my Cat Language Translator. Don't forget to feed your cat!\n");
  
  return 0;
}