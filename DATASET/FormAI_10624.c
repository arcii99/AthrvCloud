//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

int main(){

  int length;
  char alien_word[100];
  printf("Enter an Alien word to translate into English: ");
  fgets(alien_word, 100, stdin); // takes user input from keyboard

  length = strlen(alien_word);
  alien_word[length - 1] = '\0'; // removes \n added by fgets

  if(strcmp(alien_word, "qavla") == 0){ // sample alien word
    printf("The English meaning of %s is Hello!\n", alien_word);
  }
  else if(strcmp(alien_word, "fzurple") == 0){
    printf("The English meaning of %s is Goodbye!\n", alien_word);
  }
  else if(strcmp(alien_word, "tunka") == 0){
    printf("The English meaning of %s is Please.\n", alien_word);
  }
  else if(strcmp(alien_word, "ranska") == 0){
    printf("The English meaning of %s is Thank you.\n", alien_word);
  }
  else{
    printf("I'm sorry, I don't recognize the word %s.\n", alien_word);
  }

  return 0;
}