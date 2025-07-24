//FormAI DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Opening a file in read mode
  FILE *fp = fopen("myArtisticFile.txt", "r");

  // Checking if file exists or not
  if (fp == NULL) {
    printf("File does not exist!\n");
    exit(1);
  }

  // Reading contents of the file
  printf("The contents of the file are:\n");
  char c = fgetc(fp);
  while (c != EOF) {
    putchar(c);
    c = fgetc(fp);
  }

  // Closing the file
  fclose(fp);

  // Opening the same file in write mode
  fp = fopen("myArtisticFile.txt", "w");

  // Checking if file is opened or not
  if (fp == NULL) {
    printf("Unable to open file to write!\n");
    exit(1);
  }

  // Writing a poem to the file
  fprintf(fp, "Roses are red,\n");
  fprintf(fp, "Violets are blue,\n");
  fprintf(fp, "Sugar is sweet,\n");
  fprintf(fp, "And so are you.\n");

  // Closing the file
  fclose(fp);

  // Opening the file again in read mode
  fp = fopen("myArtisticFile.txt", "r");

  // Checking if file is opened or not
  if (fp == NULL) {
    printf("Unable to open file to read!\n");
    exit(1);
  }

  // Reading contents of the file again
  printf("The contents of the file now are:\n");
  c = fgetc(fp);
  while (c != EOF) {
    putchar(c);
    c = fgetc(fp);
  }

  // Closing the file
  fclose(fp);

  return 0;
}