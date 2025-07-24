//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[50], ch;
  int count = 0;

  printf("Enter the filename to open:\n");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: Unable to open file!\n");
    exit(1);
  }

  printf("The contents of %s:\n", filename);

  while ((ch = fgetc(fp)) != EOF) {
    count++;

    putchar(ch);
  }

  fclose(fp);
  printf("\n\nFile size: %d bytes\n", count);

  return 0;
}