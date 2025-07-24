//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[50];
  char line[100];
  int count = 0;

  printf("Enter name of file to read: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    count++;
    printf("Line %d: %s", count, line);
  }

  fclose(fp);
  return 0;
}