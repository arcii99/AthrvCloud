//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void cleanUp(char *word); 
int isMisspelled(char *word);

// Main function
int main() {
  char input[50];
  char *word;

  printf("Enter a word to check for spelling errors: ");
  fgets(input, 50, stdin);

  // Removing newline character from input
  input[strcspn(input, "\n")] = 0;

  // Tokenizing the input string
  word = strtok(input, " ");

  while (word != NULL) {
    // Cleaning up the word 
    cleanUp(word);

    // Checking if the word is misspelled 
    if (isMisspelled(word)) {
      printf("%s is misspelled.\n", word);
    } else {
      printf("%s is spelled correctly.\n", word);
    }

    // Getting the next word
    word = strtok(NULL, " ");
  }

  return 0;
}

// Function to remove non-alphabetic characters from word and convert to lowercase
void cleanUp(char *word) {
  int i, j = 0;
  char temp[50];

  for (i = 0; word[i] != '\0'; i++) {
    if (isalpha(word[i])) {
      temp[j] = tolower(word[i]);
      j++;
    }
  }

  temp[j] = '\0';

  strcpy(word, temp);
}

// Function to check if word is misspelled by comparing to dictionary
int isMisspelled(char *word) {
  FILE *fp;

  fp = fopen("dictionary.txt", "r");

  if (fp == NULL) {
    printf("Error opening dictionary file.\n");
    exit(1);
  }

  char currentWord[50];

  while (fgets(currentWord, sizeof(currentWord), fp)) {
    // Removing newline character from dictionary word
    currentWord[strcspn(currentWord, "\n")] = 0;

    // Comparing dictionary word to input word
    if (strcmp(currentWord, word) == 0) {
      fclose(fp);
      return 0;
    }
  }

  fclose(fp);
  
  return 1;
}