//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inputText[1000];
  int numChars = 0, numWords = 0, numLines = 0, i;

  printf("Welcome to the Text Processing Program!\n\n");
  printf("Please enter some text: ");

  // Read in text until user hits ENTER
  scanf("%[^\n]", inputText);

  // Count the number of characters, words, and lines in the input text
  for (i = 0; i < strlen(inputText); i++) {
    if (inputText[i] != ' ') {  // Not a space; must be a character
      numChars++;
    }
    if (inputText[i] == ' ' || inputText[i] == '\t' || inputText[i] == '\n') {  // Space, tab, or newline; must be a word separator
      numWords++;
    }
    if (inputText[i] == '\n') {  // Newline; must be a line separator
      numLines++;
    }
  }

  // If last character was not a word separator, increment word count
  if (inputText[strlen(inputText) - 1] != ' ' && inputText[strlen(inputText) - 1] != '\t' && inputText[strlen(inputText) - 1] != '\n') {
    numWords++;
  }

  // If last character was not a line separator, increment line count
  if (inputText[strlen(inputText) - 1] != '\n') {
    numLines++;
  }

  // Output the results
  printf("\n\n");
  printf("------------------------------------------------------------------\n");
  printf("Here are the results of your text processing:\n");
  printf("Number of characters: %d\n", numChars);
  printf("Number of words: %d\n", numWords);
  printf("Number of lines: %d\n", numLines);
  printf("------------------------------------------------------------------\n");

  return 0;
}