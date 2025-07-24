//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *logFile;
  char line[1024];
  char fileName[50];
  char searchString[50];
  int lineNumber = 0;

  printf("Enter the name of the log file to be searched: ");
  scanf("%s", fileName);

  printf("Enter the search string: ");
  scanf("%s", searchString);

  logFile = fopen(fileName, "r");

  if (logFile == NULL) {
    printf("Error opening file\n");
    return 0;
  }

  while (fgets(line, sizeof(line), logFile)) {
    lineNumber++;

    if (strstr(line, searchString) != NULL) {
      printf("Line %d: %s", lineNumber, line);
    }
  }

  fclose(logFile);

  return 0;
}