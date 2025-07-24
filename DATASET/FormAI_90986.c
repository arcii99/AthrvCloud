//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[50];
  char recovered_data[100];
  int size;
  FILE *fp;

  printf("Enter the filename to recover data from: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: file does not exist.");
    return 1;
  }

  fseek(fp, 0L, SEEK_END);
  size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  fread(recovered_data, size, 1, fp);

  fclose(fp);

  printf("Recovered data: %s", recovered_data);

  return 0;
}