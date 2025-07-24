//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  int num, result;

  fp = fopen("sample.txt", "r"); //opening sample.txt file for reading
  if (fp == NULL) { //checking if the file exists
    printf("Error opening file\n");
    exit(EXIT_FAILURE); //exit the program with failure status
  }

  //reading an integer from the file
  result = fscanf(fp, "%d", &num);
  if (result == EOF) { //checking if end of file is reached
    printf("Error reading file\n");
    exit(EXIT_FAILURE); //exit the program with failure status
  }
  fclose(fp); //close the file

  //doing some calculations with the read integer
  if (num % 2 == 0) {
    printf("%d is even\n", num);
  } else {
    printf("%d is odd\n", num);
  }
  return 0;
}