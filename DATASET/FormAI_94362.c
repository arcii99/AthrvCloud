//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch;

   // create a new file
   fp = fopen("genius.txt", "w");
   
   // check if the file was created successfully
   if (fp == NULL) {
      printf("Failed to create file.");
      exit(0);
   }

   printf("You are a genius!\n");
   fprintf(fp, "You are a genius!\n");

   // close the file
   fclose(fp);

   // open the file for reading
   fp = fopen("genius.txt", "r");

   // check if the file was opened successfully
   if (fp == NULL) {
      printf("Failed to open file.");
      exit(0);
   }

   // read the file character by character
   printf("Reading from the file...\n");
   while (!feof(fp)) {
      ch = fgetc(fp);
      putchar(ch);
   }

   // close the file
   fclose(fp);

   // delete the file
   if (remove("genius.txt") == 0) {
      printf("\nFile deleted.\n");
   }
   else {
      printf("\nFailed to delete file.\n");
   }

   return 0;
}