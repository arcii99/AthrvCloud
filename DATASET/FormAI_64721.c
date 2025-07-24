//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename.csv\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *filename = argv[1];

  // Open file
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("File not found: %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Read header line
  char header_line[MAX_SIZE];
  fgets(header_line, MAX_SIZE, file);

  // Split header line into fields
  char *field;
  char *fields[100];
  int num_fields = 0;

  field = strtok(header_line, ",");
  while (field) {
    // Remove any newline characters from the field
    int len = strlen(field);
    if (len > 0 && field[len-1] == '\n') {
      field[len-1] = '\0';
    }

    fields[num_fields] = field;
    num_fields++;
    field = strtok(NULL, ",");
  }

  // Read data lines
  char line[MAX_SIZE];

  while (fgets(line, MAX_SIZE, file)) {
    // Split line into fields
    char *field;
    char *values[100];
    int num_values = 0;

    field = strtok(line, ",");
    while (field) {
      // Remove any newline characters from the field
      int len = strlen(field);
      if (len > 0 && field[len-1] == '\n') {
        field[len-1] = '\0';
      }

      values[num_values] = field;
      num_values++;
      field = strtok(NULL, ",");
    }

    // Print row
    for (int i = 0; i < num_fields; i++) {
      printf("%s: %s\n", fields[i], values[i]);
    }
    printf("\n");
  }

  // Close file
  fclose(file);

  return 0;
}