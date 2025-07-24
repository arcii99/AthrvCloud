//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>

#define MAX_ROWS 100

int main() {
  FILE *fileptr;        // File pointer
  char filename[100];   // File name
  int data[MAX_ROWS];   // Array to store integers
  int i = 0;            // Index for data array
  int value;            // Temporary variable to hold each integer

  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open file for reading
  fileptr = fopen(filename, "r");
  if (fileptr == NULL) {
    printf("Error opening file.");
    return 1;
  }

  // Read file one integer at a time
  while ((fscanf(fileptr, "%d,", &value)) != EOF) {
    data[i] = value;
    i++;
  }

  // Print contents of the data array
  printf("Data from %s:\n", filename);
  for (int j = 0; j < i; j++) {
    printf("%d ", data[j]);
  }

  // Close file
  fclose(fileptr);

  return 0;
}