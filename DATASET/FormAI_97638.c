//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Function to extract metadata from a file */
void extract_metadata(char *filename) {
  FILE *fp; /* file pointer to read from file */
  char *line = NULL; /* pointer to each line read from the file */
  size_t len = 0; /* length of each line */
  ssize_t read; /* return value of getline() */
  int line_count = 0; /* counter for lines in file */

  /* Open file for reading */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  /* Loop through each line in file */
  while ((read = getline(&line, &len, fp)) != -1) {
    line_count++; /* Increment line counter */

    /* Check if line has metadata */
    if (line[0] == '#' && 
        line[1] == ' ' && 
        (line[2] >= 'A' && line[2] <= 'Z') &&
        line[3] == ':') {
      printf("Metadata found on line %d: %s", line_count, line);
    }
  }

  /* Close file and free memory */
  fclose(fp);
  if (line) free(line);
}

/* Main function */
int main() {
  char *filename = "example.txt";
  extract_metadata(filename);
  return 0;
}