//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char alien_sentence[1000], human_sentence[1000];
  int i, j;
  
  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please enter an alien sentence for translation:\n");
  scanf("%[^\n]", alien_sentence); // read the entire input line, including spaces
  getchar(); // clear the input buffer
  
  printf("Translating...\n");
  
  // replace each letter according to the rules of the alien language
  for (i = 0; i < strlen(alien_sentence); i++) {
    switch (alien_sentence[i]) {
      case 'a':
        human_sentence[i] = 'z';
        break;
      case 'b':
        human_sentence[i] = 'y';
        break;
      case 'c':
        human_sentence[i] = 'x';
        break;
      case 'd':
        human_sentence[i] = 'w';
        break;
      case 'e':
        human_sentence[i] = 'v';
        break;
      case 'f':
        human_sentence[i] = 'u';
        break;
      case 'g':
        human_sentence[i] = 't';
        break;
      case 'h':
        human_sentence[i] = 's';
        break;
      case 'i':
        human_sentence[i] = 'r';
        break;
      case 'j':
        human_sentence[i] = 'q';
        break;
      case 'k':
        human_sentence[i] = 'p';
        break;
      case 'l':
        human_sentence[i] = 'o';
        break;
      case 'm':
        human_sentence[i] = 'n';
        break;
      case 'n':
        human_sentence[i] = 'm';
        break;
      case 'o':
        human_sentence[i] = 'l';
        break;
      case 'p':
        human_sentence[i] = 'k';
        break;
      case 'q':
        human_sentence[i] = 'j';
        break;
      case 'r':
        human_sentence[i] = 'i';
        break;
      case 's':
        human_sentence[i] = 'h';
        break;
      case 't':
        human_sentence[i] = 'g';
        break;
      case 'u':
        human_sentence[i] = 'f';
        break;
      case 'v':
        human_sentence[i] = 'e';
        break;
      case 'w':
        human_sentence[i] = 'd';
        break;
      case 'x':
        human_sentence[i] = 'c';
        break;
      case 'y':
        human_sentence[i] = 'b';
        break;
      case 'z':
        human_sentence[i] = 'a';
        break;
      default:
        human_sentence[i] = alien_sentence[i];
        break;
    }
  }
  
  human_sentence[i] = '\0'; // add a null terminator to the end of the string
  
  printf("The alien sentence \"%s\" translates to \"%s\" in human language.\n", alien_sentence, human_sentence);
  
  return 0;
}