//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_LEN 50
#define DELIMITER ","

typedef struct Record {
  char *fields[10];
} Record;

int main(int argc, char const *argv[]) {
  char filename[256] = "data.csv";
  FILE *csvfile = fopen(filename, "r");

  if (!csvfile) {
    fprintf(stderr, "Could not open file: %s\n", filename);
    return 1;
  }

  char line[256];
  int recordCount = 0;
  Record records[MAX_RECORDS];

  while (fgets(line, sizeof(line), csvfile)) {
    Record record;
    char *field = strtok(line, DELIMITER);

    for (int i = 0; i < 10 && field != NULL; i++) {
      record.fields[i] = strdup(field);
      field = strtok(NULL, DELIMITER);
    }

    records[recordCount++] = record;
  }

  fclose(csvfile);

  for (int i = 0; i < recordCount; i++) {
    Record record = records[i];

    for (int j = 0; j < 10 && record.fields[j] != NULL; j++) {
      printf("%s ", record.fields[j]);
    }

    printf("\n");
  }

  return 0;
}