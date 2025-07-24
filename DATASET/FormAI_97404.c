//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LEN 100

int main() {
  char input[MAX_STRING_LEN+1], temp[MAX_STRING_LEN+1], c;
  int i, j, misspelled, count = 0;

  FILE *dictionary = fopen("dictionary.txt", "r");
  if (dictionary == NULL) {
    printf("Error: Dictionary file not found!\n");
    exit(1);
  }

  printf("Enter a string to check for spelling errors:\n");
  fgets(input, MAX_STRING_LEN, stdin);
  
  // Tokenize input string into words
  char *token = strtok(input, " \n");
  while (token != NULL) {
    // Remove leading and trailing punctuation
    i = 0; j = 0; misspelled = 1;
    while (token[i]) {
      c = token[i];
      if (isalpha(c)) {
        temp[j++] = tolower(c);
      }
      if (j == 0) {
        continue;
      }
      if (!isalpha(c) && !isdigit(c)) {
        temp[j] = '\0';
        break;
      }
      i++;
    }
    temp[j] = '\0';
    
    // Compare word to dictionary
    rewind(dictionary);
    while (fgets(temp, MAX_STRING_LEN, dictionary)) {
      temp[strcspn(temp, "\n")] = '\0';
      if (strcmp(temp, token) == 0) {
        misspelled = 0;
        break;
      }
    }

    if (misspelled) {
      printf("%s is misspelled!\n", token);
      count++;
    }

    token = strtok(NULL, " \n");
  }

  if (count == 0) {
    printf("No spelling errors.\n");
  }

  fclose(dictionary);
  return 0;
}