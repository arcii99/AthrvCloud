//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELD_COUNT 16

int main(int argc, char *argv[]) {
  FILE *file = NULL;
  char line[MAX_LINE_SIZE];
  char field[MAX_FIELD_COUNT][MAX_FIELD_SIZE];
  char *token = NULL;

  if (argc != 2) {
    printf("Usage: csv_reader <file_name>\n");
    return -1;
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Unable to open file: %s\n", argv[1]);
    return -1;
  }

  while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
    int field_count = 0;

    token = strtok(line, ",");
    while (token != NULL && field_count < MAX_FIELD_COUNT) {
      strcpy(field[field_count], token);
      field_count++;
      token = strtok(NULL, ",");
    }

    printf("Fields:\n");
    for (int i = 0; i < field_count; i++) {
      printf("%s\n", field[i]);
    }
  }

  fclose(file);

  return 0;
}