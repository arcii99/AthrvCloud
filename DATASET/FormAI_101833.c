//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 1024
#define MAX_TOKENS_PER_LINE 100

// Define a structure for each row in the CSV file
typedef struct {
  int id;
  char name[50];
  int score;
} CsvRow;

// Define a structure for the CSV data
typedef struct {
  int numRows;
  CsvRow *rows;
} CsvData;

// Define a function to read a CSV file and return a CsvData struct
CsvData readCsvFile(char *filename) {
  FILE *csvFile = fopen(filename, "r");
  if (csvFile == NULL) {
    printf("Could not open file: %s\n", filename);
    exit(1);
  }

  // Count the number of rows in the file
  int numRows = 0;
  char line[MAX_CHARS_PER_LINE];
  while (fgets(line, MAX_CHARS_PER_LINE, csvFile) != NULL) {
    if (strlen(line) > 1) {
      numRows++;
    }
  }

  // Allocate memory for the CsvData struct
  CsvData csvData;
  csvData.numRows = numRows;
  csvData.rows = (CsvRow *)malloc(numRows * sizeof(CsvRow));

  // Read in each row of data
  rewind(csvFile);
  int rowCounter = 0;
  while (fgets(line, MAX_CHARS_PER_LINE, csvFile) != NULL) {
    if (strlen(line) > 1) {
      // Tokenize the line
      char *token;
      int tokenCounter = 0;
      char *tokens[MAX_TOKENS_PER_LINE];
      token = strtok(line, ",");
      while (token != NULL) {
        tokens[tokenCounter] = token;
        tokenCounter++;
        token = strtok(NULL, ",");
      }

      // Parse the tokens into the CsvRow struct
      CsvRow dataRow;
      dataRow.id = atoi(tokens[0]);
      strcpy(dataRow.name, tokens[1]);
      dataRow.score = atoi(tokens[2]);
      csvData.rows[rowCounter] = dataRow;
      rowCounter++;
    }
  }

  fclose(csvFile);

  return csvData;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please provide a CSV file to read.\n");
    exit(1);
  }

  CsvData csvData = readCsvFile(argv[1]);

  // Print out the contents of the CSV file
  printf("ID\tName\t\tScore\n");
  printf("====================================\n");
  for (int i = 0; i < csvData.numRows; i++) {
    CsvRow row = csvData.rows[i];
    printf("%d\t%s\t\t%d\n", row.id, row.name, row.score);
  }

  // Free the memory allocated for the CsvData struct
  free(csvData.rows);

  return 0;
}