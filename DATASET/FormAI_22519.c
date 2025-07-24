//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char ch;

  // create a new file
  fp = fopen("new_file.txt", "w");

  // write to the file
  fprintf(fp, "Hello, world!\n");
  fprintf(fp, "This is a new file.\n");
  fprintf(fp, "It's a test file.\n");

  // close the file
  fclose(fp);

  // open the file for reading
  fp = fopen("new_file.txt", "r");

  // read the contents of the file
  printf("The contents of the file are:\n");
  while ((ch = fgetc(fp)) != EOF)
  {
    putchar(ch);
  }

  // close the file
  fclose(fp);

  // delete the file
  remove("new_file.txt");

  return 0;
}