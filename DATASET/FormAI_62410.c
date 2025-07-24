//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char str[50];
  char filename[20];
  int num;

  printf("Enter file name to create: ");
  scanf("%s", filename);

  fp = fopen(filename, "w");

  if(fp == NULL) {
    printf("Error creating file.\n");
    exit(1);
  }

  printf("Enter the number of lines to write: ");
  scanf("%d", &num);
  getchar();

  for(int i=0; i<num; i++) {
    printf("Enter line %d:\n", i+1);
    fgets(str, 50, stdin);
    fprintf(fp, "%s", str);
  }

  fclose(fp);

  printf("File created and saved successfully.\n");

  return 0;
}