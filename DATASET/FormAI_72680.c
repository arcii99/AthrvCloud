//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char buffer[255];

   // Open file for writing and append
   fp = fopen("example.txt", "a");

   // Prompt user for input to be written to file
   printf("What message would you like to add to the file?\n");
   fgets(buffer, 255, stdin);

   // Write user input to file
   fprintf(fp, "%s", buffer);

   // Close the file
   fclose(fp);

   // Open file for reading
   fp = fopen("example.txt", "r");

   // Check if file exists and can be opened for reading
   if (fp == NULL) {
      printf("Could not open file.\n");
      exit(1);
   }

   // Print contents of file to console
   printf("Contents of file:\n");

   while (fgets(buffer, 255, fp)) {
      printf("%s", buffer);
   }

   // Close the file
   fclose(fp);

   return 0;
}