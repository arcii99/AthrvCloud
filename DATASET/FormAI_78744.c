//FormAI DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp;
   char ch, fileName[20];

   printf("Please enter the name of the file you wish to open: ");
   scanf("%s", fileName);

   fp = fopen(fileName, "r"); // Opening the file in read mode

   if (fp == NULL)
   {
       printf("The file named %s does not exist or could not be opened.\n", fileName);
       exit(1);
   }

   printf("Processing file...\n");

   // Counting the number of lines in the file
   int lineCount = 0; 
   while ((ch = fgetc(fp)) != EOF) 
   {
       if (ch == '\n')
       {
           lineCount++;
       }
   }
   printf("The file %s has %d lines.\n", fileName, lineCount);

   // Closing the file
   fclose(fp);

   return 0;
}