//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fptr;
  char filename[15];
  char c;

  printf("Enter the filename: ");
  scanf("%s", filename);

  fptr = fopen(filename, "r");

  if (fptr == NULL) {
    printf("Error: Cannot open file.\n");
    exit(0);
  }

  while ((c = fgetc(fptr)) != EOF) {
    printf("%c", c);
  }

  fclose(fptr);

  return 0;
}