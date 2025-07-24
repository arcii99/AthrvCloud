//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

//Declare a function to translate the Alien Language
void translateAlienLanguage(char alienLanguage[]);

int main() {
  char alienLanguage[100];

  printf("Welcome to the Alien Language Translator\n");
  printf("Please enter the phrase you wish to translate: \n");

  //Input the Alien Language phrase
  fgets(alienLanguage, 100, stdin);

  //Call the function to translate the Alien Language
  translateAlienLanguage(alienLanguage);

  return 0;
}

//Function to translate the Alien Language
void translateAlienLanguage(char alienLanguage[]) {
  int index, length;
  char translated[100];

  //Get the length of Alien Language phrase
  length = strlen(alienLanguage);

  //Loop through each character of the Alien Language and translate it
  for(index = 0; index < length; index++) {
    switch(alienLanguage[index]) {
      case 'A':
        translated[index] = 'Z';
        break;
      case 'B':
        translated[index] = 'Y';
        break;
      case 'C':
        translated[index] = 'X';
        break;
      case 'D':
        translated[index] = 'W';
        break;
      case 'E':
        translated[index] = 'V';
        break;
      case 'F':
        translated[index] = 'U';
        break;
      case 'G':
        translated[index] = 'T';
        break;
      case 'H':
        translated[index] = 'S';
        break;
      case 'I':
        translated[index] = 'R';
        break;
      case 'J':
        translated[index] = 'Q';
        break;
      case 'K':
        translated[index] = 'P';
        break;
      case 'L':
        translated[index] = 'O';
        break;
      case 'M':
        translated[index] = 'N';
        break;
      case 'N':
        translated[index] = 'M';
        break;
      case 'O':
        translated[index] = 'L';
        break;
      case 'P':
        translated[index] = 'K';
        break;
      case 'Q':
        translated[index] = 'J';
        break;
      case 'R':
        translated[index] = 'I';
        break;
      case 'S':
        translated[index] = 'H';
        break;
      case 'T':
        translated[index] = 'G';
        break;
      case 'U':
        translated[index] = 'F';
        break;
      case 'V':
        translated[index] = 'E';
        break;
      case 'W':
        translated[index] = 'D';
        break;
      case 'X':
        translated[index] = 'C';
        break;
      case 'Y':
        translated[index] = 'B';
        break;
      case 'Z':
        translated[index] = 'A';
        break;
      //If any other character is found in the Alien Language, simply add it to the translated phrase
      default:
        translated[index] = alienLanguage[index];
        break;
    }
  }

  //Print the translated phrase
  printf("Translated phrase: %s\n", translated);
}