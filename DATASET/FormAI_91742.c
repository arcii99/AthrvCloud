//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct Row {
  char cells[MAX_COLUMNS][256];
  int num_cells;
} Row;

typedef struct Csv {
  Row rows[MAX_ROWS];
  int num_rows;
} Csv;

Csv read_csv(char* filename) {
  Csv csv = {0};
  char buffer[256];
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Failed to open file");
    exit(1);
  }
  int row_index = 0;
  while (fgets(buffer, sizeof(buffer), file)) {
    char* cell;
    int cell_index = 0;
    char* token = strtok(buffer, ",");
    while (token != NULL) {
      cell = csv.rows[row_index].cells[cell_index];
      strcpy(cell, token);
      token = strtok(NULL, ",");
      cell_index++;
    }
    csv.rows[row_index].num_cells = cell_index;
    row_index++;
  }
  csv.num_rows = row_index;
  fclose(file);
  return csv;
}

void print_csv(Csv csv) {
  for (int row_index = 0; row_index < csv.num_rows; row_index++) {
    Row row = csv.rows[row_index];
    for (int cell_index = 0; cell_index < row.num_cells; cell_index++) {
      printf("%s ", row.cells[cell_index]);
    }
    printf("\n");
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    exit(1);
  }
  Csv csv = read_csv(argv[1]);
  print_csv(csv);
  return 0;
}