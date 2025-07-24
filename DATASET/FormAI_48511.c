//FormAI DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>

int main() {
  FILE *fp;
  char filename[] = "example.txt";
  char buffer[100];
  
  // Open the file for writing
  fp = fopen(filename, "w");

  // Write to the file
  fprintf(fp, "Hello World!");

  // Close the file
  fclose(fp);

  // Open the file for reading
  fp = fopen(filename, "r");

  // Read from the file
  fscanf(fp, "%s", buffer);

  // Print the contents of the file
  printf("Contents of %s: %s", filename, buffer);

  // Close the file
  fclose(fp);

  return 0;
}