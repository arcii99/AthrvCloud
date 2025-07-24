//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

  // Opening the text file containing the story
  FILE *file = fopen("sherlock_tale.txt", "r");

  // Catching the error in case the file doesn't open
  if (file == NULL) {
    printf("Error: Cannot open file\n");
    return 1;
  }

  // Initializing the variables
  char word[50];
  int i = 0;
  int flag = 0;
  int count = 0;

  // Reading the text file character by character
  while (!feof(file)) {
    char c = fgetc(file);

    // If c is alphabet and flag is 0 set word start index to i, and flag to 1
    if (isalpha(c) && flag == 0) {
      word[i] = c;
      i++;
      flag = 1;
    }
    // If c is alphabet and flag is 1 add to the word
    else if (isalpha(c) && flag == 1) {
      word[i] = c;
      i++;
    }
    // If c is not alphabet, flag is 1 and there was a word before
    else if (!isalpha(c) && flag == 1) {
      // Add null character to the end of the word and print it
      word[i] = '\0';
      printf("%s ", word);
      count++;
      // Reset the variables
      i = 0;
      flag = 0;
    }
    // If c is not alphabet and flag is 0, ignore it
    else if (!isalpha(c) && flag == 0) {
      continue;
    }
  }

  // Closing the file
  fclose(file);

  // Printing the number of words in the story
  printf("\n\nThere are a total of %d words in the story.", count);

  return 0;
}