//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include<stdio.h>
#include<string.h>

//Function to convert the given alien language word to English
void translate(char *alien_word) {

  if(strcmp(alien_word, "galaxizyn") == 0) {
    printf("Hello\n");
  }
  else if(strcmp(alien_word, "zyntax") == 0) {
    printf("How are you?\n");
  }
  else if(strcmp(alien_word, "anqar") == 0) {
    printf("Goodbye\n");
  }
  else if(strcmp(alien_word, "xenon") == 0) {
    printf("Thank you\n");
  }
  else if(strcmp(alien_word, "qazt") == 0) {
    printf("Please\n");
  }
  else {
    printf("Sorry, I don't understand.\n");
  }

}

int main() {

  char alien_word[20];

  printf("Welcome to the Alien Language Translator!\n");
  printf("Please enter an alien language word or phrase:\n");

  //Read the input from the user and remove any newline characters
  fgets(alien_word, sizeof(alien_word), stdin);
  alien_word[strcspn(alien_word, "\n")] = 0;

  //Translate the alien language word or phrase
  translate(alien_word);

  return 0;
}