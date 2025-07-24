//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  int num, sum=0;
  file = fopen("numbers.txt", "r"); // opening file in read mode

  if (file == NULL) { // checking if file is empty
    printf("File does not exist.");
    exit(0);
  }

  while (fscanf(file, "%d", &num) != EOF) { // scanning file for integer numbers
    sum += num; // calculating sum of numbers
  }

  fclose(file); // closing file
  printf("Sum of numbers in file: %d", sum);
  return 0;
}