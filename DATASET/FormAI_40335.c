//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
// Welcome to the Happy File Sync program!

#include <stdlib.h>
#include <stdio.h>

int main() {

   printf("Hello, friend! Let's sync some files!\n");

   // Step 1: Gather user input
   printf("Please enter the name of the file you want to sync: ");
   char* filename;
   scanf("%s", filename);

   printf("Please enter the name of the destination file: ");
   char* destination;
   scanf("%s", destination);

   // Step 2: Open files and check for errors
   FILE* source_file = fopen(filename, "r");
   if (source_file == NULL) {
      printf("Uh oh! Looks like we couldn't open the source file!\n");
      exit(EXIT_FAILURE);
   }

   FILE* dest_file = fopen(destination, "w");
   if (dest_file == NULL) {
      printf("Oops! Couldn't open the destination file!\n");
      exit(EXIT_FAILURE);
   }

   // Step 3: Sync the files
   int ch = getc(source_file);
   while (ch != EOF) {
      putc(ch, dest_file);
      ch = getc(source_file);
   }

   // Step 4: Close files
   fclose(source_file);
   fclose(dest_file);

   printf("Yay! File syncing complete!\n");
   exit(EXIT_SUCCESS);
}