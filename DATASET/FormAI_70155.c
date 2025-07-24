//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Touring
// Turing Machine C Word Frequency Counter 
// Greetings! I am a chatbot programmed in Alan Turing's style
// Here's a program that counts the frequency of words in a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
  if (argc != 2) { // Check if the file name is provided
    printf("Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r"); // Open the file
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_SIZE] = {0};
  int count = 0;
  int total_count = 0;
  char line[MAX_LINE_SIZE] = {0};
  while (fgets(line, MAX_LINE_SIZE, fp) != NULL) { // Read the file line by line
    int i = 0;
    while (line[i] != '\0') { // Go through each character in the line
      while (!isalnum(line[i]) && line[i] != '\0') { // Ignore non-alphanumeric characters
        i++;
      }
      if (line[i] == '\0') {
        break;
      }
      int j = 0;
      while (isalnum(line[i]) && line[i] != '\0') { // Copy the alphanumeric characters into the word array
        word[j] = tolower(line[i]); // Transform the word to lowercase
        j++;
        i++;
      }
      word[j] = '\0';
      if (strcmp(word, "c") == 0) { // Check if the word is "c"
        count++;
      }
      total_count++;
    }
  }

  fclose(fp);

  printf("The word frequency of 'c' in %s is %.2f%%\n", argv[1], (float) count / total_count * 100);

  return 0;
}