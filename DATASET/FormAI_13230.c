//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1024

int read_csv(char filename[], char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH]) {
  int row_count = 0;
  int col_count = 0;
  char line[MAX_LINE_LENGTH];

  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    while (fgets(line, sizeof(line), file)) {
      col_count = 0;
      char* token = strtok(line, ",");
      while (token != NULL) {
        strcpy(data[row_count][col_count], token);
        col_count++;
        token = strtok(NULL, ",");
      }
      row_count++;
    }
    fclose(file);
  } else {
    printf("Unable to open file: %s\n", filename);
    return -1;
  }

  return row_count;
}

int main() {
    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH];
    int num_rows = read_csv("data.csv", data);

    if (num_rows > 0) {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%s\t", data[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}