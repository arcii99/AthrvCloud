//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void error_check(int result, char *error_msg) {
  if (result < 0) {
    fprintf(stderr, "%s\n", error_msg); // Print error message to stderr
    exit(EXIT_FAILURE); // Terminate the program with a non-zero exit code
  }
}

int main() {
  FILE *fp = fopen("sample.txt", "r");
  error_check(fp != NULL, "Unable to open file"); // Check if file exists
  
  int num;
  int sum = 0;
  while (fscanf(fp, "%d", &num) == 1) {
    sum += num;
  }
  error_check(!feof(fp), "Error occurred when reading file"); // Check if error occurred while reading file
  
  fclose(fp);
  printf("Sum of numbers in file: %d\n", sum);
  
  return 0;
}