//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *logFile;
  char fileName[200];
  int totalLines = 0;
  int totalErrorLines = 0;
  float errorPercentage = 0.0;
  char line[1000];
  
  printf("Welcome to the Log Analyzer!\n");
  printf("Please enter the name of the log file: ");
  scanf("%s", fileName);
  
  logFile = fopen(fileName, "r");
  
  if (logFile == NULL) {
    printf("Error opening file. Please make sure the file exists and try again.\n");
    return 1;
  }
  
  while (fgets(line, sizeof(line), logFile)) {
    totalLines++; // counting total lines in file
    
    if (strstr(line, "ERROR")) { // checking if line contains the keyword "ERROR"
      totalErrorLines++; // counting total lines containing the word "ERROR"
    }
  }
  
  if (totalLines == 0) {
    printf("File is empty. Nothing to analyze.\n");
    return 1;
  }
  
  errorPercentage = ((float) totalErrorLines / (float) totalLines) * 100.0; // calculating error percentage
  
  printf("\nTotal lines in file: %d\n", totalLines);
  printf("Total lines containing the word 'ERROR': %d\n", totalErrorLines);
  printf("Error percentage: %.2f%%\n", errorPercentage);
  
  fclose(logFile);
  
  return 0;
}