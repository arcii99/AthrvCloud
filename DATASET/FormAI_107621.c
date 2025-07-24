//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
/*C Spell Checking Program in a Donald Knuth Style*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a word is spelled correctly
int spell_check(char *word) {
  char dict[500][30] = {"gravity", "mathematics", "algorithm", "binary", "syntax", "compiler", "function", "array", "variable", "pointer", "struct", "stack", "queue", "linkedlist", "recursion", "iteration", "operator", "operand", "debugging", "testing"}; // dictionary of correct words
  int found = 0; // boolean flag to check if word is found in dictionary
  for(int i = 0; i < 20; i++) {
    if(strcmp(dict[i],word) == 0) {
      found = 1; // word found
      break;
    }
  }
  return found;
}

int main() {
  char text[2000]; // input text
  printf("Enter text: ");
  fgets(text, sizeof(text), stdin); // read input
  char *token = strtok(text, " \n"); // tokenize text by whitespace and newline
  while(token != NULL) {
    char *temp = token;
    int alpha = 1; // boolean flag to check if token is alphanumeric
    while(*temp) {
      if(!isalnum(*temp)) {
        alpha = 0; // token contains non-alphanumeric character
        break;
      }
      temp++;
    }
    if(!alpha) { // token contains non-alphanumeric character
      printf("%s", token); // print without spell check
    } else if(spell_check(token)) { // token spelled correctly
      printf("%s ", token); // print with space
    } else { // token spelled incorrectly
      printf("<%s> ", token); // print with angle brackets
    }
    token = strtok(NULL, " \n"); // get next token
  }
  printf("\n"); // print newline
  return 0;
}