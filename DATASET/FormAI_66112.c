//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Keyword and Identifier List
char *keywords[] = {"int", "float", "double", "char", "if", "else", "for", "while"};
int num_keywords = 8;
char identifiers[1000][128];
int num_identifiers = 0;

// Function to check if a string is a keyword
int is_keyword(char *str) {
  int i;
  for (i = 0; i < num_keywords; i++) {
    if (strcmp(str, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a string is an identifier
int is_identifier(char *str) {
  int i;
  for (i = 0; i < num_identifiers; i++) {
    if (strcmp(str, identifiers[i]) == 0) {
      return 1;
    }
  }
  strcpy(identifiers[num_identifiers], str);
  num_identifiers++;
  return 0;
}

// Main function to parse the input C code
int main() {
  char input[1000];
  printf("Enter the C code (End with a blank line):\n");
  fgets(input, 1000, stdin);
  while (strlen(input) != 1) {
    char *current_word = strtok(input, " \n\t{};,()");

    while (current_word != NULL) {
      if (is_keyword(current_word)) {
        printf("%s is a keyword.\n", current_word);
      } else if (is_identifier(current_word)) {
        printf("%s is an identifier.\n", current_word);
      }
      current_word = strtok(NULL, " \n\t{};,()");
    }
    fgets(input, 1000, stdin);
  }
  printf("Keywords found: %d\n", num_keywords);
  printf("Identifiers found: %d\n", num_identifiers);
  return 0;
}