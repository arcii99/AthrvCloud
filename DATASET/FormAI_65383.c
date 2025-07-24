//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main()
{
  //Relaxed Program that modifies input string
  char inputString[100];
  printf("Please enter a line of text: ");
  fgets(inputString, 100, stdin);
  printf("Your input is: %s\n", inputString);

  //Removing the newline character
  inputString[strlen(inputString) - 1] = '\0';
  printf("After removing the newline character: %s\n", inputString);

  //Replacing all vowels with '-'
  for(int i = 0; i < strlen(inputString); i++) {
    if(inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u' || inputString[i] == 'A' || inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' || inputString[i] == 'U') {
       inputString[i] = '-';
    }
  }
  printf("After replacing all vowels with '-': %s\n", inputString);

  //Converting all characters to uppercase
  for(int i = 0; i < strlen(inputString); i++) {
    inputString[i] = toupper(inputString[i]);
  }
  printf("After converting all characters to uppercase: %s\n", inputString);

  //Converting all '-' characters to '+'
  for (int i = 0; i < strlen(inputString); i++) {
    if(inputString[i] == '-') {
       inputString[i] = '+';
    }
  }
  printf("After replacing all '-' characters with '+': %s\n", inputString);

  return 0;
}