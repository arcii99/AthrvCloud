//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *logfile;
  char line[100];
  int num_lines = 0, num_gets = 0, num_posts = 0, num_errs = 0;

  /* Open logfile */
  if ((logfile = fopen("example.log", "r")) == NULL) {
    printf("Could not open logfile\n");
    exit(1);
  }

  /* Read logfile line-by-line */
  while (fgets(line, sizeof(line), logfile)) {
    num_lines++;

    /* Check line for GET request */
    if (strstr(line, "GET")) {
      num_gets++;
    }

    /* Check line for POST request */
    if (strstr(line, "POST")) {
      num_posts++;
    }

    /* Check line for error code */
    if (strstr(line, " 404 ")) {
      num_errs++;
    }
  }

  /* Close logfile */
  fclose(logfile);

  /* Print statistics */
  printf("=== Logfile Analysis ===\n");
  printf("Total number of lines: %d\n", num_lines);
  printf("Number of GET requests: %d\n", num_gets);
  printf("Number of POST requests: %d\n", num_posts);
  printf("Number of 404 errors: %d\n", num_errs);

  return 0;
}