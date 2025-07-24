//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

// Define the structure for CSV reader
typedef struct csv_reader {
  int rows; // Track the number of rows
  int cols; // Track the number of columns
  char data[MAX_ROWS][MAX_COLS][100]; // Store the CSV data
} csv_reader;

// Function to read the CSV file and populate the csv_reader structure
void read_csv(char* filename, csv_reader* csv) {
  FILE* file = fopen(filename, "r"); // Open the CSV file in read mode
  if (!file) {
    printf("Error: Unable to open file %s\n", filename);
    exit(1);
  }

  // Read the CSV file line by line
  char line[1024];
  int row = 0, col = 0;
  while (fgets(line, 1024, file)) {
    col = 0;
    line[strcspn(line, "\n")] = 0; // Remove the newline character from the line

    // Split the line using comma as delimiter
    char* token = strtok(line, ",");
    while (token) {
      strcpy(csv->data[row][col], token);
      col++;
      token = strtok(NULL, ",");
    }
    csv->cols = col;
    row++;
  }
  csv->rows = row;
  fclose(file); // Close the CSV file
}

// Function to print the CSV data
void print_csv(csv_reader csv) {
  int row, col;
  for (row = 0; row < csv.rows; row++) {
    for (col = 0; col < csv.cols; col++) {
      printf("%s\t", csv.data[row][col]);
    }
    printf("\n");
  }
}

int main() {
  csv_reader csv;
  read_csv("data.csv", &csv); // Read the CSV file and populate the csv_reader structure
  printf("Rows: %d, Cols: %d\n", csv.rows, csv.cols); // Print the number of rows and columns
  print_csv(csv); // Print the CSV data
  return 0;
}