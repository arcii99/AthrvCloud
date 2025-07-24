//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>

int main() {
  char userInput;
  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please enter a digit in the C Alien Language: ");
  scanf("%c", &userInput);
  
  switch(userInput) {
    case '0':
      printf("The digit in English is 'Zero'\n");
      break;
    case '1':
      printf("The digit in English is 'One'\n");
      break;
    case '2':
      printf("The digit in English is 'Two'\n");
      break;
    case '3':
      printf("The digit in English is 'Three'\n");
      break;
    case '4':
      printf("The digit in English is 'Four'\n");
      break;
    case '5':
      printf("The digit in English is 'Five'\n");
      break;
    case '6':
      printf("The digit in English is 'Six'\n");
      break;
    case '7':
      printf("The digit in English is 'Seven'\n");
      break;
    case '8':
      printf("The digit in English is 'Eight'\n");
      break;
    case '9':
      printf("The digit in English is 'Nine'\n");
      break;
    default:
      printf("Sorry, '%c' is not a valid C Alien Language digit.\n", userInput);
  }
  
  return 0;
}