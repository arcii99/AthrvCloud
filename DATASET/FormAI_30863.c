//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch;

   fp = fopen("myfile.txt", "r");
   if (fp == NULL) {
      printf("OMG! File does not exist or failed to open.\n");
      exit(1);
   }

   printf("OMG! File opened successfully.\n\n");
   
   printf("OMG! Reading contents from file.\n\n");
   while ((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   printf("\n\nOMG! Closing the file.\n");
   fclose(fp);
   printf("OMG! File closed successfully.");

   return 0;
}