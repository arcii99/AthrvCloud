//FormAI DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *filePtr;
  char filename[100];
  char ch;

  printf("Enter the file name: ");
  scanf("%s", filename);

  filePtr = fopen(filename, "r");

  if (filePtr == NULL)
  {
    printf("Error: Cannot open file.\n");
    exit(1);
  }

  while ((ch = fgetc(filePtr)) != EOF)
  {
    printf("%c", ch);
  }

  fclose(filePtr);
  printf("\nFile recovered successfully!\n");

  return 0;
}