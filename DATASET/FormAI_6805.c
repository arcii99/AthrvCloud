//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {

  char input[1000];
  printf("Welcome to the Word Count Tool!\n");
  printf("Please enter a sentence or phrase to count the words: ");
  fgets(input, 1000, stdin); // get user input

  int wordCount = 0;
  int len = strlen(input);

  if (len > 0 && input[len-1] == '\n') { // remove the new line character
    input[len-1] = '\0';
    len--;
  }

  for (int i = 0; i < len; i++) { // loop through each character in the input
    if (input[i] == ' ') { // if the character is a space, it's the end of a word
      wordCount++;
    }
  }

  if (len > 0) {
    wordCount++; // add one more for the final word
  }

  printf("The number of words in your sentence or phrase is: %d\n", wordCount);

  return 0;
}