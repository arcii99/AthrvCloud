//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp;
   char c[] = "This is an example file handling program.";
   char buffer[100];

   /* Writing to file */

   fp = fopen("example.txt", "w");
   
   if(fp == NULL){
       printf("Error opening file!");
       exit(1);
   }
   
   fputs(c, fp);

   printf("Text written to file successfully.");

   fclose(fp);

   /* Reading from file */

   fp = fopen("example.txt", "r");

   if(fp == NULL){
       printf("Error opening file!");
       exit(1);
   }

   fgets(buffer, 100, fp);

   printf("Text read from file: %s", buffer);
   fclose(fp);

   return 0;
}