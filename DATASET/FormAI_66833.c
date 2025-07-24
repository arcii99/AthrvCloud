//FormAI DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char path[100];
  
  printf("Enter path to log file: ");
  scanf("%s", path);
  
  file = fopen(path, "r");
  
  if (file == NULL) {
    printf("Unable to open file.");
    exit(EXIT_FAILURE);
  }
  
  int total_warnings = 0, total_errors = 0, total_criticals = 0;
  
  while (!feof(file)) {
    char line[256];
    fgets(line, 256, file);
    
    if (strstr(line, "WARNING")) {
      total_warnings++;
    } else if (strstr(line, "ERROR")) {
      total_errors++;
    } else if (strstr(line, "CRITICAL")) {
      total_criticals++;
    }
  }
  
  printf("Log Analysis Report:\n");
  printf("=====================\n");
  printf("Total Warnings: %d\n", total_warnings);
  printf("Total Errors: %d\n", total_errors);
  printf("Total Criticals: %d\n", total_criticals);
  
  fclose(file);
  
  return 0;
}