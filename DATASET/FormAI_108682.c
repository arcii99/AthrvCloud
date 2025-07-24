//FormAI DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Log Analysis Program!\n\n");
  printf("Please enter the name of the log file you would like to analyze: ");

  char filename[100];
  scanf("%s", filename);

  FILE *log_file = fopen(filename, "r");

  if (log_file == NULL) {
    printf("\nError: Could not open file %s.\n", filename);
    exit(1);
  }

  printf("\nAnalyzing log file %s...", filename);

  int errors = 0;
  int warnings = 0;
  int lines = 0;

  char line[1000];
  while (fgets(line, 1000, log_file) != NULL) {
    lines++;

    if (strstr(line, "ERROR") != NULL) {
      errors++;
    } else if (strstr(line, "WARNING") != NULL) {
      warnings++;
    }
  }

  printf("\n\nAnalysis Complete!\n\n");
  printf("Total Lines: %d \n", lines);
  printf("Number of Errors: %d \n", errors);
  printf("Number of Warnings: %d \n", warnings);

  float error_percentage = (float)errors / (float)lines * 100.0;
  printf("Percentage of Lines That Are Errors: %f%\n", error_percentage);

  fclose(log_file);

  printf("\nThank you for using the Log Analysis Program!\n");

  return 0;
}