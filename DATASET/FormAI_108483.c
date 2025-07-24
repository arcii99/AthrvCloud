//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
// This program extracts metadata from C program files
// Written in the style of Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Check if file argument is provided
  if(argc < 2) {
    printf("Please provide a filename as argument\n");
    return 1;
  }

  // Open file in read mode
  FILE *fp = fopen(argv[1], "r");

  // Check if file exists and can be opened
  if(fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Initialize variables for metadata
  int lines = 0;
  int words = 0;
  int chars = 0;
  int functions = 0;

  char buffer[1000];

  // Loop through file line by line
  while(fgets(buffer, sizeof(buffer), fp)) {
    lines++;
    chars += strlen(buffer);

    // Split line into words
    char *word = strtok(buffer, " \t\n\r");

    while(word != NULL) {
      words++;
      word = strtok(NULL, " \t\n\r");
    }

    // Check if line contains function declaration
    if(strstr(buffer, "(") != NULL && strstr(buffer, ")") != NULL && strstr(buffer, "{") != NULL) {
      functions++;
    }
  }

  // Print metadata
  printf("Lines: %d\n", lines);
  printf("Words: %d\n", words);
  printf("Characters: %d\n", chars);
  printf("Functions: %d\n", functions);

  // Close file
  fclose(fp);

  return 0;
}