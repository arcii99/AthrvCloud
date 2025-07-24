//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  FILE *file;
  char *filename;
  char c;
  int count = 0;
  
  if (argc == 2) {
    filename = argv[1];
  } else {
    printf("Please input a filename: ");
    scanf("%s", filename);
  }
  
  if ((file = fopen(filename, "r")) == NULL) {
    printf("File not found\n");
    exit(1);
  }
  
  while ((c = fgetc(file)) != EOF) {
    if (isalpha(c)) {
      count++;
      while (isalpha(c = fgetc(file))) {}
    }
  }
  
  fclose(file);
  printf("The file '%s' contains %d words.\n", filename, count);
  
  return 0;
}