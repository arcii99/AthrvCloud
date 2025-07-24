//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
  FILE *input_file, *output_file;

  // Check if the user passed in the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s input_file output_file\n", argv[0]);
    exit(1);
  }

  // Open the input file
  input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error opening input file %s\n", argv[1]);
    exit(1);
  }

  // Read in the data from the file
  char lines[MAX_LINES][MAX_LENGTH];
  int num_lines = 0;
  while (fgets(lines[num_lines], MAX_LENGTH, input_file) != NULL) {
    num_lines++;
  }

  // Close the input file
  fclose(input_file);

  // Bubble sort the data
  for (int i = 0; i < num_lines - 1; i++) {
    for (int j = 0; j < num_lines - i - 1; j++) {
      if (strcmp(lines[j], lines[j + 1]) > 0) {
        // Swap the lines
        char temp[MAX_LENGTH];
        strcpy(temp, lines[j]);
        strcpy(lines[j], lines[j + 1]);
        strcpy(lines[j + 1], temp);
      }
    }
  }

  // Open the output file
  output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    printf("Error opening output file %s\n", argv[2]);
    exit(1);
  }

  // Write the sorted data back out to the file
  for (int i = 0; i < num_lines; i++) {
    fputs(lines[i], output_file);
  }

  // Close the output file
  fclose(output_file);

  return 0;
}