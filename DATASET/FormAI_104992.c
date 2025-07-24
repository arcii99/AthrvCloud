//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20
#define CSV_DELIMITER ','

typedef struct {
  int num_fields;
  char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
} CSVRow;

typedef struct {
  int num_rows;
  CSVRow* rows;
} CSVFile;

int count_fields(char* line) {
  int count = 0;
  char* ptr = line;

  while (*ptr) {
    if (*ptr == CSV_DELIMITER) {
      count++;
    }
    ptr++;
  }

  return count + 1;
}

int read_csv_file(char* filename, CSVFile* csv_file) {
  FILE* fp = fopen(filename, "r");

  if (!fp) {
    fprintf(stderr, "Error: Unable to open file '%s' for reading.\n", filename);
    return 0;
  }

  char line[MAX_LINE_LENGTH];
  int num_rows = 0;
  int num_fields = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    num_fields = count_fields(line);
    if (num_fields > MAX_FIELDS) {
      fprintf(stderr, "Error: Too many fields on line %d. Maximum is %d.\n", num_rows + 1, MAX_FIELDS);
      return 0;
    }
    num_rows++;
  }

  csv_file->num_rows = num_rows;
  csv_file->rows = malloc(sizeof(CSVRow) * num_rows);
  rewind(fp);
  int i = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    CSVRow* row = &(csv_file->rows[i]);
    char* field = strtok(line, ",");
    row->num_fields = 0;
    while (field) {
      if (row->num_fields >= MAX_FIELDS) {
        fprintf(stderr, "Error: Too many fields on line %d. Maximum is %d.\n", i + 1, MAX_FIELDS);
        return 0;
      }
      strncpy(row->fields[row->num_fields], field, MAX_FIELD_LENGTH);
      row->fields[row->num_fields][MAX_FIELD_LENGTH-1] = '\0';
      row->num_fields++;
      field = strtok(NULL, ",");
    }
    i++;
  }

  fclose(fp);
  return 1;
}

int main() {
  CSVFile csv_file;
  int success = read_csv_file("example.csv", &csv_file);
  if (!success) {
    fprintf(stderr, "Failed to read CSV file.\n");
    return 1;
  }

  // Do something with csv_file...

  for (int i = 0; i < csv_file.num_rows; i++) {
    CSVRow row = csv_file.rows[i];
    for (int j = 0; j < row.num_fields; j++) {
      printf("%s,", row.fields[j]);
    }
    printf("\n");
  }

  return 0;
}