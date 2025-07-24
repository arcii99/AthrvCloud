//FormAI DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main() {
  FILE *file;
  char filename[100];
  char *data = (char*)malloc(MAX_FILE_SIZE);
  int size = 0;
  int i;

  printf("Enter filename: ");
  scanf("%s", filename);

  file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  size = ftell(file);
  rewind(file);

  if (size > MAX_FILE_SIZE) {
    printf("File too big!\n");
    exit(1);
  }

  fread(data, size, 1, file);
  fclose(file);

  printf("Data recovered from %s:\n", filename);

  for (i=0; i<size; i++) {
    printf("%c", data[i]);
  }

  free(data);
  return 0;
}