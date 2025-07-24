//FormAI DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  /* Check command line arguments */
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  /* Open file for reading */
  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: Unable to open file!\n");
    return 1;
  }

  /* Define variables */
  char line[256];
  int line_number = 0;
  int error_count = 0;
  
  /* Read each line of the file */
  while (fgets(line, sizeof(line), file)) {
    line_number++;
    
    /* Check for C Syntax errors */
    if (strstr(line, "+++") != NULL) {
      printf("Syntax error on line %d: +++ not allowed\n", line_number);
      error_count++;
    }
    
    if (strstr(line, "---") != NULL) {
      printf("Syntax error on line %d: --- not allowed\n", line_number);
      error_count++;
    }
    
    if (strstr(line, "*/*") != NULL) {
      printf("Syntax error on line %d: /* not allowed\n", line_number);
      error_count++;
    }
    
    /* Check for empty lines */
    if (strlen(line) <= 1) {
      printf("Warning: empty line on line %d\n", line_number);
    }
  }
  
  /* Close file */
  fclose(file);
  
  /* Print summary */
  if (error_count > 0) {
    printf("There were %d syntax errors.\n", error_count);
  } else {
    printf("No syntax errors found!\n");
  }

  return 0;
}