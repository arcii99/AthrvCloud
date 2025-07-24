//FormAI DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a character is a letter or not
int isLetter(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  else
    return 0; 
}

//function to check if a string is a keyword or not
int isKeyword(char *token) {
  char keywords[][10] = {"if", "else", "while", "do", "for", "int", "float", "char", "double", "return", "void"};
  int i, keywordCount = 11;

  for (i = 0; i < keywordCount; i++) {
    if (strcmp(token, keywords[i]) == 0)
      return 1;
  }
  return 0;
}

//function to parse and count the number of tokens in the input string
int parseString(char *str) {
  int len = strlen(str);
  int tokenCount = 0;
  int i = 0;

  while (i < len) {
    char token[50] = "";

    //check if current character is a letter
    if (isLetter(str[i])) {
      int j = i;
      while (j < len && (isLetter(str[j]) || str[j] == '_')) {
    strncat(token, &str[j], 1);
    j++;
      }
      i = j;
      if (isKeyword(token))
    printf("%s is a keyword\n", token);
      else
    printf("%s is an identifier\n", token);
      tokenCount++;
    }

    //check if current character is a digit
    else if (isdigit(str[i])) {
      int j = i;
      while (j < len && isdigit(str[j])) {
    strncat(token, &str[j], 1);
    j++;
      }
      i = j;
      printf("%s is a constant\n", token);
      tokenCount++;
    }

    //check if current character is a symbol
    else {
      strncat(token, &str[i], 1);
      if (strcmp(token, "(") == 0)
    printf("%s is an open parenthesis\n", token);
      else if (strcmp(token, ")") == 0)
    printf("%s is a close parenthesis\n", token);
      else if (strcmp(token, "{") == 0)
    printf("%s is an open curly brace\n", token);
      else if (strcmp(token, "}") == 0)
    printf("%s is a close curly brace\n", token);
      else if (strcmp(token, ";") == 0)
    printf("%s is a semicolon\n", token);
      i++;
      tokenCount++;
    }
  }
  return tokenCount;
}

int main() {
  char str[1000];
  printf("Enter a string:\n");
  fgets(str, 1000, stdin);
  int tokenCount = parseString(str);
  printf("Total number of tokens: %d\n", tokenCount);

  return 0;
}