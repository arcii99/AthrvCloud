//FormAI DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>

int main() {
  // Define variables
  FILE *file;
  char filename[] = "data.txt";
  double x, y, z;

  // Open file for writing
  file = fopen(filename, "w");
  if (!file){
    printf("Error opening file %s for writing!\n", filename);
    return 1;
  }

  // Write data to file
  fprintf(file, "x\ty\tz\n"); // Header
  for (double i = 0; i < 10; i++){
    x = 2 * i;
    y = x * i;
    z = x * y;
    fprintf(file, "%.2f\t%.2f\t%.2f\n", x, y, z);
  }

  // Close file
  fclose(file);

  // Open file for reading
  file = fopen(filename, "r");
  if (!file){
    printf("Error opening file %s for reading!\n", filename);
    return 1;
  }

  // Read data from file
  printf("Data from file %s:\n", filename);
  char line[50];
  while (fgets(line, 50, file)){
    printf("%s", line);
  }

  // Close file
  fclose(file);

  return 0;
}