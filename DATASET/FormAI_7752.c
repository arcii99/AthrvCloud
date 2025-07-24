//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {

  // Open the CSV file for reading
  FILE *csv_file = fopen("data.csv", "r");

  // Check if the file was opened successfully
  if (csv_file == NULL) {
    printf("Error: Unable to open file\n");
    exit(1);
  }

  char line[MAX_LENGTH];

  // Read the header line from the file
  if (fgets(line, MAX_LENGTH, csv_file) != NULL) {
    // Print the header
    printf("Header: %s\n", line);
  }

  // Read the rest of the lines from the file
  while (fgets(line, MAX_LENGTH, csv_file) != NULL) {

    // Parse the line into individual values
    char *value = strtok(line, ",");
    while (value != NULL) {
      // Print the value
      printf("%s ", value);
      value = strtok(NULL, ",");
    }

    // Move to the next line
    printf("\n");
  }

  // Close the file
  fclose(csv_file);

  return 0;
}