//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char alienLanguage[27] = "ZEBXIWRLNQYTMSFPAHVJGUDKOC";
  char inputMessage[100];
  printf("Welcome to the Alien Language Translator\n");
  printf("Enter a message in the alien language: ");
  fgets(inputMessage, 100, stdin);
  inputMessage[strcspn(inputMessage, "\n")] = 0; // remove newline character

  int messageLength = strlen(inputMessage);
  char translatedMessage[messageLength + 1];

  for(int i = 0; i < messageLength; i++) {
    char currentChar = inputMessage[i];
    if(currentChar == ' ') {
      translatedMessage[i] = ' ';
    } else {
      int index = currentChar - 'A';
      translatedMessage[i] = alienLanguage[index];
    }
  }

  translatedMessage[messageLength] = '\0';
  printf("Translated message: %s\n", translatedMessage);
  return 0;
}