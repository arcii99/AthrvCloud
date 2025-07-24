//FormAI DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE *fp; 
  int num;
  
  fp = fopen("numbers.txt", "r");
  
  if (fp == NULL) {
    perror("Unable to open file!"); // Error message
    exit(EXIT_FAILURE);
  }
  
  if (fscanf(fp, "%d", &num) != 1) { // Scan for integer
    fprintf(stderr, "Error: Failed to read integer from file!\n"); // Error message
    exit(EXIT_FAILURE);
  }
  
  if (num < 0) { // Check if integer is negative
    fprintf(stderr, "Error: Negative integer not allowed!\n"); // Error message
    exit(EXIT_FAILURE);
  }
  
  fclose(fp);
  
  printf("The number is: %d\n", num);

  return 0;
}