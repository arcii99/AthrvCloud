//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;
  char filename[50], ch;
  int n, count=0;

  printf("Enter the name of the file: ");
  scanf("%s", filename);

  fp=fopen(filename,"r");

  if(fp==NULL)
  {
    printf("\nError: File not found!\n");
    exit(1);
  }

  printf("\nEnter the number of characters to read: ");
  scanf("%d", &n);

  char *ptr=(char*)malloc(n*sizeof(char));

  printf("\nReading contents of file...\n\n");

  while((ch=fgetc(fp))!=EOF && count<n)
  {
    *(ptr+count)=ch;
    count++;
  }

  *ptr='\0';

  printf("\nThe first %d characters of the file are: %s\n", n, ptr);

  fclose(fp);
  return 0;
}