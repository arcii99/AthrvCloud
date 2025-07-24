//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define ALIEN_ALPHABET_SIZE 27 // Alien language has 26 letters + space

char getTranslatedCharacter(char alienChar);

int main() {
  char alienMessage[1000], translatedMessage[1000];
  int i;

  printf("Welcome to the Alien Language Translator program.\n");
  printf("Enter the message you want to translate: ");
  fgets(alienMessage, sizeof(alienMessage), stdin);

  printf("\nTranslating your message...\n");

  for(i=0; i < strlen(alienMessage); i++){
    translatedMessage[i] = getTranslatedCharacter(alienMessage[i]);
  }

  //Add paranoia style
  printf("\nHere is your translated message: \n");
  printf("========================================\n");
  printf("Starting self-destruct sequence...\n");
  printf("This message will self-destruct in T minus 10 seconds.\n");
  printf("========================================\n");

  //Wait 10 seconds
  for(i=10; i > 0; i--) {
    printf("%s%d%s\n", "T minus ", i, " seconds");
    sleep(1);
  }

  printf("%s", translatedMessage);

  return 0;
}

char getTranslatedCharacter(char alienChar) {
  char alienAlphabet[ALIEN_ALPHABET_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
  char translation[ALIEN_ALPHABET_SIZE] = {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a',' '};
  int i;

  for(i=0; i < ALIEN_ALPHABET_SIZE; i++) {
    if(alienChar == alienAlphabet[i]) {
      return translation[i];
    }
  }

  return alienChar; // Return the same character if not found
}