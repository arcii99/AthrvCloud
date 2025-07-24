//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  // User input for log file name and search term
  char logfile[100];
  char searchterm[50];

  printf("Enter the log file name: ");
  scanf("%s", logfile);

  printf("Enter the search term: ");
  scanf("%s", searchterm);

  FILE *fp;

  // Try to open log file
  if ((fp = fopen(logfile, "r")) == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  char *line = NULL;
  size_t len = 0;

  // Loop through each line in log file
  while (getline(&line, &len, fp) != -1) {
    // Check if search term exists in line
    if (strstr(line, searchterm) != NULL) {
      printf("%s", line);
    }
  }

  // Clean up
  fclose(fp);
  if (line) {
    free(line);
  }
  return 0;
}