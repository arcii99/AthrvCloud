//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>

int main() {
  //collecting input from user (could be a log file path or input from stdin)
  char log[1000];
  printf("Enter log for analysis: ");
  fgets(log, sizeof(log), stdin);

  //opening log file
  FILE *file = fopen(log, "r");

  //checking if file exists and can be read
  if (file == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  //declaring variables for analysis
  int num_lines = 0; //number of lines in the log
  int num_errors = 0; //number of error messages in the log

  //reading the log file line by line and analyzing each line
  char line[256];
  while (fgets(line, sizeof(line), file)) {
    num_lines++;
    if (strstr(line, "ERROR")) {
      num_errors++;
    }
  }

  //closing log file
  fclose(file);

  //displaying analysis results
  printf("\nLog analysis summary:\n");
  printf("Total lines in log: %d\n", num_lines);
  printf("Number of error messages in log: %d\n", num_errors);

  //returning 0 to indicate successful program execution
  return 0;
}