//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file_pointer;
  char filename[50], text[1000];

  printf("Enter file name: ");
  scanf("%s", filename);

  file_pointer = fopen(filename, "w");

  if(file_pointer == NULL) {
    printf("Error! Couldn't create file.");
    exit(1);
  }

  printf("Enter text:\n");
  scanf(" %[^\n]s", text);

  fprintf(file_pointer, "%s", text);
  printf("File created successfully. \n");

  fclose(file_pointer);

  file_pointer = fopen(filename, "r");

  if(file_pointer == NULL) {
    printf("Error! Couldn't open file.");
    exit(1);
  }

  printf("Reading from file: \n");
  printf("--------------------------\n");

  while(fgets(text, 1000, file_pointer) != NULL) {
    printf("%s", text);
  }

  fclose(file_pointer);
  
  return 0;
}