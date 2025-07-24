//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char ch, file_name[25];
   FILE *fp;

   printf("Enter the name of file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // opening file in read mode

   if (fp == NULL)
   {
      perror("Error");
      printf("Could not open file %s", file_name);
      exit(EXIT_FAILURE);
   }

   printf("The contents of file are:\n");

   while ((ch = fgetc(fp)) != EOF) // reading file contents and displaying them
      printf("%c", ch);

   fclose(fp); // closing file

   return 0;
}