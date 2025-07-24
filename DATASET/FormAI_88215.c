//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the Happy C Checksum Calculator!\n");
  printf("What is the name of your file? (include extension)\n");

  char filename[100];
  scanf("%s", filename);

  // Open file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
      printf("Oops! File does not exist.\n");
      return 1;
  }

  // Calculate checksum
  int c;
  int checksum = 0;
  while ((c = fgetc(fp)) != EOF) {
    checksum ^= c;
  }

  printf("Completed processing file! Your checksum is: %d\n", checksum);

  // Close file
  fclose(fp);

  printf("Thank you for using the Happy C Checksum Calculator!\n");
  return 0;
}