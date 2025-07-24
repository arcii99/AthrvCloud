//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024 // Maximum length of a line in the CSV file
#define MAX_FIELD_LEN 256 // Maximum length of a single field in the CSV file
#define MAX_FIELDS 128    // Maximum number of fields per line

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <csv_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("Error: failed to open file '%s' for reading\n", filename);
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE_LEN];
  char *fields[MAX_FIELDS];
  int field_count = 0;

  while (fgets(line, MAX_LINE_LEN, fp)) {
    // Remove newline character from end of line
    line[strcspn(line, "\n")] = '\0';

    // Split line into fields
    char *token = strtok(line, ",");
    while (token) {
      // Ensure field is not too long
      if (strlen(token) > MAX_FIELD_LEN) {
        printf("Error: field '%s' is too long\n", token);
        exit(EXIT_FAILURE);
      }

      // Add field to list
      fields[field_count++] = strdup(token);

      // Ensure we don't exceed maximum number of fields
      if (field_count == MAX_FIELDS) {
        printf("Error: too many fields in line '%s'\n", line);
        exit(EXIT_FAILURE);
      }

      // Get next token
      token = strtok(NULL, ",");
    }

    // Print out the line's values
    printf("Fields for line '%s':\n", line);
    for (int i = 0; i < field_count; i++) {
      printf("\t%s\n", fields[i]);
    }

    // Free memory used by field values
    for (int i = 0; i < field_count; i++) {
      free(fields[i]);
      fields[i] = NULL;
    }

    // Reset field count for next line
    field_count = 0;
  }

  fclose(fp);
  return 0;
}