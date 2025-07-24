//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char filename[100], c;
  int checksum = 0;

  printf("Enter the name of file to calculate checksum: ");
  scanf("%s", filename);

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found!\n");
    exit(0);
  }

  while ((c = getc(file)) != EOF) {
    checksum += (int)c;
  }

  fclose(file);

  printf("Checksum: %d", checksum);

  return 0;
}