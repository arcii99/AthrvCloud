//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>

int main()
{
  char filename[50], ch;
  FILE *fp;

  printf("Enter the name of the file you want to create: ");
  gets(filename);

  fp = fopen(filename, "w"); // opening file in write mode

  if (fp == NULL) {
    printf("Error in creating the file.\n");
    return 0;
  }

  printf("File created successfully.\n");

  printf("Enter data in the file: \n");
  while ((ch = getchar()) != EOF) {
    putc(ch, fp);
  }

  fclose(fp); // closing the file

  printf("Data successfully written to the file.\n");

  return 0;
}