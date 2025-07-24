//FormAI DATASET v1.0 Category: Data mining ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the dataset
#define MAX_COLUMNS 50

int main() {
  // Define a configurable list of comma-separated column names
  char column_names[] = "id,name,age,salary,city";

  // Convert the list of column names into an array
  char* columns[MAX_COLUMNS];
  int num_columns = 0;
  char* token = strtok(column_names, ",");
  while (token != NULL && num_columns < MAX_COLUMNS) {
    columns[num_columns++] = token;
    token = strtok(NULL, ",");
  }

  // Define the dataset with configurable data
  char* dataset[] = {
    "1,John,25,50000,New York",
    "2,Jane,30,60000,San Francisco",
    "3,Bob,35,70000,Chicago",
    "4,Sara,40,80000,Los Angeles"
  };
  int num_rows = sizeof(dataset) / sizeof(dataset[0]);

  // Print out the column names and the data in the dataset
  for (int i = 0; i < num_columns; i++) {
    printf("%-15s", columns[i]);
  }
  printf("\n");
  for (int i = 0; i < num_rows; i++) {
    char* row = dataset[i];
    char* token = strtok(row, ",");
    while (token != NULL && i < num_columns) {
      printf("%-15s", token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  return 0;
}