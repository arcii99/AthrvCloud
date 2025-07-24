//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 100

void read_csv_file(char* file_path) {
  // Open the file
  FILE* fp = fopen(file_path, "r");

  // Handle error
  if (fp == NULL) {
    printf("Error opening the file!\n");
    return;
  }

  char buffer[MAX_ROW_SIZE];
  int row_count = 0;
  int col_count = 0;

  // Read file row by row
  while (fgets(buffer, MAX_ROW_SIZE, fp)) {
    // If the first row, get the number of columns
    if (row_count == 0) {
      char* split = strtok(buffer, ",");
      while (split != NULL) {
        col_count++;
        split = strtok(NULL, ",");
      }
    }

    char* token = strtok(buffer, ",");
    int col_count_check = 0;

    // Output data row by row
    while (token != NULL) {
      printf("%s", token);

      // If there is more than one column in a row, print a comma
      if (col_count_check < col_count - 1) {
        printf(",");
        col_count_check++;
      }

      token = strtok(NULL, ",");
    }

    printf("\n");
    row_count++;

    // Handle error for too many rows
    if (row_count >= MAX_COL_SIZE) {
      printf("Excessive data rows!\n");
      break;
    }
  }

  // Handle error for too many columns
  if (col_count >= MAX_ROW_SIZE) {
    printf("Excessive data columns!\n");
  }

  // Close the file
  fclose(fp);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("File path not specified!\n");
    return 1;
  }

  char* file_path = argv[1];

  // Call the function to read the CSV file
  read_csv_file(file_path);

  return 0;
}