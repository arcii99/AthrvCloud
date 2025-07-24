//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char filename[20];
   char ch;
   int count = 0;

   printf("Enter the filename to be opened: ");
   scanf("%s", filename);

   // Open the file in read-only mode
   fp = fopen(filename, "r");

   // If unable to open file, give error message and exit
   if (fp == NULL) {
      perror("Error in opening file");
      exit(1);
   }

   // Read character by character until end-of-file is reached
   while ((ch = fgetc(fp)) != EOF) {
      printf("%c", ch);
      count++;
   }

   // Close the file
   fclose(fp);

   printf("\n\nNumber of characters in %s is %d\n", filename, count);
   return 0;
}