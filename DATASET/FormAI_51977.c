//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

typedef struct {
  char **fields;
  int num_fields;
} CsvRow;

typedef struct {
  char *filename;
  char *delimiter;
  CsvRow **rows;
  int num_rows;
} CsvFile;

CsvFile *csv_create(char *filename, char *delimiter) {
  CsvFile *csv = (CsvFile *)malloc(sizeof(CsvFile));
  csv->filename = filename;
  csv->delimiter = delimiter;
  csv->rows = (CsvRow **)malloc(sizeof(CsvRow *));
  csv->num_rows = 0;
  return csv;
}

CsvRow *csv_row_create(char *line, char *delimiter) {
  CsvRow *row = (CsvRow *)malloc(sizeof(CsvRow));
  row->fields = (char **)malloc(sizeof(char *));
  row->num_fields = 0;
  char *token = strtok(line, delimiter);
  while(token != NULL) {
    row->fields = (char **)realloc(row->fields, sizeof(char *) * (row->num_fields+1));
    row->fields[row->num_fields] = (char *)malloc(sizeof(char) * MAX_FIELD_LENGTH);
    strcpy(row->fields[row->num_fields], token);
    row->num_fields++;
    token = strtok(NULL, delimiter);
  }
  return row;
}

void csv_append_row(CsvFile *csv, CsvRow *row) {
  csv->rows = (CsvRow **)realloc(csv->rows, sizeof(CsvRow *) * (csv->num_rows+1));
  csv->rows[csv->num_rows++] = row;
}

CsvFile *csv_read(char *filename, char *delimiter) {
  CsvFile *csv = csv_create(filename, delimiter);
  FILE *file = fopen(filename, "r");
  char line[MAX_LINE_LENGTH];
  while(fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    CsvRow *row = csv_row_create(line, delimiter);
    csv_append_row(csv, row);
  }
  fclose(file);
  return csv;
}

int main(int argc, char **argv) {
  CsvFile *csv = csv_read("data.csv", ",");
  for(int i=0; i<csv->num_rows; i++) {
    CsvRow *row = csv->rows[i];
    for(int j=0; j<row->num_fields; j++) {
      printf("%s ", row->fields[j]);
    }
    printf("\n");
  }
  return 0;
}