//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  int num, count = 0, sum = 0;

  /* Open the file for reading */
  fp = fopen("numbers.txt", "r");
  if (fp == NULL) {
    printf("Failed to open file.");
    exit(1);
  }

  /* Read the file line by line and calculate the sum of all numbers */
  while (fscanf(fp, "%d", &num) == 1) {
    sum += num;
    count++;
  }

  /* Close the file */
  fclose(fp);

  /* Print the results */
  printf("The file contains %d numbers.\n", count);
  printf("The sum of all numbers is %d.\n", sum);

  return 0;
}