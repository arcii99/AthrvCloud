//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Hey there! Please provide a CSV file name as an argument.\n");
    return 1;
  }

  printf("Great! You've provided a CSV file name: %s.\n", argv[1]);
  
  FILE *file_pointer;
  char *line = NULL;
  size_t line_length = 0;
  ssize_t read_length;
  char *token;
  char *columns[MAX_COLUMNS];

  printf("Now, let's read the file.\n");

  file_pointer = fopen(argv[1], "r");

  if (file_pointer == NULL) {
    printf("Oops! It looks like there's an error opening the file.\n");
    return 1;
  }

  printf("CSV file has been opened successfully! Let's take a look at its contents.\n");

  int row = 0;

  while ((read_length = getline(&line, &line_length, file_pointer)) != -1) {
    printf("Reading row %d: %s", row, line);

    int column = 0;
    token = strtok(line, ",");

    while (token != NULL) {
      columns[column] = token;
      printf("Column %d: %s\n", column, columns[column]);
      token = strtok(NULL, ",");
      column++;
    }

    row++;
  }

  printf("All rows have been read successfully!");

  fclose(file_pointer);

  if (line) {
    free(line);
  }

  return 0;
}