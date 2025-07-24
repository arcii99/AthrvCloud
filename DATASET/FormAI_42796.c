//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *csvFile;
  csvFile = fopen("data.csv", "r");

  if (csvFile == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  char line[100];
  int row = 0;

  while (fgets(line, sizeof(line), csvFile) != NULL) {
    if (row % 2 == 0) {
      printf("row %d: ", row/2);
    }

    char *cell = strtok(line, ",");
    while (cell != NULL) {
      if (row % 2 == 0) {
        printf("%s", cell);
      } else {
        int value = atoi(cell);
        printf("%x", value);
      }

      cell = strtok(NULL, ",");
      if (cell != NULL) {
        printf(" | ");
      }
    }

    if (row % 2 == 1) {
      printf("\n");
    }

    row++;
  }

  fclose(csvFile);

  return 0;
}