//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LEN 10000

typedef struct {
  int rows;
  int cols;
  char data[MAX_ROWS][MAX_COLS][MAX_LINE_LEN];
} csv_data;

csv_data read_csv_file(const char* filename) {
  csv_data data = {0};
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file '%s'\n", filename);
    exit(1);
  }
  char line[MAX_LINE_LEN];
  while (fgets(line, sizeof(line), file)) {
    char* field = strtok(line, ",");
    int col = 0;
    while (field && col < MAX_COLS) {
      strcpy(data.data[data.rows][col++], field);
      field = strtok(NULL, ",");
    }
    data.rows++;
    if (col > data.cols) {
      data.cols = col;
    }
  }
  fclose(file);
  return data;
}

void print_csv_data(csv_data data) {
  for (int row = 0; row < data.rows; row++) {
    for (int col = 0; col < data.cols; col++) {
      printf("%s", data.data[row][col]);
      if (col < data.cols - 1) {
        printf(",");
      }
    }
    printf("\n");
  }
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename.csv\n", argv[0]);
    exit(1);
  }
  csv_data data = read_csv_file(argv[1]);
  print_csv_data(data);
  return 0;
}