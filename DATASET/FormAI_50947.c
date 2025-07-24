//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[20], ch;
  int n;
  printf("Enter the filename to open: ");
  scanf("%s", filename);
  /*  Open the file for reading */
  fp = fopen(filename, "r");
  /* Check if the file exists or not */
  if (fp == NULL) {
    printf("Cannot open %s\n", filename);
    exit(0);
  } else {
    printf("Successfully opened %s\n", filename);
    printf("Enter the number of characters to read: ");
    scanf("%d", &n);
    /* Read and display data */
    printf("The contents of the file are: \n");
    while ((ch = fgetc(fp)) != EOF && n--) {
      printf("%c", ch);
    }
  }
  /* Close the file */
  fclose(fp);
  return 0;
}