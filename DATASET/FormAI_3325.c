//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to CSV Reader!\n");
  printf("Please enter the name of the file you wish to read: ");
  
  char filename[100];
  scanf("%s", filename);
  
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Oops, cannot open file '%s'.\n", filename);
    printf("Please enter a valid filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
      printf("Sorry, we still cannot open the file '%s'.\n", filename);
      printf("Please double check the filename and try again.\n");
      exit(1);
    }
  }
  
  printf("File '%s' has been opened successfully!\n", filename);
  printf("Parsing the CSV data now...\n");
  
  char line[1024];
  int line_count = 0;
  while (fgets(line, 1024, file)) {
    char *token;
    int token_count = 0;
    while ((token = strsep(&line, ","))) {
      printf("Token %d: %s\n", token_count++, token);
    }
    line_count++;
  }
  
  printf("A total of %d lines have been parsed successfully!\n", line_count);
  printf("Thank you for using CSV Reader!\n");
  
  fclose(file);
  return 0;
}