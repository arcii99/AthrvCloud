//FormAI DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char filename[100];
  char line[200];
  char *tok;
  int num_lines = 0;
  int num_errors = 0;
  float error_percent;
  
  printf("Enter the name of the log file: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  while(fgets(line, sizeof(line), fp)) {
    tok = strtok(line, " ");

    while(tok != NULL) {
      if(strcmp(tok, "ERROR") == 0) {
        num_errors++;
        break;
      }

      tok = strtok(NULL, " ");
    }

    num_lines++;
  }

  error_percent = (float)num_errors / (float)num_lines * 100.0;

  printf("\nLog analysis complete.\n\n");
  printf("Number of lines in log file: %d\n", num_lines);
  printf("Number of errors in log file: %d\n", num_errors);
  printf("Percentage of errors in log file: %.2f%%\n", error_percent);

  fclose(fp);

  return 0;
}