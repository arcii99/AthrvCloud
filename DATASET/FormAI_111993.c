//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count the occurrences of a string in a log file
int countOccurrences(char fileName[], char searchStr[]) {
  FILE* filePtr;
  char line[256];
  int count = 0;

  filePtr = fopen(fileName, "r");

  if (filePtr == NULL) {
    printf("Error! Could not open file");
    exit(-1);
  }

  while (fgets(line, sizeof(line), filePtr)) {
    if (strstr(line, searchStr)) {
      count++;
    }
  }

  fclose(filePtr);

  return count;
}

int main() {
  char fileName[256] = "app.log";
  char searchStr[256] = "Error";

  int numErrors = countOccurrences(fileName, searchStr);

  printf("There were %d errors found in the log file", numErrors);

  return 0;
}