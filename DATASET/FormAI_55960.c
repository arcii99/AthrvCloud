//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void checkSpell(char* word);
int searchForWord(char* word);

char dictionary[][15] = {"hello", "world", "program", "computer", "science", "engineering"};

int main() {
  char input[50];
  printf("Enter a sentence: ");
  fgets(input, 50, stdin);
  printf("Checking spelling...\n");

  // Tokenize input string
  char* token = strtok(input, " ");
  while(token != NULL) {
    // Remove newline character if present
    if(token[strlen(token) - 1] == '\n') {
      token[strlen(token) - 1] = '\0';
    }
    checkSpell(token);
    token = strtok(NULL, " ");
  }

  return 0;
}

void checkSpell(char* word) {
  // Convert to lowercase for case-insensitive comparison
  for(int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }
  
  // Search for word in dictionary
  int result = searchForWord(word);
  if(result == -1) {
    printf("Did you mean: ");
    // Generate suggestions
    for(int i = 0; i < strlen(word); i++) {
      char temp = word[i];
      for(char c = 'a'; c <= 'z'; c++) {
        // Replace character with different letter of the alphabet
        if(c != temp) {
          word[i] = c;
          result = searchForWord(word);
          if(result != -1) {
            printf("%s ", dictionary[result]);
          }
        }
      }
      word[i] = temp;
    }
    printf("\n");
  }
}

int searchForWord(char* word) {
  int index = -1;
  for(int i = 0; i < 6; i++) {
    if(strcmp(dictionary[i], word) == 0) {
      index = i;
      break;
    }
  }
  return index;
}