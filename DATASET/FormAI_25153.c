//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  FILE *f;
  char *filename = argv[1];

  /* Open file */
  f = fopen(filename, "r");
  if (f == NULL) {
    printf("Could not open file: %s", filename);
    return 1;
  }

  /* Read file line by line */
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, f)) {
    /* Look for metadata tags */
    if (strncmp(line, "Title:", 6) == 0) {
      printf("Title: %s", line + 6);
    } else if (strncmp(line, "Author:", 7) == 0) {
      printf("Author: %s", line + 7);
    } else if (strncmp(line, "Date:", 5) == 0) {
      printf("Date: %s", line + 5);
    }
  }

  /* Close file */
  fclose(f);

  return 0;
}