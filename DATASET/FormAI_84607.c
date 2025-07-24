//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
  FILE* file = fopen("example.csv", "r");
  char line[MAX_LINE_LENGTH];
  int line_count = 0;

  if (file == NULL) {
    printf("Error opening file.\n");
    return -1;
  }

  while (fgets(line, MAX_LINE_LENGTH, file)) {
    line_count++;
    
    // Remove newline character
    line[strcspn(line, "\n")] = 0;

    // Split line into fields
    char* field = strtok(line, ",");
    while (field) {
      printf("%s | ", field);
      field = strtok(NULL, ",");
    }
    printf("\n");
  }

  printf("Read %d lines.\n", line_count);

  fclose(file);
  return 0;
}