//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[MAX_LINE_SIZE];
  char *fields[MAX_FIELDS];
  char *field;
  int nfields, i, j;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename.csv\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "r");

  if (!fp) {
    fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
    nfields = 0;
    field = strtok(line, ",");

    while (field && nfields < MAX_FIELDS) {
      fields[nfields] = field;
      nfields++;
      field = strtok(NULL, ",");
    }

    for (i = 0; i < nfields; i++) {
      for (j = 0; j < strlen(fields[i]); j++) {
        if (fields[i][j] == '\n' || fields[i][j] == '\r') {
          fields[i][j] = '\0';
          break;
        }
      }
      printf("%s ", fields[i]);
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}