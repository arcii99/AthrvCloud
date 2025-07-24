//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
/*
Cyberpunk Word Count Tool
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 256

// function to count words
int countWords(char* line) {
  int words = 0;
  char word[MAX_WORD_LENGTH];
  
  // loop through each character in the line
  for (int i = 0; i < strlen(line); i++) {
    // if the character is a valid character for a word, add it to the current word
    if (isalpha(line[i]) || isdigit(line[i]) || line[i] == '-') {
      word[strlen(word)] = tolower(line[i]);
    }
    // if the character is not a valid character for a word, it must be the end of a word
    else {
      // if the current word is not empty, increase the word count
      if (strlen(word) > 0) {
        words++;
        memset(word, 0, MAX_WORD_LENGTH * sizeof(char)); // clear the word
      }
    }
  }
  
  // add the final word if it is not empty
  if (strlen(word) > 0) {
    words++;
  }
  
  return words;
}

int main(int argc, char** argv) {
  FILE* file = NULL;
  char line[MAX_LINE_LENGTH];
  int totalWords = 0;
  
  // check for correct arguments
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }
  
  // open the file for reading
  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error: Could not open file '%s'\n", argv[1]);
    return -1;
  }
  
  // read each line from the file and count its words
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    totalWords += countWords(line);
  }
  
  printf("Total words in file '%s': %d\n", argv[1], totalWords);
  
  // close the file
  fclose(file);
  
  return 0;
}