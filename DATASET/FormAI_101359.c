//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>

int main() {
  printf("Welcome to our C Log Analysis Program!\n");
  printf("Please enter the name of the log file you want to analyze: ");

  char fileName[20]; // assuming file name won't be longer than 20 characters
  scanf("%s", fileName);

  FILE *logFile;
  logFile = fopen(fileName, "r"); // open file in read mode

  if (logFile == NULL) { // if file does not exist
    printf("Error opening file. Please make sure the file name is correct and try again.\n");
    return 1;
  }

  printf("File opened successfully!\n");
  printf("Analyzing log file...\n");

  int numErrors = 0;
  int numWarnings = 0;

  char line[100]; // assuming each line in log file won't be longer than 100 characters

  while (fgets(line, 100, logFile) != NULL) { // read each line in log file
    if (strstr(line, "ERROR") != NULL) { // check if line contains "ERROR"
      numErrors++;
    } else if (strstr(line, "WARNING") != NULL) { // check if line contains "WARNING"
      numWarnings++;
    }
  }

  fclose(logFile); // close file

  printf("Log file analysis completed.\n");
  printf("Number of errors: %d\n", numErrors);
  printf("Number of warnings: %d\n", numWarnings);

  return 0;
}