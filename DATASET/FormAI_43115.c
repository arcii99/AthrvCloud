//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char character;

   // Open the file
   fp = fopen("test.txt", "w+");

   // Write to the file
   fprintf(fp, "This is a test line\n");

   // Move file pointer to the beginning of the file
   rewind(fp);

   // Read the file character by character
   while ((character = fgetc(fp)) != EOF) {
      printf("%c", character);
   }

   // Close the file
   fclose(fp);

   return 0;
}