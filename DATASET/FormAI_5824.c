//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

// function to translate C Cat language
void c_cat_translator(char sentence[]) {
  int i, len = strlen(sentence);
  
  // loop through sentence
  for (i = 0; i < len; i++) {
    switch(sentence[i]) {
      case 'm': printf("Meow"); break;
      case 'p': printf("Purr"); break;
      case 'h': printf("Hiss"); break;
      case 't': printf("Twitch tail"); break;
      case 'c': printf("Clean paws"); break;
      case 'y': printf("Yawn"); break;
      case 'n': printf("Nap"); break;
      case 'f': printf("Scratch furniture"); break;
      case 's': printf("Snuggle"); break;
      case 'e': printf("Eat"); break;
      default: printf("%c", sentence[i]);
    }
  }
}

int main() {
  char sentence[1000];
  
  // get input sentence from user
  printf("Enter a sentence in C Cat language: ");
  fgets(sentence, 1000, stdin);
  
  // translate the sentence
  c_cat_translator(sentence);
  
  return 0;
}