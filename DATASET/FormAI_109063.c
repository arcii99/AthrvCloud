//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
#include<stdio.h>

int main() {
  
  printf("Hello there fellow coders! Today, I'm going to show you something truly exciting - a C syntax parser program!\n");
  printf("With this program, we'll be able to analyze and parse any C code you throw at it, no matter how complicated or messy it may seem!\n");
  printf("But before we begin, let's make sure we have all the necessary tools in place.\n");
  
  // Initializing variables
  int i = 0, j = 0, k = 0;
  char code[1000];
  char parsedCode[1000];
  char currentChar;
  
  // Getting user input
  printf("Please enter the C code you want to parse:\n");
  fgets(code, 1000, stdin);
  
  // Removing comments and whitespace
  while (code[i] != '\0') {
    
    currentChar = code[i];
    
    // Removing // type comments
    if (currentChar == '/' && code[i+1] == '/') {
      while (code[i] != '\n') {
        i++;
      }
      parsedCode[j] = ' ';
      j++;
    }
    
    // Removing /* */ type comments
    else if (currentChar == '/' && code[i+1] == '*') {
      i += 2;
      while (code[i] != '*' && code[i+1] != '/') {
        i++;
      }
      i += 2;
      parsedCode[j] = ' ';
      j++;
    }
    
    // Removing whitespace
    else if (!(currentChar == ' ' || currentChar == '\t' || currentChar == '\n' || currentChar == '\r')) {
      parsedCode[j] = currentChar;
      j++;
    }
    
    i++;
  }
  
  // Printing the parsed code
  printf("Here's your code, all parsed and clean:\n");
  printf("%s", parsedCode);
  
  return 0;
}