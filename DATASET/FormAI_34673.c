//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","

int main() {
  FILE *fp;
  char buffer[BUFFER_SIZE];
  char *field;

  fp = fopen("example.csv", "r");

  if (!fp) {
    printf("Unable to open file\n");
    exit(1);
  }

  while (fgets(buffer, BUFFER_SIZE, fp)) {
    field = strtok(buffer, DELIMITER);

    while (field != NULL) {
      printf("%s ", field);
      field = strtok(NULL, DELIMITER);
    }

    printf("\n");
  }

  fclose(fp);
  return 0;
}