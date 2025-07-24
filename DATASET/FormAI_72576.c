//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program translates the Alien language,
  which is made up of combinations of the letters 'a', 'b', and 'c'. 
  
  The translations are as follows:
  
  'a' -> 'x'
  'b' -> 'y'
  'c' -> 'z'
  
  This program takes in a string of Alien text from the user,
  and translates it to English.
*/

int main() {
  char alienText[100];
  char englishText[100];
  
  printf("Welcome to the Alien Language Translator!\n\n");
  printf("Please enter the Alien text to be translated: ");
  scanf("%s", alienText);
  
  int alienLength = strlen(alienText);
  for(int i = 0; i < alienLength; i++) {
    switch(alienText[i]) {
      case 'a':
        strcat(englishText, "x");
        break;
      case 'b':
        strcat(englishText, "y");
        break;
      case 'c':
        strcat(englishText, "z");
        break;
      default:
        strcat(englishText, "?");
        break;
    }
  }
  
  printf("The translated text is: %s\n", englishText);
  printf("Thank you for using Alien Language Translator!");
  
  return 0;
}