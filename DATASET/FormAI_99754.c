//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp;
   char ch, file_name[25];
   
   printf("Enter the file name: ");
   scanf("%s", file_name);
   
   fp = fopen(file_name, "r");

   if (fp == NULL)
   {
      printf("Error opening file.\n");
      exit(1);
   }

   while ((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
   return 0;
}