//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>

int main() {
   FILE *fp;
   char ch;

   // Open file for writing
   fp = fopen("file.txt", "w");

   // Write to file
   fprintf(fp, "This is a demo file.\n");

   // Close file
   fclose(fp);

   // Open file for reading
   fp = fopen("file.txt", "r");

   // Read and print file contents
   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   // Close file
   fclose(fp);

   return 0;
}