//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of a file
int checksum(char *filename) {
  FILE *file = fopen(filename, "r");
  int sum = 0;
  char ch;

  if (file == NULL) {
    printf("Error opening file.");
    exit(1);
  }

  // Calculate the sum of all characters in file
  while ((ch = fgetc(file)) != EOF) {
    sum += (int) ch;
  }

  // Close the file
  fclose(file);

  // Return the checksum
  return sum;
}

int main() {
  char filename[100];
  int sum;

  printf("Enter the filename: ");
  scanf("%s", filename);

  // Calculate the checksum of the file
  sum = checksum(filename);

  printf("Checksum of file '%s' is: %d\n", filename, sum);

  return 0;
}