//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the Log Analysis program!\n");

  // Ask the user for the log file input
  char file_name[100];
  printf("Please enter the name of the log file you wish to analyze:\n");
  scanf("%s", file_name);

  // Open the log file and start analyzing
  FILE* file = fopen(file_name, "r");
  if(file == NULL) {
    printf("Oops! The file %s could not be opened.\n", file_name);
    return 1;
  }

  printf("Analyzing logfile...\n\n");
  
  // Start counting the number of different types of log entries
  int info_count = 0;
  int warning_count = 0;
  int error_count = 0;

  char buffer[1000];
  while(fgets(buffer, 1000, file)) {
    if(strstr(buffer, "INFO")) {
      info_count++;
    } else if(strstr(buffer, "WARNING")) {
      warning_count++;
    } else if(strstr(buffer, "ERROR")) {
      error_count++;
    }
  }

  // Output the results
  printf("ANALYSIS COMPLETE\n");
  
  printf("\nCount of INFO log entries: %d\n", info_count);
  printf("\nCount of WARNING log entries: %d\n", warning_count);
  printf("\nCount of ERROR log entries: %d\n", error_count);

  // Close the file
  fclose(file);

  return 0;
}