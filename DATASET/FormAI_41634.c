//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include <stdio.h>

// Define the language identifiers
#define C_LANG 1
#define CAT_LANG 2

int main() {

  int language;
  printf("Which language do you want to translate to?\n");
  printf("1. C Language\n2. Cat Language\n");
  scanf("%d", &language);
  
  // If user selects C Language
  if(language == C_LANG) {
    printf("Type your sentence to translate to C language:\n");
    char sentence[100];
    scanf(" %[^\n]", sentence);

    printf("Translated Sentence in C Language:\n");
    printf("%s", sentence);
    printf(";\n");
  }
  // If user selects Cat Language
  else if(language == CAT_LANG) {
    printf("Meow! Meow! Please enter your sentence.\n");
    char sentence[100];
    scanf(" %[^\n]", sentence);
    
    // Replace spaces with meows and add some excitement at beginning and end of sentence
    int i = 0;
    while(sentence[i] != '\0') {
      if(sentence[i] == ' ') {
        printf("meow ");
      }
      else {
        printf("%c", sentence[i]);
      }
      i++;
    }
    printf("! Meow!");
  }
  // If user enters invalid input
  else {
    printf("Sorry, I didn't understand your input. Please try again.\n");
  }

  return 0;
}