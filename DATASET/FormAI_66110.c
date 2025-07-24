//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>

int main() {
   // File pointer declaration
   FILE *fp;
   char ch;

   // Open file in read mode
   fp = fopen("myfile.txt", "r");

   // If file pointer is null
   if(fp == NULL) {
      printf("Error opening file");
      return 1;
   }

   // Read and print content character by character
   printf("The content of the file is:\n");
   while((ch = fgetc(fp)) != EOF) {
      printf("%c", ch);
   }

   // Close file
   fclose(fp);

   // Open same file in write mode
   fp = fopen("myfile.txt", "w");

   // If file pointer is null
   if(fp == NULL) {
      printf("Error opening file");
      return 1;
   }

   // Write to file
   fputs("This is a new line.", fp);

   // Close file
   fclose(fp);

   // Open file in read mode
   fp = fopen("myfile.txt", "r");

   // If file pointer is null
   if(fp == NULL) {
      printf("Error opening file");
      return 1;
   }

   // Read and print content character by character
   printf("\nThe modified content of the file is:\n");
   while((ch = fgetc(fp)) != EOF) {
      printf("%c", ch);
   }

   // Close file
   fclose(fp);
   
   return 0;
}